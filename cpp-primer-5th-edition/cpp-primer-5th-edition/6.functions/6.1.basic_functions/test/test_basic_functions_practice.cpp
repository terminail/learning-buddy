#include <gtest/gtest.h>
#include <iostream>

// Practice problems for basic functions

class BasicFunctionsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: MULTIPLE FUNCTIONS ==========

/**
 * Practice Problem 1: Create multiple functions with different purposes
 * 
 * Practice organizing code into multiple functions.
 */
TEST_F(BasicFunctionsPracticeTest, Practice1_MultipleFunctions) {
    // TODO: Practice creating multiple functions:
    // - Create functions for input, processing, and output
    // - Separate concerns into different functions
    // Example approach: Write a program that uses separate functions for each step
    
    SUCCEED() << "Implement multiple functions practice problem";
}

// ========== PRACTICE PROBLEM 2: FUNCTION DOCUMENTATION ==========

/**
 * Practice Problem 2: Document functions with comments
 * 
 * Practice writing clear function documentation.
 */
TEST_F(BasicFunctionsPracticeTest, Practice2_FunctionDocumentation) {
    // TODO: Practice documenting functions:
    // - Write clear function comments
    // - Document parameters and return values
    // - Explain function purpose and behavior
    // Example approach: Add detailed comments to your functions
    
    SUCCEED() << "Implement function documentation practice problem";
}

// ========== PRACTICE PROBLEM 3: ERROR HANDLING ==========

/**
 * Practice Problem 3: Handle errors in functions
 * 
 * Practice implementing basic error handling in functions.
 */
TEST_F(BasicFunctionsPracticeTest, Practice3_ErrorHandling) {
    // TODO: Practice error handling in functions:
    // - Check for invalid input parameters
    // - Return appropriate error codes or values
    // - Handle edge cases gracefully
    // Example approach: Write functions that validate input and handle errors
    
    SUCCEED() << "Implement error handling practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}