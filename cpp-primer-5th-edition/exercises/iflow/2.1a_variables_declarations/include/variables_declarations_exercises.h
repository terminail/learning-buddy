#ifndef VARIABLES_DECLARATIONS_EXERCISES_H
#define VARIABLES_DECLARATIONS_EXERCISES_H

#include <string>

namespace cpp_primer {

/**
 * @class VariablesDeclarations
 * @brief Student implementation for C++ variables and types exercise
 * 
 * This exercise focuses on variable declarations and basic data types in C++.
 * 
 * Learning Objectives:
 * - Understand fundamental C++ data types (int, double, char, bool, etc.)
 * - Learn how to declare variables with appropriate types
 * - Understand the concept of type inference with auto keyword
 * - Practice declaring variables with descriptive names
 */
class VariablesDeclarations {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    VariablesDeclarations();
    
    // ========== VARIABLE DECLARATION METHODS ==========
    
    /**
     * @brief Declare and return an integer variable
     * TODO: Implement to return an integer value
     * @return An integer value
     */
    int declare_integer();
    
    /**
     * @brief Declare and return a double variable
     * TODO: Implement to return a double value
     * @return A double value
     */
    double declare_double();
    
    /**
     * @brief Declare and return a character variable
     * TODO: Implement to return a character value
     * @return A character value
     */
    char declare_character();
    
    /**
     * @brief Declare and return a boolean variable
     * TODO: Implement to return a boolean value
     * @return A boolean value
     */
    bool declare_boolean();
    
    /**
     * @brief Use auto keyword to declare a variable
     * TODO: Implement to return a value using auto keyword
     * @param value The value to assign to the auto variable
     * @return The same value passed in
     */
    int use_auto_keyword(int value);
    
    /**
     * @brief Declare multiple variables of the same type
     * TODO: Implement to return the sum of three integer variables
     * @return Sum of three integer variables
     */
    int declare_multiple_variables();
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // VARIABLES_DECLARATIONS_EXERCISES_H