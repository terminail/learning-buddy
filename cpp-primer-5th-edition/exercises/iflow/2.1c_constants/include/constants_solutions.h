#ifndef CONSTANTS_SOLUTIONS_H
#define CONSTANTS_SOLUTIONS_H

#include <string>

namespace cpp_primer {

/**
 * @class ConstantsSolutions
 * @brief Complete solution implementations for C++ constants exercise
 * 
 * This class demonstrates proper constant declaration techniques in C++.
 */
class ConstantsSolutions {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    ConstantsSolutions();
    
    // ========== CONSTANT DECLARATION METHODS ==========
    
    /**
     * @brief Declare and return a const integer
     * @return A const integer value
     */
    const int declare_const_integer();
    
    /**
     * @brief Declare and return a constexpr integer
     * @return A constexpr integer value
     */
    constexpr int declare_constexpr_integer();
    
    /**
     * @brief Declare and return a const double
     * @return A const double value
     */
    const double declare_const_double();
    
    /**
     * @brief Calculate area of circle using const value for PI
     * @param radius The radius of the circle
     * @return Area of the circle
     */
    double calculate_circle_area(double radius);
    
    /**
     * @brief Use const reference parameter
     * @param value A const reference to an integer
     * @return The value passed in
     */
    int use_const_reference(const int& value);
    
    /**
     * @brief Declare a const member function
     * @return A constant value
     */
    int get_constant_value() const;
    
private:
    const int constant_member = 100;  // Example const member variable
};

} // namespace cpp_primer

#endif // CONSTANTS_SOLUTIONS_H