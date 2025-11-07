#include <gtest/gtest.h>
#include "dynamic_arrays_exercises.h"
#include "dynamic_arrays_solutions.h"
#include <cstddef>

// Test suite for basic dynamic array operations
class DynamicArraysBasicsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test createIntArray function
TEST_F(DynamicArraysBasicsTest, TestCreateIntArray) {
    size_t size = 5;
    int* result = DynamicArrays::createIntArray(size);
    EXPECT_NE(result, nullptr);
    
    // Check that all elements are initialized to 0
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(result[i], 0);
    }
    
    // Test with solution for comparison
    int* solutionResult = DynamicArraysSolutions::createIntArray(size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(result[i], solutionResult[i]);
    }
    
    // Clean up
    DynamicArrays::deleteIntArray(result);
    DynamicArraysSolutions::deleteIntArray(solutionResult);
}

// Test createSimpleClassArray function
TEST_F(DynamicArraysBasicsTest, TestCreateSimpleClassArray) {
    size_t size = 3;
    SimpleClass* result = DynamicArrays::createSimpleClassArray(size);
    EXPECT_NE(result, nullptr);
    
    // Check that all elements are initialized using default constructor
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(result[i].getValue(), 0);
        EXPECT_EQ(result[i].getName(), "");
    }
    
    // Test with solution for comparison
    SimpleClass* solutionResult = DynamicArraysSolutions::createSimpleClassArray(size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(result[i].getValue(), solutionResult[i].getValue());
        EXPECT_EQ(result[i].getName(), solutionResult[i].getName());
    }
    
    // Clean up
    DynamicArrays::deleteSimpleClassArray(result);
    DynamicArraysSolutions::deleteSimpleClassArray(solutionResult);
}

// Test deleteIntArray function
TEST_F(DynamicArraysBasicsTest, TestDeleteIntArray) {
    size_t size = 3;
    int* array = DynamicArrays::createIntArray(size);
    EXPECT_NE(array, nullptr);
    
    // Fill the array with values
    for (size_t i = 0; i < size; ++i) {
        array[i] = static_cast<int>(i + 1);
    }
    
    // Deallocate the array
    DynamicArrays::deleteIntArray(array);
    // Note: We can't really test if the memory was properly freed,
    // but we can ensure the function doesn't crash
}

// Test sumIntArray function
TEST_F(DynamicArraysBasicsTest, TestSumIntArray) {
    size_t size = 4;
    int* array = DynamicArrays::createIntArray(size);
    EXPECT_NE(array, nullptr);
    
    // Fill the array with values
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    array[3] = 40;
    
    int result = DynamicArrays::sumIntArray(array, size);
    EXPECT_EQ(result, 100);
    
    // Test with solution for comparison
    int solutionResult = DynamicArraysSolutions::sumIntArray(array, size);
    EXPECT_EQ(result, solutionResult);
    
    // Clean up
    DynamicArrays::deleteIntArray(array);
}

// Test fillIntArray function
TEST_F(DynamicArraysBasicsTest, TestFillIntArray) {
    size_t size = 3;
    int* array = DynamicArrays::createIntArray(size);
    EXPECT_NE(array, nullptr);
    
    // Fill the array with a specific value
    DynamicArrays::fillIntArray(array, size, 42);
    
    // Check that all elements have the filled value
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], 42);
    }
    
    // Clean up
    DynamicArrays::deleteIntArray(array);
}