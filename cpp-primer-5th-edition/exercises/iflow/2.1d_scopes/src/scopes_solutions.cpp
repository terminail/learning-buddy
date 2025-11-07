#include "scopes_solutions.h"

// Define the global variable
int cpp_primer::global_variable = 999;

namespace cpp_primer {

// Global variable for scope demonstration
int global_var = 500;

// ========== CONSTRUCTORS ==========

ScopesSolutions::ScopesSolutions() {
    // Default constructor implementation
}

// ========== SCOPE METHODS ==========

int ScopesSolutions::demonstrate_block_scope() {
    // Demonstrate block scope behavior
    {
        int block_var = 42;
        return block_var;
    }
}

int ScopesSolutions::demonstrate_nested_scopes() {
    // Demonstrate nested scope behavior
    int outer_var = 10;
    {
        int inner_var = 20;
        return outer_var + inner_var;
    }
}

int ScopesSolutions::demonstrate_variable_shadowing() {
    // Demonstrate variable shadowing
    int shadowed_var = 100;
    {
        int shadowed_var = 200;  // This shadows the outer variable
        return shadowed_var;  // Return inner value
    }
}

int ScopesSolutions::access_global_variable() {
    // Access global variable
    return global_var;
}

int ScopesSolutions::demonstrate_scope_resolution(int value) {
    // Demonstrate scope resolution operator
    return ::cpp_primer::global_var + value;
}

int ScopesSolutions::demonstrate_function_scope(int param) {
    // Demonstrate function scope behavior
    int local_var = 50;
    return param + local_var;
}

} // namespace cpp_primer