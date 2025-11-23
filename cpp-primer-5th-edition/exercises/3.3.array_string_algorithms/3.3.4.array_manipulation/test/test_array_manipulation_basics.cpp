#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>

// Test std::reverse and std::reverse_copy
TEST(ArrayManipulationTest, ReverseFunctions) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Test std::reverse
    std::reverse(numbers.begin(), numbers.end());
    EXPECT_EQ(5, numbers[0]);
    EXPECT_EQ(4, numbers[1]);
    EXPECT_EQ(3, numbers[2]);
    EXPECT_EQ(2, numbers[3]);
    EXPECT_EQ(1, numbers[4]);
    
    // Test std::reverse_copy
    std::vector<int> original = {1, 2, 3, 4, 5};
    std::vector<int> reversed(original.size());
    std::reverse_copy(original.begin(), original.end(), reversed.begin());
    
    EXPECT_EQ(5, reversed[0]);
    EXPECT_EQ(4, reversed[1]);
    EXPECT_EQ(3, reversed[2]);
    EXPECT_EQ(2, reversed[3]);
    EXPECT_EQ(1, reversed[4]);
}

// Test std::unique and std::unique_copy
TEST(ArrayManipulationTest, UniqueFunctions) {
    std::vector<int> duplicates = {1, 1, 2, 2, 2, 3, 3, 4, 5, 5};
    
    // Test std::unique
    auto new_end = std::unique(duplicates.begin(), duplicates.end());
    duplicates.erase(new_end, duplicates.end());
    
    EXPECT_EQ(5, duplicates.size());
    EXPECT_EQ(1, duplicates[0]);
    EXPECT_EQ(2, duplicates[1]);
    EXPECT_EQ(3, duplicates[2]);
    EXPECT_EQ(4, duplicates[3]);
    EXPECT_EQ(5, duplicates[4]);
    
    // Test std::unique_copy
    std::vector<int> with_duplicates = {1, 1, 2, 2, 3, 3};
    std::vector<int> unique_copy(with_duplicates.size());
    auto copy_end = std::unique_copy(with_duplicates.begin(), with_duplicates.end(), unique_copy.begin());
    unique_copy.erase(copy_end, unique_copy.end());
    
    EXPECT_EQ(3, unique_copy.size());
    EXPECT_EQ(1, unique_copy[0]);
    EXPECT_EQ(2, unique_copy[1]);
    EXPECT_EQ(3, unique_copy[2]);
}

// Test std::remove and std::remove_if
TEST(ArrayManipulationTest, RemoveFunctions) {
    // Test std::remove
    std::vector<int> numbers = {1, 2, 3, 2, 4, 2, 5};
    auto new_end = std::remove(numbers.begin(), numbers.end(), 2);
    numbers.erase(new_end, numbers.end());
    
    EXPECT_EQ(4, numbers.size());
    EXPECT_EQ(1, numbers[0]);
    EXPECT_EQ(3, numbers[1]);
    EXPECT_EQ(4, numbers[2]);
    EXPECT_EQ(5, numbers[3]);
    
    // Test std::remove_if
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto even_end = std::remove_if(data.begin(), data.end(),
                                   [](int n) { return n % 2 == 0; });
    data.erase(even_end, data.end());
    
    EXPECT_EQ(5, data.size());
    EXPECT_EQ(1, data[0]);
    EXPECT_EQ(3, data[1]);
    EXPECT_EQ(5, data[2]);
    EXPECT_EQ(7, data[3]);
    EXPECT_EQ(9, data[4]);
}

// Test rotation and shuffling
TEST(ArrayManipulationTest, RotationAndShuffling) {
    // Test std::rotate
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::rotate(data.begin(), data.begin() + 2, data.end());
    
    EXPECT_EQ(3, data[0]);
    EXPECT_EQ(4, data[1]);
    EXPECT_EQ(5, data[2]);
    EXPECT_EQ(1, data[3]);
    EXPECT_EQ(2, data[4]);
    
    // Test that shuffle changes order (not exact test since it's random)
    std::vector<int> shuffle_data = {1, 2, 3, 4, 5};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffle_data.begin(), shuffle_data.end(), g);
    
    // At least verify the size and that elements are still there
    EXPECT_EQ(5, shuffle_data.size());
    std::sort(shuffle_data.begin(), shuffle_data.end());
    EXPECT_EQ(1, shuffle_data[0]);
    EXPECT_EQ(2, shuffle_data[1]);
    EXPECT_EQ(3, shuffle_data[2]);
    EXPECT_EQ(4, shuffle_data[3]);
    EXPECT_EQ(5, shuffle_data[4]);
}