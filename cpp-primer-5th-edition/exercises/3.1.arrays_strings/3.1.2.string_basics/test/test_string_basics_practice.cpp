#include <gtest/gtest.h>
#include <iostream>
#include <string>

// Practice problems for string basics

class StringBasicsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: STRING SEARCHING AND REPLACEMENT ==========

/**
 * Practice Problem 1: Use string searching and replacement methods
 * 
 * Practice using find, replace, and substr methods.
 */
TEST_F(StringBasicsPracticeTest, Practice1_StringSearchingReplacement) {
    // TODO: Practice string searching and replacement:
    // - Use find() to locate substrings
    // - Use replace() to substitute parts of strings
    // - Use substr() to extract parts of strings
    // Example approach: Try each method on sample strings
    
    SUCCEED() << "Implement string searching and replacement practice problem";
}

// ========== PRACTICE PROBLEM 2: STRING COMPARISON OPERATIONS ==========

/**
 * Practice Problem 2: Use string comparison operations
 * 
 * Practice comparing strings using various methods.
 */
TEST_F(StringBasicsPracticeTest, Practice2_StringComparison) {
    // TODO: Practice string comparison operations:
    // - Use comparison operators (==, !=, <, >, <=, >=)
    // - Use compare() method for detailed comparisons
    // - Understand lexicographical ordering
    // Example approach: Try comparing different strings
    
    SUCCEED() << "Implement string comparison operations practice problem";
}

// ========== PRACTICE PROBLEM 3: STRING CONVERSION OPERATIONS ==========

/**
 * Practice Problem 3: Convert between strings and numbers
 * 
 * Practice converting strings to numbers and vice versa.
 */
TEST_F(StringBasicsPracticeTest, Practice3_StringConversion) {
    // TODO: Practice string conversion operations:
    // - Use std::to_string() to convert numbers to strings
    // - Use std::stoi(), std::stof(), etc. to convert strings to numbers
    // - Handle conversion errors with try-catch blocks
    // Example approach: Try converting between strings and numbers
    
    SUCCEED() << "Implement string conversion operations practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}