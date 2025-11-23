#include <gtest/gtest.h>
#include <sstream>
#include <iomanip>
#include <string>

// Test for basic stream manipulators
TEST(OutputFormattingTest, BasicManipulators) {
    std::ostringstream oss;
    
    // Test setw and setfill
    oss << std::setw(10) << std::setfill('*') << 42;
    EXPECT_EQ(oss.str(), "********42");
    
    // Reset and test again
    oss.str("");
    oss.clear();
    oss << std::setw(5) << std::setfill(' ') << std::left << 123;
    EXPECT_EQ(oss.str(), "123  ");
}

// Test for numeric formatting
TEST(OutputFormattingTest, NumericFormatting) {
    std::ostringstream oss;
    
    // Test precision
    double value = 3.14159;
    oss << std::fixed << std::setprecision(2) << value;
    EXPECT_EQ(oss.str(), "3.14");
    
    // Test scientific notation
    oss.str("");
    oss.clear();
    oss << std::scientific << std::setprecision(2) << value;
    EXPECT_EQ(oss.str(), "3.14e+00");
}

// Test for base formatting
TEST(OutputFormattingTest, BaseFormatting) {
    std::ostringstream oss;
    
    // Test hexadecimal
    int number = 255;
    oss << std::hex << number;
    EXPECT_EQ(oss.str(), "ff");
    
    // Reset and test decimal
    oss.str("");
    oss.clear();
    oss << std::dec << number;
    EXPECT_EQ(oss.str(), "255");
    
    // Test octal
    oss.str("");
    oss.clear();
    oss << std::oct << number;
    EXPECT_EQ(oss.str(), "377");
}