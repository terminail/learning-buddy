#include <gtest/gtest.h>
#include <map>
#include <string>

// Practice test for map operations - students need to implement these
TEST(MapBasicsPracticeTest, IterationAndLookup) {
    std::map<std::string, int> word_count;
    word_count["apple"] = 3;
    word_count["banana"] = 5;
    word_count["orange"] = 2;
    
    // TODO: Implement a test that verifies iteration through the map
    // Check that all key-value pairs are present
    
    // TODO: Implement a test that uses find() to locate elements
    // Verify that found elements have correct values
    // Verify that unfound elements are handled properly
    
    // TODO: Implement a test that checks the ordering of map elements
    // Maps should automatically sort by keys
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(MapBasicsPracticeTest, AtVsSubscript) {
    std::map<std::string, int> word_count;
    word_count["apple"] = 3;
    
    // TODO: Implement tests that demonstrate the difference between
    // operator[] and at() method
    // Specifically, what happens when accessing a non-existent key?
    
    SUCCEED(); // Placeholder - replace with actual tests
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}