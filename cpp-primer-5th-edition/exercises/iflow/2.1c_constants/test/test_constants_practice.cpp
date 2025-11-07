#include <gtest/gtest.h>
#include "constants_exercises.h"

using namespace cpp_primer;

class ConstantsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: DIFFERENT CONSTANT TYPES ==========

/**
 * Practice Problem 1: Declare constants of different types
 * 
 * In the exercise file, modify the functions to declare constants of different types
 * such as const char, const bool, const string, etc.
 */
TEST_F(ConstantsPracticeTest, Practice1_DifferentConstantTypes) {
    SUCCEED() << "Practice: Try declaring constants of different types like const char, const bool";
}

// ========== PRACTICE PROBLEM 2: CONST POINTER AND REFERENCE ==========

/**
 * Practice Problem 2: Use const pointers and references
 * 
 * Practice declaring const pointers and pointers to const values
 */
TEST_F(ConstantsPracticeTest, Practice2_ConstPointers) {
    SUCCEED() << "Practice: Try declaring const pointers and pointers to const values";
}

// ========== PRACTICE PROBLEM 3: CONSTEXPR WITH COMPLEX EXPRESSIONS ==========

/**
 * Practice Problem 3: Use constexpr with complex expressions
 * 
 * Try using constexpr with arithmetic expressions that can be evaluated at compile time
 */
TEST_F(ConstantsPracticeTest, Practice3_ConstexprExpressions) {
    SUCCEED() << "Practice: Try using constexpr with complex compile-time expressions";
}

// ========== PRACTICE PROBLEM 4: CONST MEMBER FUNCTIONS ==========

/**
 * Practice Problem 4: Create more const member functions
 * 
 * Add more const member functions to the class that access but don't modify members
 */
TEST_F(ConstantsPracticeTest, Practice4_MoreConstFunctions) {
    SUCCEED() << "Practice: Add more const member functions to the class";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(ConstantsPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own constant declaration exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Verify constant behavior
 * 
 * Test that const values cannot be modified
 */
TEST_F(ConstantsPracticeTest, BonusChallenge_ConstantBehavior) {
    SUCCEED() << "Bonus: Verify that const values cannot be modified (this should cause compile errors)";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}