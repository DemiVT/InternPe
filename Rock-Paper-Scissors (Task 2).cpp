#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

void printIntroduction() {
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "You will play against the computer." << endl;
    cout << "Enter 1 for Rock, 2 for Paper, 3 for Scissors." << endl;
}

int getComputerChoice() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    return rand() % 3 + 1;  // Random number between 1 and 3
}

void determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }
}

int main() {
    printIntroduction();
    
    int playerChoice;
    cout << "Enter your choice: ";
    cin >> playerChoice;

    if (playerChoice < 1 || playerChoice > 3) {
        cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        return 1;
    }

    int computerChoice = getComputerChoice();
    cout << "Computer chose: " << computerChoice << endl;
    
    determineWinner(playerChoice, computerChoice);

    return 0;
}
