#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>

// Test std::find and std::find_if
TEST(SearchingAlgorithmsTest, FindFunctions) {
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    
    // Test std::find
    auto it = std::find(numbers.begin(), numbers.end(), 30);
    EXPECT_NE(numbers.end(), it);
    EXPECT_EQ(30, *it);
    EXPECT_EQ(2, it - numbers.begin());
    
    // Test std::find with non-existing element
    it = std::find(numbers.begin(), numbers.end(), 99);
    EXPECT_EQ(numbers.end(), it);
    
    // Test std::find_if
    auto even_it = std::find_if(numbers.begin(), numbers.end(),
                                [](int n) { return n % 2 == 0 && n > 30; });
    EXPECT_NE(numbers.end(), even_it);
    EXPECT_EQ(40, *even_it);
}

// Test std::count and std::count_if
TEST(SearchingAlgorithmsTest, CountFunctions) {
    std::vector<int> numbers = {1, 2, 2, 3, 2, 4, 2, 5};
    
    // Test std::count
    int count = std::count(numbers.begin(), numbers.end(), 2);
    EXPECT_EQ(4, count);
    
    // Test std::count with non-existing element
    count = std::count(numbers.begin(), numbers.end(), 99);
    EXPECT_EQ(0, count);
    
    // Test std::count_if
    int even_count = std::count_if(numbers.begin(), numbers.end(),
                                   [](int n) { return n % 2 == 0; });
    EXPECT_EQ(5, even_count);
}

// Test binary search functions
TEST(SearchingAlgorithmsTest, BinarySearchFunctions) {
    std::vector<int> sorted = {10, 20, 30, 40, 50, 60, 70};
    
    // Test std::binary_search
    EXPECT_TRUE(std::binary_search(sorted.begin(), sorted.end(), 40));
    EXPECT_FALSE(std::binary_search(sorted.begin(), sorted.end(), 35));
    
    // Test std::lower_bound
    auto lower = std::lower_bound(sorted.begin(), sorted.end(), 35);
    EXPECT_EQ(40, *lower);
    EXPECT_EQ(3, lower - sorted.begin());
    
    // Test std::upper_bound
    auto upper = std::upper_bound(sorted.begin(), sorted.end(), 35);
    EXPECT_EQ(40, *upper);
    EXPECT_EQ(3, upper - sorted.begin());
}

// Test string searching
TEST(SearchingAlgorithmsTest, StringSearching) {
    std::string text = "Hello World";
    
    // Test std::search
    auto it = std::search(text.begin(), text.end(), 
                          std::string("World").begin(), std::string("World").end());
    EXPECT_NE(text.end(), it);
    EXPECT_EQ(6, it - text.begin());
    
    // Test std::find_end
    auto end_it = std::find_end(text.begin(), text.end(),
                                std::string("l").begin(), std::string("l").end());
    EXPECT_NE(text.end(), end_it);
    EXPECT_EQ(9, end_it - text.begin());  // Last 'l' in "Hello"
}