// Solution 8.1b: Stream States and Error Handling
// This exercise demonstrates stream state management and error handling in C++ IO operations.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // Solution: Check and handle stream states
    std::cout << "Testing stream states..." << std::endl;
    std::cout << "Stream is good: " << std::cout.good() << std::endl;
    std::cout << "Stream is fail: " << std::cout.fail() << std::endl;
    std::cout << "Stream is eof: " << std::cout.eof() << std::endl;
    std::cout << "Stream is bad: " << std::cout.bad() << std::endl;
    std::cout << std::endl;

    // Solution: Clear stream errors and continue processing
    std::cout << "Testing error handling..." << std::endl;
    std::cin.clear(); // Clear any existing error flags
    
    // Force stream into error state by trying to read a string into an int
    std::istringstream iss("not_a_number");
    int number;
    if (!(iss >> number)) {
        std::cout << "Invalid input detected, clearing error state" << std::endl;
        iss.clear(); // Clear error flags
        iss.ignore(1000, '\n'); // Ignore invalid input
        std::cout << "Recovered from error, continuing processing" << std::endl;
    }
    std::cout << std::endl;

    // Solution: Handle file opening errors
    std::cout << "Testing file operations..." << std::endl;
    std::ofstream outFile("test_output.txt");
    if (outFile.is_open()) {
        std::cout << "File opened successfully" << std::endl;
        outFile << "This is a test file." << std::endl;
        outFile.close();
        std::cout << "File operation completed" << std::endl;
    } else {
        std::cout << "Failed to open file for writing" << std::endl;
    }

    return 0;
}