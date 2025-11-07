// Solution 5.1.1: If Statements
// This exercise demonstrates conditional statements in C++.

#include <iostream>

int main() {
    // Solution: Check if a number is positive, negative, or zero
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    if (number > 0) {
        std::cout << number << " is positive." << std::endl;
    } else if (number < 0) {
        std::cout << number << " is negative." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }
    
    // Solution: Check if a person is eligible to vote
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    if (age >= 18) {
        std::cout << "You are eligible to vote." << std::endl;
    } else {
        std::cout << "You are not eligible to vote." << std::endl;
    }
    
    // Solution: Find the larger of two numbers
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    
    if (num1 > num2) {
        std::cout << num1 << " is larger than " << num2 << std::endl;
    } else if (num2 > num1) {
        std::cout << num2 << " is larger than " << num1 << std::endl;
    } else {
        std::cout << "Both numbers are equal." << std::endl;
    }
    
    return 0;
}