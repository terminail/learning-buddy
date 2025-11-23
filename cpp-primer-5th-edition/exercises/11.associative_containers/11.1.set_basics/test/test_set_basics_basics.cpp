#include <gtest/gtest.h>
#include <set>
#include <string>

// Basic test for set operations
TEST(SetBasicsTest, BasicOperations) {
    // Create a set
    std::set<std::string> unique_words;
    
    // Test insertion
    unique_words.insert("apple");
    unique_words.insert("banana");
    unique_words.insert("orange");
    
    // Test size
    EXPECT_EQ(unique_words.size(), 3);
    
    // Test duplicate handling
    unique_words.insert("apple");  // Insert duplicate
    EXPECT_EQ(unique_words.size(), 3);  // Size should remain the same
}

// Test element lookup
TEST(SetBasicsTest, ElementLookup) {
    std::set<std::string> unique_words;
    unique_words.insert("apple");
    unique_words.insert("banana");
    
    // Test count method
    EXPECT_EQ(unique_words.count("apple"), 1);
    EXPECT_EQ(unique_words.count("grape"), 0);
    
    // Test find method
    EXPECT_NE(unique_words.find("apple"), unique_words.end());
    EXPECT_EQ(unique_words.find("grape"), unique_words.end());
}