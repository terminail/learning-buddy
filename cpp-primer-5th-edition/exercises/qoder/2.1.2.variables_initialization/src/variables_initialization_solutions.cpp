// Solution 2.1.2: Variable Initialization Methods
// This exercise demonstrates different ways to initialize variables in C++.

#include <iostream>
#include <string>

int main() {
    // Solution: Declare and initialize an integer variable named 'count' with value 10
    int count = 10;  // Copy initialization
    
    // Solution: Declare and initialize a double variable named 'price' with value 19.99
    double price{19.99};  // Uniform initialization (list initialization)
    
    // Solution: Declare and initialize a char variable named 'grade' with value 'A'
    char grade = 'A';  // Assignment initialization
    
    // Solution: Declare and initialize a bool variable named 'is_complete' with value false
    auto is_complete = false;  // Auto with direct initialization
    
    // Solution: Declare and initialize a string variable named 'message' with value "Hello"
    std::string message{"Hello"};  // List initialization with braces
    
    // Solution: Print all variables to the console
    std::cout << "Count: " << count << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Grade: " << grade << std::endl;
    std::cout << "Is Complete: " << std::boolalpha << is_complete << std::endl;
    std::cout << "Message: " << message << std::endl;
    
    return 0;
}