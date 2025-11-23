// Exercise 2.1a: Variable Declarations - Solution
// This exercise demonstrates declaring variables of different types in C++.

#include <iostream>

// Global variable declaration
int globalVariable = 100;

int main() {
    // Solution: Declare variables of basic data types
    
    // Integer types
    int integerVar = 42;
    short shortVar = 1000;
    long longVar = 1000000L;
    long long longLongVar = 10000000000LL;
    
    std::cout << "Integer types:" << std::endl;
    std::cout << "int: " << integerVar << std::endl;
    std::cout << "short: " << shortVar << std::endl;
    std::cout << "long: " << longVar << std::endl;
    std::cout << "long long: " << longLongVar << std::endl;
    
    // Floating-point types
    float floatVar = 3.14f;
    double doubleVar = 3.14159265359;
    long double longDoubleVar = 3.141592653589793238L;
    
    std::cout << "\nFloating-point types:" << std::endl;
    std::cout << "float: " << floatVar << std::endl;
    std::cout << "double: " << doubleVar << std::endl;
    std::cout << "long double: " << longDoubleVar << std::endl;
    
    // Character types
    char charVar = 'A';
    wchar_t wideCharVar = L'Z';
    
    std::cout << "\nCharacter types:" << std::endl;
    std::cout << "char: " << charVar << std::endl;
    std::cout << "wchar_t: " << wideCharVar << std::endl;
    
    // Boolean type
    bool boolVar = true;
    
    std::cout << "\nBoolean type:" << std::endl;
    std::cout << "bool: " << boolVar << " (true)" << std::endl;
    std::cout << "bool: " << !boolVar << " (false)" << std::endl;
    
    // Variable naming conventions
    int camelCaseVariable = 1;
    int snake_case_variable = 2;
    int PascalCaseVariable = 3;
    
    std::cout << "\nVariable naming conventions:" << std::endl;
    std::cout << "camelCaseVariable: " << camelCaseVariable << std::endl;
    std::cout << "snake_case_variable: " << snake_case_variable << std::endl;
    std::cout << "PascalCaseVariable: " << PascalCaseVariable << std::endl;
    
    // Variable scope demonstration
    {
        // Block scope variable
        int blockScopedVar = 999;
        std::cout << "\nBlock scope variable: " << blockScopedVar << std::endl;
        std::cout << "Global variable (inside block): " << globalVariable << std::endl;
    }
    
    // This would cause a compilation error because blockScopedVar is out of scope:
    // std::cout << blockScopedVar << std::endl;  // Error!
    
    std::cout << "Global variable (outside block): " << globalVariable << std::endl;
    
    return 0;
}