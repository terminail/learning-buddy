#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>

// Test std::sort with default ordering
TEST(SortingAlgorithmsTest, DefaultSorting) {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    std::sort(numbers.begin(), numbers.end());
    
    EXPECT_EQ(11, numbers[0]);
    EXPECT_EQ(12, numbers[1]);
    EXPECT_EQ(22, numbers[2]);
    EXPECT_EQ(25, numbers[3]);
    EXPECT_EQ(34, numbers[4]);
    EXPECT_EQ(64, numbers[5]);
    EXPECT_EQ(90, numbers[6]);
    
    // Test string sorting
    std::vector<std::string> words = {"banana", "apple", "cherry"};
    std::sort(words.begin(), words.end());
    
    EXPECT_EQ("apple", words[0]);
    EXPECT_EQ("banana", words[1]);
    EXPECT_EQ("cherry", words[2]);
}

// Test std::sort with custom comparators
TEST(SortingAlgorithmsTest, CustomComparators) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Sort in descending order
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    
    EXPECT_EQ(5, numbers[0]);
    EXPECT_EQ(4, numbers[1]);
    EXPECT_EQ(3, numbers[2]);
    EXPECT_EQ(2, numbers[3]);
    EXPECT_EQ(1, numbers[4]);
    
    // Sort strings by length
    std::vector<std::string> words = {"a", "abc", "ab"};
    std::sort(words.begin(), words.end(), 
              [](const std::string& a, const std::string& b) {
                  return a.length() < b.length();
              });
    
    EXPECT_EQ("a", words[0]);
    EXPECT_EQ("ab", words[1]);
    EXPECT_EQ("abc", words[2]);
}

// Test std::stable_sort
TEST(SortingAlgorithmsTest, StableSort) {
    std::vector<std::pair<int, char>> data = {{1, 'a'}, {2, 'b'}, {1, 'c'}, {2, 'd'}};
    
    // Sort by first element using stable sort
    std::stable_sort(data.begin(), data.end());
    
    // First elements with same value should maintain their relative order
    EXPECT_EQ(1, data[0].first);
    EXPECT_EQ('a', data[0].second);  // 'a' comes before 'c'
    EXPECT_EQ(1, data[1].first);
    EXPECT_EQ('c', data[1].second);
    
    EXPECT_EQ(2, data[2].first);
    EXPECT_EQ('b', data[2].second);  // 'b' comes before 'd'
    EXPECT_EQ(2, data[3].first);
    EXPECT_EQ('d', data[3].second);
}

// Test partial sorting algorithms
TEST(SortingAlgorithmsTest, PartialSorting) {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    // Partial sort - sort first 3 elements
    std::partial_sort(numbers.begin(), numbers.begin() + 3, numbers.end());
    
    // First 3 elements should be sorted
    EXPECT_LE(numbers[0], numbers[1]);
    EXPECT_LE(numbers[1], numbers[2]);
    
    // The 3rd element should be the 3rd smallest overall
    EXPECT_EQ(22, numbers[2]);
    
    // nth_element test
    std::vector<int> more_numbers = {64, 34, 25, 12, 22, 11, 90};
    std::nth_element(more_numbers.begin(), more_numbers.begin() + 3, more_numbers.end());
    
    // The element at position 3 should be the 4th smallest
    EXPECT_EQ(25, more_numbers[3]);
}