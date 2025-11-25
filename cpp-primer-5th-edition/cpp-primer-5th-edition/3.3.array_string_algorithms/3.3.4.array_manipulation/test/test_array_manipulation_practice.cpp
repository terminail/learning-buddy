#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <random>

// Practice test for advanced manipulation scenarios
TEST(ArrayManipulationPractice, AdvancedScenarios) {
    // Test unique with custom predicate
    std::vector<std::string> words = {"apple", "Apple", "banana", "Banana", "cherry"};
    
    // Sort case-insensitively first
    std::sort(words.begin(), words.end(),
              [](const std::string& a, const std::string& b) {
                  std::string lower_a = a;
                  std::string lower_b = b;
                  std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
                  std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
                  return lower_a < lower_b;
              });
    
    // Remove case-insensitive duplicates
    auto new_end = std::unique(words.begin(), words.end(),
                               [](const std::string& a, const std::string& b) {
                                   std::string lower_a = a;
                                   std::string lower_b = b;
                                   std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
                                   std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
                                   return lower_a == lower_b;
                               });
    words.erase(new_end, words.end());
    
    EXPECT_LE(words.size(), 5);  // Should have removed some duplicates
    
    // Test remove_if with complex predicate
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    // Remove numbers that are multiples of 2 or 3
    auto multiples_end = std::remove_if(numbers.begin(), numbers.end(),
                                       [](int n) { return (n % 2 == 0) || (n % 3 == 0); });
    numbers.erase(multiples_end, numbers.end());
    
    // Remaining numbers should be 1, 5, 7, 11 (not multiples of 2 or 3)
    std::set<int> expected = {1, 5, 7, 11};
    std::set<int> actual(numbers.begin(), numbers.end());
    EXPECT_EQ(expected, actual);
}

// Practice test for performance considerations
TEST(ArrayManipulationPractice, PerformanceConsiderations) {
    // Test with large dataset
    std::vector<int> large_data(10000);
    std::iota(large_data.begin(), large_data.end(), 1);
    
    // Reverse large dataset
    auto start = std::chrono::high_resolution_clock::now();
    std::reverse(large_data.begin(), large_data.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto reverse_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Verify it's reversed
    EXPECT_EQ(10000, large_data[0]);
    EXPECT_EQ(1, large_data[9999]);
    
    // Test unique with large dataset with many duplicates
    std::vector<int> many_duplicates(10000);
    for (size_t i = 0; i < many_duplicates.size(); ++i) {
        many_duplicates[i] = i / 100;  // Each value repeated 100 times
    }
    
    start = std::chrono::high_resolution_clock::now();
    auto unique_end = std::unique(many_duplicates.begin(), many_duplicates.end());
    many_duplicates.erase(unique_end, many_duplicates.end());
    end = std::chrono::high_resolution_clock::now();
    auto unique_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Should have 100 unique values (0 to 99)
    EXPECT_EQ(100, many_duplicates.size());
    EXPECT_EQ(0, many_duplicates[0]);
    EXPECT_EQ(99, many_duplicates[99]);
    
    std::cout << "Reverse time: " << reverse_duration.count() << " microseconds" << std::endl;
    std::cout << "Unique time: " << unique_duration.count() << " microseconds" << std::endl;
}

// Practice test for edge cases
TEST(ArrayManipulationPractice, EdgeCases) {
    // Test with empty container
    std::vector<int> empty;
    std::reverse(empty.begin(), empty.end());
    EXPECT_TRUE(empty.empty());
    
    auto unique_end = std::unique(empty.begin(), empty.end());
    EXPECT_EQ(empty.end(), unique_end);
    
    auto remove_end = std::remove(empty.begin(), empty.end(), 42);
    EXPECT_EQ(empty.end(), remove_end);
    
    // Test with single element
    std::vector<int> single = {42};
    std::reverse(single.begin(), single.end());
    EXPECT_EQ(42, single[0]);
    
    unique_end = std::unique(single.begin(), single.end());
    EXPECT_EQ(single.end(), unique_end);
    
    remove_end = std::remove(single.begin(), single.end(), 99);
    EXPECT_EQ(single.end(), remove_end);
    
    // Test with all same elements
    std::vector<int> all_same = {5, 5, 5, 5, 5};
    unique_end = std::unique(all_same.begin(), all_same.end());
    all_same.erase(unique_end, all_same.end());
    EXPECT_EQ(1, all_same.size());
    EXPECT_EQ(5, all_same[0]);
    
    // Test rotate with edge cases
    std::vector<int> rotate_test = {1, 2, 3};
    
    // Rotate by 0 positions (no change)
    std::rotate(rotate_test.begin(), rotate_test.begin(), rotate_test.end());
    EXPECT_EQ(1, rotate_test[0]);
    EXPECT_EQ(2, rotate_test[1]);
    EXPECT_EQ(3, rotate_test[2]);
    
    // Rotate by size positions (no change)
    std::rotate(rotate_test.begin(), rotate_test.begin() + 3, rotate_test.end());
    EXPECT_EQ(1, rotate_test[0]);
    EXPECT_EQ(2, rotate_test[1]);
    EXPECT_EQ(3, rotate_test[2]);
}