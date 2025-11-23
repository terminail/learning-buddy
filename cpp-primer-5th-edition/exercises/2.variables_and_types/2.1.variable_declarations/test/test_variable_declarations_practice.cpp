#include <gtest/gtest.h>

// Practice test for variable naming conventions
TEST(VariableDeclarationsPractice, NamingConventions) {
    // Valid variable names
    int validVariableName = 1;
    int _underscore_start = 2;
    int number123 = 3;
    int CamelCase = 4;
    int snake_case = 5;
    
    EXPECT_EQ(1, validVariableName);
    EXPECT_EQ(2, _underscore_start);
    EXPECT_EQ(3, number123);
    EXPECT_EQ(4, CamelCase);
    EXPECT_EQ(5, snake_case);
    
    // Test that variables can be modified
    validVariableName = 10;
    _underscore_start = 20;
    
    EXPECT_EQ(10, validVariableName);
    EXPECT_EQ(20, _underscore_start);
}

// Practice test for different integer types and their ranges
TEST(VariableDeclarationsPractice, IntegerTypesAndRanges) {
    // Test signed vs unsigned
    signed int signedInt = -42;
    unsigned int unsignedInt = 42U;
    
    EXPECT_EQ(-42, signedInt);
    EXPECT_EQ(42U, unsignedInt);
    
    // Test different sizes
    short shortVar = 32767;  // Maximum value for 16-bit signed short
    long longVar = 2147483647L;  // Maximum value for 32-bit signed long
    
    EXPECT_EQ(32767, shortVar);
    EXPECT_EQ(2147483647L, longVar);
    
    // Test long long for larger values
    long long longLongVar = 9223372036854775807LL;  // Maximum value for 64-bit signed long long
    EXPECT_EQ(9223372036854775807LL, longLongVar);
}

// Practice test for floating-point precision
TEST(VariableDeclarationsPractice, FloatingPointPrecision) {
    float floatVar = 0.1f;
    double doubleVar = 0.1;
    long double longDoubleVar = 0.1L;
    
    // Float has less precision
    EXPECT_FLOAT_EQ(0.1f, floatVar);
    
    // Double has more precision
    EXPECT_DOUBLE_EQ(0.1, doubleVar);
    
    // Demonstrate precision differences
    float sumFloat = 0.0f;
    double sumDouble = 0.0;
    
    for (int i = 0; i < 10; i++) {
        sumFloat += 0.1f;
        sumDouble += 0.1;
    }
    
    // Due to floating-point representation, these might not be exactly 1.0
    EXPECT_NEAR(1.0f, sumFloat, 1e-6f);
    EXPECT_NEAR(1.0, sumDouble, 1e-10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}