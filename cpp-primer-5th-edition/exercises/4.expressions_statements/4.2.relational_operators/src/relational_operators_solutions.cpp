// Exercise: Relational Operators - Solution
// This exercise demonstrates relational operators in C++.

#include <iostream>
#include <string>

int main() {
    // Use equality operators (==, !=)
    int a = 10;
    int b = 20;
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    
    // Work with floating-point equality (be careful!)
    double x = 0.1 + 0.2;
    double y = 0.3;
    
    std::cout << "\nx = " << x << ", y = " << y << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    
    // Use relational operators (<, >, <=, >=)
    std::cout << "\nRelational comparisons:" << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    
    // Compare characters and strings
    char c1 = 'A';
    char c2 = 'B';
    
    std::cout << "\nCharacter comparisons:" << std::endl;
    std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
    std::cout << "c1 < c2: " << (c1 < c2) << std::endl;
    
    std::string s1 = "apple";
    std::string s2 = "banana";
    
    std::cout << "\nString comparisons:" << std::endl;
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
    std::cout << "s1 == \"apple\": " << (s1 == "apple") << std::endl;
    
    // Work with mixed-type comparisons
    int int_val = 5;
    double double_val = 5.0;
    
    std::cout << "\nMixed-type comparisons:" << std::endl;
    std::cout << "int_val = " << int_val << ", double_val = " << double_val << std::endl;
    std::cout << "int_val == double_val: " << (int_val == double_val) << std::endl;
    
    return 0;
}