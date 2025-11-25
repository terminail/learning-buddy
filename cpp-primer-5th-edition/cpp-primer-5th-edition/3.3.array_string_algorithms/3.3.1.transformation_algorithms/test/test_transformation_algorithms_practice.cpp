#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>

// Practice test for advanced transformation scenarios
TEST(TransformationAlgorithmsPractice, AdvancedScenarios) {
    // Test transform with two input ranges
    std::vector<int> input1 = {1, 2, 3};
    std::vector<int> input2 = {4, 5, 6};
    std::vector<int> output(3);
    
    // Add corresponding elements
    std::transform(input1.begin(), input1.end(), input2.begin(), output.begin(),
                   std::plus<int>());
    
    EXPECT_EQ(5, output[0]);
    EXPECT_EQ(7, output[1]);
    EXPECT_EQ(9, output[2]);
    
    // Test in-place transformation
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::transform(data.begin(), data.end(), data.begin(), 
                   [](int n) { return n * 2; });
    
    EXPECT_EQ(2, data[0]);
    EXPECT_EQ(4, data[1]);
    EXPECT_EQ(6, data[2]);
    EXPECT_EQ(8, data[3]);
    EXPECT_EQ(10, data[4]);
}

// Practice test for lambda capture mechanisms
TEST(TransformationAlgorithmsPractice, LambdaCapture) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> output(input.size());
    int multiplier = 3;
    
    // Capture by value
    std::transform(input.begin(), input.end(), output.begin(),
                   [multiplier](int n) { return n * multiplier; });
    
    EXPECT_EQ(3, output[0]);
    EXPECT_EQ(6, output[1]);
    EXPECT_EQ(9, output[2]);
    EXPECT_EQ(12, output[3]);
    EXPECT_EQ(15, output[4]);
    
    // Capture by reference
    int factor = 2;
    std::transform(input.begin(), input.end(), output.begin(),
                   [&factor](int n) { return n * factor; factor++; });
    
    EXPECT_EQ(2, output[0]);
    EXPECT_EQ(4, output[1]);  // 2 * 2 = 4 (factor is still 2)
    EXPECT_EQ(6, output[2]);  // 3 * 2 = 6 (factor is still 2)
    EXPECT_EQ(8, output[3]);  // 4 * 2 = 8 (factor is still 2)
    EXPECT_EQ(10, output[4]); // 5 * 2 = 10 (factor is still 2)
}

// Practice test for function objects
TEST(TransformationAlgorithmsPractice, FunctionObjects) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> output(input.size());
    
    // Use standard function objects
    std::transform(input.begin(), input.end(), output.begin(), 
                   std::negate<int>());
    
    EXPECT_EQ(-1, output[0]);
    EXPECT_EQ(-2, output[1]);
    EXPECT_EQ(-3, output[2]);
    EXPECT_EQ(-4, output[3]);
    EXPECT_EQ(-5, output[4]);
}