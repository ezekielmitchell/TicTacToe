#include <iostream>
#include <vector>
#include <array>

using namespace std;
// declare players
const string PLAYER1 = "Player (1)";
const string PLAYER2 = "Player (2)";

// setup board
char newBoard[5][5] = {
    {'1', '|', '2', '|', '3'},
    {'-', '|', '-', '|', '-'},
    {'4', '|', '5', '|', '6'},
    {'-', '|', '-', '|', '-'},
    {'7', '|', '8', '|', '9'}
};



void runGame() {


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << newBoard[i][j] << " ";
        }
        cout << std::endl; // Newline after each row
    }
}


int main() {

    setup();
    runGame();

    return 0;
}
