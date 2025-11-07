#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

// Practice problems for stack basics

class StackBasicsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: STACK WITH DIFFERENT CONTAINERS ==========

/**
 * Practice Problem 1: Use stacks with different underlying containers
 * 
 * Practice using stacks with different container types.
 */
TEST_F(StackBasicsPracticeTest, Practice1_DifferentContainers) {
    // TODO: Practice using stacks with different underlying containers:
    // - Default stack (uses deque internally)
    // - Stack with vector as underlying container: std::stack<int, std::vector<int>>
    // - Stack with list as underlying container: std::stack<int, std::list<int>>
    // Example approach: Try declaring and using each type of stack
    
    SUCCEED() << "Implement different container stacks practice problem";
}

// ========== PRACTICE PROBLEM 2: STACK ALGORITHM APPLICATIONS ==========

/**
 * Practice Problem 2: Apply stacks to algorithmic problems
 * 
 * Practice using stacks to solve common algorithmic problems.
 */
TEST_F(StackBasicsPracticeTest, Practice2_AlgorithmApplications) {
    // TODO: Practice applying stacks to algorithmic problems:
    // - Reverse a string using a stack
    // - Check for balanced parentheses
    // - Evaluate simple postfix expressions
    // Example approach: Implement each algorithm using stack operations
    
    SUCCEED() << "Implement stack algorithm applications practice problem";
}

// ========== PRACTICE PROBLEM 3: STACK PERFORMANCE CONSIDERATIONS ==========

/**
 * Practice Problem 3: Understand stack performance characteristics
 * 
 * Practice understanding the performance of stack operations.
 */
TEST_F(StackBasicsPracticeTest, Practice3_PerformanceConsiderations) {
    // TODO: Practice understanding stack performance:
    // - Time complexity of push, pop, top, empty, size operations
    // - Memory usage patterns for different underlying containers
    // - When to use stacks vs other data structures
    // Example approach: Analyze and compare performance characteristics
    
    SUCCEED() << "Implement stack performance considerations practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}