#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
// declare standards
int userChoice; // user input choice
int userOptions[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // possible user options
char xo[2] = {'X', 'O'};
vector<int> userPicks = {0};
char userInput;
bool state = true;
bool userTurn = true;

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

// declare winner or tie
bool winner();
bool tie();


int main() {

    player1();

    return 0;
}

// check user input for validity with location
bool validOption(int userChoice) {
    for (int number : userOptions) {
        if (number == userChoice) {
            return true;
            break;
        }
    }
    return false;
}

// check if option is still open
bool openOption(int userChoice) {
    for (int number : userPicks) {
        if (number != userChoice) {
            return true;
            break;
        }
    }
    return false;
}

// check user input for validity with input
bool validInput(int userInput) {
    for (char c : xo) {
        if (c == toupper(userInput)) {
            return true;
            break;
        }
    }

    cout << "Invalid input; only enter X or O" << endl;

    return false;
}

// game options for players
void player1() {

    while(userTurn) {

        cout << "(1) Enter desired block #: ";
        cin >> userChoice;

        while(!validOption(userChoice) || !openOption(userChoice)) {
            cout << "Invalid input!" << endl;
            cout << "(1) Enter desired block #: ";
            cin.clear();
            cin.ignore();
            cin >> userChoice;
        }

        userPicks.push_back(userChoice);
        editBoard(userChoice);
        printBoard();
        cout << endl;


        cout << "(1) Location [" << userChoice << "] to [" << userInput << "]" << endl;
        cout << "Player count: " << userPicks.size() << endl;
        userTurn = false;
    }
}

// TODO: adsa
void player2() {
    while(userTurn) {

        cout << "(2) Enter desired block #: ";
        cin >> userChoice;

        while(!validOption(userChoice) || !openOption(userChoice)) {
            cout << "Invalid input!" << endl;
            cout << "(2) Enter desired block #: ";
            cin.clear();
            cin.ignore();
            cin >> userChoice;
        }

        userPicks.push_back(userChoice);
        editBoard(userChoice);
        printBoard();
        cout << endl;

        cout << "(2) Location [" << userChoice << "] to [" << userInput << "]" << endl;
        cout << "Player count: " << userPicks.size() << endl;
        userTurn = false;
    }
}

// edit board
void editBoard(int userChoice) {
    cout << "Enter the value you want to input (X/O): ";
    cin >> userInput;

    if (validInput(userInput)) {
        switch (userChoice) {
            case 1:
                board[0][0] = toupper(userInput);
                break;
            case 2:
                board[0][2] = toupper(userInput);
                    break;
            case 3:
                board[0][4] = toupper(userInput);
                break;
            case 4:
                board[2][0] = toupper(userInput);
                break;
            case 5:
                board[2][2] = toupper(userInput);
                break;
            case 6:
                board[2][4] = toupper(userInput);
                break;
            case 7:
                board[4][0] = toupper(userInput);
                break;
            case 8:
                board[4][2] = toupper(userInput);
                break;
            case 9:
                board[4][4] = toupper(userInput);
            break;
            default:
                break;
        }
        
    }
}

// print board
void printBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << board[i][j] << " ";
        }
        cout << std::endl; // Newline after each row
    }
}

// declare winner or tie
bool winner(){
    if ((board[0][0] == board[0][2]) && (board[0][0] == board[0][4])) {
        return true;
    } else if ((board[2][0] == board[2][2]) && (board[2][0] == board[2][4])) {
        return true;
    } else if ((board[4][0] == board[4][2]) && (board[4][0] == board[4][4])) {
        return true;
    } else if ((board[0][0] == board[2][2]) && (board[0][0] == board[4][4])) {
        return true;
    } else if ((board[0][4] == board[0][2]) && (board[0][4] == board[4][0])) {
        return true;
    }

    return false;
}

bool tie() {
    if (userPicks.size() == 9) {
        return true;
    } 

    return false;
}
