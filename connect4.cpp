#include <iostream>
#include <vector>
#include "connect4.h"

using namespace std;

Board::Board(int w, int h) : width(w), height(h) {
    board.resize(height, vector<int>(width, 0));
    NextEmptyPositions.resize(width, height-1);
    turn = 1;
    status = GameStatus::INCOMPLETE;
    numColsFilled = 0;
}

bool Board::InsertVal(int col) {
    if (!ValidateMove(col)) {
        cout << "Invalid Move" << endl;
        return false;
    }

    int row = NextEmptyPositions[col];
    --NextEmptyPositions[col];
    if (NextEmptyPositions[col] == -1) {
        ++numColsFilled;
    }

    board[row][col] = turn;

    if (numColsFilled == width) {
        status = GameStatus::DRAW;
    }

    if (isWinningMove(row, col)) {
        status = GameStatus::WON;
    }

    return true;
}

bool Board::ValidateMove(int col) {
    if (col < 0 || col >= width) {
        cout << "Column should be in range of " << 0 << " to " << width-1 << endl;
        return false;
    }
    
    if (NextEmptyPositions[col] < 0) {
        cout << "There are no empty positions left on column " << col << endl;
        return false;
    }
    return true;
}

bool Board::isWinningMove(int row, int col) {
    // check row
    for (int start = max(0, col-3); start <= col; ++start) {
        if (start + 3 >= width) continue;
        bool windowCheck = true;
        for (int j = 0; j < 4; j++) {
            if (board[row][start+j] != board[row][col]) {
                windowCheck = false;
                break;
            }
        }

        if (windowCheck) {
            return true;
        }
    }

    // check col
    if (row <= height-4) {
        bool windowCheck = true;
        for (int j = 0; j < 4; j++) {
            if (board[row+j][col] != board[row][col]) {
                windowCheck = false;
                break;
            }
        }
        if (windowCheck) return true;
    }

    // check topdown diagonal
    for (int start = -3; start <= 0; ++start) {
        if (row+start < 0 || col+start < 0) continue;
        if (row+start+3 >= height || col+start+3 >= width) continue;
        bool windowCheck = true;
        for (int j = 0; j < 4; j++) {
            if (board[row+start+j][col+start+j] != board[row][col]) {
                windowCheck = false;
                break;
            }
        }

        if (windowCheck) {
            return true;
        }
    }

    // check bottomup diagonal
    for (int start = -3; start <= 0; ++start) {
        if (row-start >= height || col+start < 0) continue;
        if (row-start-3 < 0 || col+start+3 >= width) continue;
        bool windowCheck = true;
        for (int j = 0; j < 4; j++) {
            if (board[row-start-j][col+start+j] != board[row][col]) {
                windowCheck = false;
                break;
            }
        }

        if (windowCheck) {
            return true;
        }
    }

    return false;
}

void Board::changeTurn() {
    turn = turn^1^2;
}

void Board::PrintBoard() {
    for (int row  = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

int Board::getTurn() {
    return turn;
}

GameStatus Board::GetGameStatus() {
    return status;
}