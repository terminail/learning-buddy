#include <gtest/gtest.h>
#include "smart_pointers_exercises.h"
#include "smart_pointers_solutions.h"
#include <memory>
#include <string>

// Test suite for advanced smart pointer operations
class SmartPointersPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test resetUniquePtr function
TEST_F(SmartPointersPracticeTest, TestResetUniquePtr) {
    auto ptr = SmartPointers::createUniquePtr(1, "first");
    EXPECT_EQ(ptr->getValue(), 1);
    EXPECT_EQ(ptr->getName(), "first");
    
    SmartPointers::resetUniquePtr(ptr, 2, "second");
    EXPECT_EQ(ptr->getValue(), 2);
    EXPECT_EQ(ptr->getName(), "second");
    
    // Compare with solution
    auto solutionPtr = SmartPointersSolutions::createUniquePtr(1, "first");
    SmartPointersSolutions::resetUniquePtr(solutionPtr, 2, "second");
    EXPECT_EQ(ptr->getValue(), solutionPtr->getValue());
    EXPECT_EQ(ptr->getName(), solutionPtr->getName());
}

// Test resetSharedPtr function
TEST_F(SmartPointersPracticeTest, TestResetSharedPtr) {
    auto ptr = SmartPointers::createSharedPtr(10, "shared1");
    EXPECT_EQ(ptr->getValue(), 10);
    EXPECT_EQ(ptr->getName(), "shared1");
    EXPECT_EQ(ptr.use_count(), 1);
    
    auto ptrCopy = ptr;  // Create a copy to test reference count
    EXPECT_EQ(ptr.use_count(), 2);
    
    SmartPointers::resetSharedPtr(ptr, 20, "shared2");
    EXPECT_EQ(ptr->getValue(), 20);
    EXPECT_EQ(ptr->getName(), "shared2");
    EXPECT_EQ(ptr.use_count(), 1);  // Only one reference now
    
    // Compare with solution
    auto solutionPtr = SmartPointersSolutions::createSharedPtr(10, "shared1");
    SmartPointersSolutions::resetSharedPtr(solutionPtr, 20, "shared2");
    EXPECT_EQ(ptr->getValue(), solutionPtr->getValue());
    EXPECT_EQ(ptr->getName(), solutionPtr->getName());
}

// Test weak_ptr operations
TEST_F(SmartPointersPracticeTest, TestWeakPtrOperations) {
    auto sharedPtr = SmartPointers::createSharedPtr(100, "weak_test");
    auto weakPtr = SmartPointers::createWeakPtr(sharedPtr);
    
    // Test that weak_ptr is valid while shared_ptr exists
    EXPECT_TRUE(SmartPointers::isWeakPtrValid(weakPtr));
    
    // Test locking weak_ptr to get shared_ptr
    auto lockedPtr = SmartPointers::lockWeakPtr(weakPtr);
    EXPECT_NE(lockedPtr, nullptr);
    EXPECT_EQ(lockedPtr->getValue(), 100);
    EXPECT_EQ(lockedPtr->getName(), "weak_test");
    
    // Test that reference count increases when locking
    EXPECT_EQ(sharedPtr.use_count(), 2);
    
    // Reset the shared_ptr and test weak_ptr expiration
    sharedPtr.reset();
    EXPECT_FALSE(SmartPointers::isWeakPtrValid(weakPtr));
    
    // Test locking expired weak_ptr returns nullptr
    auto expiredLockedPtr = SmartPointers::lockWeakPtr(weakPtr);
    EXPECT_EQ(expiredLockedPtr, nullptr);
    
    // Compare with solution
    auto solutionSharedPtr = SmartPointersSolutions::createSharedPtr(100, "weak_test");
    auto solutionWeakPtr = SmartPointersSolutions::createWeakPtr(solutionSharedPtr);
    EXPECT_EQ(SmartPointers::isWeakPtrValid(weakPtr), SmartPointersSolutions::isWeakPtrValid(solutionWeakPtr));
}

// Test comprehensive smart pointer workflow
TEST_F(SmartPointersPracticeTest, TestComprehensiveWorkflow) {
    // Create unique_ptr
    auto uniquePtr = SmartPointers::createUniquePtr(1, "unique");
    EXPECT_EQ(SmartPointers::getValueFromUniquePtr(uniquePtr), 1);
    
    // Create shared_ptr
    auto sharedPtr1 = SmartPointers::createSharedPtr(2, "shared1");
    auto sharedPtr2 = sharedPtr1;  // Copy to increase reference count
    
    EXPECT_EQ(SmartPointers::getValueFromSharedPtr(sharedPtr1), 2);
    EXPECT_EQ(SmartPointers::getSharedRefCount(sharedPtr1), 2);
    
    // Create weak_ptr from shared_ptr
    auto weakPtr = SmartPointers::createWeakPtr(sharedPtr1);
    EXPECT_TRUE(SmartPointers::isWeakPtrValid(weakPtr));
    
    // Use make_unique and make_shared
    auto makeUniquePtr = SmartPointers::createWithMakeUnique(3, "make_unique");
    auto makeSharedPtr = SmartPointers::createWithMakeShared(4, "make_shared");
    
    EXPECT_EQ(SmartPointers::getValueFromUniquePtr(makeUniquePtr), 3);
    EXPECT_EQ(SmartPointers::getValueFromSharedPtr(makeSharedPtr), 4);
    
    // Reset pointers
    SmartPointers::resetUniquePtr(uniquePtr, 10, "reset_unique");
    SmartPointers::resetSharedPtr(sharedPtr1, 20, "reset_shared");
    
    EXPECT_EQ(SmartPointers::getValueFromUniquePtr(uniquePtr), 10);
    EXPECT_EQ(SmartPointers::getValueFromSharedPtr(sharedPtr1), 20);
    
    // Lock weak_ptr
    auto lockedPtr = SmartPointers::lockWeakPtr(weakPtr);
    EXPECT_NE(lockedPtr, nullptr);
    EXPECT_EQ(lockedPtr->getValue(), 20);
    
    // Compare with solution for consistency
    auto solutionUniquePtr = SmartPointersSolutions::createUniquePtr(1, "unique");
    auto solutionSharedPtr = SmartPointersSolutions::createSharedPtr(2, "shared1");
    EXPECT_EQ(SmartPointers::getValueFromUniquePtr(uniquePtr), 
              SmartPointersSolutions::getValueFromUniquePtr(solutionUniquePtr) + 9);
    EXPECT_EQ(SmartPointers::getValueFromSharedPtr(sharedPtr1), 
              SmartPointersSolutions::getValueFromSharedPtr(solutionSharedPtr) + 18);
}