#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <string>

// Practice problems for list basics

class ListBasicsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: LIST ITERATION METHODS ==========

/**
 * Practice Problem 1: Use different list iteration methods
 * 
 * Practice using various ways to iterate through lists.
 */
TEST_F(ListBasicsPracticeTest, Practice1_ListIteration) {
    // TODO: Practice different list iteration methods:
    // - Using range-based for loops
    // - Using iterators (begin/end)
    // - Using reverse iterators (rbegin/rend)
    // Example approach: Try iterating through a list with each method
    
    SUCCEED() << "Implement different list iteration practice problem";
}

// ========== PRACTICE PROBLEM 2: LIST MODIFICATION OPERATIONS ==========

/**
 * Practice Problem 2: Use list modification operations
 * 
 * Practice using operations that modify list structure.
 */
TEST_F(ListBasicsPracticeTest, Practice2_ListModification) {
    // TODO: Practice list modification operations:
    // - Use splice() to move elements between lists
    // - Use merge() to combine sorted lists
    // - Use unique() to remove consecutive duplicates
    // - Use sort() to sort list elements
    // Example approach: Try each modification operation on sample lists
    
    SUCCEED() << "Implement list modification operations practice problem";
}

// ========== PRACTICE PROBLEM 3: LIST COMPARISON OPERATIONS ==========

/**
 * Practice Problem 3: Use list comparison operations
 * 
 * Practice using operations that compare lists.
 */
TEST_F(ListBasicsPracticeTest, Practice3_ListComparison) {
    // TODO: Practice list comparison operations:
    // - Use comparison operators (==, !=, <, >, <=, >=)
    // - Use swap() to exchange contents between lists
    // - Use assign() to replace list contents
    // Example approach: Try each comparison operation on sample lists
    
    SUCCEED() << "Implement list comparison operations practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}