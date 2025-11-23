#include <gtest/gtest.h>
#include <array>
#include <string>

// Test const variables
TEST(ConstantsTest, ConstVariables) {
    const int ARRAY_SIZE = 10;
    const double PI = 3.14159;
    const std::string MESSAGE = "test";
    
    EXPECT_EQ(10, ARRAY_SIZE);
    EXPECT_DOUBLE_EQ(3.14159, PI);
    EXPECT_EQ("test", MESSAGE);
    
    // Const variables cannot be modified (compile-time check)
    // ARRAY_SIZE = 20;  // This would cause compilation error
}

// Test constexpr variables
TEST(ConstantsTest, ConstexprVariables) {
    constexpr int COMPILE_TIME_SIZE = 5;
    constexpr double E = 2.71828;
    
    EXPECT_EQ(5, COMPILE_TIME_SIZE);
    EXPECT_DOUBLE_EQ(2.71828, E);
    
    // Constexpr can be used in compile-time contexts
    constexpr int SQUARED = 5 * 5;
    EXPECT_EQ(25, SQUARED);
}

// Test literal constants
TEST(ConstantsTest, LiteralConstants) {
    // Integer literals
    EXPECT_EQ(42, 42);
    EXPECT_EQ(1000000L, 1000000L);
    EXPECT_EQ(10000000000LL, 10000000000LL);
    
    // Floating-point literals
    EXPECT_FLOAT_EQ(3.14f, 3.14f);
    EXPECT_DOUBLE_EQ(3.14159, 3.14159);
    EXPECT_DOUBLE_EQ(1.23e-4, 1.23e-4);
    
    // Character literals
    EXPECT_EQ('A', 'A');
    EXPECT_EQ('Z', 'Z');
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}