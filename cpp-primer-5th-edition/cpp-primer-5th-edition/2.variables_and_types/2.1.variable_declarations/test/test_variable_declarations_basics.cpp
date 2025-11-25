#include <gtest/gtest.h>

// Test basic variable declarations
TEST(VariableDeclarationsTest, BasicTypes) {
    // Integer types
    int intVar = 42;
    short shortVar = 1000;
    long longVar = 1000000L;
    long long longLongVar = 10000000000LL;
    
    EXPECT_EQ(42, intVar);
    EXPECT_EQ(1000, shortVar);
    EXPECT_EQ(1000000L, longVar);
    EXPECT_EQ(10000000000LL, longLongVar);
    
    // Floating-point types
    float floatVar = 3.14f;
    double doubleVar = 3.14159;
    long double longDoubleVar = 3.141592653589793238L;
    
    EXPECT_FLOAT_EQ(3.14f, floatVar);
    EXPECT_DOUBLE_EQ(3.14159, doubleVar);
    
    // Character types
    char charVar = 'A';
    wchar_t wideCharVar = L'Z';
    
    EXPECT_EQ('A', charVar);
    EXPECT_EQ(L'Z', wideCharVar);
    
    // Boolean type
    bool boolVar = true;
    
    EXPECT_TRUE(boolVar);
    EXPECT_FALSE(!boolVar);
}

// Test variable scope
TEST(VariableDeclarationsTest, VariableScope) {
    int outerVar = 100;
    EXPECT_EQ(100, outerVar);
    
    {
        int innerVar = 200;
        EXPECT_EQ(200, innerVar);
        EXPECT_EQ(100, outerVar);  // Outer variable still accessible
        
        // Shadowing outer variable
        int outerVar = 300;  // This shadows the outer outerVar
        EXPECT_EQ(300, outerVar);  // Refers to inner outerVar
    }
    
    // innerVar is out of scope here
    EXPECT_EQ(100, outerVar);  // Original outerVar
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}