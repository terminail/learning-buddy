#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>

// Practice problems for vector basics

class VectorBasicsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: DIFFERENT VECTOR INITIALIZATIONS ==========

/**
 * Practice Problem 1: Use different vector initialization methods
 * 
 * Practice using various ways to initialize vectors.
 */
TEST_F(VectorBasicsPracticeTest, Practice1_DifferentInitializations) {
    // TODO: Practice different vector initialization methods:
    // - Default initialization (empty vector)
    // - Size-based initialization
    // - Initializer list initialization
    // - Copy initialization from another vector
    // Example approach: Try initializing vectors with each method
    
    SUCCEED() << "Implement different vector initialization practice problem";
}

// ========== PRACTICE PROBLEM 2: VECTOR ELEMENT ACCESS ==========

/**
 * Practice Problem 2: Access vector elements in different ways
 * 
 * Practice using different methods to access vector elements.
 */
TEST_F(VectorBasicsPracticeTest, Practice2_ElementAccess) {
    // TODO: Practice accessing vector elements:
    // - Using index notation: vector[index]
    // - Using at() method: vector.at(index)
    // - Using front() and back() methods
    // - Handle out-of-bounds access appropriately
    // Example approach: Try accessing elements with different methods
    
    SUCCEED() << "Implement vector element access practice problem";
}

// ========== PRACTICE PROBLEM 3: VECTOR CAPACITY METHODS ==========

/**
 * Practice Problem 3: Use vector capacity methods
 * 
 * Practice using size, capacity, and empty methods.
 */
TEST_F(VectorBasicsPracticeTest, Practice3_CapacityMethods) {
    // TODO: Practice using vector capacity methods:
    // - size(): Get number of elements
    // - capacity(): Get allocated storage capacity
    // - empty(): Check if vector is empty
    // - max_size(): Get maximum possible size
    // Example approach: Try using each capacity method on different vectors
    
    SUCCEED() << "Implement vector capacity methods practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}