#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));
    
    // Generate a random number between 1 and 100
    int numberToGuess = std::rand() % 100 + 1;
    int guess = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I've picked a number between 1 and 100. Can you guess it?" << std::endl;

    // Loop until the user guesses the correct number
    while (guess != numberToGuess) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Provide feedback
        if (guess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number!" << std::endl;
        }
    }

    return 0;
}
