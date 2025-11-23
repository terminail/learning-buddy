// Exercise: Logical Operators - Solution
// This exercise demonstrates logical operators in C++.

#include <iostream>

int main() {
    // Use logical AND operator (&&)
    bool a = true;
    bool b = false;
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a && b = " << (a && b) << std::endl;
    std::cout << "a && true = " << (a && true) << std::endl;
    std::cout << "b && false = " << (b && false) << std::endl;
    
    // Demonstrate short-circuit evaluation with &&
    int x = 5;
    std::cout << "\nShort-circuit with &&:" << std::endl;
    if (x > 0 && x < 10) {
        std::cout << "x is between 0 and 10" << std::endl;
    }
    
    // Use logical OR operator (||)
    std::cout << "\nLogical OR:" << std::endl;
    std::cout << "a || b = " << (a || b) << std::endl;
    std::cout << "false || false = " << (false || false) << std::endl;
    
    // Demonstrate short-circuit evaluation with ||
    std::cout << "\nShort-circuit with ||:" << std::endl;
    if (x < 0 || x > 10) {
        std::cout << "x is outside range 0-10" << std::endl;
    } else {
        std::cout << "x is within range 0-10" << std::endl;
    }
    
    // Use logical NOT operator (!)
    std::cout << "\nLogical NOT:" << std::endl;
    std::cout << "!a = " << (!a) << std::endl;
    std::cout << "!b = " << (!b) << std::endl;
    
    // Complex logical expressions
    int y = 15;
    std::cout << "\nComplex expressions:" << std::endl;
    bool complex_result = (x > 0 && x < 10) || (y > 10 && y < 20);
    std::cout << "(x > 0 && x < 10) || (y > 10 && y < 20): " << complex_result << std::endl;
    
    // De Morgan's laws
    bool p = true, q = false;
    std::cout << "\nDe Morgan's laws:" << std::endl;
    std::cout << "!(p && q) = " << !(p && q) << std::endl;
    std::cout << "!p || !q = " << (!p || !q) << std::endl;
    std::cout << "!(p || q) = " << !(p || q) << std::endl;
    std::cout << "!p && !q = " << (!p && !q) << std::endl;
    
    return 0;
}