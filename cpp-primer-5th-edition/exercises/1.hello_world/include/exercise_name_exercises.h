#ifndef EXERCISE_NAME_EXERCISES_H
#define EXERCISE_NAME_EXERCISES_H

#include <string>
#include <vector>
#include <memory>

namespace cpp_primer {

/**
 * @class ExerciseName
 * @brief Student implementation template for C++ Primer exercises
 * 
 * This class provides a structured approach to learning C++ concepts
 * through hands-on implementation. Students should complete the TODO
 * comments following the exercise guide.
 * 
 * Learning Approach:
 * 1. Read function declarations and understand requirements
 * 2. Implement functions in src/exercise_name_exercises.cpp
 * 3. Run tests to validate implementations
 * 4. Compare with solutions in exercise_name_solutions.h
 * 
 * Customization Instructions:
 * 1. Update class name: ExerciseName → YourExerciseName
 * 2. Update function declarations for your specific exercise
 * 3. Add/remove member variables as needed
 * 4. Update namespace if desired
 */
class ExerciseName {
public:
    // ========== CONSTRUCTORS AND DESTRUCTORS ==========
    
    /**
     * @brief Default constructor
     * Initializes with default value
     * TODO: Implement default constructor
     */
    ExerciseName();
    
    /**
     * @brief Parameterized constructor
     * @param initial_value Initial value for the exercise
     * TODO: Implement with input validation
     */
    explicit ExerciseName(const std::string& initial_value);
    
    /**
     * @brief Copy constructor
     * @param other Object to copy from
     * TODO: Implement deep copy if needed
     */
    ExerciseName(const ExerciseName& other);
    
    /**
     * @brief Destructor
     * TODO: Implement cleanup if needed
     */
    ~ExerciseName();
    
    // ========== BASIC OPERATIONS ==========
    
    /**
     * @brief Basic operation example
     * @param input Input parameter
     * @return Processed result
     * TODO: Implement basic string processing
     */
    std::string basic_operation(const std::string& input);
    
    /**
     * @brief Combine two strings
     * @param param1 First string
     * @param param2 Second string
     * @return Combined result
     * TODO: Implement string combination
     */
    std::string combine_strings(const std::string& param1, const std::string& param2);
    
    // ========== INTERMEDIATE OPERATIONS ==========
    
    /**
     * @brief Count character occurrences
     * @param str String to search
     * @param ch Character to count
     * @return Number of occurrences (case-insensitive)
     * TODO: Implement character counting
     */
    int count_character(const std::string& str, char ch);
    
    /**
     * @brief Reverse a string
     * @param str String to reverse
     * @return Reversed string
     * TODO: Implement string reversal
     */
    std::string reverse_string(const std::string& str);
    
    /**
     * @brief Remove duplicate characters
     * @param str String to process
     * @return String with duplicates removed
     * TODO: Implement duplicate removal
     */
    std::string remove_duplicates(const std::string& str);
    
    // ========== ADVANCED OPERATIONS ==========
    
    /**
     * @brief Find longest common substring
     * @param str1 First string
     * @param str2 Second string
     * @return Longest common substring
     * TODO: Implement using dynamic programming
     */
    std::string longest_common_substring(const std::string& str1, const std::string& str2);
    
    /**
     * @brief Check if strings are anagrams
     * @param str1 First string
     * @param str2 Second string
     * @return true if anagrams, false otherwise
     * TODO: Implement anagram check
     */
    bool are_anagrams(const std::string& str1, const std::string& str2);
    
    /**
     * @brief Compress string using run-length encoding
     * @param str String to compress
     * @return Compressed string or original if not shorter
     * TODO: Implement run-length encoding
     */
    std::string compress_string(const std::string& str);
    
    // ========== GETTERS AND SETTERS ==========
    
    /**
     * @brief Get current value
     * @return Current string value
     */
    std::string get_value() const;
    
    /**
     * @brief Set current value
     * @param value New value to set
     * TODO: Implement with validation
     */
    void set_value(const std::string& value);
    
    /**
     * @brief Get data size/length
     * @return Length of current value
     */
    size_t get_length() const;
    
private:
    std::string value_;  // Internal storage for exercise data
    
    // Add any additional private members as needed
};

} // namespace cpp_primer

#endif // EXERCISE_NAME_EXERCISES_H