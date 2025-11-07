#include <gtest/gtest.h>
#include <iostream>
#include <string>

// Practice problems for variable declarations

class VariablesDeclarationsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: ADDITIONAL VARIABLE DECLARATIONS ==========

/**
 * Practice Problem 1: Declare additional variables of different types
 * 
 * Practice declaring variables with less common types.
 */
TEST_F(VariablesDeclarationsPracticeTest, Practice1_AdditionalTypes) {
    // TODO: Practice declaring variables of these types:
    // - float (single-precision floating point)
    // - long (larger integer type)
    // - unsigned int (non-negative integer)
    // - Example approach: Try declaring variables of these types without initialization
    
    SUCCEED() << "Implement additional variable declarations practice problem";
}

// ========== PRACTICE PROBLEM 2: VARIABLE NAMING CONVENTIONS ==========

/**
 * Practice Problem 2: Use proper variable naming conventions
 * 
 * Practice using descriptive variable names that follow C++ conventions.
 */
TEST_F(VariablesDeclarationsPracticeTest, Practice2_NamingConventions) {
    // TODO: Practice declaring variables with good names:
    // - Use descriptive names (e.g., student_count instead of sc)
    // - Use snake_case for multi-word names
    // - Start with lowercase letters
    // - Example approach: Declare variables with meaningful names for a school system
    
    SUCCEED() << "Implement variable naming conventions practice problem";
}

// ========== PRACTICE PROBLEM 3: MIXED DECLARATIONS ==========

/**
 * Practice Problem 3: Declare multiple variables in a single statement
 * 
 * Practice declaring multiple variables of the same type in one statement.
 */
TEST_F(VariablesDeclarationsPracticeTest, Practice3_MixedDeclarations) {
    // TODO: Practice declaring multiple variables:
    // - Declare multiple int variables in one statement
    // - Declare multiple double variables in one statement
    // - Example approach: Try declaring x, y, z coordinates in one statement
    
    SUCCEED() << "Implement mixed declarations practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}