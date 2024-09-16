/*   
                TASK 1
         NUMBER GUESSING GAME

A program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.
*/




#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = std::rand() % 100 + 1;
    int userGuess;

    // Defined text colors 
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string CYAN = "\033[96m";
    const std::string GREEN = "\033[92m";
    const std::string RED = "\033[91m";
    const std::string YELLOW = "\033[93m";

    // INTRODUCTION
    std::cout << CYAN
              << "╔════════════════════════════════════════════════════╗\n"
              << "║ " << BOLD << "  🎉 Welcome to the Number Guessing Game! 🎉" << RESET << " ║\n"
              << "║                                                    ║\n"
              << "║ " << BOLD << "  I’m thinking of a number between 1 and 100." << RESET << " ║\n"
              << "║ " << BOLD << "  Can you guess it? Try your best!" << RESET << "        ║\n"
              << "╚════════════════════════════════════════════════════╝\n\n" << RESET;

    std::cout << YELLOW << "Let's get started! 🌟\n";
    std::cout << "Enter your guess: " << RESET;

    do {
        std::cin >> userGuess;
        if (userGuess > randomNumber) {
            std::cout << RED << "Oops! Your guess is too high. Try a lower number! 🙃 " << RESET;
        } else if (userGuess < randomNumber) {
            std::cout << RED << "Almost there! Your guess is too low. Try a higher number! 😊 " << RESET;
        }
    } while (userGuess != randomNumber);

    // Congratulatory message 
    std::cout << "\n" << GREEN << "🎉 Congratulations! You've guessed the number " << randomNumber << "! 🎉\n";
    std::cout << "You did it! 🏆 Well done, guess-master! 👏\n" << RESET;

    // Thank you 
    std::cout << CYAN
              << "\n╔════════════════════════════════════════════════════╗\n"
              << "║ " << BOLD << "  Thanks for playing! 🌟" << RESET << "                        ║\n"
              << "║ " << BOLD << "  Created with ❤️ by Viraj Tupe" << RESET << "                ║\n"
              << "╚════════════════════════════════════════════════════╝\n" << RESET;

    return 0;
}
