#include "scopes_exercises.h"

// Define the global variable
int cpp_primer::global_variable = 999;

namespace cpp_primer {

// Global variable for scope demonstration
int global_var = 500;

// ========== CONSTRUCTORS ==========

Scopes::Scopes() {
    // Default constructor implementation
}

// ========== SCOPE METHODS ==========

int Scopes::demonstrate_block_scope() {
    // TODO: Implement to show block scope behavior
    // Example: declare a variable in a block and return its value
    // {
    //     int block_var = 42;
    //     return block_var;
    // }
    
    // Replace with your implementation
    return 0;  // Placeholder
}

int Scopes::demonstrate_nested_scopes() {
    // TODO: Implement to show nested scope behavior
    // Example: create nested blocks and access variables from different scopes
    // int outer_var = 10;
    // {
    //     int inner_var = 20;
    //     return outer_var + inner_var;
    // }
    
    // Replace with your implementation
    return 0;  // Placeholder
}

int Scopes::demonstrate_variable_shadowing() {
    // TODO: Implement to show variable shadowing
    // Example: declare a variable, then declare another with the same name in nested scope
    // int shadowed_var = 100;
    // {
    //     int shadowed_var = 200;  // This shadows the outer variable
    //     return shadowed_var;  // Return inner value
    // }
    
    // Replace with your implementation
    return 0;  // Placeholder
}

int Scopes::access_global_variable() {
    // TODO: Implement to access global variable
    // Example: return the global variable value
    
    // Replace with your implementation
    return 0;  // Placeholder
}

int Scopes::demonstrate_scope_resolution(int value) {
    // TODO: Implement to show scope resolution operator
    // Example: access global variable using :: operator
    
    // Replace with your implementation
    return 0;  // Placeholder
}

int Scopes::demonstrate_function_scope(int param) {
    // TODO: Implement to show function scope behavior
    // Example: work with function parameter and local variables
    
    // Replace with your implementation
    return 0;  // Placeholder
}

} // namespace cpp_primer