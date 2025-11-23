// Exercise 8.1d: Output Formatting - Solution
// This exercise demonstrates output formatting in C++.

#include <iostream>
#include <iomanip>
#include <string>

int main() {
    // Use basic stream manipulators
    std::cout << "Basic formatting:" << std::endl;
    std::cout << std::setw(10) << "Name" << std::setw(10) << "Age" << std::setw(10) << "Score" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;
    
    // Format numeric values
    double pi = 3.14159265359;
    std::cout << "Pi (default): " << pi << std::endl;
    std::cout << "Pi (fixed): " << std::fixed << pi << std::endl;
    std::cout << "Pi (scientific): " << std::scientific << pi << std::endl;
    std::cout << "Pi (precision 2): " << std::setprecision(2) << pi << std::endl;
    std::cout.unsetf(std::ios::fixed | std::ios::scientific); // Reset format
    
    // Format integers in different bases
    int number = 255;
    std::cout << "Number in decimal: " << number << std::endl;
    std::cout << "Number in hexadecimal: " << std::hex << number << std::endl;
    std::cout << "Number in octal: " << std::oct << number << std::endl;
    std::cout << std::dec; // Reset to decimal
    
    // Create formatted tables
    std::cout << "\nStudent Grades:" << std::endl;
    std::cout << std::left << std::setw(15) << "Student" 
              << std::right << std::setw(8) << "Math" 
              << std::setw(8) << "Science" 
              << std::setw(8) << "Average" << std::endl;
    std::cout << std::setfill('-') << std::setw(47) << "" << std::setfill(' ') << std::endl;
    
    std::cout << std::left << std::setw(15) << "Alice" 
              << std::right << std::setw(8) << "95" 
              << std::setw(8) << "87" 
              << std::setw(8) << std::fixed << std::setprecision(1) << 91.0 << std::endl;
    
    std::cout << std::left << std::setw(15) << "Bob" 
              << std::right << std::setw(8) << "78" 
              << std::setw(8) << "92" 
              << std::setw(8) << std::fixed << std::setprecision(1) << 85.0 << std::endl;
    
    std::cout << std::left << std::setw(15) << "Charlie" 
              << std::right << std::setw(8) << "88" 
              << std::setw(8) << "85" 
              << std::setw(8) << std::fixed << std::setprecision(1) << 86.5 << std::endl;
    
    return 0;
}