// Solution to Exercise 5.1.1: Control Flow Statements

#include <iostream>
#include <string>

int main() {
    // Program that determines if a number is positive, negative, or zero
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    if (number > 0) {
        std::cout << "The number is positive" << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative" << std::endl;
    } else {
        std::cout << "The number is zero" << std::endl;
    }
    
    // Program that prints numbers from 1 to 10 using a for loop
    std::cout << "\nNumbers from 1 to 10: ";
    for (int i = 1; i <= 10; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // Program that calculates the sum of numbers from 1 to n using a while loop
    int n, sum = 0, i = 1;
    std::cout << "\nEnter a number to calculate sum from 1 to n: ";
    std::cin >> n;
    
    while (i <= n) {
        sum += i;
        i++;
    }
    std::cout << "Sum of numbers from 1 to " << n << " is: " << sum << std::endl;
    
    // Program that prints a pattern of stars using nested loops
    int rows;
    std::cout << "\nEnter number of rows for star pattern: ";
    std::cin >> rows;
    
    std::cout << "Star pattern:" << std::endl;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    return 0;
}