#include "constants_solutions.h"
#include <cmath>

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

ConstantsSolutions::ConstantsSolutions() {
    // Default constructor implementation
}

// ========== CONSTANT DECLARATION METHODS ==========

const int ConstantsSolutions::declare_const_integer() {
    // Declare a const integer variable and return its value
    const int my_const = 42;
    return my_const;
}

constexpr int ConstantsSolutions::declare_constexpr_integer() {
    // Declare a constexpr integer variable and return its value
    constexpr int my_constexpr = 100;
    return my_constexpr;
}

const double ConstantsSolutions::declare_const_double() {
    // Declare a const double variable and return its value
    const double my_const = 3.14159;
    return my_const;
}

double ConstantsSolutions::calculate_circle_area(double radius) {
    // Calculate area of circle using const value for PI
    const double PI = 3.14159265358979323846;
    return PI * radius * radius;
}

int ConstantsSolutions::use_const_reference(const int& value) {
    // Use the const reference parameter
    return value; // No modification allowed
}

int ConstantsSolutions::get_constant_value() const {
    // Implement as a const member function
    return constant_member;
}

} // namespace cpp_primer