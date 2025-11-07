#include <gtest/gtest.h>
#include "set_operations_exercises.h"
#include "set_operations_solutions.h"
#include <vector>
#include <set>

// Test suite for basic set operations
class SetOperationsBasicsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test createEmptySet function
TEST_F(SetOperationsBasicsTest, TestCreateEmptySet) {
    std::set<int> result = SetOperations::createEmptySet();
    EXPECT_TRUE(result.empty());
    EXPECT_EQ(result.size(), 0);
    
    // Test with solution for comparison
    std::set<int> solutionResult = SetOperationsSolutions::createEmptySet();
    EXPECT_EQ(result, solutionResult);
}

// Test createSetWithElements function
TEST_F(SetOperationsBasicsTest, TestCreateSetWithElements) {
    std::vector<int> elements = {3, 1, 4, 1, 5, 9, 2, 6, 5}; // Note: duplicates will be removed
    std::set<int> result = SetOperations::createSetWithElements(elements);
    
    // Expected result should be sorted and without duplicates: {1, 2, 3, 4, 5, 6, 9}
    std::set<int> expected = {1, 2, 3, 4, 5, 6, 9};
    EXPECT_EQ(result, expected);
    
    // Test with solution for comparison
    std::set<int> solutionResult = SetOperationsSolutions::createSetWithElements(elements);
    EXPECT_EQ(result, solutionResult);
}

// Test insertElement function
TEST_F(SetOperationsBasicsTest, TestInsertElement) {
    std::set<int> mySet = {1, 3, 5};
    
    // Insert a new element
    bool result = SetOperations::insertElement(mySet, 7);
    EXPECT_TRUE(result); // Should return true since 7 was not in the set
    EXPECT_EQ(mySet.size(), 4);
    EXPECT_TRUE(mySet.find(7) != mySet.end());
    
    // Try to insert an existing element
    bool result2 = SetOperations::insertElement(mySet, 3);
    EXPECT_FALSE(result2); // Should return false since 3 was already in the set
    
    // Compare with solution
    std::set<int> mySetSol = {1, 3, 5};
    bool solResult = SetOperationsSolutions::insertElement(mySetSol, 7);
    EXPECT_EQ(result, solResult);
}

// Test containsElement function
TEST_F(SetOperationsBasicsTest, TestContainsElement) {
    std::set<int> mySet = {1, 2, 3, 4, 5};
    
    EXPECT_TRUE(SetOperations::containsElement(mySet, 3));
    EXPECT_FALSE(SetOperations::containsElement(mySet, 6));
    
    // Compare with solution
    EXPECT_EQ(SetOperations::containsElement(mySet, 3), 
              SetOperationsSolutions::containsElement(mySet, 3));
    EXPECT_EQ(SetOperations::containsElement(mySet, 6), 
              SetOperationsSolutions::containsElement(mySet, 6));
}

// Test setSize function
TEST_F(SetOperationsBasicsTest, TestSetSize) {
    std::set<int> mySet = {1, 2, 3, 4, 5};
    EXPECT_EQ(SetOperations::setSize(mySet), 5);
    
    mySet.insert(6);
    EXPECT_EQ(SetOperations::setSize(mySet), 6);
    
    // Compare with solution
    EXPECT_EQ(SetOperations::setSize(mySet), 
              SetOperationsSolutions::setSize(mySet));
}

// Test isSetEmpty function
TEST_F(SetOperationsBasicsTest, TestIsSetEmpty) {
    std::set<int> emptySet;
    EXPECT_TRUE(SetOperations::isSetEmpty(emptySet));
    
    std::set<int> nonEmptySet = {1, 2, 3};
    EXPECT_FALSE(SetOperations::isSetEmpty(nonEmptySet));
    
    // Compare with solution
    EXPECT_EQ(SetOperations::isSetEmpty(emptySet), 
              SetOperationsSolutions::isSetEmpty(emptySet));
    EXPECT_EQ(SetOperations::isSetEmpty(nonEmptySet), 
              SetOperationsSolutions::isSetEmpty(nonEmptySet));
}