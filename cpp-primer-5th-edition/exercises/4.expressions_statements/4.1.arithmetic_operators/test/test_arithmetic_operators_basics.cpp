#include <gtest/gtest.h>
#include <iostream>

// Test basic arithmetic operations
TEST(ArithmeticOperatorsTest, BasicOperations) {
    int a = 10;
    int b = 3;
    
    EXPECT_EQ(13, a + b);
    EXPECT_EQ(7, a - b);
    EXPECT_EQ(30, a * b);
    EXPECT_EQ(3, a / b);  // Integer division
    EXPECT_EQ(1, a % b);  // Modulus
}

// Test floating-point arithmetic
TEST(ArithmeticOperatorsTest, FloatingPointOperations) {
    double x = 10.5;
    double y = 3.2;
    
    EXPECT_DOUBLE_EQ(13.7, x + y);
    EXPECT_DOUBLE_EQ(7.3, x - y);
    EXPECT_DOUBLE_EQ(33.6, x * y);
    EXPECT_DOUBLE_EQ(3.28125, x / y);
}

// Test unary operators
TEST(ArithmeticOperatorsTest, UnaryOperators) {
    int a = 5;
    int b = -3;
    
    EXPECT_EQ(5, +a);
    EXPECT_EQ(-5, -a);
    EXPECT_EQ(-3, +b);
    EXPECT_EQ(3, -b);
}

// Test operator precedence
TEST(ArithmeticOperatorsTest, OperatorPrecedence) {
    int result1 = 10 + 5 * 2;      // Multiplication first
    int result2 = (10 + 5) * 2;    // Parentheses first
    
    EXPECT_EQ(20, result1);
    EXPECT_EQ(30, result2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}