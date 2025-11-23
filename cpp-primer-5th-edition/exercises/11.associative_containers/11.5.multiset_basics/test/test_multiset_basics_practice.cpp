#include <gtest/gtest.h>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

// Practice exercises for multiset operations

// TODO: Implement a function that analyzes word frequency in a text
// Requirements:
// 1. Take a vector of words as input
// 2. Return a multiset containing all words
// 3. The multiset will automatically count word frequencies
std::multiset<std::string> analyzeWordFrequency(const std::vector<std::string>& words) {
    // Student implementation goes here
    return std::multiset<std::string>(); // Placeholder
}

// TODO: Implement a function that finds the most frequent elements
// Requirements:
// 1. Take a multiset as parameter
// 2. Return a vector of the most frequent elements
// 3. If multiple elements have the same highest frequency, return all of them
template<typename T>
std::vector<T> findMostFrequent(const std::multiset<T>& ms) {
    // Student implementation goes here
    return std::vector<T>(); // Placeholder
}

// TODO: Implement a function that removes duplicates to create a set
// Requirements:
// 1. Take a multiset as parameter
// 2. Return a set containing unique elements
// 3. Preserve the sorted order
template<typename T>
std::set<T> removeDuplicates(const std::multiset<T>& ms) {
    // Student implementation goes here
    return std::set<T>(); // Placeholder
}

// Tests for word frequency analysis function
TEST(MultisetPractice, AnalyzeWordFrequencyFunction) {
    std::vector<std::string> words = {
        "apple", "banana", "apple", "cherry", "banana", "apple"
    };
    
    auto result = analyzeWordFrequency(words);
    
    EXPECT_EQ(result.size(), 6);
    EXPECT_EQ(result.count("apple"), 3);
    EXPECT_EQ(result.count("banana"), 2);
    EXPECT_EQ(result.count("cherry"), 1);
}

// Tests for finding most frequent elements function
TEST(MultisetPractice, FindMostFrequentFunction) {
    std::multiset<int> ms = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    
    auto result = findMostFrequent(ms);
    
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 4);  // 4 appears 4 times, most frequent
    
    // Test with multiple elements having same highest frequency
    std::multiset<int> ms2 = {1, 1, 2, 2, 3, 3};
    auto result2 = findMostFrequent(ms2);
    
    EXPECT_EQ(result2.size(), 3);  // All elements appear twice
    EXPECT_TRUE(std::find(result2.begin(), result2.end(), 1) != result2.end());
    EXPECT_TRUE(std::find(result2.begin(), result2.end(), 2) != result2.end());
    EXPECT_TRUE(std::find(result2.begin(), result2.end(), 3) != result2.end());
}

// Tests for removing duplicates function
TEST(MultisetPractice, RemoveDuplicatesFunction) {
    std::multiset<int> ms = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    
    auto result = removeDuplicates(ms);
    
    EXPECT_EQ(result.size(), 5);
    EXPECT_TRUE(result.find(1) != result.end());
    EXPECT_TRUE(result.find(2) != result.end());
    EXPECT_TRUE(result.find(3) != result.end());
    EXPECT_TRUE(result.find(4) != result.end());
    EXPECT_TRUE(result.find(5) != result.end());
    
    // Verify elements are in sorted order
    std::vector<int> elements(result.begin(), result.end());
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(elements, expected);
}