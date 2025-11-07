#ifndef STRINGS_VECTORS_SOLUTIONS_H
#define STRINGS_VECTORS_SOLUTIONS_H

#include <string>
#include <vector>

namespace cpp_primer {

/**
 * @class StringsVectorsSolutions
 * @brief Complete solution implementations for C++ strings and vectors exercise
 * 
 * This class demonstrates proper string and vector operations in C++.
 */
class StringsVectorsSolutions {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    StringsVectorsSolutions();
    
    // ========== STRING METHODS ==========
    
    /**
     * @brief Create and return a string
     * @param content The content to initialize the string with
     * @return A string with the given content
     */
    std::string create_string(const std::string& content);
    
    /**
     * @brief Concatenate two strings
     * @param str1 First string
     * @param str2 Second string
     * @return Concatenated string
     */
    std::string concatenate_strings(const std::string& str1, const std::string& str2);
    
    /**
     * @brief Get string length
     * @param str Input string
     * @return Length of the string
     */
    size_t get_string_length(const std::string& str);
    
    // ========== VECTOR METHODS ==========
    
    /**
     * @brief Create and return a vector of integers
     * @param size Size of the vector
     * @param initial_value Initial value for all elements
     * @return A vector with the given size and initial value
     */
    std::vector<int> create_vector(int size, int initial_value);
    
    /**
     * @brief Add element to vector
     * @param vec Reference to the vector
     * @param value Value to add
     * @return Updated vector size
     */
    size_t add_to_vector(std::vector<int>& vec, int value);
    
    /**
     * @brief Get vector size
     * @param vec Input vector
     * @return Size of the vector
     */
    size_t get_vector_size(const std::vector<int>& vec);
    
    /**
     * @brief Sum all elements in a vector
     * @param vec Input vector
     * @return Sum of all elements
     */
    int sum_vector_elements(const std::vector<int>& vec);
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // STRINGS_VECTORS_SOLUTIONS_H