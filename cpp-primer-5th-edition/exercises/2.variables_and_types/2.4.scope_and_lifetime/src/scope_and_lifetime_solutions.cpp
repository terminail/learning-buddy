// Exercise 2.1d: Scope and Lifetime - Solution
// This exercise demonstrates variable scope and lifetime in C++.

#include <iostream>

// Solution: Work with global scope
int globalVariable = 100;
const double PI = 3.14159;

// Function to demonstrate global variable access
void accessGlobal() {
    std::cout << "Accessing global variable: " << globalVariable << std::endl;
    std::cout << "Accessing global constant: " << PI << std::endl;
    
    // Can modify global variables (if not const)
    globalVariable += 10;
}

// Solution: Work with local scope
void localScopeExample() {
    int localVariable = 50;
    std::cout << "Local variable in function: " << localVariable << std::endl;
    
    // localVariable is destroyed when function ends
}

// Solution: Work with block scope
void blockScopeExample() {
    int outerBlock = 10;
    std::cout << "Outer block variable: " << outerBlock << std::endl;
    
    {
        int innerBlock = 20;
        std::cout << "Inner block variable: " << innerBlock << std::endl;
        std::cout << "Outer block variable (still accessible): " << outerBlock << std::endl;
        
        // Variable shadowing
        int outerBlock = 30;  // Shadows the outer outerBlock
        std::cout << "Shadowed variable: " << outerBlock << std::endl;
    }
    
    // innerBlock is out of scope here
    // outerBlock refers to the original variable
    std::cout << "Back to outer block variable: " << outerBlock << std::endl;
    
    // This would cause a compilation error:
    // std::cout << innerBlock << std::endl;  // Error! innerBlock is out of scope
}

// Solution: Understand static variables
void staticVariableExample() {
    // Static variable - initialized only once, persists between function calls
    static int staticCounter = 0;
    int localCounter = 0;  // Local variable - initialized every time
    
    staticCounter++;
    localCounter++;
    
    std::cout << "Static counter: " << staticCounter << std::endl;
    std::cout << "Local counter: " << localCounter << std::endl;
}

int main() {
    // Solution: Work with global scope
    std::cout << "=== Global Scope ===" << std::endl;
    std::cout << "Global variable: " << globalVariable << std::endl;
    accessGlobal();
    std::cout << "Global variable after modification: " << globalVariable << std::endl;
    
    // Solution: Work with local scope
    std::cout << "\n=== Local Scope ===" << std::endl;
    localScopeExample();
    // localVariable is not accessible here
    
    // Solution: Work with block scope
    std::cout << "\n=== Block Scope ===" << std::endl;
    blockScopeExample();
    
    // Solution: Understand static variables
    std::cout << "\n=== Static Variables ===" << std::endl;
    staticVariableExample();  // Static: 1, Local: 1
    staticVariableExample();  // Static: 2, Local: 1
    staticVariableExample();  // Static: 3, Local: 1
    
    return 0;
}