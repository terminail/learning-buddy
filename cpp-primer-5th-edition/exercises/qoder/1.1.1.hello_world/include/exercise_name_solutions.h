#ifndef EXERCISE_NAME_SOLUTIONS_H
#define EXERCISE_NAME_SOLUTIONS_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iterator>

namespace cpp_primer {

/**
 * @class ExerciseNameSolutions
 * @brief Complete solution implementations for C++ Primer exercises
 * 
 * This class provides reference implementations for all exercise functions.
 * Students should compare their solutions with these implementations.
 * 
 * Learning Approach:
 * 1. Compare with your implementation after attempting the exercise
 * 2. Identify differences and understand the solution approach
 * 3. Learn best practices and efficient algorithms from implementations
 * 4. Use as reference for similar problems in the future
 * 
 * Customization Instructions:
 * 1. Update class name: ExerciseNameSolutions → YourExerciseNameSolutions
 * 2. Update function implementations for your specific exercise
 * 3. Add/remove member variables as needed
 * 4. Update namespace if desired
 */
class ExerciseNameSolutions {
public:
    // ========== CONSTRUCTORS AND DESTRUCTORS ==========
    
    /**
     * @brief Default constructor
     * Initializes with default value
     */
    ExerciseNameSolutions();
    
    /**
     * @brief Parameterized constructor
     * @param initial_value Initial value for the exercise
     */
    explicit ExerciseNameSolutions(const std::string& initial_value);
    
    /**
     * @brief Copy constructor
     * @param other Object to copy from
     */
    ExerciseNameSolutions(const ExerciseNameSolutions& other);
    
    /**
     * @brief Destructor
     */
    ~ExerciseNameSolutions() = default;
    
    // ========== BASIC OPERATIONS ==========
    
    /**
     * @brief Basic operation example - returns processed input
     * @param input Input parameter
     * @return Processed result
     */
    std::string basic_operation(const std::string& input);
    
    /**
     * @brief Combine two strings with a separator
     * @param str1 First string
     * @param str2 Second string
     * @return Combined string
     */
    std::string combine_strings(const std::string& str1, const std::string& str2);
    
    // ========== INTERMEDIATE OPERATIONS ==========
    
    /**
     * @brief Count character occurrences (case-insensitive)
     * @param str String to search
     * @param ch Character to count
     * @return Number of occurrences
     */
    int count_character(const std::string& str, char ch);
    
    /**
     * @brief Reverse a string
     * @param str String to reverse
     * @return Reversed string
     */
    std::string reverse_string(const std::string& str);
    
    /**
     * @brief Remove duplicate characters preserving order
     * @param str String to process
     * @return String with duplicates removed
     */
    std::string remove_duplicates(const std::string& str);
    
    // ========== ADVANCED OPERATIONS ==========
    
    /**
     * @brief Find longest common substring using dynamic programming
     * @param str1 First string
     * @param str2 Second string
     * @return Longest common substring
     */
    std::string longest_common_substring(const std::string& str1, const std::string& str2);
    
    /**
     * @brief Check if strings are anagrams (case-insensitive)
     * @param str1 First string
     * @param str2 Second string
     * @return true if anagrams, false otherwise
     */
    bool are_anagrams(const std::string& str1, const std::string& str2);
    
    /**
     * @brief Compress string using run-length encoding
     * @param str String to compress
     * @return Compressed string or original if not shorter
     */
    std::string compress_string(const std::string& str);
    
    // ========== GETTERS AND SETTERS ==========
    
    /**
     * @brief Get current value
     * @return Current string value
     */
    std::string get_value() const;
    
    /**
     * @brief Set current value with validation
     * @param value New value to set
     */
    void set_value(const std::string& value);
    
    /**
     * @brief Get string length
     * @return Length of current value
     */
    size_t get_length() const;
    
private:
    std::string value_;  // Internal storage for solution data
};

} // namespace cpp_primer

#endif // EXERCISE_NAME_SOLUTIONS_H