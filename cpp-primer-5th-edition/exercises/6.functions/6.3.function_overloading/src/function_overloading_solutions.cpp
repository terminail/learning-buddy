// Exercise 6.1d: Function Overloading - Solution
// This exercise demonstrates function overloading in C++.

#include <iostream>
#include <vector>
#include <string>

// Solution: Create overloaded functions with different parameter counts
void printValue() {
    std::cout << "No parameters" << std::endl;
}

void printValue(int value) {
    std::cout << "One int parameter: " << value << std::endl;
}

void printValue(int value1, int value2) {
    std::cout << "Two int parameters: " << value1 << ", " << value2 << std::endl;
}

void printValue(int value1, int value2, int value3) {
    std::cout << "Three int parameters: " << value1 << ", " << value2 << ", " << value3 << std::endl;
}

// Solution: Create overloaded functions with different parameter types
void printValue(double value) {
    std::cout << "One double parameter: " << value << std::endl;
}

void printValue(const std::string& value) {
    std::cout << "One string parameter: " << value << std::endl;
}

void printValue(bool value) {
    std::cout << "One bool parameter: " << (value ? "true" : "false") << std::endl;
}

// Solution: Create overloaded functions with different parameter orders
void printValue(int intValue, double doubleValue) {
    std::cout << "Int then double: " << intValue << ", " << doubleValue << std::endl;
}

void printValue(double doubleValue, int intValue) {
    std::cout << "Double then int: " << doubleValue << ", " << intValue << std::endl;
}

// Solution: Function that might cause ambiguity
void ambiguousFunction(int value) {
    std::cout << "ambiguousFunction with int: " << value << std::endl;
}

void ambiguousFunction(double value) {
    std::cout << "ambiguousFunction with double: " << value << std::endl;
}

// Solution: Function with exact match to resolve ambiguity
void ambiguousFunction(float value) {
    std::cout << "ambiguousFunction with float: " << value << std::endl;
}

int main() {
    // Solution: Test overloaded functions with different parameter counts
    std::cout << "=== Different Parameter Counts ===" << std::endl;
    printValue();
    printValue(42);
    printValue(1, 2);
    printValue(1, 2, 3);
    
    // Solution: Test overloaded functions with different parameter types
    std::cout << "\n=== Different Parameter Types ===" << std::endl;
    printValue(42);           // Calls printValue(int)
    printValue(3.14);         // Calls printValue(double)
    printValue("Hello");      // Calls printValue(const std::string&)
    printValue(true);         // Calls printValue(bool)
    
    // Solution: Test overloaded functions with different parameter orders
    std::cout << "\n=== Different Parameter Orders ===" << std::endl;
    printValue(10, 3.14);     // Calls printValue(int, double)
    printValue(3.14, 10);     // Calls printValue(double, int)
    
    // Solution: Test overload resolution and ambiguity
    std::cout << "\n=== Overload Resolution ===" << std::endl;
    ambiguousFunction(42);      // Calls ambiguousFunction(int)
    ambiguousFunction(3.14);    // Calls ambiguousFunction(double)
    ambiguousFunction(1.23f);   // Calls ambiguousFunction(float) - exact match
    
    // Promotion in overload resolution
    short shortValue = 100;
    ambiguousFunction(shortValue);  // Promotes to int, calls ambiguousFunction(int)
    
    // This would be ambiguous without the float overload:
    // ambiguousFunction(1.23f);  // float could promote to double or int
    
    return 0;
}