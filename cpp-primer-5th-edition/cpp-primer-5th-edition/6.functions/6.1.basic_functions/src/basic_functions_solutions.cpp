// Solution 6.1.1: Basic Functions
// This exercise demonstrates basic functions in C++.

#include <iostream>
#include <string>

// Solution: Function that takes no parameters and returns nothing
void printWelcome() {
    std::cout << "Welcome to the functions exercise!" << std::endl;
}

// Solution: Function that takes two integers and returns their sum
int addNumbers(int a, int b) {
    return a + b;
}

// Solution: Function that takes a string and prints it with a prefix
void printWithPrefix(const std::string& message) {
    std::cout << "Prefix: " << message << std::endl;
}

int main() {
    // Call the functions to test them
    printWelcome();
    
    int sum = addNumbers(5, 7);
    std::cout << "5 + 7 = " << sum << std::endl;
    
    printWithPrefix("Hello, World!");
    printWithPrefix("Functions are useful!");
    
    return 0;
}