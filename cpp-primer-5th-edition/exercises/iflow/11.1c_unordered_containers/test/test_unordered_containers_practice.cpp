#include <gtest/gtest.h>
#include "unordered_containers_exercises.h"
#include "unordered_containers_solutions.h"
#include <vector>
#include <unordered_set>
#include <unordered_map>

// Test suite for advanced unordered containers operations
class UnorderedContainersPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test findElement function for unordered_set
TEST_F(UnorderedContainersPracticeTest, TestFindElement) {
    std::unordered_set<int> mySet = {1, 3, 5, 7, 9};
    
    // Find existing element
    auto it = UnorderedContainers::findElement(mySet, 5);
    EXPECT_NE(it, mySet.end());
    EXPECT_EQ(*it, 5);
    
    // Try to find non-existing element
    auto notFound = UnorderedContainers::findElement(mySet, 4);
    EXPECT_EQ(notFound, mySet.end());
    
    // Compare with solution
    auto solIt = UnorderedContainersSolutions::findElement(mySet, 5);
    auto solNotFound = UnorderedContainersSolutions::findElement(mySet, 4);
    EXPECT_EQ(*it, *solIt);
    EXPECT_EQ(notFound, solNotFound);
}

// Test unorderedSetToVector function
TEST_F(UnorderedContainersPracticeTest, TestUnorderedSetToVector) {
    std::unordered_set<int> mySet = {5, 2, 8, 1, 9, 3};
    std::vector<int> result = UnorderedContainers::unorderedSetToVector(mySet);
    
    // Check that the vector contains all elements from the set
    EXPECT_EQ(result.size(), mySet.size());
    
    // Check that all elements from set are in vector
    for (const auto& elem : mySet) {
        EXPECT_NE(std::find(result.begin(), result.end(), elem), result.end());
    }
    
    // Compare with solution
    std::vector<int> solutionResult = UnorderedContainersSolutions::unorderedSetToVector(mySet);
    EXPECT_EQ(result.size(), solutionResult.size());
}

// Test map operations
TEST_F(UnorderedContainersPracticeTest, TestMapOperations) {
    std::unordered_map<std::string, int> myMap = UnorderedContainers::createEmptyUnorderedMap();
    
    // Insert key-value pairs
    EXPECT_TRUE(UnorderedContainers::insertKeyValue(myMap, "apple", 5));
    EXPECT_TRUE(UnorderedContainers::insertKeyValue(myMap, "banana", 3));
    EXPECT_FALSE(UnorderedContainers::insertKeyValue(myMap, "apple", 10)); // Should return false since key exists
    
    // Check size
    EXPECT_EQ(UnorderedContainers::mapSize(myMap), 2);
    
    // Check if keys exist
    EXPECT_TRUE(UnorderedContainers::containsKey(myMap, "apple"));
    EXPECT_FALSE(UnorderedContainers::containsKey(myMap, "orange"));
    
    // Get values
    int value;
    EXPECT_TRUE(UnorderedContainers::getValue(myMap, "apple", value));
    EXPECT_EQ(value, 5);
    
    EXPECT_FALSE(UnorderedContainers::getValue(myMap, "orange", value));
    
    // Remove a key
    EXPECT_TRUE(UnorderedContainers::removeKeyValue(myMap, "apple"));
    EXPECT_FALSE(UnorderedContainers::removeKeyValue(myMap, "apple")); // Should return false since key no longer exists
    EXPECT_EQ(UnorderedContainers::mapSize(myMap), 1);
    
    // Compare with solution
    std::unordered_map<std::string, int> solutionMap = UnorderedContainersSolutions::createEmptyUnorderedMap();
    UnorderedContainersSolutions::insertKeyValue(solutionMap, "apple", 5);
    EXPECT_EQ(UnorderedContainers::mapSize(myMap), UnorderedContainersSolutions::mapSize(solutionMap) - 1);
}

// Test clear operations
TEST_F(UnorderedContainersPracticeTest, TestClearOperations) {
    // Test clearing unordered_set
    std::unordered_set<int> mySet = {1, 2, 3, 4, 5};
    UnorderedContainers::clearSet(mySet);
    EXPECT_TRUE(UnorderedContainers::isSetEmpty(mySet));
    
    // Test clearing unordered_map
    std::unordered_map<std::string, int> myMap;
    myMap["key1"] = 1;
    myMap["key2"] = 2;
    UnorderedContainers::clearMap(myMap);
    EXPECT_TRUE(UnorderedContainers::isMapEmpty(myMap));
    
    // Compare with solution
    std::unordered_set<int> solutionSet = {1, 2, 3};
    UnorderedContainersSolutions::clearSet(solutionSet);
    EXPECT_EQ(UnorderedContainers::setSize(mySet), UnorderedContainersSolutions::setSize(solutionSet));
}

// Test comprehensive unordered containers workflow
TEST_F(UnorderedContainersPracticeTest, TestComprehensiveWorkflow) {
    // Work with unordered_set
    std::vector<int> elements = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::unordered_set<int> mySet = UnorderedContainers::createUnorderedSetWithElements(elements);
    
    // Verify initial state
    EXPECT_EQ(UnorderedContainers::setSize(mySet), 7); // Unique elements: 1,2,3,4,5,6,9
    
    // Insert new elements
    UnorderedContainers::insertElement(mySet, 7);
    UnorderedContainers::insertElement(mySet, 8);
    EXPECT_EQ(UnorderedContainers::setSize(mySet), 9);
    
    // Check if elements exist
    EXPECT_TRUE(UnorderedContainers::containsElement(mySet, 7));
    EXPECT_FALSE(UnorderedContainers::containsElement(mySet, 10));
    
    // Convert to vector
    std::vector<int> vec = UnorderedContainers::unorderedSetToVector(mySet);
    EXPECT_EQ(vec.size(), mySet.size());
    
    // Remove some elements
    EXPECT_TRUE(UnorderedContainers::removeElement(mySet, 1));
    EXPECT_FALSE(UnorderedContainers::removeElement(mySet, 10)); // Not in set
    EXPECT_EQ(UnorderedContainers::setSize(mySet), 8);
    
    // Work with unordered_map
    std::unordered_map<std::string, int> myMap = UnorderedContainers::createEmptyUnorderedMap();
    UnorderedContainers::insertKeyValue(myMap, "first", 1);
    UnorderedContainers::insertKeyValue(myMap, "second", 2);
    EXPECT_EQ(UnorderedContainers::mapSize(myMap), 2);
    
    // Update existing value
    UnorderedContainers::insertKeyValue(myMap, "first", 10); // This won't update, just return false
    int value;
    EXPECT_TRUE(UnorderedContainers::getValue(myMap, "first", value));
    EXPECT_EQ(value, 1); // Value should still be 1
    
    // Compare with solution for consistency
    std::unordered_set<int> solutionSet = UnorderedContainersSolutions::createUnorderedSetWithElements(elements);
    EXPECT_EQ(UnorderedContainers::setSize(mySet), UnorderedContainersSolutions::setSize(solutionSet) + 2);
}