#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// ANSI color codes for terminal output (may not work on all terminals)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

// Board dimensions
const int ROWS = 6;
const int COLS = 7;

// Game board
vector<vector<char>> board(ROWS, vector<char>(COLS, ' '));

// Function to display the Connect Four board
void displayBoard() {
    system("clear"); // Clears the terminal for a clean look (use "cls" for Windows)

    // Display the board grid with symbols and colors
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'X') {
                cout << "| " << RED << "⚫" << RESET << " "; // Player 1: Red disc
            } else if (board[i][j] == 'O') {
                cout << "| " << YELLOW << "⚪" << RESET << " "; // Player 2: Yellow disc
            } else {
                cout << "|   "; // Empty space
            }
        }
        cout << "|" << endl;
    }

    // Display column numbers for easier navigation
    for (int j = 0; j < COLS; j++) {
        cout << "----";
    }
    cout << "-" << endl;

    for (int j = 0; j < COLS; j++) {
        cout << "  " << j + 1 << " ";
    }
    cout << endl;
}

// Function to check if a column is full
bool isFull(int col) {
    return board[0][col] != ' ';
}

// Function to drop a player's disc into the board
bool dropDisc(int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

// Function to check if the current player has won
bool checkWin(char player) {
    // Horizontal check
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    // Vertical check
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS - 3; i++) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // Diagonal (top-left to bottom-right) check
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    // Diagonal (bottom-left to top-right) check
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    char player = 'X'; // 'X' for Player 1, 'O' for Player 2
    int moves = 0;

    // Game instructions
    cout << "Welcome to Connect Four!" << endl;
    cout << "Player 1: " << RED "⚫" RESET << " (X)\n";
    cout << "Player 2: " << YELLOW "⚪" RESET << " (O)\n";
    cout << "Take turns to drop your disc into a column. First to connect four wins!\n" << endl;

    displayBoard();

    // Main game loop
    while (true) {
        int col;
        cout << "Player " << (player == 'X' ? RED "⚫" RESET : YELLOW "⚪" RESET) << "'s turn. Enter a column (1-7): ";
        cin >> col;
        col--; // Adjust for 0-based index

        // Validate the input and column availability
        if (col < 0 || col >= COLS || isFull(col)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Drop the disc and check for win condition
        if (dropDisc(col, player)) {
            displayBoard();
            if (checkWin(player)) {
                cout << "Player " << (player == 'X' ? RED "⚫" RESET : YELLOW "⚪" RESET) << " wins!" << endl;
                break;
            }

            // Switch players
            player = (player == 'X') ? 'O' : 'X';
            moves++;

            // Check for draw condition
            if (moves == ROWS * COLS) {
                cout << "It's a draw!" << endl;
                break;
            }
        }
    }

    return 0;
}
