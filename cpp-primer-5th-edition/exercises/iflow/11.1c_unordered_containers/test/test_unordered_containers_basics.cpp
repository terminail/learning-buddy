#include <gtest/gtest.h>
#include "unordered_containers_exercises.h"
#include "unordered_containers_solutions.h"
#include <vector>
#include <unordered_set>
#include <unordered_map>

// Test suite for basic unordered containers operations
class UnorderedContainersBasicsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test createEmptyUnorderedSet function
TEST_F(UnorderedContainersBasicsTest, TestCreateEmptyUnorderedSet) {
    std::unordered_set<int> result = UnorderedContainers::createEmptyUnorderedSet();
    EXPECT_TRUE(result.empty());
    EXPECT_EQ(result.size(), 0);
    
    // Test with solution for comparison
    std::unordered_set<int> solutionResult = UnorderedContainersSolutions::createEmptyUnorderedSet();
    EXPECT_EQ(result.size(), solutionResult.size());
}

// Test createUnorderedSetWithElements function
TEST_F(UnorderedContainersBasicsTest, TestCreateUnorderedSetWithElements) {
    std::vector<int> elements = {3, 1, 4, 1, 5, 9, 2, 6, 5}; // Note: duplicates will be removed
    std::unordered_set<int> result = UnorderedContainers::createUnorderedSetWithElements(elements);
    
    // Expected result should have all unique elements: {1, 2, 3, 4, 5, 6, 9}
    EXPECT_EQ(result.size(), 7);
    EXPECT_EQ(result.count(1), 1);
    EXPECT_EQ(result.count(3), 1);
    EXPECT_EQ(result.count(5), 1);
    EXPECT_EQ(result.count(9), 1);
    
    // Test with solution for comparison
    std::unordered_set<int> solutionResult = UnorderedContainersSolutions::createUnorderedSetWithElements(elements);
    EXPECT_EQ(result.size(), solutionResult.size());
}

// Test insertElement function for unordered_set
TEST_F(UnorderedContainersBasicsTest, TestInsertElement) {
    std::unordered_set<int> mySet = {1, 3, 5};
    
    // Insert a new element
    bool result = UnorderedContainers::insertElement(mySet, 7);
    EXPECT_TRUE(result); // Should return true since 7 was not in the set
    EXPECT_EQ(mySet.count(7), 1);
    
    // Try to insert an existing element
    bool result2 = UnorderedContainers::insertElement(mySet, 3);
    EXPECT_FALSE(result2); // Should return false since 3 was already in the set
    
    // Compare with solution
    std::unordered_set<int> mySetSol = {1, 3, 5};
    bool solResult = UnorderedContainersSolutions::insertElement(mySetSol, 7);
    EXPECT_EQ(result, solResult);
}

// Test containsElement function for unordered_set
TEST_F(UnorderedContainersBasicsTest, TestContainsElement) {
    std::unordered_set<int> mySet = {1, 2, 3, 4, 5};
    
    EXPECT_TRUE(UnorderedContainers::containsElement(mySet, 3));
    EXPECT_FALSE(UnorderedContainers::containsElement(mySet, 6));
    
    // Compare with solution
    EXPECT_EQ(UnorderedContainers::containsElement(mySet, 3), 
              UnorderedContainersSolutions::containsElement(mySet, 3));
    EXPECT_EQ(UnorderedContainers::containsElement(mySet, 6), 
              UnorderedContainersSolutions::containsElement(mySet, 6));
}

// Test setSize function for unordered_set
TEST_F(UnorderedContainersBasicsTest, TestSetSize) {
    std::unordered_set<int> mySet = {1, 2, 3, 4, 5};
    EXPECT_EQ(UnorderedContainers::setSize(mySet), 5);
    
    mySet.insert(6);
    EXPECT_EQ(UnorderedContainers::setSize(mySet), 6);
    
    // Compare with solution
    EXPECT_EQ(UnorderedContainers::setSize(mySet), 
              UnorderedContainersSolutions::setSize(mySet));
}

// Test isSetEmpty function for unordered_set
TEST_F(UnorderedContainersBasicsTest, TestIsSetEmpty) {
    std::unordered_set<int> emptySet;
    EXPECT_TRUE(UnorderedContainers::isSetEmpty(emptySet));
    
    std::unordered_set<int> nonEmptySet = {1, 2, 3};
    EXPECT_FALSE(UnorderedContainers::isSetEmpty(nonEmptySet));
    
    // Compare with solution
    EXPECT_EQ(UnorderedContainers::isSetEmpty(emptySet), 
              UnorderedContainersSolutions::isSetEmpty(emptySet));
    EXPECT_EQ(UnorderedContainers::isSetEmpty(nonEmptySet), 
              UnorderedContainersSolutions::isSetEmpty(nonEmptySet));
}

// Test createEmptyUnorderedMap function
TEST_F(UnorderedContainersBasicsTest, TestCreateEmptyUnorderedMap) {
    std::unordered_map<std::string, int> result = UnorderedContainers::createEmptyUnorderedMap();
    EXPECT_TRUE(result.empty());
    EXPECT_EQ(result.size(), 0);
    
    // Test with solution for comparison
    std::unordered_map<std::string, int> solutionResult = UnorderedContainersSolutions::createEmptyUnorderedMap();
    EXPECT_EQ(result.size(), solutionResult.size());
}