#ifndef CONSTANTS_EXERCISES_H
#define CONSTANTS_EXERCISES_H

#include <string>

namespace cpp_primer {

/**
 * @class Constants
 * @brief Student implementation for C++ constants exercise
 * 
 * This exercise focuses on constant variables and constant expressions in C++.
 * 
 * Learning Objectives:
 * - Understand const keyword and its usage
 * - Learn about constexpr for constant expressions
 * - Practice declaring constants with different data types
 * - Understand constant references and pointers
 */
class Constants {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    Constants();
    
    // ========== CONSTANT DECLARATION METHODS ==========
    
    /**
     * @brief Declare and return a const integer
     * TODO: Implement to return a const integer value
     * @return A const integer value
     */
    const int declare_const_integer();
    
    /**
     * @brief Declare and return a constexpr integer
     * TODO: Implement to return a constexpr integer value
     * @return A constexpr integer value
     */
    constexpr int declare_constexpr_integer();
    
    /**
     * @brief Declare and return a const double
     * TODO: Implement to return a const double value
     * @return A const double value
     */
    const double declare_const_double();
    
    /**
     * @brief Calculate area of circle using const value for PI
     * TODO: Implement using a const variable for PI
     * @param radius The radius of the circle
     * @return Area of the circle
     */
    double calculate_circle_area(double radius);
    
    /**
     * @brief Use const reference parameter
     * TODO: Implement to accept and return a const reference
     * @param value A const reference to an integer
     * @return The value passed in
     */
    int use_const_reference(const int& value);
    
    /**
     * @brief Declare a const member function
     * TODO: Implement as a const member function
     * @return A constant value
     */
    int get_constant_value() const;
    
private:
    const int constant_member = 100;  // Example const member variable
};

} // namespace cpp_primer

#endif // CONSTANTS_EXERCISES_H