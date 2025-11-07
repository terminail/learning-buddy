#include <gtest/gtest.h>
#include <iostream>

// Practice problems for array basics

class ArrayBasicsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: MULTI-DIMENSIONAL ARRAYS ==========

/**
 * Practice Problem 1: Work with multi-dimensional arrays
 * 
 * Practice declaring and using multi-dimensional arrays.
 */
TEST_F(ArrayBasicsPracticeTest, Practice1_MultiDimensionalArrays) {
    // TODO: Practice working with multi-dimensional arrays:
    // - Declare a 2D array (e.g., 3x4 matrix)
    // - Initialize the array with values
    // - Access elements using multiple indices
    // - Traverse the array using nested loops
    // Example approach: Try declaring and using a 2D array
    
    SUCCEED() << "Implement multi-dimensional arrays practice problem";
}

// ========== PRACTICE PROBLEM 2: ARRAY PASSING TO FUNCTIONS ==========

/**
 * Practice Problem 2: Pass arrays to functions
 * 
 * Practice passing arrays as parameters to functions.
 */
TEST_F(ArrayBasicsPracticeTest, Practice2_ArrayPassing) {
    // TODO: Practice passing arrays to functions:
    // - Create a function that takes an array parameter
    // - Pass an array to the function
    // - Modify array elements within the function
    // - Understand array decay to pointers
    // Example approach: Try passing arrays to functions and modifying them
    
    SUCCEED() << "Implement array passing to functions practice problem";
}

// ========== PRACTICE PROBLEM 3: ARRAY ALGORITHMS ==========

/**
 * Practice Problem 3: Implement array algorithms
 * 
 * Practice implementing common array algorithms.
 */
TEST_F(ArrayBasicsPracticeTest, Practice3_ArrayAlgorithms) {
    // TODO: Practice implementing array algorithms:
    // - Implement linear search in an array
    // - Implement bubble sort on an array
    // - Reverse the elements of an array
    // Example approach: Try implementing each algorithm on sample arrays
    
    SUCCEED() << "Implement array algorithms practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}