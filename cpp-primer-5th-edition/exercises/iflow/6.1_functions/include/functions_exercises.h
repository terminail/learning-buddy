#ifndef FUNCTIONS_EXERCISES_H
#define FUNCTIONS_EXERCISES_H

#include <string>
#include <vector>

namespace cpp_primer {

/**
 * @class Functions
 * @brief Student implementation for C++ functions exercise
 * 
 * This exercise focuses on function declarations, definitions, and usage in C++.
 * 
 * Learning Objectives:
 * - Understand function declaration and definition
 * - Learn about function parameters and return values
 * - Practice function overloading
 * - Understand pass by value vs pass by reference
 * - Learn about default parameters
 */
class Functions {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    Functions();
    
    // ========== BASIC FUNCTIONS ==========
    
    /**
     * @brief Calculate the square of a number
     * @param number The number to square
     * @return The square of the number
     */
    int square(int number);
    
    /**
     * @brief Calculate the area of a rectangle
     * @param length Length of the rectangle
     * @param width Width of the rectangle
     * @return The area of the rectangle
     */
    double rectangle_area(double length, double width);
    
    // ========== FUNCTION OVERLOADING ==========
    
    /**
     * @brief Add two integers
     * @param a First integer
     * @param b Second integer
     * @return Sum of the two integers
     */
    int add(int a, int b);
    
    /**
     * @brief Add two doubles
     * @param a First double
     * @param b Second double
     * @return Sum of the two doubles
     */
    double add(double a, double b);
    
    /**
     * @brief Concatenate two strings
     * @param str1 First string
     * @param str2 Second string
     * @return Concatenated string
     */
    std::string add(const std::string& str1, const std::string& str2);
    
    // ========== PASS BY REFERENCE ==========
    
    /**
     * @brief Swap two integers using pass by reference
     * @param a First integer (will be swapped)
     * @param b Second integer (will be swapped)
     */
    void swap(int& a, int& b);
    
    /**
     * @brief Find the maximum element in a vector and return it by reference
     * @param numbers Vector of integers
     * @return Reference to the maximum element
     */
    int& find_maximum(std::vector<int>& numbers);
    
    // ========== DEFAULT PARAMETERS ==========
    
    /**
     * @brief Calculate the power of a number with default exponent
     * @param base The base number
     * @param exponent The exponent (default is 2)
     * @return Base raised to the power of exponent
     */
    int power(int base, int exponent = 2);
    
    // ========== FUNCTION WITH ARRAY PARAMETER ==========
    
    /**
     * @brief Calculate the sum of array elements
     * @param arr Array of integers
     * @param size Size of the array
     * @return Sum of all elements
     */
    int sum_array(const int arr[], int size);
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // FUNCTIONS_EXERCISES_H