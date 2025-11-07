#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Practice problems for vector algorithms

class VectorAlgorithmsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: ADVANCED SORTING ==========

/**
 * Practice Problem 1: Use advanced sorting techniques
 * 
 * Practice using custom comparators with sorting algorithms.
 */
TEST_F(VectorAlgorithmsPracticeTest, Practice1_AdvancedSorting) {
    // TODO: Practice advanced sorting techniques:
    // - Sort in descending order using std::sort with custom comparator
    // - Sort by absolute value for negative numbers
    // - Sort strings by length instead of alphabetical order
    // Example approach: Use lambda functions or function objects as comparators
    
    SUCCEED() << "Implement advanced sorting practice problem";
}

// ========== PRACTICE PROBLEM 2: SEARCHING ALGORITHMS ==========

/**
 * Practice Problem 2: Use different searching algorithms
 * 
 * Practice using binary search and other searching techniques.
 */
TEST_F(VectorAlgorithmsPracticeTest, Practice2_SearchingAlgorithms) {
    // TODO: Practice different searching algorithms:
    // - Use std::binary_search() for sorted vectors
    // - Use std::lower_bound() and std::upper_bound()
    // - Use std::equal_range() for finding ranges of equal elements
    // Example approach: Try each searching algorithm on appropriate data
    
    SUCCEED() << "Implement searching algorithms practice problem";
}

// ========== PRACTICE PROBLEM 3: MUTATING ALGORITHMS ==========

/**
 * Practice Problem 3: Use mutating algorithms
 * 
 * Practice using algorithms that modify vector elements.
 */
TEST_F(VectorAlgorithmsPracticeTest, Practice3_MutatingAlgorithms) {
    // TODO: Practice using mutating algorithms:
    // - Use std::transform() to modify all elements
    // - Use std::replace() to replace specific values
    // - Use std::unique() to remove consecutive duplicates
    // Example approach: Try each mutating algorithm on sample data
    
    SUCCEED() << "Implement mutating algorithms practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}