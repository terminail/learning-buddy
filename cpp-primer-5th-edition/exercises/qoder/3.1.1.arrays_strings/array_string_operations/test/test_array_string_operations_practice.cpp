#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

// Practice problems for array and string operations

class ArrayStringOperationsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: DYNAMIC STRING ARRAYS ==========

/**
 * Practice Problem 1: Use dynamic arrays with strings
 * 
 * Practice using std::vector<std::string> for dynamic string collections.
 */
TEST_F(ArrayStringOperationsPracticeTest, Practice1_DynamicStringArrays) {
    // TODO: Practice using dynamic string arrays:
    // - Use std::vector<std::string> instead of fixed-size arrays
    // - Add and remove strings dynamically
    // - Resize the vector as needed
    // Example approach: Try using vector operations with strings
    
    SUCCEED() << "Implement dynamic string arrays practice problem";
}

// ========== PRACTICE PROBLEM 2: STRING SORTING AND SEARCHING ==========

/**
 * Practice Problem 2: Sort and search string arrays
 * 
 * Practice sorting string arrays and searching for strings.
 */
TEST_F(ArrayStringOperationsPracticeTest, Practice2_StringSortingSearching) {
    // TODO: Practice string array sorting and searching:
    // - Use std::sort() to sort string arrays
    // - Use std::binary_search() for efficient searching
    // - Implement custom sorting criteria
    // Example approach: Try sorting and searching string arrays
    
    SUCCEED() << "Implement string sorting and searching practice problem";
}

// ========== PRACTICE PROBLEM 3: STRING PARSING OPERATIONS ==========

/**
 * Practice Problem 3: Parse and manipulate strings
 * 
 * Practice parsing strings to extract information.
 */
TEST_F(ArrayStringOperationsPracticeTest, Practice3_StringParsing) {
    // TODO: Practice string parsing operations:
    // - Parse comma-separated values into string arrays
    // - Extract substrings based on delimiters
    // - Convert parsed strings to other data types
    // Example approach: Try parsing sample input strings
    
    SUCCEED() << "Implement string parsing operations practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}