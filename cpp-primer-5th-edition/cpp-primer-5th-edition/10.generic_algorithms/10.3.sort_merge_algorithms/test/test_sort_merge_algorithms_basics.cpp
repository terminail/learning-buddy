#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <algorithm>

// Test for std::sort algorithm
TEST(SortMergeAlgorithmsTest, SortAlgorithm) {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    // Test ascending sort
    std::sort(numbers.begin(), numbers.end());
    
    EXPECT_TRUE(std::is_sorted(numbers.begin(), numbers.end()));
    EXPECT_EQ(numbers[0], 11);
    EXPECT_EQ(numbers[6], 90);
}

// Test for std::sort with custom comparator
TEST(SortMergeAlgorithmsTest, SortWithComparator) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Test descending sort
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    
    EXPECT_TRUE(std::is_sorted(numbers.begin(), numbers.end(), std::greater<int>()));
    EXPECT_EQ(numbers[0], 5);
    EXPECT_EQ(numbers[4], 1);
}

// Test for std::stable_sort algorithm
TEST(SortMergeAlgorithmsTest, StableSortAlgorithm) {
    std::vector<std::pair<int, char>> pairs = {
        {1, 'a'}, {2, 'b'}, {1, 'c'}, {2, 'd'}, {1, 'e'}
    };
    
    // Test stable sort
    std::stable_sort(pairs.begin(), pairs.end());
    
    // Check that relative order is maintained for equal elements
    EXPECT_EQ(pairs[0].second, 'a');
    EXPECT_EQ(pairs[1].second, 'c');
    EXPECT_EQ(pairs[2].second, 'e');
    EXPECT_EQ(pairs[3].second, 'b');
    EXPECT_EQ(pairs[4].second, 'd');
}

// Test for std::merge algorithm
TEST(SortMergeAlgorithmsTest, MergeAlgorithm) {
    std::vector<int> first = {1, 3, 5};
    std::vector<int> second = {2, 4, 6};
    std::vector<int> result(6);
    
    // Test merge
    std::merge(first.begin(), first.end(), second.begin(), second.end(), result.begin());
    
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 4);
    EXPECT_EQ(result[4], 5);
    EXPECT_EQ(result[5], 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}