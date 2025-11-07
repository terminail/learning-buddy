#ifndef SCOPES_SOLUTIONS_H
#define SCOPES_SOLUTIONS_H

#include <string>

namespace cpp_primer {

/**
 * @class ScopesSolutions
 * @brief Complete solution implementations for C++ scopes exercise
 * 
 * This class demonstrates proper scope handling techniques in C++.
 */
class ScopesSolutions {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    ScopesSolutions();
    
    // ========== SCOPE METHODS ==========
    
    /**
     * @brief Demonstrate block scope
     * @return Value from block scope
     */
    int demonstrate_block_scope();
    
    /**
     * @brief Demonstrate nested scopes
     * @return Value from inner scope
     */
    int demonstrate_nested_scopes();
    
    /**
     * @brief Demonstrate variable shadowing
     * @return Value from shadowed variable
     */
    int demonstrate_variable_shadowing();
    
    /**
     * @brief Access global variable
     * @return Global variable value
     */
    int access_global_variable();
    
    /**
     * @brief Demonstrate scope resolution
     * @param value Value to process
     * @return Processed value
     */
    int demonstrate_scope_resolution(int value);
    
    /**
     * @brief Demonstrate function scope
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

#endif // SCOPES_SOLUTIONS_H