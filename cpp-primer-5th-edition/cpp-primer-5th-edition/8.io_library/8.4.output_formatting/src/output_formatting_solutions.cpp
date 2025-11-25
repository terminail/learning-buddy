// Solution 8.1d: Output Formatting
// This exercise demonstrates formatting output in C++ using stream manipulators.

#include <iostream>
#include <iomanip>
#include <string>

int main() {
    // Solution: Use basic stream manipulators
    std::cout << "Testing basic stream manipulators:" << std::endl;
    std::cout << std::setw(10) << "Column 1" << std::setw(15) << "Column 2" << std::endl;
    std::cout << std::setfill('-') << std::setw(25) << "-" << std::setfill(' ') << std::endl;
    std::cout << std::setw(10) << "Data 1" << std::setw(15) << "Value 1" << std::endl;
    std::cout << std::setw(10) << "Data 2" << std::setw(15) << "Value 2" << std::endl;
    std::cout << std::endl;

    // Solution: Format numeric values
    std::cout << "Testing numeric formatting:" << std::endl;
    double pi = 3.14159265359;
    std::cout << "Default: " << pi << std::endl;
    std::cout << "Fixed (2 decimals): " << std::fixed << std::setprecision(2) << pi << std::endl;
    std::cout << "Scientific: " << std::scientific << pi << std::endl;
    std::cout << "General: " << std::defaultfloat << pi << std::endl;
    std::cout << std::endl;

    // Reset formatting
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << std::setprecision(6);

    // Solution: Work with different number bases
    std::cout << "Testing number base formatting:" << std::endl;
    int number = 255;
    std::cout << "Decimal: " << std::dec << number << std::endl;
    std::cout << "Hexadecimal: " << std::hex << number << std::endl;
    std::cout << "Octal: " << std::oct << number << std::endl;
    std::cout << std::endl;

    // Reset to decimal
    std::cout << std::dec;

    // Solution: Create formatted tables
    std::cout << "Testing formatted tables:" << std::endl;
    std::cout << std::left << std::setw(15) << "Name" << std::setw(10) << "Age" << std::setw(15) << "City" << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::setfill(' ') << std::endl;
    std::cout << std::left << std::setw(15) << "John Doe" << std::setw(10) << 25 << std::setw(15) << "New York" << std::endl;
    std::cout << std::left << std::setw(15) << "Jane Smith" << std::setw(10) << 30 << std::setw(15) << "Los Angeles" << std::endl;
    std::cout << std::left << std::setw(15) << "Bob Johnson" << std::setw(10) << 35 << std::setw(15) << "Chicago" << std::endl;

    return 0;
}