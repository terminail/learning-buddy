#include <gtest/gtest.h>
#include <iostream>

// Practice problems for if statements

class IfStatementsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: COMPLEX CONDITIONS ==========

/**
 * Practice Problem 1: Use logical operators in conditions
 * 
 * Practice combining multiple conditions with && and || operators.
 */
TEST_F(IfStatementsPracticeTest, Practice1_ComplexConditions) {
    // TODO: Practice using logical operators:
    // - Use && to check multiple conditions must all be true
    // - Use || to check if at least one condition is true
    // - Combine && and || in complex expressions
    // Example approach: Write a program that checks if a year is a leap year
    
    SUCCEED() << "Implement complex conditions practice problem";
}

// ========== PRACTICE PROBLEM 2: NESTED IF STATEMENTS ==========

/**
 * Practice Problem 2: Work with nested if statements
 * 
 * Practice creating nested conditional structures for complex decision making.
 */
TEST_F(IfStatementsPracticeTest, Practice2_NestedIfStatements) {
    // TODO: Practice nested if statements:
    // - Create an if statement inside another if statement
    // - Handle multiple levels of conditions
    // Example approach: Write a program that categorizes a number as positive/negative and even/odd
    
    SUCCEED() << "Implement nested if statements practice problem";
}

// ========== PRACTICE PROBLEM 3: INPUT VALIDATION ==========

/**
 * Practice Problem 3: Validate user input with if statements
 * 
 * Practice using if statements to validate and sanitize user input.
 */
TEST_F(IfStatementsPracticeTest, Practice3_InputValidation) {
    // TODO: Practice input validation:
    // - Check if input is within expected range
    // - Validate input format
    // - Handle invalid input gracefully
    // Example approach: Write a program that accepts only positive numbers
    
    SUCCEED() << "Implement input validation practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}