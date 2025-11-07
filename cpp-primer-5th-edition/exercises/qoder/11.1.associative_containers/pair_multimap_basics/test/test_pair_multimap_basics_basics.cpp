#include <gtest/gtest.h>
#include <map>
#include <string>

// Basic test for pair operations
TEST(PairMultimapBasicsTest, PairOperations) {
    // Create pairs using different methods
    std::pair<std::string, int> p1("apple", 3);
    auto p2 = std::make_pair("banana", 5);
    std::pair<std::string, int> p3{"orange", 2};
    
    // Test pair access
    EXPECT_EQ(p1.first, "apple");
    EXPECT_EQ(p1.second, 3);
    
    EXPECT_EQ(p2.first, "banana");
    EXPECT_EQ(p2.second, 5);
}

// Basic test for multimap operations
TEST(PairMultimapBasicsTest, MultimapOperations) {
    // Create a multimap
    std::multimap<std::string, int> family_children;
    
    // Test insertion
    family_children.insert({"Smith", 2});
    family_children.insert({"Smith", 4});
    family_children.insert({"Johnson", 1});
    
    // Test size
    EXPECT_EQ(family_children.size(), 3);
    
    // Test equal_range
    auto range = family_children.equal_range("Smith");
    int count = 0;
    for (auto it = range.first; it != range.second; ++it) {
        count++;
    }
    EXPECT_EQ(count, 2);
}