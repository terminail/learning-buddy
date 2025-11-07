#include <gtest/gtest.h>
#include "scopes_exercises.h"

using namespace cpp_primer;

class ScopesTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(ScopesTest, DefaultConstructor) {
    Scopes exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== SCOPE BEHAVIOR TESTS ==========

TEST_F(ScopesTest, DemonstrateBlockScope) {
    Scopes exercise;
    int result = exercise.demonstrate_block_scope();
    
    // Verify that the function demonstrates block scope correctly
    EXPECT_NE(result, 0) << "Expected a non-zero value from block scope";
    EXPECT_EQ(result, 42) << "Expected 42 as example block scope value";
}

TEST_F(ScopesTest, DemonstrateNestedScopes) {
    Scopes exercise;
    int result = exercise.demonstrate_nested_scopes();
    
    // Verify that the function demonstrates nested scopes correctly
    EXPECT_EQ(result, 30) << "Expected sum of outer (10) and inner (20) variables";
}

TEST_F(ScopesTest, DemonstrateVariableShadowing) {
    Scopes exercise;
    int result = exercise.demonstrate_variable_shadowing();
    
    // Verify that the function demonstrates variable shadowing correctly
    EXPECT_EQ(result, 200) << "Expected inner variable value (200) due to shadowing";
}

// ========== GLOBAL VARIABLE TESTS ==========

TEST_F(ScopesTest, AccessGlobalVariable) {
    Scopes exercise;
    int result = exercise.access_global_variable();
    
    // Verify that the function accesses global variable correctly
    EXPECT_EQ(result, 500) << "Expected global variable value (500)";
}

// ========== SCOPE RESOLUTION TESTS ==========

TEST_F(ScopesTest, DemonstrateScopeResolution) {
    Scopes exercise;
    int input = 10;
    int result = exercise.demonstrate_scope_resolution(input);
    
    // Verify that the function demonstrates scope resolution correctly
    EXPECT_EQ(result, 510) << "Expected global_var (500) + input (10)";
}

// ========== FUNCTION SCOPE TESTS ==========

TEST_F(ScopesTest, DemonstrateFunctionScope) {
    Scopes exercise;
    int input = 25;
    int result = exercise.demonstrate_function_scope(input);
    
    // Verify that the function demonstrates function scope correctly
    EXPECT_EQ(result, 75) << "Expected parameter (25) + local_var (50)";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}