#include <gtest/gtest.h>
#include <iostream>
#include <string>

// Practice problems for variable initialization

class VariablesInitializationPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: DIFFERENT INITIALIZATION METHODS ==========

/**
 * Practice Problem 1: Use different initialization methods for the same type
 * 
 * Practice using copy, direct, and uniform initialization for integers.
 */
TEST_F(VariablesInitializationPracticeTest, Practice1_DifferentMethods) {
    // TODO: Practice using different initialization methods:
    // - Copy initialization: int a = 5;
    // - Direct initialization: int b(10);
    // - Uniform initialization: int c{15};
    // - Example approach: Try initializing integers with each method
    
    SUCCEED() << "Implement different initialization methods practice problem";
}

// ========== PRACTICE PROBLEM 2: AUTO KEYWORD PRACTICE ==========

/**
 * Practice Problem 2: Use auto keyword with different initializers
 * 
 * Practice using auto keyword for type deduction.
 */
TEST_F(VariablesInitializationPracticeTest, Practice2_AutoKeyword) {
    // TODO: Practice using auto keyword:
    // - auto with integer literal: auto x = 42;
    // - auto with floating point: auto y = 3.14;
    // - auto with character: auto z = 'A';
    // - auto with string: auto s = std::string("Hello");
    // - Example approach: Try declaring variables with auto and different initializers
    
    SUCCEED() << "Implement auto keyword practice problem";
}

// ========== PRACTICE PROBLEM 3: INITIALIZATION WITH EXPRESSIONS ==========

/**
 * Practice Problem 3: Initialize variables with expressions
 * 
 * Practice initializing variables with arithmetic expressions.
 */
TEST_F(VariablesInitializationPracticeTest, Practice3_Expressions) {
    // TODO: Practice initializing with expressions:
    // - Initialize with arithmetic: int sum = 5 + 3;
    // - Initialize with function call: auto length = std::string("test").length();
    // - Initialize with another variable: int copy = original;
    // - Example approach: Try initializing variables with various expressions
    
    SUCCEED() << "Implement initialization with expressions practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}