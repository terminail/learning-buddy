#include <gtest/gtest.h>

// Test logical AND operator
TEST(LogicalOperatorsTest, LogicalAND) {
    bool t = true;
    bool f = false;
    
    EXPECT_TRUE(t && t);
    EXPECT_FALSE(t && f);
    EXPECT_FALSE(f && t);
    EXPECT_FALSE(f && f);
}

// Test logical OR operator
TEST(LogicalOperatorsTest, LogicalOR) {
    bool t = true;
    bool f = false;
    
    EXPECT_TRUE(t || t);
    EXPECT_TRUE(t || f);
    EXPECT_TRUE(f || t);
    EXPECT_FALSE(f || f);
}

// Test logical NOT operator
TEST(LogicalOperatorsTest, LogicalNOT) {
    bool t = true;
    bool f = false;
    
    EXPECT_FALSE(!t);
    EXPECT_TRUE(!f);
}

// Test operator precedence
TEST(LogicalOperatorsTest, OperatorPrecedence) {
    bool a = true, b = false, c = true;
    
    // && has higher precedence than ||
    bool result1 = a || b && c;    // Equivalent to: a || (b && c)
    bool result2 = (a || b) && c;  // Parentheses override precedence
    
    EXPECT_TRUE(result1);  // true || (false && true) = true || false = true
    EXPECT_TRUE(result2);  // (true || false) && true = true && true = true
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}