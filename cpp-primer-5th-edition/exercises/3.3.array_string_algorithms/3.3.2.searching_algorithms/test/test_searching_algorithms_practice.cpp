#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

// Practice test for advanced searching scenarios
TEST(SearchingAlgorithmsPractice, AdvancedScenarios) {
    // Test searching with custom comparators
    std::vector<std::string> words = {"apple", "Banana", "cherry", "Date"};
    
    // Case-insensitive search using custom predicate
    auto it = std::find_if(words.begin(), words.end(),
                           [](const std::string& s) { 
                               return std::equal(s.begin(), s.end(), "banana", 
                                               [](char a, char b) {
                                                   return std::tolower(a) == std::tolower(b);
                                               });
                           });
    EXPECT_NE(words.end(), it);
    EXPECT_EQ("Banana", *it);
    
    // Test counting with complex predicates
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Count numbers in range [3, 7]
    int range_count = std::count_if(numbers.begin(), numbers.end(),
                                    [](int n) { return n >= 3 && n <= 7; });
    EXPECT_EQ(5, range_count);
    
    // Test with associative containers
    std::set<int> sorted_set = {10, 20, 30, 40, 50};
    
    // std::binary_search works with sets too
    EXPECT_TRUE(std::binary_search(sorted_set.begin(), sorted_set.end(), 30));
    EXPECT_FALSE(std::binary_search(sorted_set.begin(), sorted_set.end(), 35));
}

// Practice test for performance considerations
TEST(SearchingAlgorithmsPractice, PerformanceConsiderations) {
    // Test with large dataset
    std::vector<int> large_data(10000);
    std::iota(large_data.begin(), large_data.end(), 1);  // Fill with 1, 2, 3, ..., 10000
    
    // Binary search should be much faster than linear search on sorted data
    auto start = std::chrono::high_resolution_clock::now();
    bool found_binary = std::binary_search(large_data.begin(), large_data.end(), 7500);
    auto end = std::chrono::high_resolution_clock::now();
    auto binary_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    start = std::chrono::high_resolution_clock::now();
    auto linear_it = std::find(large_data.begin(), large_data.end(), 7500);
    end = std::chrono::high_resolution_clock::now();
    auto linear_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    EXPECT_TRUE(found_binary);
    EXPECT_NE(large_data.end(), linear_it);
    
    // Binary search should be faster (or at least not significantly slower)
    EXPECT_TRUE(binary_duration.count() <= linear_duration.count() * 2);
}

// Practice test for edge cases
TEST(SearchingAlgorithmsPractice, EdgeCases) {
    // Test with empty container
    std::vector<int> empty;
    auto it = std::find(empty.begin(), empty.end(), 42);
    EXPECT_EQ(empty.end(), it);
    
    EXPECT_EQ(0, std::count(empty.begin(), empty.end(), 42));
    EXPECT_FALSE(std::binary_search(empty.begin(), empty.end(), 42));
    
    // Test with single element
    std::vector<int> single = {42};
    it = std::find(single.begin(), single.end(), 42);
    EXPECT_NE(single.end(), it);
    EXPECT_EQ(42, *it);
    
    EXPECT_EQ(1, std::count(single.begin(), single.end(), 42));
    EXPECT_TRUE(std::binary_search(single.begin(), single.end(), 42));
    
    // Test boundary conditions
    std::vector<int> boundary = {1, 2, 3};
    
    // Search for first element
    it = std::find(boundary.begin(), boundary.end(), 1);
    EXPECT_EQ(boundary.begin(), it);
    
    // Search for last element
    it = std::find(boundary.begin(), boundary.end(), 3);
    EXPECT_EQ(boundary.end() - 1, it);
}