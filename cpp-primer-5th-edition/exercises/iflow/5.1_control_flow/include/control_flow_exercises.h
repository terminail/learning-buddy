#ifndef CONTROL_FLOW_EXERCISES_H
#define CONTROL_FLOW_EXERCISES_H

#include <string>
#include <vector>

namespace cpp_primer {

/**
 * @class ControlFlow
 * @brief Student implementation for C++ control flow exercise
 * 
 * This exercise focuses on control flow statements in C++.
 * 
 * Learning Objectives:
 * - Understand if/else statements
 * - Learn for loops and range-based for loops
 * - Practice while and do-while loops
 * - Understand switch statements
 * - Practice break and continue statements
 */
class ControlFlow {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    ControlFlow();
    
    // ========== CONDITIONAL STATEMENTS ==========
    
    /**
     * @brief Check if a number is positive, negative, or zero
     * @param number The number to check
     * @return A string describing the number ("positive", "negative", or "zero")
     */
    std::string check_number_sign(int number);
    
    /**
     * @brief Find the maximum of three numbers using if statements
     * @param a First number
     * @param b Second number
     * @param c Third number
     * @return The maximum of the three numbers
     */
    int find_maximum(int a, int b, int c);
    
    // ========== LOOP STATEMENTS ==========
    
    /**
     * @brief Calculate the sum of numbers from 1 to n using a for loop
     * @param n The upper limit
     * @return The sum of numbers from 1 to n
     */
    int sum_with_for_loop(int n);
    
    /**
     * @brief Calculate the sum of numbers from 1 to n using a while loop
     * @param n The upper limit
     * @return The sum of numbers from 1 to n
     */
    int sum_with_while_loop(int n);
    
    /**
     * @brief Sum all even numbers in a vector
     * @param numbers Vector of integers
     * @return Sum of all even numbers
     */
    int sum_even_numbers(const std::vector<int>& numbers);
    
    // ========== SWITCH STATEMENTS ==========
    
    /**
     * @brief Convert a numeric grade to a letter grade
     * @param grade Numeric grade (0-100)
     * @return Letter grade (A, B, C, D, F)
     */
    char convert_to_letter_grade(int grade);
    
    // ========== BREAK AND CONTINUE ==========
    
    /**
     * @brief Find the first even number in a vector, or -1 if none exists
     * @param numbers Vector of integers
     * @return First even number or -1
     */
    int find_first_even(const std::vector<int>& numbers);
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // CONTROL_FLOW_EXERCISES_H