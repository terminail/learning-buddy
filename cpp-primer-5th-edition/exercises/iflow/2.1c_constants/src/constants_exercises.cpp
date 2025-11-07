#include "constants_exercises.h"
#include <cmath>

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

Constants::Constants() {
    // Default constructor implementation
}

// ========== CONSTANT DECLARATION METHODS ==========

const int Constants::declare_const_integer() {
    // TODO: Declare a const integer variable and return its value
    // Example: const int my_const = 42; return my_const;
    
    // Replace with your implementation
    return 0;  // Placeholder
}

constexpr int Constants::declare_constexpr_integer() {
    // TODO: Declare a constexpr integer variable and return its value
    // Example: constexpr int my_constexpr = 100; return my_constexpr;
    
    // Replace with your implementation
    return 0;  // Placeholder
}

const double Constants::declare_const_double() {
    // TODO: Declare a const double variable and return its value
    // Example: const double my_const = 3.14159; return my_const;
    
    // Replace with your implementation
    return 0.0;  // Placeholder
}

double Constants::calculate_circle_area(double radius) {
    // TODO: Calculate area of circle using const value for PI
    // Example: const double PI = 3.14159; return PI * radius * radius;
    
    // Replace with your implementation
    return 0.0;  // Placeholder
}

int Constants::use_const_reference(const int& value) {
    // TODO: Use the const reference parameter
    // Example: return value; (no modification allowed)
    
    // Replace with your implementation
    return 0;  // Placeholder
}

int Constants::get_constant_value() const {
    // TODO: Implement as a const member function
    // Example: return constant_member;
    
    // Replace with your implementation
    return 0;  // Placeholder
}

} // namespace cpp_primer