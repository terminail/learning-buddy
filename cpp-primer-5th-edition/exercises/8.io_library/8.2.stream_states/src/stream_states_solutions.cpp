// Exercise 8.1b: Stream States and Error Handling - Solution
// This exercise demonstrates stream state management and error handling in C++ IO operations.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // Check and handle stream states
    std::istringstream iss("123 abc 456");
    int number;
    
    // Read first number successfully
    iss >> number;
    std::cout << "Read number: " << number << std::endl;
    std::cout << "Stream good(): " << iss.good() << std::endl;
    std::cout << "Stream fail(): " << iss.fail() << std::endl;
    std::cout << "Stream eof(): " << iss.eof() << std::endl;
    std::cout << "Stream bad(): " << iss.bad() << std::endl;
    
    // Try to read string into int (will fail)
    iss >> number;
    std::cout << "After failed read:" << std::endl;
    std::cout << "Stream good(): " << iss.good() << std::endl;
    std::cout << "Stream fail(): " << iss.fail() << std::endl;
    std::cout << "Stream eof(): " << iss.eof() << std::endl;
    std::cout << "Stream bad(): " << iss.bad() << std::endl;
    
    // Clear error and continue
    iss.clear();
    std::string str;
    iss >> str;
    std::cout << "Read string after clear(): " << str << std::endl;
    
    // Handle file opening errors
    std::ifstream file("nonexistent.txt");
    if (file.is_open()) {
        std::cout << "File opened successfully" << std::endl;
        file.close();
    } else {
        std::cout << "Failed to open file" << std::endl;
    }
    
    // Work with stringstream states
    std::ostringstream oss;
    oss << "Hello, World!";
    std::cout << "String stream content: " << oss.str() << std::endl;
    std::cout << "String stream good(): " << oss.good() << std::endl;
    
    return 0;
}