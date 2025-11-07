#include "variables_declarations_solutions.h"
#include <iostream>

namespace cpp_primer {

VariablesDeclarationsSolutions::VariablesDeclarationsSolutions() {
    // Constructor implementation
}

void VariablesDeclarationsSolutions::demonstrateDeclarations() {
    // Demonstrate proper variable declarations
    std::cout << "Demonstrating variable declarations:" << std::endl;
    
    // Integer declaration
    int age;
    
    // Double declaration
    double temperature;
    
    // Char declaration
    char first_initial;
    
    // Bool declaration
    bool is_raining;
    
    // String declaration
    std::string city_name;
    
    std::cout << "All variables declared successfully!" << std::endl;
}

} // namespace cpp_primer