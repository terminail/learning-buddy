#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

// Test for std::transform algorithm
TEST(TransformCopyAlgorithmsTest, TransformAlgorithm) {
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination(source.size());
    
    // Test unary transform
    std::transform(source.begin(), source.end(), destination.begin(),
                  [](int n) { return n * 2; });
    
    EXPECT_EQ(destination[0], 2);
    EXPECT_EQ(destination[1], 4);
    EXPECT_EQ(destination[2], 6);
    EXPECT_EQ(destination[3], 8);
    EXPECT_EQ(destination[4], 10);
}

// Test for std::copy algorithm
TEST(TransformCopyAlgorithmsTest, CopyAlgorithm) {
    std::vector<int> source = {10, 20, 30, 40, 50};
    std::vector<int> destination(5);
    
    // Test basic copy
    std::copy(source.begin(), source.end(), destination.begin());
    
    EXPECT_EQ(destination[0], 10);
    EXPECT_EQ(destination[1], 20);
    EXPECT_EQ(destination[2], 30);
    EXPECT_EQ(destination[3], 40);
    EXPECT_EQ(destination[4], 50);
}

// Test for std::copy_if algorithm
TEST(TransformCopyAlgorithmsTest, CopyIfAlgorithm) {
    std::vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> destination;
    
    // Test copy_if with even numbers
    std::copy_if(source.begin(), source.end(), std::back_inserter(destination),
                [](int n) { return n % 2 == 0; });
    
    EXPECT_EQ(destination.size(), 5);
    EXPECT_EQ(destination[0], 2);
    EXPECT_EQ(destination[1], 4);
    EXPECT_EQ(destination[2], 6);
    EXPECT_EQ(destination[3], 8);
    EXPECT_EQ(destination[4], 10);
}

// Test for std::transform with binary operation
TEST(TransformCopyAlgorithmsTest, BinaryTransform) {
    std::vector<int> first = {1, 2, 3};
    std::vector<int> second = {10, 20, 30};
    std::vector<int> result(3);
    
    // Test binary transform (addition)
    std::transform(first.begin(), first.end(), second.begin(), result.begin(),
                  [](int a, int b) { return a + b; });
    
    EXPECT_EQ(result[0], 11);
    EXPECT_EQ(result[1], 22);
    EXPECT_EQ(result[2], 33);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}