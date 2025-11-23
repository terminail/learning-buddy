#include <gtest/gtest.h>
#include <string>

// Function template for finding the maximum of two values
template<typename T>
T max_value(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Test for function template with integers
TEST(FunctionTemplatesTest, IntegerMax) {
    EXPECT_EQ(max_value(5, 10), 10);
    EXPECT_EQ(max_value(-5, -10), -5);
    EXPECT_EQ(max_value(0, 0), 0);
}

// Test for function template with doubles
TEST(FunctionTemplatesTest, DoubleMax) {
    EXPECT_DOUBLE_EQ(max_value(3.14, 2.71), 3.14);
    EXPECT_DOUBLE_EQ(max_value(-1.5, -2.5), -1.5);
}

// Test for function template with strings
TEST(FunctionTemplatesTest, StringMax) {
    EXPECT_EQ(max_value(std::string("apple"), std::string("banana")), "banana");
    EXPECT_EQ(max_value(std::string("zebra"), std::string("aardvark")), "zebra");
}

// Test for function template with multiple template parameters
template<typename T1, typename T2>
std::string combine_values(const T1& first, const T2& second) {
    return std::to_string(first) + " and " + std::to_string(second);
}

TEST(FunctionTemplatesTest, MultipleTemplateParameters) {
    EXPECT_EQ(combine_values(42, 3.14), "42 and 3.140000");
    EXPECT_EQ(combine_values('A', 100), "65 and 100.000000");
}