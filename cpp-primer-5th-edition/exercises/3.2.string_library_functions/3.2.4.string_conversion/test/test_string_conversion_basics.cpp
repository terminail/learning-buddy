#include <gtest/gtest.h>
#include <string>

// Test std::to_string() function
TEST(StringConversionTest, ToStringFunction) {
    // Test integer to string
    int int_val = 42;
    std::string int_str = std::to_string(int_val);
    EXPECT_EQ("42", int_str);
    
    // Test double to string
    double double_val = 3.14;
    std::string double_str = std::to_string(double_val);
    EXPECT_EQ("3.140000", double_str);  // Default precision
    
    // Test long to string
    long long_val = 1234567890L;
    std::string long_str = std::to_string(long_val);
    EXPECT_EQ("1234567890", long_str);
}

// Test std::stoi(), std::stol(), std::stoll() functions
TEST(StringConversionTest, StringToIntegerFunctions) {
    // Test stoi
    std::string int_str = "123";
    int converted_int = std::stoi(int_str);
    EXPECT_EQ(123, converted_int);
    
    // Test stol
    std::string long_str = "9876543210";
    long converted_long = std::stol(long_str);
    EXPECT_EQ(9876543210L, converted_long);
    
    // Test stoll
    std::string long_long_str = "123456789012345";
    long long converted_long_long = std::stoll(long_long_str);
    EXPECT_EQ(123456789012345LL, converted_long_long);
    
    // Test with base
    std::string hex_str = "FF";
    int hex_int = std::stoi(hex_str, nullptr, 16);
    EXPECT_EQ(255, hex_int);
}

// Test std::stof(), std::stod(), std::stold() functions
TEST(StringConversionTest, StringToFloatingPointFunctions) {
    // Test stof
    std::string float_str = "3.14";
    float converted_float = std::stof(float_str);
    EXPECT_FLOAT_EQ(3.14f, converted_float);
    
    // Test stod
    std::string double_str = "2.718281828";
    double converted_double = std::stod(double_str);
    EXPECT_DOUBLE_EQ(2.718281828, converted_double);
}

// Test error handling
TEST(StringConversionTest, ErrorHandling) {
    // Test invalid argument
    std::string invalid_str = "abc";
    EXPECT_THROW(std::stoi(invalid_str), std::invalid_argument);
    
    // Test out of range
    std::string out_of_range_str = "999999999999999999999999999999";
    EXPECT_THROW(std::stoi(out_of_range_str), std::out_of_range);
}