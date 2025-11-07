// Solution 8.1a: Basic IO Operations
// This exercise demonstrates basic input/output operations in C++.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main() {
    // Solution: Work with basic console input and output
    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!" << std::endl;
    
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    std::cout << "You are " << age << " years old." << std::endl;
    
    // Clear the input buffer
    std::cin.ignore();
    
    // Solution: Work with file output
    std::ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "Name: " << name << std::endl;
        outFile << "Age: " << age << std::endl;
        outFile << "This is a sample output file." << std::endl;
        outFile.close();
        std::cout << "Data written to output.txt" << std::endl;
    } else {
        std::cout << "Unable to open output.txt for writing" << std::endl;
    }
    
    // Solution: Work with file input
    std::ifstream inFile("output.txt");
    if (inFile.is_open()) {
        std::string line;
        std::cout << "Contents of output.txt:" << std::endl;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cout << "Unable to open output.txt for reading" << std::endl;
    }
    
    // Solution: Handle stream states and errors
    std::cout << "Enter a number: ";
    int number;
    if (std::cin >> number) {
        std::cout << "You entered: " << number << std::endl;
    } else {
        std::cout << "Invalid input. Clearing error state." << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n'); // Ignore up to 1000 characters or until newline
    }
    
    // Solution: Work with string streams
    std::string data = "John 25 Computer Science";
    std::istringstream iss(data);
    std::string studentName, major;
    int studentAge;
    
    if (iss >> studentName >> studentAge >> major) {
        std::cout << "Parsed data:" << std::endl;
        std::cout << "Name: " << studentName << std::endl;
        std::cout << "Age: " << studentAge << std::endl;
        std::cout << "Major: " << major << std::endl;
    } else {
        std::cout << "Failed to parse string data" << std::endl;
    }
    
    // Convert number to string using stringstream
    std::ostringstream oss;
    oss << "The number is: " << 42;
    std::string numberString = oss.str();
    std::cout << numberString << std::endl;
    
    return 0;
}