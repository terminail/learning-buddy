#include <gtest/gtest.h>
#include "set_operations_exercises.h"
#include "set_operations_solutions.h"
#include <vector>
#include <set>
#include <algorithm>

// Test suite for advanced set operations
class SetOperationsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test findElement function
TEST_F(SetOperationsPracticeTest, TestFindElement) {
    std::set<int> mySet = {1, 3, 5, 7, 9};
    
    // Find existing element
    auto it = SetOperations::findElement(mySet, 5);
    EXPECT_NE(it, mySet.end());
    EXPECT_EQ(*it, 5);
    
    // Try to find non-existing element
    auto notFound = SetOperations::findElement(mySet, 4);
    EXPECT_EQ(notFound, mySet.end());
    
    // Compare with solution
    auto solIt = SetOperationsSolutions::findElement(mySet, 5);
    auto solNotFound = SetOperationsSolutions::findElement(mySet, 4);
    EXPECT_EQ(*it, *solIt);
    EXPECT_EQ(notFound, solNotFound);
}

// Test setToVector function
TEST_F(SetOperationsPracticeTest, TestSetToVector) {
    std::set<int> mySet = {5, 2, 8, 1, 9};
    std::vector<int> result = SetOperations::setToVector(mySet);
    
    // Check that vector has the same size as the set
    EXPECT_EQ(result.size(), mySet.size());
    
    // Check that vector is sorted
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
    
    // Check that all elements from set are in vector
    for (const auto& elem : mySet) {
        EXPECT_NE(std::find(result.begin(), result.end(), elem), result.end());
    }
    
    // Compare with solution
    std::vector<int> solutionResult = SetOperationsSolutions::setToVector(mySet);
    EXPECT_EQ(result, solutionResult);
}

// Test setUnion function
TEST_F(SetOperationsPracticeTest, TestSetUnion) {
    std::set<int> set1 = {1, 2, 3, 4};
    std::set<int> set2 = {3, 4, 5, 6};
    std::set<int> result = SetOperations::setUnion(set1, set2);
    
    // Union should contain all unique elements from both sets
    std::set<int> expected = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(result, expected);
    
    // Test with empty sets
    std::set<int> emptySet;
    std::set<int> unionWithEmpty = SetOperations::setUnion(set1, emptySet);
    EXPECT_EQ(unionWithEmpty, set1);
    
    // Compare with solution
    std::set<int> solutionResult = SetOperationsSolutions::setUnion(set1, set2);
    EXPECT_EQ(result, solutionResult);
}

// Test setIntersection function
TEST_F(SetOperationsPracticeTest, TestSetIntersection) {
    std::set<int> set1 = {1, 2, 3, 4};
    std::set<int> set2 = {3, 4, 5, 6};
    std::set<int> result = SetOperations::setIntersection(set1, set2);
    
    // Intersection should contain only elements present in both sets
    std::set<int> expected = {3, 4};
    EXPECT_EQ(result, expected);
    
    // Test with disjoint sets
    std::set<int> set3 = {1, 2};
    std::set<int> set4 = {3, 4};
    std::set<int> emptyIntersection = SetOperations::setIntersection(set3, set4);
    EXPECT_TRUE(emptyIntersection.empty());
    
    // Compare with solution
    std::set<int> solutionResult = SetOperationsSolutions::setIntersection(set1, set2);
    EXPECT_EQ(result, solutionResult);
}

// Test comprehensive set operations workflow
TEST_F(SetOperationsPracticeTest, TestComprehensiveWorkflow) {
    // Create a set with elements
    std::vector<int> elements = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::set<int> mySet = SetOperations::createSetWithElements(elements);
    
    // Verify initial state
    EXPECT_EQ(SetOperations::setSize(mySet), 7); // Unique elements: 1,2,3,4,5,6,9
    
    // Insert new elements
    SetOperations::insertElement(mySet, 7);
    SetOperations::insertElement(mySet, 8);
    EXPECT_EQ(SetOperations::setSize(mySet), 9);
    
    // Check if elements exist
    EXPECT_TRUE(SetOperations::containsElement(mySet, 7));
    EXPECT_FALSE(SetOperations::containsElement(mySet, 10));
    
    // Convert to vector and verify sorting
    std::vector<int> vec = SetOperations::setToVector(mySet);
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    
    // Remove some elements
    EXPECT_TRUE(SetOperations::removeElement(mySet, 1));
    EXPECT_FALSE(SetOperations::removeElement(mySet, 10)); // Not in set
    EXPECT_EQ(SetOperations::setSize(mySet), 8);
    
    // Find elements
    auto it = SetOperations::findElement(mySet, 5);
    EXPECT_NE(it, mySet.end());
    EXPECT_EQ(*it, 5);
    
    // Clear the set
    SetOperations::clearSet(mySet);
    EXPECT_TRUE(SetOperations::isSetEmpty(mySet));
}