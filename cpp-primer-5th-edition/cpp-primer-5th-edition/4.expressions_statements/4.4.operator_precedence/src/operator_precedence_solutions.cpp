// Exercise: Operator Precedence and Associativity - Solution
// This exercise demonstrates operator precedence and associativity in C++.

#include <iostream>

int main() {
    // Understand arithmetic operator precedence
    int a = 10, b = 5, c = 2;
    
    // Multiplication and division have higher precedence than addition and subtraction
    int result1 = a + b * c;      // 10 + (5 * 2) = 10 + 10 = 20
    int result2 = a * b + c;      // (10 * 5) + 2 = 50 + 2 = 52
    int result3 = a + b * c - 5;  // 10 + (5 * 2) - 5 = 10 + 10 - 5 = 15
    
    std::cout << "Arithmetic precedence:" << std::endl;
    std::cout << "a + b * c = " << result1 << std::endl;
    std::cout << "a * b + c = " << result2 << std::endl;
    std::cout << "a + b * c - 5 = " << result3 << std::endl;
    
    // Use parentheses to override natural precedence
    int result4 = (a + b) * c;    // (10 + 5) * 2 = 15 * 2 = 30
    int result5 = a * (b + c);    // 10 * (5 + 2) = 10 * 7 = 70
    
    std::cout << "\nWith parentheses:" << std::endl;
    std::cout << "(a + b) * c = " << result4 << std::endl;
    std::cout << "a * (b + c) = " << result5 << std::endl;
    
    // Understand logical operator precedence
    bool x = true, y = false, z = true;
    
    // ! has highest precedence, then &&, then ||
    bool result6 = x || y && z;        // x || (y && z) = true || (false && true) = true || false = true
    bool result7 = x && y || z;        // (x && y) || z = (true && false) || true = false || true = true
    bool result8 = !x && y || z;       // (!x && y) || z = (false && false) || true = false || true = true
    
    std::cout << "\nLogical precedence:" << std::endl;
    std::cout << "x || y && z = " << result6 << std::endl;
    std::cout << "x && y || z = " << result7 << std::endl;
    std::cout << "!x && y || z = " << result8 << std::endl;
    
    // Use parentheses to make precedence explicit
    bool result9 = x || (y && z);      // Same as result6
    bool result10 = (x && y) || z;     // Same as result7
    bool result11 = (!x && y) || z;    // Same as result8
    
    std::cout << "\nWith explicit parentheses:" << std::endl;
    std::cout << "x || (y && z) = " << result9 << std::endl;
    std::cout << "(x && y) || z = " << result10 << std::endl;
    std::cout << "(!x && y) || z = " << result11 << std::endl;
    
    // Understand mixed operator precedence
    int num1 = 5, num2 = 3;
    bool flag = true;
    
    // Arithmetic operators have higher precedence than relational operators
    // Relational operators have higher precedence than logical operators
    bool result12 = num1 + num2 > 6 && flag;  // ((num1 + num2) > 6) && flag = (8 > 6) && true = true && true = true
    
    std::cout << "\nMixed operator precedence:" << std::endl;
    std::cout << "num1 + num2 > 6 && flag = " << result12 << std::endl;
    
    // Understand operator associativity
    int p = 2, q = 3, r = 4;
    
    // Left-to-right associativity for most operators
    int result13 = p + q + r;        // (p + q) + r = (2 + 3) + 4 = 5 + 4 = 9
    int result14 = p - q - r;        // (p - q) - r = (2 - 3) - 4 = -1 - 4 = -5
    
    std::cout << "\nOperator associativity:" << std::endl;
    std::cout << "p + q + r = " << result13 << std::endl;
    std::cout << "p - q - r = " << result14 << std::endl;
    
    return 0;
}