#ifndef VARIABLES_DECLARATIONS_SOLUTIONS_H
#define VARIABLES_DECLARATIONS_SOLUTIONS_H

#include <string>

namespace cpp_primer {

/**
 * @class VariablesDeclarationsSolutions
 * @brief Complete solution implementations for C++ variables and types exercise
 * 
 * This class demonstrates proper variable declaration techniques in C++.
 */
class VariablesDeclarationsSolutions {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    VariablesDeclarationsSolutions();
    
    // ========== VARIABLE DECLARATION METHODS ==========
    
    /**
     * @brief Declare and return an integer variable
     * @return An integer value
     */
    int declare_integer();
    
    /**
     * @brief Declare and return a double variable
     * @return A double value
     */
    double declare_double();
    
    /**
     * @brief Declare and return a character variable
     * @return A character value
     */
    char declare_character();
    
    /**
     * @brief Declare and return a boolean variable
     * @return A boolean value
     */
    bool declare_boolean();
    
    /**
     * @brief Use auto keyword to declare a variable
     * @param value The value to assign to the auto variable
     * @return The same value passed in
     */
    int use_auto_keyword(int value);
    
    /**
     * @brief Declare multiple variables of the same type
     * @return Sum of three integer variables
     */
    int declare_multiple_variables();
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // VARIABLES_DECLARATIONS_SOLUTIONS_H