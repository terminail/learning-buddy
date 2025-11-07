#ifndef SCOPES_EXERCISES_H
#define SCOPES_EXERCISES_H

#include <string>

namespace cpp_primer {

/**
 * @class Scopes
 * @brief Student implementation for C++ scopes exercise
 * 
 * This exercise focuses on variable scopes and lifetimes in C++.
 * 
 * Learning Objectives:
 * - Understand block scope and local variables
 * - Learn about global and file scope
 * - Practice with nested scopes
 * - Understand variable shadowing
 * - Learn about scope resolution operator
 */
class Scopes {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    Scopes();
    
    // ========== SCOPE METHODS ==========
    
    /**
     * @brief Demonstrate block scope
     * TODO: Implement to show block scope behavior
     * @return Value from block scope
     */
    int demonstrate_block_scope();
    
    /**
     * @brief Demonstrate nested scopes
     * TODO: Implement to show nested scope behavior
     * @return Value from inner scope
     */
    int demonstrate_nested_scopes();
    
    /**
     * @brief Demonstrate variable shadowing
     * TODO: Implement to show variable shadowing
     * @return Value from shadowed variable
     */
    int demonstrate_variable_shadowing();
    
    /**
     * @brief Access global variable
     * TODO: Implement to access global variable
     * @return Global variable value
     */
    int access_global_variable();
    
    /**
     * @brief Demonstrate scope resolution
     * TODO: Implement to show scope resolution operator
     * @param value Value to process
     * @return Processed value
     */
    int demonstrate_scope_resolution(int value);
    
    /**
     * @brief Demonstrate function scope
     * TODO: Implement to show function scope behavior
     * @param param Function parameter
     * @return Parameter value
     */
    int demonstrate_function_scope(int param);
    
private:
    int class_member = 200;  // Example class member variable
};

// Global variable for demonstration
extern int global_variable;

} // namespace cpp_primer

#endif // SCOPES_EXERCISES_H