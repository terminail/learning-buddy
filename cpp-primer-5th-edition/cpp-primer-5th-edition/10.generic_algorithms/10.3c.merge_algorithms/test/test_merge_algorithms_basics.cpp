#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

// Test for std::merge algorithm
TEST(MergeAlgorithmsTest, MergeAlgorithm) {
    std::vector<int> first = {1, 3, 5, 7, 9};
    std::vector<int> second = {2, 4, 6, 8, 10};
    std::vector<int> result(10);
    
    // Test merge
    std::merge(first.begin(), first.end(), second.begin(), second.end(), result.begin());
    
    // Check that result is sorted
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
    
    // Check specific values
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[9], 10);
}

// Test for std::inplace_merge algorithm
TEST(MergeAlgorithmsTest, InplaceMergeAlgorithm) {
    std::vector<int> sequence = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    
    // Sort the second half
    std::sort(sequence.begin() + 5, sequence.end());
    
    // Merge the two sorted halves
    std::inplace_merge(sequence.begin(), sequence.begin() + 5, sequence.end());
    
    // Check that result is sorted
    EXPECT_TRUE(std::is_sorted(sequence.begin(), sequence.end()));
    
    // Check specific values
    EXPECT_EQ(sequence[0], 1);
    EXPECT_EQ(sequence[9], 10);
}

// Test for merge with custom comparator
TEST(MergeAlgorithmsTest, MergeWithComparator) {
    std::vector<int> first = {9, 7, 5, 3, 1};  // descending order
    std::vector<int> second = {10, 8, 6, 4, 2};  // descending order
    std::vector<int> result(10);
    
    // Merge with greater comparator to get descending order
    std::merge(first.begin(), first.end(), second.begin(), second.end(), 
               result.begin(), std::greater<int>());
    
    // Check that result is sorted in descending order
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end(), std::greater<int>()));
    
    // Check specific values
    EXPECT_EQ(result[0], 10);
    EXPECT_EQ(result[9], 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}