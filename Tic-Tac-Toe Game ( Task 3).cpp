#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << "Tic Tac Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return 0;
}

void switchPlayer() {
    if (current_player == 1) {
        current_player = 2;
        current_marker = 'O';
    } else {
        current_player = 1;
        current_marker = 'X';
    }
}

void game() {
    int player_won;
    current_player = 1;
    current_marker = 'X';
    
    for (int i = 0; i < 9; i++) {
        drawBoard();
        cout << "Player " << current_player << ", enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot occupied! Try another slot.\n";
            i--;
            continue;
        }

        player_won = winner();

        if (player_won != 0) {
            drawBoard();
            cout << "Player " << player_won << " wins!\n";
            return;
        }

        switchPlayer();
    }

    drawBoard();
    cout << "It's a tie!\n";
}

int main() {
    game();
    return 0;
}
