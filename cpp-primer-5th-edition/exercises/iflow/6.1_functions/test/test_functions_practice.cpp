#include <gtest/gtest.h>
#include "functions_exercises.h"
#include <vector>

using namespace cpp_primer;

class FunctionsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: RECURSIVE FUNCTIONS ==========

/**
 * Practice Problem 1: Implement recursive functions
 * 
 * Practice implementing recursive functions like factorial or fibonacci
 */
TEST_F(FunctionsPracticeTest, Practice1_RecursiveFunctions) {
    SUCCEED() << "Practice: Try implementing a recursive factorial function";
}

// ========== PRACTICE PROBLEM 2: FUNCTION TEMPLATES ==========

/**
 * Practice Problem 2: Use function templates
 * 
 * Practice implementing generic functions using templates
 */
TEST_F(FunctionsPracticeTest, Practice2_FunctionTemplates) {
    SUCCEED() << "Practice: Try creating a template function for finding maximum of two values";
}

// ========== PRACTICE PROBLEM 3: FUNCTION POINTERS ==========

/**
 * Practice Problem 3: Work with function pointers
 * 
 * Practice using function pointers to pass functions as parameters
 */
TEST_F(FunctionsPracticeTest, Practice3_FunctionPointers) {
    SUCCEED() << "Practice: Try implementing a function that takes another function as parameter";
}

// ========== PRACTICE PROBLEM 4: CONSTANT REFERENCES ==========

/**
 * Practice Problem 4: Use constant references
 * 
 * Practice using const references in function parameters to avoid copying
 */
TEST_F(FunctionsPracticeTest, Practice4_ConstReferences) {
    SUCCEED() << "Practice: Try implementing functions that use const references for efficiency";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(FunctionsPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own function exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Implement more complex functions
 * 
 * Try implementing complex functions like sorting algorithms or mathematical operations
 */
TEST_F(FunctionsPracticeTest, BonusChallenge_ComplexFunctions) {
    SUCCEED() << "Bonus: Implement a function to check if a number is prime";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}