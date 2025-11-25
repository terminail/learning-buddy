#include <gtest/gtest.h>
#include <map>
#include <string>

// Basic test for map operations
TEST(MapBasicsTest, BasicOperations) {
    // Create a map
    std::map<std::string, int> word_count;
    
    // Test insertion
    word_count["apple"] = 3;
    word_count["banana"] = 5;
    
    // Test access
    EXPECT_EQ(word_count["apple"], 3);
    EXPECT_EQ(word_count["banana"], 5);
    
    // Test size
    EXPECT_EQ(word_count.size(), 2);
}

// Test insert method
TEST(MapBasicsTest, InsertMethod) {
    std::map<std::string, int> word_count;
    
    // Test insert with pair
    word_count.insert(std::make_pair("orange", 2));
    EXPECT_EQ(word_count["orange"], 2);
    
    // Test insert with initializer list
    word_count.insert({"grape", 7});
    EXPECT_EQ(word_count["grape"], 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}