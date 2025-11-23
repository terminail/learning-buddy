#include <gtest/gtest.h>
#include <iostream>

// Practice problems for loop statements

class LoopStatementsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: NESTED LOOPS ==========

/**
 * Practice Problem 1: Work with nested loops
 * 
 * Practice creating nested loop structures for complex patterns.
 */
TEST_F(LoopStatementsPracticeTest, Practice1_NestedLoops) {
    // TODO: Practice nested loops:
    // - Create a loop inside another loop
    // - Handle multiple levels of iteration
    // Example approach: Write a program that prints a multiplication table
    
    SUCCEED() << "Implement nested loops practice problem";
}

// ========== PRACTICE PROBLEM 2: LOOP CONTROL STATEMENTS ==========

/**
 * Practice Problem 2: Use break and continue statements
 * 
 * Practice using break to exit loops and continue to skip iterations.
 */
TEST_F(LoopStatementsPracticeTest, Practice2_LoopControlStatements) {
    // TODO: Practice loop control statements:
    // - Use break to exit a loop early
    // - Use continue to skip to the next iteration
    // Example approach: Write a program that skips even numbers or stops at a specific value
    
    SUCCEED() << "Implement loop control statements practice problem";
}

// ========== PRACTICE PROBLEM 3: RANGE-BASED FOR LOOPS ==========

/**
 * Practice Problem 3: Use range-based for loops with containers
 * 
 * Practice using modern C++ range-based for loops.
 */
TEST_F(LoopStatementsPracticeTest, Practice3_RangeBasedForLoops) {
    // TODO: Practice range-based for loops:
    // - Use for (auto& element : container) syntax
    // - Iterate over arrays, vectors, or other containers
    // Example approach: Write a program that processes elements in an array or vector
    
    SUCCEED() << "Implement range-based for loops practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}