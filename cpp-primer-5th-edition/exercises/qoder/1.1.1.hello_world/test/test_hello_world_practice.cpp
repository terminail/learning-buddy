#include <gtest/gtest.h>
#include "exercise_name_exercises.h"

using namespace cpp_primer;

class ExerciseNamePracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: STRING TRANSFORMATION ==========

/**
 * Practice Problem 1: Implement a function that transforms a string by
 * alternating case (first character uppercase, next lowercase, etc.)
 * 
 * Add this function to the ExerciseName class:
 * std::string alternating_case(const std::string& str);
 */
TEST_F(ExerciseNamePracticeTest, Practice1_AlternatingCase) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_EQ(exercise.alternating_case("hello"), "HeLlO");
    // EXPECT_EQ(exercise.alternating_case("HELLO"), "HeLlO");
    // EXPECT_EQ(exercise.alternating_case("a"), "A");
    // EXPECT_EQ(exercise.alternating_case(""), "");
}

// ========== PRACTICE PROBLEM 2: WORD COUNT ==========

/**
 * Practice Problem 2: Implement a function that counts words in a string
 * Words are separated by spaces, tabs, or newlines
 * 
 * Add this function to the ExerciseName class:
 * int word_count(const std::string& str);
 */
TEST_F(ExerciseNamePracticeTest, Practice2_WordCount) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_EQ(exercise.word_count("hello world"), 2);
    // EXPECT_EQ(exercise.word_count("hello   world  test"), 3);
    // EXPECT_EQ(exercise.word_count(""), 0);
    // EXPECT_EQ(exercise.word_count("  "), 0);
}

// ========== PRACTICE PROBLEM 3: STRING ROTATION ==========

/**
 * Practice Problem 3: Implement a function that rotates a string by n positions
 * Positive n rotates right, negative n rotates left
 * 
 * Add this function to the ExerciseName class:
 * std::string rotate_string(const std::string& str, int n);
 */
TEST_F(ExerciseNamePracticeTest, Practice3_StringRotation) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_EQ(exercise.rotate_string("hello", 2), "lohel");
    // EXPECT_EQ(exercise.rotate_string("hello", -2), "llohe");
    // EXPECT_EQ(exercise.rotate_string("hello", 5), "hello");
    // EXPECT_EQ(exercise.rotate_string("a", 3), "a");
}

// ========== PRACTICE PROBLEM 4: VALID EMAIL CHECK ==========

/**
 * Practice Problem 4: Implement a function that validates email format
 * Basic validation: contains @, has domain part, no spaces
 * 
 * Add this function to the ExerciseName class:
 * bool is_valid_email(const std::string& email);
 */
TEST_F(ExerciseNamePracticeTest, Practice4_ValidEmail) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_TRUE(exercise.is_valid_email("test@example.com"));
    // EXPECT_FALSE(exercise.is_valid_email("test@"));
    // EXPECT_FALSE(exercise.is_valid_email("@example.com"));
    // EXPECT_FALSE(exercise.is_valid_email("test example@domain.com"));
}

// ========== PRACTICE PROBLEM 5: STRING INTERLEAVING ==========

/**
 * Practice Problem 5: Implement a function that interleaves two strings
 * Example: interleave("abc", "123") → "a1b2c3"
 * 
 * Add this function to the ExerciseName class:
 * std::string interleave_strings(const std::string& str1, const std::string& str2);
 */
TEST_F(ExerciseNamePracticeTest, Practice5_StringInterleaving) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_EQ(exercise.interleave_strings("abc", "123"), "a1b2c3");
    // EXPECT_EQ(exercise.interleave_strings("ab", "1234"), "a1b234");
    // EXPECT_EQ(exercise.interleave_strings("", "123"), "123");
    // EXPECT_EQ(exercise.interleave_strings("abc", ""), "abc");
}

// ========== PRACTICE PROBLEM 6: ROMAN NUMERAL CONVERSION ==========

/**
 * Practice Problem 6: Implement a function that converts integers to Roman numerals
 * Support numbers 1-1000
 * 
 * Add this function to the ExerciseName class:
 * std::string int_to_roman(int num);
 */
TEST_F(ExerciseNamePracticeTest, Practice6_RomanNumeral) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_EQ(exercise.int_to_roman(1), "I");
    // EXPECT_EQ(exercise.int_to_roman(4), "IV");
    // EXPECT_EQ(exercise.int_to_roman(9), "IX");
    // EXPECT_EQ(exercise.int_to_roman(49), "XLIX");
    // EXPECT_EQ(exercise.int_to_roman(99), "XCIX");
    // EXPECT_EQ(exercise.int_to_roman(444), "CDXLIV");
}

// ========== PRACTICE PROBLEM 7: STRING DIFFERENCE ==========

/**
 * Practice Problem 7: Implement a function that finds characters in str1 not in str2
 * 
 * Add this function to the ExerciseName class:
 * std::string string_difference(const std::string& str1, const std::string& str2);
 */
TEST_F(ExerciseNamePracticeTest, Practice7_StringDifference) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_EQ(exercise.string_difference("abc", "ac"), "b");
    // EXPECT_EQ(exercise.string_difference("hello", "world"), "he");
    // EXPECT_EQ(exercise.string_difference("", "abc"), "");
    // EXPECT_EQ(exercise.string_difference("abc", ""), "abc");
}

// ========== PRACTICE PROBLEM 8: STRING ENCODING ==========

/**
 * Practice Problem 8: Implement URL encoding for strings
 * Convert spaces to %20, special characters to %XX
 * 
 * Add this function to the ExerciseName class:
 * std::string url_encode(const std::string& str);
 */
TEST_F(ExerciseNamePracticeTest, Practice8_URLEncoding) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_EQ(exercise.url_encode("hello world"), "hello%20world");
    // EXPECT_EQ(exercise.url_encode("test&value"), "test%26value");
    // EXPECT_EQ(exercise.url_encode(""), "");
    // EXPECT_EQ(exercise.url_encode("normal"), "normal");
}

// ========== PRACTICE PROBLEM 9: ANAGRAM GROUPS ==========

/**
 * Practice Problem 9: Implement a function that groups anagrams from a vector of strings
 * 
 * Add this function to the ExerciseName class:
 * std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string>& words);
 */
TEST_F(ExerciseNamePracticeTest, Practice9_AnagramGroups) {
    ExerciseName exercise;
    
    // Test cases would require custom comparison for vector of vectors
    // This is an advanced practice problem
}

// ========== PRACTICE PROBLEM 10: PATTERN MATCHING ==========

/**
 * Practice Problem 10: Implement wildcard pattern matching
 * Support ? (single char) and * (multiple chars)
 * 
 * Add this function to the ExerciseName class:
 * bool wildcard_match(const std::string& pattern, const std::string& str);
 */
TEST_F(ExerciseNamePracticeTest, Practice10_WildcardMatching) {
    ExerciseName exercise;
    
    // Test cases to implement:
    // EXPECT_TRUE(exercise.wildcard_match("h*lo", "hello"));
    // EXPECT_TRUE(exercise.wildcard_match("h?llo", "hello"));
    // EXPECT_FALSE(exercise.wildcard_match("h?llo", "heello"));
    // EXPECT_TRUE(exercise.wildcard_match("*", "anything"));
}

// ========== ADVANCED PRACTICE: TEMPLATE FUNCTION ==========

/**
 * Advanced Practice: Implement a template function for string operations
 * This demonstrates C++ template usage
 * 
 * Example template function to add to the ExerciseName class:
 * template<typename T>
 * std::vector<T> filter_elements(const std::vector<T>& elements, 
 *                               std::function<bool(const T&)> predicate);
 */
TEST_F(ExerciseNamePracticeTest, AdvancedPractice_TemplateFunction) {
    // This would require modifying the class to support templates
    // Advanced C++ concept for extension
}

// ========== PERFORMANCE PRACTICE: LARGE DATA HANDLING ==========

/**
 * Performance Practice: Test functions with large input data
 * Focus on efficiency and memory usage
 */
TEST_F(ExerciseNamePracticeTest, PerformancePractice_LargeData) {
    ExerciseName exercise;
    
    // Create large test data
    std::string large_string(10000, 'a');
    
    // Test performance of various operations
    // This helps identify bottlenecks and optimize algorithms
    std::string result = exercise.reverse_string(large_string);
    EXPECT_EQ(result.length(), 10000);
}

// ========== ERROR HANDLING PRACTICE ==========

/**
 * Error Handling Practice: Test robust error handling
 * Implement proper exception handling and validation
 */
TEST_F(ExerciseNamePracticeTest, ErrorHandlingPractice) {
    ExerciseName exercise;
    
    // Test various error conditions:
    // - Invalid input parameters
    // - Edge cases
    // - Resource constraints
    // - Memory allocation issues
    
    // Test with empty strings
    EXPECT_EQ(exercise.reverse_string(""), "");
    
    // Test with valid input
    EXPECT_EQ(exercise.reverse_string("a"), "a");
}

// ========== INTEGRATION PRACTICE: COMBINING MULTIPLE FUNCTIONS ==========

/**
 * Integration Practice: Combine multiple functions to solve complex problems
 */
TEST_F(ExerciseNamePracticeTest, IntegrationPractice_ComplexProblem) {
    ExerciseName exercise;
    
    // Example: Process a text document through multiple string operations
    // 1. Clean the text (remove extra spaces)
    // 2. Count words
    // 3. Find most frequent words
    // 4. Generate summary statistics
    
    // This tests the integration of multiple functions
    std::string text = "hello world hello";
    std::string cleaned = exercise.remove_duplicates(text);
    int count = exercise.count_character(cleaned, 'l');
    std::string reversed = exercise.reverse_string(cleaned);
    
    EXPECT_GT(count, 0);
    EXPECT_FALSE(reversed.empty());
}

// ========== ALGORITHM OPTIMIZATION PRACTICE ==========

/**
 * Algorithm Optimization Practice: Compare different implementations
 */
TEST_F(ExerciseNamePracticeTest, AlgorithmOptimizationPractice) {
    // Compare performance of different algorithm implementations
    // Test time complexity and space complexity
    // Optimize based on profiling results
    
    ExerciseName exercise;
    
    // Test with medium-sized input
    std::string medium_string(1000, 'a');
    std::string result = exercise.compress_string(medium_string);
    EXPECT_FALSE(result.empty());
}

// ========== CUSTOM EXTENSION PRACTICE ==========

/**
 * Custom Extension Practice: Extend the class with custom functionality
 */
TEST_F(ExerciseNamePracticeTest, CustomExtensionPractice) {
    // Students can add their own functions and test them
    // Encourages creativity and problem-solving skills
    
    ExerciseName exercise;
    // This test will initially fail until students implement custom functions
    // Suggest students add functions like:
    // - find_substring_all_occurrences
    // - replace_substring_ignore_case
    // - extract_words_by_length
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}