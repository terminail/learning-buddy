#include <gtest/gtest.h>

// Global variable for testing
int globalTestVar = 100;

// Test global scope
TEST(ScopeAndLifetimeTest, GlobalScope) {
    EXPECT_EQ(100, globalTestVar);
    
    // Modify global variable
    globalTestVar = 200;
    EXPECT_EQ(200, globalTestVar);
}

// Function with static variable for testing
int getStaticValue() {
    static int staticVar = 0;
    staticVar++;
    return staticVar;
}

// Test static variables
TEST(ScopeAndLifetimeTest, StaticVariables) {
    EXPECT_EQ(1, getStaticValue());  // First call
    EXPECT_EQ(2, getStaticValue());  // Second call
    EXPECT_EQ(3, getStaticValue());  // Third call
    
    // Static variable persists between function calls
}

// Test block scope
TEST(ScopeAndLifetimeTest, BlockScope) {
    int outerVar = 10;
    EXPECT_EQ(10, outerVar);
    
    {
        int innerVar = 20;
        EXPECT_EQ(20, innerVar);
        EXPECT_EQ(10, outerVar);  // Outer variable still accessible
        
        // Shadowing
        int outerVar = 30;
        EXPECT_EQ(30, outerVar);  // Refers to inner outerVar
    }
    
    // innerVar is out of scope here
    EXPECT_EQ(10, outerVar);  // Original outerVar
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}