#include <iostream>
#include <vector>
#include <array>

using namespace std;
// declare standards
int userChoice; // user input choice
int userOptions[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // possible user options
vector<int> userPicks;
char userInput;

// declare board
char board[5][5] = {
    {'1', '|', '2', '|', '3'},
    {'-', '|', '-', '|', '-'},
    {'4', '|', '5', '|', '6'},
    {'-', '|', '-', '|', '-'},
    {'7', '|', '8', '|', '9'}
};

// check user input for validity
bool validOption(int userChoice);
bool openOption(int userChoice);
void editBoard(int a);

// game options for players
void player1();
void player2();


// print board
void printBoard();


int main() {

    player1();
    printBoard();

    return 0;
}

// check user input for validity
bool validOption(int userChoice) {
    for (int number : userOptions) {
        if (number == userChoice) {
            return true;
        }
    }
    return false;
}

// check if option is still open
bool openOption(int userChoice) {
    for (int number : userPicks) {
        if (number != userChoice) {
            return true;
        }
    }
    return false;
}

// game options for players
void player1() {
    
    cout << "(1) Enter the block # you want to edit: ";
    cin >> userChoice;

    if (validOption && openOption) {
        editBoard(userChoice);
    } else {
        cout << "Invalid choice!\nPlease enter a valid remaining option";
    }

}

void player2() {
    
    cout << "(2) Enter the block # you want to edit: ";
    cin >> userChoice;

    if (validOption && openOption) {
        editBoard(userChoice);
    } else {
        cout << "Invalid choice!\nPlease enter a valid remaining option";
    }

}

void editBoard(int userChoice) {
    cout << "Enter the value you want to input (X/O): ";
    cin >> userInput;

    switch (userChoice) {
    case 1:
        board[0][0] = userInput;
        break;
    case 2:
        board[0][2] = userInput;
            break;
    case 3:
        board[0][4] = userInput;
        break;
    case 4:
        board[2][0] = userInput;
        break;
    case 5:
        board[2][2] = userInput;
        break;
    case 6:
        board[2][4] = userInput;
        break;
    case 7:
        board[4][0] = userInput;
        break;
    case 8:
        board[4][2] = userInput;
        break;
    case 9:
        board[4][4] = userInput;
       break;
    default:
        break;
    }
}

void printBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << board[i][j] << " ";
        }
        cout << std::endl; // Newline after each row
    }
}