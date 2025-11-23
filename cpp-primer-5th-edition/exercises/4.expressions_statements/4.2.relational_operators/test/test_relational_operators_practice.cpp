#include <gtest/gtest.h>
#include <string>
#include <cmath>

// Practice test for floating-point comparisons
TEST(RelationalOperatorsPractice, FloatingPointComparisons) {
    double a = 0.1 + 0.2;
    double b = 0.3;
    
    // Direct comparison might fail due to precision issues
    // EXPECT_EQ(a, b);  // This might fail!
    
    // Better approach: compare with small epsilon
    EXPECT_NEAR(a, b, 1e-10);
}

// Practice test for mixed-type comparisons
TEST(RelationalOperatorsPractice, MixedTypeComparisons) {
    int int_val = 5;
    double double_val = 5.0;
    float float_val = 5.0f;
    
    // Mixed-type comparisons with implicit conversions
    EXPECT_TRUE(int_val == double_val);
    EXPECT_TRUE(int_val == float_val);
    EXPECT_TRUE(double_val == float_val);
}

// Practice test for complex relational expressions
TEST(RelationalOperatorsPractice, ComplexExpressions) {
    int x = 10, y = 20, z = 15;
    
    // Chained comparisons (each comparison is independent)
    bool result1 = x < y && y < z;  // x < y < z in mathematical sense
    bool result2 = x < y && y > z;  // x < y and y > z
    
    EXPECT_FALSE(result1);  // 10 < 20 but 20 is not < 15
    EXPECT_TRUE(result2);   // 10 < 20 and 20 > 15
}

// Practice test for string relational operations
TEST(RelationalOperatorsPractice, StringRelationalOperations) {
    std::string apple = "apple";
    std::string banana = "banana";
    std::string cherry = "cherry";
    
    // Lexicographical ordering
    EXPECT_TRUE(apple < banana);
    EXPECT_TRUE(banana < cherry);
    EXPECT_TRUE(apple < cherry);
    
    // Length doesn't determine ordering
    std::string a = "a";
    std::string long_string = "abcdefghijklmnopqrstuvwxyz";
    
    EXPECT_TRUE(a < long_string);  // 'a' comes before 'a'...'z'
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}