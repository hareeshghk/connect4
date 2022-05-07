#include <vector>

using namespace std;

enum class GameStatus {
    WON, DRAW, INCOMPLETE
};

class Board {
    int width, height;
    int turn; // 1 or 2
    vector<vector<int>> board;
    vector<int> NextEmptyPositions; // per column empty positions.
    int numColsFilled; // number of columns which are completely filled.
    GameStatus status; // current status of the game
public:
    Board(int w, int h);

    bool InsertVal(int col);

    bool ValidateMove(int col);

    bool isWinningMove(int row, int col);

    void changeTurn();

    void PrintBoard();

    int getTurn();

    GameStatus GetGameStatus();
};