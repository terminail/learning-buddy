#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

// Test for std::accumulate algorithm
TEST(NumericAlgorithmsTest, AccumulateAlgorithm) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Test basic accumulation
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    EXPECT_EQ(sum, 15);
    
    // Test accumulation with initial value
    int sum_with_initial = std::accumulate(numbers.begin(), numbers.end(), 10);
    EXPECT_EQ(sum_with_initial, 25);
    
    // Test accumulation with custom operation
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, 
                                [](int a, int b) { return a * b; });
    EXPECT_EQ(product, 120);
}

// Test for std::inner_product algorithm
TEST(NumericAlgorithmsTest, InnerProductAlgorithm) {
    std::vector<int> first = {1, 2, 3};
    std::vector<int> second = {4, 5, 6};
    
    // Test basic inner product
    int dot_product = std::inner_product(first.begin(), first.end(), second.begin(), 0);
    EXPECT_EQ(dot_product, 32); // (1*4) + (2*5) + (3*6) = 4 + 10 + 18 = 32
    
    // Test inner product with custom operations
    int custom_inner = std::inner_product(first.begin(), first.end(), second.begin(), 0,
                                        [](int a, int b) { return a + b; },
                                        [](int a, int b) { return a + b; });
    EXPECT_EQ(custom_inner, 21); // (1+4) + (2+5) + (3+6) = 5 + 7 + 9 = 21
}

// Test for std::partial_sum algorithm
TEST(NumericAlgorithmsTest, PartialSumAlgorithm) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> partial_sums(numbers.size());
    
    // Test partial sum calculation
    std::partial_sum(numbers.begin(), numbers.end(), partial_sums.begin());
    
    EXPECT_EQ(partial_sums[0], 1);
    EXPECT_EQ(partial_sums[1], 3);
    EXPECT_EQ(partial_sums[2], 6);
    EXPECT_EQ(partial_sums[3], 10);
    EXPECT_EQ(partial_sums[4], 15);
}

// Test for std::adjacent_difference algorithm
TEST(NumericAlgorithmsTest, AdjacentDifferenceAlgorithm) {
    std::vector<int> numbers = {1, 3, 6, 10, 15};
    std::vector<int> differences(numbers.size());
    
    // Test adjacent difference calculation
    std::adjacent_difference(numbers.begin(), numbers.end(), differences.begin());
    
    EXPECT_EQ(differences[0], 1);
    EXPECT_EQ(differences[1], 2);
    EXPECT_EQ(differences[2], 3);
    EXPECT_EQ(differences[3], 4);
    EXPECT_EQ(differences[4], 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
