#include <gtest/gtest.h>
#include <map>
#include <string>
#include <utility>

// Basic tests for pair and multimap operations

// TODO: Test pair creation and multimap insertion
// Requirements:
// 1. Create pairs with different methods
// 2. Insert pairs into multimaps
// 3. Verify elements are stored correctly

// TODO: Test multimap element access with pairs
// Requirements:
// 1. Use iterators to traverse multimaps
// 2. Find elements with specific keys
// 3. Count occurrences of keys
// 4. Access value ranges for keys

TEST(PairMultimapBasics, PairCreationAndInsertion) {
    // Test creating pairs with different methods
    std::pair<std::string, int> p1("key1", 10);
    auto p2 = std::make_pair("key2", 20);
    std::pair<std::string, int> p3{"key3", 30};
    
    // Test inserting pairs into multimap
    std::multimap<std::string, int> mm;
    mm.insert(p1);
    mm.insert(p2);
    mm.insert(p3);
    
    EXPECT_EQ(mm.size(), 3);
    
    // Test inserting duplicate keys
    mm.insert({"key1", 15});
    EXPECT_EQ(mm.size(), 4);
    EXPECT_EQ(mm.count("key1"), 2);
}

TEST(PairMultimapBasics, ElementAccessAndTraversal) {
    std::multimap<int, std::string> mm = {
        {1, "one"},
        {2, "two"},
        {1, "another one"},
        {3, "three"},
        {1, "yet another"}
    };
    
    // Test counting elements with specific keys
    EXPECT_EQ(mm.count(1), 3);
    EXPECT_EQ(mm.count(2), 1);
    EXPECT_EQ(mm.count(4), 0);
    
    // Test finding ranges
    auto range = mm.equal_range(1);
    int count = 0;
    for (auto it = range.first; it != range.second; ++it) {
        ++count;
    }
    EXPECT_EQ(count, 3);
    
    // Test iterator traversal
    int total_count = 0;
    for (const auto& pair : mm) {
        ++total_count;
    }
    EXPECT_EQ(total_count, 5);
}