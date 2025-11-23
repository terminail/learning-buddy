#include <gtest/gtest.h>
#include <string>
#include <sstream>

// Practice test for advanced conversion scenarios
TEST(StringConversionPractice, AdvancedScenarios) {
    // Test stoi with position parameter
    std::string str = "123abc";
    size_t pos;
    int result = std::stoi(str, &pos);
    EXPECT_EQ(123, result);
    EXPECT_EQ(3, pos);  // Position after the number
    
    // Test conversion with whitespace
    std::string ws_str = "  456  ";
    int ws_result = std::stoi(ws_str);
    EXPECT_EQ(456, ws_result);
    
    // Test floating point with scientific notation
    std::string sci_str = "1.23e4";
    double sci_result = std::stod(sci_str);
    EXPECT_DOUBLE_EQ(12300.0, sci_result);
}

// Practice test for stringstream usage
TEST(StringConversionPractice, StringStreamUsage) {
    // Test parsing multiple values
    std::string data = "42 3.14 Hello";
    std::stringstream ss(data);
    
    int num;
    double decimal;
    std::string word;
    
    ss >> num >> decimal >> word;
    
    EXPECT_EQ(42, num);
    EXPECT_DOUBLE_EQ(3.14, decimal);
    EXPECT_EQ("Hello", word);
    
    // Test string building with stringstream
    std::stringstream builder;
    builder << "Number: " << 42 << ", Decimal: " << 3.14;
    std::string result = builder.str();
    EXPECT_EQ("Number: 42, Decimal: 3.14", result);
}

// Practice test for edge cases
TEST(StringConversionPractice, EdgeCases) {
    // Test empty string
    std::string empty = "";
    EXPECT_THROW(std::stoi(empty), std::invalid_argument);
    
    // Test string with only whitespace
    std::string ws_only = "   ";
    EXPECT_THROW(std::stoi(ws_only), std::invalid_argument);
    
    // Test to_string with negative numbers
    std::string neg_str = std::to_string(-42);
    EXPECT_EQ("-42", neg_str);
    
    // Test to_string with floating point
    std::string float_str = std::to_string(-3.14);
    EXPECT_EQ("-3.140000", float_str);
}