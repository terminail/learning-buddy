#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <algorithm>

// Test for std::find algorithm
TEST(FindCountAlgorithmsTest, FindAlgorithm) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Test finding an existing element
    auto it = std::find(numbers.begin(), numbers.end(), 3);
    EXPECT_NE(it, numbers.end());
    EXPECT_EQ(*it, 3);
    EXPECT_EQ(it - numbers.begin(), 2);
    
    // Test finding a non-existing element
    auto it2 = std::find(numbers.begin(), numbers.end(), 10);
    EXPECT_EQ(it2, numbers.end());
}

// Test for std::count algorithm
TEST(FindCountAlgorithmsTest, CountAlgorithm) {
    std::vector<int> numbers = {1, 2, 3, 2, 4, 2, 5};
    
    // Test counting existing elements
    int count_2 = std::count(numbers.begin(), numbers.end(), 2);
    EXPECT_EQ(count_2, 3);
    
    // Test counting non-existing elements
    int count_10 = std::count(numbers.begin(), numbers.end(), 10);
    EXPECT_EQ(count_10, 0);
}

// Test for std::find_if algorithm
TEST(FindCountAlgorithmsTest, FindIfAlgorithm) {
    std::vector<int> numbers = {1, 3, 5, 8, 9, 12};
    
    // Test finding first even number
    auto it = std::find_if(numbers.begin(), numbers.end(), 
                          [](int n) { return n % 2 == 0; });
    EXPECT_NE(it, numbers.end());
    EXPECT_EQ(*it, 8);
}

// Test for std::count_if algorithm
TEST(FindCountAlgorithmsTest, CountIfAlgorithm) {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test counting even numbers
    int count_even = std::count_if(numbers.begin(), numbers.end(), 
                                 [](int n) { return n % 2 == 0; });
    EXPECT_EQ(count_even, 5);
    
    // Test counting numbers greater than 5
    int count_greater_5 = std::count_if(numbers.begin(), numbers.end(), 
                                      [](int n) { return n > 5; });
    EXPECT_EQ(count_greater_5, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}