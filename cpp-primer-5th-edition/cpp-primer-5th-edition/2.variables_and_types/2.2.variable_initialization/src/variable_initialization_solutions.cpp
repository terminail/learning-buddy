// Exercise 2.1b: Variable Initialization - Solution
// This exercise demonstrates different methods of variable initialization in C++.

#include <iostream>
#include <vector>
#include <string>

int main() {
    // Solution: Use copy initialization
    int copyInit = 42;
    double copyInitDouble = 3.14;
    std::string copyInitString = "Hello";
    
    std::cout << "Copy initialization:" << std::endl;
    std::cout << "int: " << copyInit << std::endl;
    std::cout << "double: " << copyInitDouble << std::endl;
    std::cout << "string: " << copyInitString << std::endl;
    
    // Solution: Use direct initialization
    int directInit(100);
    double directInitDouble(2.718);
    std::string directInitString("World");
    
    std::cout << "\nDirect initialization:" << std::endl;
    std::cout << "int: " << directInit << std::endl;
    std::cout << "double: " << directInitDouble << std::endl;
    std::cout << "string: " << directInitString << std::endl;
    
    // Solution: Use list initialization (C++11)
    int listInit{200};
    double listInitDouble{1.414};
    std::string listInitString{"C++"};
    std::vector<int> listInitVector{1, 2, 3, 4, 5};
    
    std::cout << "\nList initialization:" << std::endl;
    std::cout << "int: " << listInit << std::endl;
    std::cout << "double: " << listInitDouble << std::endl;
    std::cout << "string: " << listInitString << std::endl;
    std::cout << "vector size: " << listInitVector.size() << std::endl;
    
    // Solution: List initialization with narrowing prevention
    // int narrowingPrevention{3.14};  // This would cause a compilation error!
    
    // Solution: Understand default initialization
    int defaultInit;  // Uninitialized - contains garbage value
    std::string defaultString;  // Default initialized to empty string
    
    std::cout << "\nDefault initialization:" << std::endl;
    std::cout << "string (default): '" << defaultString << "'" << std::endl;
    // std::cout << "int (uninitialized): " << defaultInit << std::endl;  // Undefined behavior!
    
    // Solution: Compare initialization methods
    int a = 10;      // Copy initialization
    int b(20);       // Direct initialization
    int c{30};       // List initialization
    int d = {40};    // Copy list initialization
    
    std::cout << "\nComparison of initialization methods:" << std::endl;
    std::cout << "Copy init: " << a << std::endl;
    std::cout << "Direct init: " << b << std::endl;
    std::cout << "List init: " << c << std::endl;
    std::cout << "Copy list init: " << d << std::endl;
    
    return 0;
}