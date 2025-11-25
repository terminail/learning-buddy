#include <gtest/gtest.h>
#include <iostream>

// Practice test for mixed type arithmetic
TEST(ArithmeticOperatorsPractice, MixedTypeOperations) {
    int int_val = 7;
    double double_val = 2.5;
    
    // When int and double are used together, int is promoted to double
    double result = int_val + double_val;
    
    EXPECT_DOUBLE_EQ(9.5, result);
}

// Practice test for complex expressions
TEST(ArithmeticOperatorsPractice, ComplexExpressions) {
    int a = 2, b = 3, c = 4, d = 5;
    
    // Test complex expression with multiple operators
    int result = a + b * c - d / 2;
    // This evaluates as: 2 + (3 * 4) - (5 / 2) = 2 + 12 - 2 = 12
    
    EXPECT_EQ(12, result);
}

// Practice test for unary operators with complex expressions
TEST(ArithmeticOperatorsPractice, UnaryInExpressions) {
    int x = 10;
    int y = -5;
    
    // Test unary operators in expressions
    int result1 = -x + 3;   // -10 + 3 = -7
    int result2 = +y - 2;   // -5 - 2 = -7
    
    EXPECT_EQ(-7, result1);
    EXPECT_EQ(-7, result2);
}

// Practice test for modulus with negative numbers
TEST(ArithmeticOperatorsPractice, ModulusWithNegatives) {
    int a = 7;
    int b = -3;
    int c = -7;
    
    // Modulus behavior with negative numbers
    EXPECT_EQ(1, a % b);   // 7 % -3 = 1
    EXPECT_EQ(-1, c % b);  // -7 % -3 = -1
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}