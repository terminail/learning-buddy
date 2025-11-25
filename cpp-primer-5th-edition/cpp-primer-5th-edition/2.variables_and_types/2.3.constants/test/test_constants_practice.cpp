#include <gtest/gtest.h>
#include <array>
#include <string>

// Constexpr function that can be evaluated at compile time
constexpr int square(int x) {
    return x * x;
}

// Practice test for constexpr functions
TEST(ConstantsPractice, ConstexprFunctions) {
    constexpr int result = square(5);
    EXPECT_EQ(25, result);
    
    // Can be used in contexts requiring compile-time constants
    constexpr int SIZE = square(3);
    std::array<int, SIZE> arr{};  // SIZE must be compile-time constant
    EXPECT_EQ(9, SIZE);
    EXPECT_EQ(9, arr.size());
}

// Practice test for const vs constexpr
TEST(ConstantsPractice, ConstVsConstexpr) {
    // Runtime value
    int runtimeValue = 10;
    
    // const can be initialized with runtime values
    const int constRuntime = runtimeValue;
    EXPECT_EQ(10, constRuntime);
    
    // constexpr cannot be initialized with runtime values
    constexpr int COMPILE_TIME_VALUE = 20;
    EXPECT_EQ(20, COMPILE_TIME_VALUE);
    
    // Both const and constexpr can be used in similar contexts when initialized with compile-time values
    const int constCompileTime = 30;
    constexpr int constexprCompileTime = 30;
    
    EXPECT_EQ(30, constCompileTime);
    EXPECT_EQ(30, constexprCompileTime);
}

// Practice test for literal suffixes
TEST(ConstantsPractice, LiteralSuffixes) {
    // Different integer types
    auto intValue = 42;        // int
    auto longValue = 42L;      // long
    auto longLongValue = 42LL; // long long
    
    EXPECT_EQ(42, intValue);
    EXPECT_EQ(42L, longValue);
    EXPECT_EQ(42LL, longLongValue);
    
    // Different floating-point types
    auto floatValue = 3.14f;   // float
    auto doubleValue = 3.14;   // double
    auto longDoubleValue = 3.14L; // long double
    
    EXPECT_FLOAT_EQ(3.14f, floatValue);
    EXPECT_DOUBLE_EQ(3.14, doubleValue);
    EXPECT_DOUBLE_EQ(3.14L, longDoubleValue);
}

// Practice test for array sizes with constexpr
TEST(ConstantsPractice, ArraySizesWithConstexpr) {
    constexpr int SIZE = 5;
    
    // This works because SIZE is a compile-time constant
    std::array<int, SIZE> compileTimeArray{};
    EXPECT_EQ(5, compileTimeArray.size());
    
    // Demonstrate that const variables initialized with compile-time values
    // can also be used for array sizes in some contexts
    const int CONST_SIZE = 10;
    std::array<int, CONST_SIZE> constArray{};
    EXPECT_EQ(10, constArray.size());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}