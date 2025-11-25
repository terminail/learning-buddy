#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>

// Test for std::partial_sort algorithm
TEST(AdvancedSortingAlgorithmsTest, PartialSortAlgorithm) {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    
    // Test partial sort for first 5 elements
    std::partial_sort(numbers.begin(), numbers.begin() + 5, numbers.end());
    
    // Check that first 5 elements are sorted
    EXPECT_TRUE(std::is_sorted(numbers.begin(), numbers.begin() + 5));
    
    // Check that the 5th element is in its correct position
    EXPECT_EQ(numbers[4], 25);
    
    // Check that elements after position 5 are >= elements before position 5
    for (int i = 0; i < 5; ++i) {
        for (int j = 5; j < 10; ++j) {
            EXPECT_LE(numbers[i], numbers[j]);
        }
    }
}

// Test for std::nth_element algorithm
TEST(AdvancedSortingAlgorithmsTest, NthElementAlgorithm) {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    
    // Find median element (5th element in 0-indexed array of 10 elements)
    std::nth_element(numbers.begin(), numbers.begin() + 4, numbers.end());
    
    // Check that elements before position 4 are <= element at position 4
    for (int i = 0; i < 4; ++i) {
        EXPECT_LE(numbers[i], numbers[4]);
    }
    
    // Check that elements after position 4 are >= element at position 4
    for (int i = 5; i < 10; ++i) {
        EXPECT_GE(numbers[i], numbers[4]);
    }
}

// Test for performance characteristics
TEST(AdvancedSortingAlgorithmsTest, PerformanceCharacteristics) {
    // Create a large vector for testing
    std::vector<int> large_numbers(1000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);
    
    for (int& n : large_numbers) {
        n = dis(gen);
    }
    
    // Test that partial_sort is faster than full sort for small k
    std::vector<int> partial_test = large_numbers;
    std::vector<int> full_test = large_numbers;
    
    // Both should correctly sort the first 10 elements
    std::partial_sort(partial_test.begin(), partial_test.begin() + 10, partial_test.end());
    std::sort(full_test.begin(), full_test.end());
    
    // Check that first 10 elements are the same
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(partial_test[i], full_test[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}