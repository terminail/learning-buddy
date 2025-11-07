#include <gtest/gtest.h>
#include <map>
#include <string>

// Practice test for pair and multimap operations - students need to implement these
TEST(PairMultimapBasicsPracticeTest, AdvancedMultimapOperations) {
    std::multimap<std::string, int> data;
    data.insert({"A", 1});
    data.insert({"A", 2});
    data.insert({"B", 3});
    data.insert({"A", 4});
    data.insert({"C", 5});
    
    // TODO: Implement a test that verifies the lower_bound and upper_bound methods
    // These methods can be used to find ranges of elements with the same key
    
    // TODO: Implement a test that demonstrates erasing elements from a multimap
    // Try erasing specific elements or ranges of elements
    
    // TODO: Implement a test that shows how to count elements with a specific key
    // Use the count() method to determine how many values are associated with a key
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(PairMultimapBasicsPracticeTest, PairUtilities) {
    // TODO: Implement tests for utility functions that work with pairs
    // - Test std::tie for unpacking pair values
    // - Test structured bindings (C++17 feature) for pairs
    
    SUCCEED(); // Placeholder - replace with actual tests
}