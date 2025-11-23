#include <gtest/gtest.h>
#include <set>
#include <string>

// Basic tests for multiset operations

// TODO: Test multiset creation and initialization
// Requirements:
// 1. Create multisets with different types
// 2. Initialize multisets with values
// 3. Verify element insertion with duplicates

// TODO: Test multiset element access
// Requirements:
// 1. Use iterators to traverse multisets
// 2. Find elements in multisets
// 3. Count occurrences of elements
// 4. Access element ranges

// TODO: Test multiset modification operations
// Requirements:
// 1. Insert elements using different methods
// 2. Erase elements by value or iterator
// 3. Check multiset size and empty status

TEST(MultisetBasics, CreationAndInitialization) {
    // Test default construction
    std::multiset<int> ms1;
    EXPECT_TRUE(ms1.empty());
    
    // Test initialization with values
    std::multiset<int> ms2 = {1, 2, 2, 3, 3, 3, 4};
    EXPECT_EQ(ms2.size(), 7);
    
    // Test insertion methods
    ms1.insert(5);
    ms1.insert(5);  // Duplicate allowed
    ms1.insert(1);
    EXPECT_EQ(ms1.size(), 3);
    
    // Verify duplicate elements are allowed
    EXPECT_EQ(ms1.count(5), 2);
    EXPECT_EQ(ms2.count(3), 3);
}

TEST(MultisetBasics, ElementAccess) {
    std::multiset<int> ms = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    
    // Test counting elements
    EXPECT_EQ(ms.count(1), 1);
    EXPECT_EQ(ms.count(2), 2);
    EXPECT_EQ(ms.count(3), 3);
    EXPECT_EQ(ms.count(6), 0);
    
    // Test finding elements
    auto it = ms.find(3);
    EXPECT_NE(it, ms.end());
    EXPECT_EQ(*it, 3);
    
    auto not_found = ms.find(6);
    EXPECT_EQ(not_found, ms.end());
    
    // Test iterator traversal (elements should be sorted)
    std::vector<int> elements;
    for (const auto& element : ms) {
        elements.push_back(element);
    }
    
    std::vector<int> expected = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    EXPECT_EQ(elements, expected);
}

TEST(MultisetBasics, ModificationOperations) {
    std::multiset<int> ms = {1, 2, 2, 3, 3, 3};
    
    // Test element insertion
    ms.insert(2);
    ms.insert(4);
    EXPECT_EQ(ms.size(), 8);
    EXPECT_EQ(ms.count(2), 3);
    
    // Test element erasure by value
    size_t erased = ms.erase(3);
    EXPECT_EQ(erased, 3);
    EXPECT_EQ(ms.size(), 5);
    EXPECT_EQ(ms.count(3), 0);
    
    // Test clearing all elements
    ms.clear();
    EXPECT_TRUE(ms.empty());
    EXPECT_EQ(ms.size(), 0);
}