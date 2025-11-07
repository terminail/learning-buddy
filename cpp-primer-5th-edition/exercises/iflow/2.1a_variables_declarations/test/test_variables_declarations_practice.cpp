#include <gtest/gtest.h>
#include "variables_declarations_exercises.h"
#include <typeinfo>

using namespace cpp_primer;

class VariablesDeclarationsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: DIFFERENT DATA TYPES ==========

/**
 * Practice Problem 1: Declare variables of different data types
 * 
 * In the exercise file, modify the functions to declare variables of different types
 * such as short, long, float, etc.
 */
TEST_F(VariablesDeclarationsPracticeTest, Practice1_DifferentDataTypes) {
    SUCCEED() << "Practice: Try declaring variables of different data types like short, long, float";
}

// ========== PRACTICE PROBLEM 2: VARIABLE NAMES ==========

/**
 * Practice Problem 2: Use descriptive variable names
 * 
 * In the exercise file, modify the functions to use more descriptive variable names
 * that follow C++ naming conventions
 */
TEST_F(VariablesDeclarationsPracticeTest, Practice2_DescriptiveNames) {
    SUCCEED() << "Practice: Use descriptive variable names that follow C++ naming conventions";
}

// ========== PRACTICE PROBLEM 3: TYPE INFERENCE WITH AUTO ==========

/**
 * Practice Problem 3: Experiment with auto keyword
 * 
 * Try using auto with different initializations to see how the type is inferred
 */
TEST_F(VariablesDeclarationsPracticeTest, Practice3_AutoInference) {
    SUCCEED() << "Practice: Try using auto with different types like auto x = 42, y = 3.14, z = 'c'";
}

// ========== PRACTICE PROBLEM 4: UNSIGNED VARIABLES ==========

/**
 * Practice Problem 4: Declare unsigned variables
 * 
 * Practice declaring variables with unsigned type
 */
TEST_F(VariablesDeclarationsPracticeTest, Practice4_UnsignedVariables) {
    SUCCEED() << "Practice: Declare and use unsigned variables like unsigned int, unsigned char";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(VariablesDeclarationsPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own variable declaration exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Verify type sizes
 * 
 * Use sizeof operator to verify the sizes of different variable types
 */
TEST_F(VariablesDeclarationsPracticeTest, BonusChallenge_TypeSizes) {
    SUCCEED() << "Bonus: Use sizeof operator to check sizes - sizeof(int), sizeof(double), etc.";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}