#include <gtest/gtest.h>
#include <set>
#include <string>
#include <utility>

// Basic tests for pair and multiset operations

// TODO: Test pair creation and multiset insertion
// Requirements:
// 1. Create pairs with different methods
// 2. Insert pairs into multisets
// 3. Verify elements are stored correctly
// 4. Test duplicate pair handling

// TODO: Test multiset element access with pairs
// Requirements:
// 1. Use iterators to traverse multisets
// 2. Find specific pairs in multisets
// 3. Count occurrences of pairs
// 4. Access pair elements

TEST(PairMultisetBasics, PairCreationAndInsertion) {
    // Test creating pairs with different methods
    std::pair<std::string, int> p1("key1", 10);
    auto p2 = std::make_pair("key2", 20);
    std::pair<std::string, int> p3{"key1", 10};  // Same as p1
    
    // Test inserting pairs into multiset
    std::multiset<std::pair<std::string, int>> ms;
    ms.insert(p1);
    ms.insert(p2);
    ms.insert(p3);  // Duplicate of p1
    
    EXPECT_EQ(ms.size(), 3);
    EXPECT_EQ(ms.count({"key1", 10}), 2);
    EXPECT_EQ(ms.count({"key2", 20}), 1);
}

TEST(PairMultisetBasics, ElementAccessAndTraversal) {
    std::multiset<std::pair<int, std::string>> ms = {
        {1, "one"},
        {2, "two"},
        {1, "one"},  // Duplicate
        {3, "three"},
        {1, "another"}
    };
    
    // Test counting elements
    EXPECT_EQ(ms.count({1, "one"}), 2);
    EXPECT_EQ(ms.count({2, "two"}), 1);
    EXPECT_EQ(ms.count({4, "four"}), 0);
    
    // Test finding elements
    auto it = ms.find({3, "three"});
    EXPECT_NE(it, ms.end());
    EXPECT_EQ(it->first, 3);
    EXPECT_EQ(it->second, "three");
    
    // Test iterator traversal (elements should be sorted)
    std::vector<std::pair<int, std::string>> elements;
    for (const auto& pair : ms) {
        elements.push_back(pair);
    }
    
    // Multiset should be sorted by pair's first element, then second
    std::vector<std::pair<int, std::string>> expected = {
        {1, "another"},
        {1, "one"},
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };
    EXPECT_EQ(elements, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
