#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char currentPlayer);
bool checkWin(const vector<vector<char>>& board, char currentPlayer);
bool checkDraw(const vector<vector<char>>& board);
char switchPlayer(char currentPlayer);
bool playAgain();

int main() {
    bool replay = true;

    while (replay) {
        // Initialize the game board
        vector<vector<char>> board(3, vector<char>(3, ' '));

        // Initialize players
        char currentPlayer = 'X';

        // Game loop
        while (true) {
            // Display the current state of the board
            displayBoard(board);

            // Prompt the current player to enter their move
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            while (!makeMove(board, currentPlayer)) {
                cout << "Invalid move. Try again: ";
            }

            // Check for a win
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for a draw
            if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players
            currentPlayer = switchPlayer(currentPlayer);
        }

        // Ask if the players want to play again
        replay = playAgain();
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool makeMove(vector<vector<char>>& board, char currentPlayer) {
    int row, col;
    cin >> row >> col;

    // Check if the chosen cell is empty
    if (board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = currentPlayer;
        return true;
    } else {
        return false;
    }
}

bool checkWin(const vector<vector<char>>& board, char currentPlayer) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;  // Check rows
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;  // Check columns
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;  // Diagonal from top-left to bottom-right
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;  // Diagonal from top-right to bottom-left
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    // Check if the board is full (no empty spaces)
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;  // Board is not full, the game can continue
            }
        }
    }
    return true;  // Board is full, and there is no winner - it's a draw
}

char switchPlayer(char currentPlayer) {
    // Switch between 'X' and 'O'
    return (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}
