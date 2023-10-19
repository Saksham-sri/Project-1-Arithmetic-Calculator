#include <iostream>
#include <cstdlib> // for random number generation
#include <ctime>   // for seeding the random number generator

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    while (true) {
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> userGuess;

        attempts++;

        if (userGuess == randomNumber) {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;
            break;
        } else if (userGuess < randomNumber) {
            std::cout << "The number is too low. Try again." << std::endl;
        } else {
            std::cout << "The number is too high. Try again." << std::endl;
        }
    }

    return 0;
}
