#include <gtest/gtest.h>
#include "dynamic_arrays_exercises.h"
#include "dynamic_arrays_solutions.h"
#include <cstddef>

// Test suite for advanced dynamic array operations
class DynamicArraysPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test findInIntArray function
TEST_F(DynamicArraysPracticeTest, TestFindInIntArray) {
    size_t size = 5;
    int* array = DynamicArrays::createIntArray(size);
    EXPECT_NE(array, nullptr);
    
    // Fill the array with values
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    array[3] = 40;
    array[4] = 50;
    
    // Find existing element
    int* found = DynamicArrays::findInIntArray(array, size, 30);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(*found, 30);
    
    // Find non-existing element
    int* notFound = DynamicArrays::findInIntArray(array, size, 99);
    EXPECT_EQ(notFound, nullptr);
    
    // Test with solution for comparison
    int* solutionFound = DynamicArraysSolutions::findInIntArray(array, size, 30);
    EXPECT_EQ(*found, *solutionFound);
    
    // Clean up
    DynamicArrays::deleteIntArray(array);
}

// Test resizeIntArray function
TEST_F(DynamicArraysPracticeTest, TestResizeIntArray) {
    size_t oldSize = 3;
    int* oldArray = DynamicArrays::createIntArray(oldSize);
    EXPECT_NE(oldArray, nullptr);
    
    // Fill the original array
    oldArray[0] = 1;
    oldArray[1] = 2;
    oldArray[2] = 3;
    
    // Resize to a larger array
    size_t newSize = 5;
    int* newArray = DynamicArrays::resizeIntArray(oldArray, oldSize, newSize);
    
    // Check that old elements are preserved
    EXPECT_EQ(newArray[0], 1);
    EXPECT_EQ(newArray[1], 2);
    EXPECT_EQ(newArray[2], 3);
    
    // Check that new elements are initialized to 0
    EXPECT_EQ(newArray[3], 0);
    EXPECT_EQ(newArray[4], 0);
    
    // Resize to a smaller array
    size_t smallerSize = 2;
    int* smallerArray = DynamicArrays::resizeIntArray(newArray, newSize, smallerSize);
    
    // Check that only the first elements are preserved
    EXPECT_EQ(smallerArray[0], 1);
    EXPECT_EQ(smallerArray[1], 2);
    
    // Clean up
    DynamicArrays::deleteIntArray(smallerArray);
}

// Test createCopyOfIntArray function
TEST_F(DynamicArraysPracticeTest, TestCreateCopyOfIntArray) {
    size_t size = 4;
    int* original = DynamicArrays::createIntArray(size);
    EXPECT_NE(original, nullptr);
    
    // Fill the original array
    original[0] = 100;
    original[1] = 200;
    original[2] = 300;
    original[3] = 400;
    
    // Create a copy
    int* copy = DynamicArrays::createCopyOfIntArray(original, size);
    EXPECT_NE(copy, nullptr);
    
    // Check that the copy has the same values
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(copy[i], original[i]);
    }
    
    // Modify the copy and verify original is unchanged
    copy[0] = 999;
    EXPECT_EQ(copy[0], 999);
    EXPECT_EQ(original[0], 100);
    
    // Test with solution for comparison
    int* solutionCopy = DynamicArraysSolutions::createCopyOfIntArray(original, size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(copy[i], solutionCopy[i]);
    }
    
    // Clean up
    DynamicArrays::deleteIntArray(original);
    DynamicArrays::deleteIntArray(copy);
    DynamicArraysSolutions::deleteIntArray(solutionCopy);
}

// Test copyIntArray function
TEST_F(DynamicArraysPracticeTest, TestCopyIntArray) {
    size_t size = 3;
    int* source = DynamicArrays::createIntArray(size);
    int* destination = DynamicArrays::createIntArray(size);
    EXPECT_NE(source, nullptr);
    EXPECT_NE(destination, nullptr);
    
    // Fill the source array
    source[0] = 5;
    source[1] = 10;
    source[2] = 15;
    
    // Copy from source to destination
    DynamicArrays::copyIntArray(source, destination, size);
    
    // Check that destination now has the same values as source
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(destination[i], source[i]);
    }
    
    // Test with solution for comparison
    int* testDest = DynamicArrays::createIntArray(size);
    DynamicArraysSolutions::copyIntArray(source, testDest, size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(destination[i], testDest[i]);
    }
    
    // Clean up
    DynamicArrays::deleteIntArray(source);
    DynamicArrays::deleteIntArray(destination);
    DynamicArraysSolutions::deleteIntArray(testDest);
}

// Test comprehensive dynamic arrays workflow
TEST_F(DynamicArraysPracticeTest, TestComprehensiveWorkflow) {
    // Create an array
    size_t size = 3;
    int* array = DynamicArrays::createIntArray(size);
    EXPECT_NE(array, nullptr);
    
    // Fill the array
    DynamicArrays::fillIntArray(array, size, 7);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(array[i], 7);
    }
    
    // Calculate sum
    int sum = DynamicArrays::sumIntArray(array, size);
    EXPECT_EQ(sum, 21); // 7 + 7 + 7
    
    // Find an element
    int* found = DynamicArrays::findInIntArray(array, size, 7);
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(*found, 7);
    
    // Create a copy
    int* copy = DynamicArrays::createCopyOfIntArray(array, size);
    EXPECT_NE(copy, nullptr);
    
    // Verify the copy
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(copy[i], array[i]);
    }
    
    // Resize the array
    size_t newSize = 5;
    copy = DynamicArrays::resizeIntArray(copy, size, newSize);
    EXPECT_NE(copy, nullptr);
    
    // Check that old values are preserved and new values are 0
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(copy[i], 7);
    }
    for (size_t i = size; i < newSize; ++i) {
        EXPECT_EQ(copy[i], 0);
    }
    
    // Clean up
    DynamicArrays::deleteIntArray(array);
    DynamicArrays::deleteIntArray(copy);
}