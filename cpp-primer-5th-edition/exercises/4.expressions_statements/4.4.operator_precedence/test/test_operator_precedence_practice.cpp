#include <gtest/gtest.h>

// Practice test for complex precedence expressions
TEST(OperatorPrecedencePractice, ComplexExpressions) {
    int a = 2, b = 3, c = 4, d = 5;
    
    // Complex expression with multiple operators
    int result = a + b * c - d / 2;
    // Evaluation order: b * c, d / 2, then addition and subtraction (left to right)
    // b * c = 3 * 4 = 12
    // d / 2 = 5 / 2 = 2 (integer division)
    // a + 12 - 2 = 2 + 12 - 2 = 12
    
    EXPECT_EQ(12, result);
}

// Practice test for parentheses overriding precedence
TEST(OperatorPrecedencePractice, ParenthesesOverride) {
    int x = 10, y = 5, z = 2;
    
    // Natural precedence
    int result1 = x + y * z;        // 10 + (5 * 2) = 10 + 10 = 20
    
    // Parentheses override precedence
    int result2 = (x + y) * z;      // (10 + 5) * 2 = 15 * 2 = 30
    
    EXPECT_EQ(20, result1);
    EXPECT_EQ(30, result2);
}

// Practice test for operator associativity
TEST(OperatorPrecedencePractice, OperatorAssociativity) {
    int a = 20, b = 5, c = 2;
    
    // Left-to-right associativity for division
    int result1 = a / b / c;        // (a / b) / c = (20 / 5) / 2 = 4 / 2 = 2
    int result2 = (a / b) / c;      // Same as above
    int result3 = a / (b / c);      // Different: 20 / (5 / 2) = 20 / 2 = 10 (integer division)
    
    EXPECT_EQ(2, result1);
    EXPECT_EQ(2, result2);
    EXPECT_EQ(10, result3);
}

// Practice test for complex logical expressions
TEST(OperatorPrecedencePractice, ComplexLogicalExpressions) {
    bool p = true, q = false, r = true, s = false;
    
    // Complex logical expression
    bool result = p || q && r || s;
    // Evaluation: q && r first, then left to right for ||
    // q && r = false && true = false
    // p || false = true || false = true
    // true || s = true || false = true
    
    EXPECT_TRUE(result);
    
    // Same expression with explicit parentheses
    bool result2 = p || (q && r) || s;
    EXPECT_TRUE(result2);
    
    // Different grouping
    bool result3 = (p || q) && (r || s);
    // (p || q) = true || false = true
    // (r || s) = true || false = true
    // true && true = true
    
    EXPECT_TRUE(result3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}