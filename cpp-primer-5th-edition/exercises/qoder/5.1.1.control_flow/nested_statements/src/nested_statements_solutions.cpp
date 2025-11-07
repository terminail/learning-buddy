// Solution 5.1.3: Nested Control Statements
// This exercise demonstrates nested control statements in C++.

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Solution: Print a right-angled triangle of stars using nested loops
    int rows;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    // Solution: Find all prime numbers up to n using nested loops and if statements
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    
    std::cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    
    // Solution: Implement a simple number guessing game
    // For this exercise, we'll use a fixed number
    int secretNumber = 7;
    int guess;
    int attempts = 0;
    const int maxAttempts = 5;
    
    std::cout << "Guess a number between 1 and 10 (you have " << maxAttempts << " attempts):" << std::endl;
    
    while (attempts < maxAttempts) {
        std::cout << "Attempt " << (attempts + 1) << ": ";
        std::cin >> guess;
        attempts++;
        
        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
            break;
        } else if (guess < secretNumber) {
            std::cout << "Too low!" << std::endl;
        } else {
            std::cout << "Too high!" << std::endl;
        }
        
        if (attempts == maxAttempts) {
            std::cout << "Game over! The number was " << secretNumber << std::endl;
        }
    }
    
    return 0;
}