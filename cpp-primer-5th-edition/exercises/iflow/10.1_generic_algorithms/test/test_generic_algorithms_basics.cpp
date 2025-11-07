#include <gtest/gtest.h>
#include "generic_algorithms_exercises.h"
#include <vector>
#include <list>
#include <deque>

using namespace cpp_primer;

class GenericAlgorithmsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(GenericAlgorithmsTest, DefaultConstructor) {
    GenericAlgorithms exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== FINDING ALGORITHM TESTS ==========

TEST_F(GenericAlgorithmsTest, FindElement) {
    GenericAlgorithms exercise;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Test finding existing element
    auto it = exercise.find_element(vec, 3);
    EXPECT_NE(it, vec.end()) << "Expected to find element 3";
    if (it != vec.end()) {
        EXPECT_EQ(*it, 3) << "Expected found element to be 3";
    }
    
    // Test finding non-existing element
    auto it2 = exercise.find_element(vec, 10);
    EXPECT_EQ(it2, vec.end()) << "Expected to not find element 10";
}

TEST_F(GenericAlgorithmsTest, CountOccurrences) {
    GenericAlgorithms exercise;
    std::vector<int> vec = {1, 2, 2, 3, 2, 4};
    
    // Test counting occurrences
    int count = exercise.count_occurrences(vec, 2);
    EXPECT_EQ(count, 3) << "Expected to find 3 occurrences of 2";
    
    // Test counting non-existing element
    int count2 = exercise.count_occurrences(vec, 10);
    EXPECT_EQ(count2, 0) << "Expected to find 0 occurrences of 10";
}

// ========== SORTING ALGORITHM TESTS ==========

TEST_F(GenericAlgorithmsTest, SortContainer) {
    GenericAlgorithms exercise;
    std::vector<int> vec = {5, 2, 8, 1, 9};
    
    // Test sorting container
    exercise.sort_container(vec);
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end())) 
        << "Expected vector to be sorted in ascending order";
}

TEST_F(GenericAlgorithmsTest, SortContainerCustom) {
    GenericAlgorithms exercise;
    std::vector<int> vec = {5, 2, 8, 1, 9};
    
    // Test sorting container in descending order
    exercise.sort_container_custom(vec, std::greater<int>());
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end(), std::greater<int>())) 
        << "Expected vector to be sorted in descending order";
}

// ========== TRANSFORMATION ALGORITHM TESTS ==========

TEST_F(GenericAlgorithmsTest, TransformContainer) {
    GenericAlgorithms exercise;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Test transforming each element by multiplying by 2
    exercise.transform_container(vec, [](int x) { return x * 2; });
    
    EXPECT_EQ(vec[0], 2) << "Expected first element to be 2";
    EXPECT_EQ(vec[1], 4) << "Expected second element to be 4";
    EXPECT_EQ(vec[2], 6) << "Expected third element to be 6";
    EXPECT_EQ(vec[3], 8) << "Expected fourth element to be 8";
    EXPECT_EQ(vec[4], 10) << "Expected fifth element to be 10";
}

TEST_F(GenericAlgorithmsTest, CopyIfCondition) {
    GenericAlgorithms exercise;
    std::vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> destination;
    
    // Test copying even numbers
    int count = exercise.copy_if_condition(source, destination, [](int x) { return x % 2 == 0; });
    
    EXPECT_EQ(count, 5) << "Expected to copy 5 elements";
    EXPECT_EQ(destination.size(), 5) << "Expected destination to have 5 elements";
    EXPECT_EQ(destination[0], 2) << "Expected first copied element to be 2";
    EXPECT_EQ(destination[1], 4) << "Expected second copied element to be 4";
    EXPECT_EQ(destination[2], 6) << "Expected third copied element to be 6";
    EXPECT_EQ(destination[3], 8) << "Expected fourth copied element to be 8";
    EXPECT_EQ(destination[4], 10) << "Expected fifth copied element to be 10";
}

// ========== NUMERIC ALGORITHM TESTS ==========

TEST_F(GenericAlgorithmsTest, SumContainer) {
    GenericAlgorithms exercise;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Test summing elements
    int sum = exercise.sum_container(vec);
    EXPECT_EQ(sum, 15) << "Expected sum to be 15";
    
    // Test sum of empty container
    std::vector<int> empty_vec;
    int empty_sum = exercise.sum_container(empty_vec);
    EXPECT_EQ(empty_sum, 0) << "Expected sum of empty container to be 0";
}

// ========== SEARCHING ALGORITHM TESTS ==========

TEST_F(GenericAlgorithmsTest, FindIfCondition) {
    GenericAlgorithms exercise;
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    // Test finding first even number
    auto it = exercise.find_if_condition(vec, [](int x) { return x % 2 == 0; });
    EXPECT_NE(it, vec.end()) << "Expected to find an even number";
    if (it != vec.end()) {
        EXPECT_EQ(*it, 2) << "Expected to find 2 as first even number";
    }
    
    // Test finding element that doesn't exist
    auto it2 = exercise.find_if_condition(vec, [](int x) { return x > 10; });
    EXPECT_EQ(it2, vec.end()) << "Expected to not find element > 10";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}