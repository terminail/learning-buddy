#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

// Test std::transform with function pointers
TEST(TransformationAlgorithmsTest, FunctionPointers) {
    std::vector<char> input = {'a', 'b', 'c', 'd'};
    std::vector<char> output(input.size());
    
    // Transform to uppercase
    std::transform(input.begin(), input.end(), output.begin(), ::toupper);
    
    EXPECT_EQ('A', output[0]);
    EXPECT_EQ('B', output[1]);
    EXPECT_EQ('C', output[2]);
    EXPECT_EQ('D', output[3]);
}

// Test std::transform with lambda functions
TEST(TransformationAlgorithmsTest, LambdaFunctions) {
    std::vector<int> input = {1, 2, 3, 4};
    std::vector<int> output(input.size());
    
    // Square each element
    std::transform(input.begin(), input.end(), output.begin(), 
                   [](int n) { return n * n; });
    
    EXPECT_EQ(1, output[0]);
    EXPECT_EQ(4, output[1]);
    EXPECT_EQ(9, output[2]);
    EXPECT_EQ(16, output[3]);
}

// Test std::transform with custom functions
TEST(TransformationAlgorithmsTest, CustomFunctions) {
    std::vector<int> input = {10, 20, 30};
    std::vector<int> output(input.size());
    
    // Double each element using a custom function
    std::transform(input.begin(), input.end(), output.begin(), 
                   [](int n) { return n * 2; });
    
    EXPECT_EQ(20, output[0]);
    EXPECT_EQ(40, output[1]);
    EXPECT_EQ(60, output[2]);
}

// Test string transformations
TEST(TransformationAlgorithmsTest, StringTransformations) {
    std::string text = "Hello";
    
    // Convert to uppercase
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    
    EXPECT_EQ("HELLO", text);
}