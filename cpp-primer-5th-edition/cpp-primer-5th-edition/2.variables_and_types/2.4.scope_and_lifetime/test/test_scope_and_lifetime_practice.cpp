#include <gtest/gtest.h>

// Practice test for variable lifetime
TEST(ScopeAndLifetimePractice, VariableLifetime) {
    // Test that local variables are destroyed when out of scope
    int* ptr = nullptr;
    
    {
        int localVar = 42;
        ptr = &localVar;
        EXPECT_EQ(42, *ptr);
    }
    
    // localVar is destroyed here, ptr points to invalid memory
    // We cannot safely test the value, but we can demonstrate the concept
    // In practice, accessing *ptr here would be undefined behavior
}

// Practice test for nested scopes
TEST(ScopeAndLifetimePractice, NestedScopes) {
    int level1 = 1;
    
    {
        int level2 = 2;
        EXPECT_EQ(1, level1);  // Level 1 accessible
        EXPECT_EQ(2, level2);  // Level 2 accessible
        
        {
            int level3 = 3;
            EXPECT_EQ(1, level1);  // Level 1 accessible
            EXPECT_EQ(2, level2);  // Level 2 accessible
            EXPECT_EQ(3, level3);  // Level 3 accessible
            
            // Shadowing at different levels
            int level1 = 100;  // Shadows level1 from outer scope
            EXPECT_EQ(100, level1);  // Refers to inner level1
        }
        
        // level3 is out of scope
        // level2 still accessible
        EXPECT_EQ(2, level2);
        // level1 refers to the original variable
        EXPECT_EQ(1, level1);
    }
    
    // Only level1 accessible here
    EXPECT_EQ(1, level1);
}

// Practice test for static variable persistence
TEST(ScopeAndLifetimePractice, StaticVariablePersistence) {
    // Lambda function with static variable
    auto counter = []() -> int {
        static int count = 0;
        return ++count;
    };
    
    EXPECT_EQ(1, counter());  // First call
    EXPECT_EQ(2, counter());  // Second call
    EXPECT_EQ(3, counter());  // Third call
    
    // The static variable persists across lambda calls
}

// Practice test for scope resolution
TEST(ScopeAndLifetimePractice, ScopeResolution) {
    int variable = 100;
    
    {
        int variable = 200;  // Shadows outer variable
        EXPECT_EQ(200, variable);  // Refers to inner variable
        
        // Access outer variable using scope resolution (not applicable for local variables)
        // But we can demonstrate the concept with a different approach
        int& outerRef = *([]() -> int* { 
            static int outerVar = 100; 
            return &outerVar; 
        }());
        
        EXPECT_EQ(100, outerRef);  // Access "outer" variable
        EXPECT_EQ(200, variable);   // Local variable unchanged
    }
    
    // Back to outer scope
    EXPECT_EQ(100, variable);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}