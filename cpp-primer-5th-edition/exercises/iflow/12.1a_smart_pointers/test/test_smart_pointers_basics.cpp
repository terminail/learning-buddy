#include <gtest/gtest.h>
#include "smart_pointers_exercises.h"
#include "smart_pointers_solutions.h"
#include <memory>
#include <string>

// Test suite for basic smart pointer operations
class SmartPointersBasicsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test createUniquePtr function
TEST_F(SmartPointersBasicsTest, TestCreateUniquePtr) {
    auto result = SmartPointers::createUniquePtr(42, "test");
    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getValue(), 42);
    EXPECT_EQ(result->getName(), "test");
    
    // Compare with solution
    auto solutionResult = SmartPointersSolutions::createUniquePtr(42, "test");
    EXPECT_EQ(result->getValue(), solutionResult->getValue());
    EXPECT_EQ(result->getName(), solutionResult->getName());
}

// Test createSharedPtr function
TEST_F(SmartPointersBasicsTest, TestCreateSharedPtr) {
    auto result = SmartPointers::createSharedPtr(100, "shared");
    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getValue(), 100);
    EXPECT_EQ(result->getName(), "shared");
    EXPECT_EQ(result.use_count(), 1);
    
    // Compare with solution
    auto solutionResult = SmartPointersSolutions::createSharedPtr(100, "shared");
    EXPECT_EQ(result->getValue(), solutionResult->getValue());
    EXPECT_EQ(result->getName(), solutionResult->getName());
}

// Test getValueFromUniquePtr function
TEST_F(SmartPointersBasicsTest, TestGetValueFromUniquePtr) {
    auto ptr = SmartPointers::createUniquePtr(25, "unique");
    int result = SmartPointers::getValueFromUniquePtr(ptr);
    EXPECT_EQ(result, 25);
    
    // Compare with solution
    int solutionResult = SmartPointersSolutions::getValueFromUniquePtr(ptr);
    EXPECT_EQ(result, solutionResult);
}

// Test getValueFromSharedPtr function
TEST_F(SmartPointersBasicsTest, TestGetValueFromSharedPtr) {
    auto ptr = SmartPointers::createSharedPtr(75, "shared");
    int result = SmartPointers::getValueFromSharedPtr(ptr);
    EXPECT_EQ(result, 75);
    
    // Compare with solution
    int solutionResult = SmartPointersSolutions::getValueFromSharedPtr(ptr);
    EXPECT_EQ(result, solutionResult);
}

// Test getSharedRefCount function
TEST_F(SmartPointersBasicsTest, TestGetSharedRefCount) {
    auto ptr1 = SmartPointers::createSharedPtr(10, "count");
    EXPECT_EQ(SmartPointers::getSharedRefCount(ptr1), 1);
    
    {
        auto ptr2 = ptr1;  // Copy the shared_ptr
        EXPECT_EQ(SmartPointers::getSharedRefCount(ptr1), 2);
        EXPECT_EQ(SmartPointers::getSharedRefCount(ptr2), 2);
    }
    
    // After ptr2 goes out of scope, count should be back to 1
    EXPECT_EQ(SmartPointers::getSharedRefCount(ptr1), 1);
    
    // Compare with solution
    auto solutionPtr = SmartPointersSolutions::createSharedPtr(10, "count");
    EXPECT_EQ(SmartPointers::getSharedRefCount(ptr1), SmartPointersSolutions::getSharedRefCount(solutionPtr));
}

// Test createWithMakeUnique function
TEST_F(SmartPointersBasicsTest, TestCreateWithMakeUnique) {
    auto result = SmartPointers::createWithMakeUnique(50, "make_unique");
    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getValue(), 50);
    EXPECT_EQ(result->getName(), "make_unique");
    
    // Compare with solution
    auto solutionResult = SmartPointersSolutions::createWithMakeUnique(50, "make_unique");
    EXPECT_EQ(result->getValue(), solutionResult->getValue());
    EXPECT_EQ(result->getName(), solutionResult->getName());
}

// Test createWithMakeShared function
TEST_F(SmartPointersBasicsTest, TestCreateWithMakeShared) {
    auto result = SmartPointers::createWithMakeShared(60, "make_shared");
    EXPECT_NE(result, nullptr);
    EXPECT_EQ(result->getValue(), 60);
    EXPECT_EQ(result->getName(), "make_shared");
    
    // Compare with solution
    auto solutionResult = SmartPointersSolutions::createWithMakeShared(60, "make_shared");
    EXPECT_EQ(result->getValue(), solutionResult->getValue());
    EXPECT_EQ(result->getName(), solutionResult->getName());
}