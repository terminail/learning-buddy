// Exercise: Arithmetic Operators - Solution
// This exercise demonstrates arithmetic operators in C++.

#include <iostream>

int main() {
    // Use basic arithmetic operators (+, -, *, /, %)
    int a = 15;
    int b = 4;
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;  // Integer division
    std::cout << "a % b = " << (a % b) << std::endl;  // Modulus
    
    // Work with floating-point numbers
    double x = 15.0;
    double y = 4.0;
    
    std::cout << "\nx = " << x << ", y = " << y << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;  // Floating-point division
    
    // Work with unary arithmetic operators (+, -)
    int positive_value = +a;  // Unary plus (no effect)
    int negative_value = -a;  // Unary minus (negation)
    
    std::cout << "\nUnary operators:" << std::endl;
    std::cout << "+a = " << positive_value << std::endl;
    std::cout << "-a = " << negative_value << std::endl;
    
    // Understand arithmetic operator precedence
    int result1 = a + b * 2;      // Multiplication has higher precedence
    int result2 = (a + b) * 2;    // Parentheses override precedence
    
    std::cout << "\nOperator precedence:" << std::endl;
    std::cout << "a + b * 2 = " << result1 << std::endl;
    std::cout << "(a + b) * 2 = " << result2 << std::endl;
    
    // Mixed type arithmetic
    int int_val = 10;
    double double_val = 3.5;
    double mixed_result = int_val + double_val;  // int is promoted to double
    
    std::cout << "\nMixed type arithmetic:" << std::endl;
    std::cout << "int_val + double_val = " << mixed_result << std::endl;
    
    return 0;
}