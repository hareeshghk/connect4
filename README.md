# connect4game-cpp
Implementation of connect4 game

Completed backend code for Game engine
(TODO) Implement UI to expose board over browser.

# Usage
Compile with following command. You can use g++ compiler as well
/usr/bin/clang++ -std=c++17 -stdlib=libc++ -fdiagnostics-color=always -g connect4.cpp -o ./connect4.out

Run the output file.
./connect4.out

Same output when run this binary:

Number of Games: 2

width of board: 5

height of board: 4

Current turn: 1

Give Input: 0

0 0 0 0 0

0 0 0 0 0 

0 0 0 0 0 

1 0 0 0 0 



Board is printed after every output.

Game ends if any player won or if game results in draw.

Win message:
"Game won by player 1/2"

Draw Message:
"Game resulted in a DRAW"

Once a game is completed next game starts, it depends on number of games chosen in beginning.
