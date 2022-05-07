#include <iostream>
#include <vector>
#include "connect4.h"

using namespace std;

int main() {
    int num_games;
    cout << "Number of Games: ";
    cin >> num_games;
    while (num_games--) {
        int w, h;
        cout << "width of board: ";
        cin >> w;
        cout << "height of board: ";
        cin >> h;
        Board board(w, h);

        int inputCol;
        // game loop until game done.
        while (true) {
            cout << "Current turn: " << board.getTurn() << endl;
            cout << "Give Input: ";
            cin >> inputCol;

            if (!board.InsertVal(inputCol)) {
                continue;
            }

            board.PrintBoard();

            auto gameStatus = board.GetGameStatus();

            if (gameStatus == GameStatus::WON) {
                cout << "Game won by player " << board.getTurn() << endl;
                break;
            } else if (gameStatus == GameStatus::DRAW) {
                cout << "Game resulted in a DRAW" << endl;
                break;
            }

            board.changeTurn();
        }
    }
    return 0;
}