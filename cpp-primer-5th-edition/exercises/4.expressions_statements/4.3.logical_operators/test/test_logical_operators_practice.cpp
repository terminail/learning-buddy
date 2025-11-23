#include <gtest/gtest.h>

// Practice test for short-circuit evaluation
TEST(LogicalOperatorsPractice, ShortCircuitEvaluation) {
    int call_count = 0;
    
    // Function that increments call_count and returns false
    auto false_func = [&call_count]() {
        call_count++;
        return false;
    };
    
    // Function that increments call_count and returns true
    auto true_func = [&call_count]() {
        call_count++;
        return true;
    };
    
    // With &&, if first operand is false, second is not evaluated
    call_count = 0;
    bool result1 = false && false_func();
    EXPECT_FALSE(result1);
    EXPECT_EQ(0, call_count);  // false_func was not called
    
    // With ||, if first operand is true, second is not evaluated
    call_count = 0;
    bool result2 = true || true_func();
    EXPECT_TRUE(result2);
    EXPECT_EQ(0, call_count);  // true_func was not called
}

// Practice test for De Morgan's laws
TEST(LogicalOperatorsPractice, DeMorgansLaws) {
    bool p = true, q = false;
    
    // First law: !(p && q) is equivalent to !p || !q
    EXPECT_EQ(!(p && q), !p || !q);
    
    // Second law: !(p || q) is equivalent to !p && !q
    EXPECT_EQ(!(p || q), !p && !q);
}

// Practice test for complex logical expressions
TEST(LogicalOperatorsPractice, ComplexExpressions) {
    int x = 5, y = 10, z = 15;
    
    // Complex expression with mixed operators
    bool result = (x < y && y < z) || (x > y && y > z);
    // This evaluates as: (5 < 10 && 10 < 15) || (5 > 10 && 10 > 15)
    //                   (true && true) || (false && false)
    //                   true || false = true
    
    EXPECT_TRUE(result);
}

// Practice test for parentheses and clarity
TEST(LogicalOperatorsPractice, ParenthesesForClarity) {
    bool a = true, b = false, c = true;
    
    // Without parentheses - relies on operator precedence
    bool result1 = a || b && c;  // a || (b && c)
    
    // With parentheses - explicit and clear
    bool result2 = a || (b && c);  // Same as above
    bool result3 = (a || b) && c;  // Different from above
    
    EXPECT_TRUE(result1);
    EXPECT_TRUE(result2);
    EXPECT_TRUE(result3);
    
    // But let's test a case where they differ:
    bool x = false, y = true, z = false;
    bool result4 = x || y && z;      // x || (y && z) = false || (true && false) = false || false = false
    bool result5 = (x || y) && z;    // (x || y) && z = (false || true) && false = true && false = false
    
    EXPECT_FALSE(result4);
    EXPECT_FALSE(result5);
    
    // Another case:
    bool p = true, q = true, r = false;
    bool result6 = p || q && r;      // p || (q && r) = true || (true && false) = true || false = true
    bool result7 = (p || q) && r;    // (p || q) && r = (true || true) && false = true && false = false
    
    EXPECT_TRUE(result6);
    EXPECT_FALSE(result7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}