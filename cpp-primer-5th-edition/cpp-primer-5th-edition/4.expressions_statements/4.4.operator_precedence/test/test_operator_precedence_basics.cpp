#include <gtest/gtest.h>

// Test arithmetic operator precedence
TEST(OperatorPrecedenceTest, ArithmeticPrecedence) {
    int a = 10, b = 5, c = 2;
    
    // Multiplication has higher precedence than addition
    EXPECT_EQ(20, a + b * c);      // 10 + (5 * 2) = 10 + 10 = 20
    EXPECT_EQ(30, (a + b) * c);    // (10 + 5) * 2 = 15 * 2 = 30
    
    // Division has higher precedence than addition
    EXPECT_EQ(12, a + b / c);      // 10 + (5 / 2) = 10 + 2 = 12 (integer division)
    EXPECT_EQ(4, a / b + c);       // (10 / 5) + 2 = 2 + 2 = 4
}

// Test logical operator precedence
TEST(OperatorPrecedenceTest, LogicalPrecedence) {
    bool x = true, y = false, z = true;
    
    // && has higher precedence than ||
    EXPECT_TRUE(x || y && z);        // x || (y && z) = true || (false && true) = true || false = true
    EXPECT_TRUE(x && y || z);        // (x && y) || z = (true && false) || true = false || true = true
    
    // ! has highest precedence
    EXPECT_TRUE(!y && z);            // (!y) && z = true && true = true
    EXPECT_FALSE(!x || y);           // (!x) || y = false || false = false
}

// Test mixed operator precedence
TEST(OperatorPrecedenceTest, MixedPrecedence) {
    int a = 5, b = 3;
    bool flag = true;
    
    // Arithmetic > Relational > Logical
    bool result = a + b > 6 && flag;  // ((a + b) > 6) && flag = (8 > 6) && true = true && true = true
    EXPECT_TRUE(result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}