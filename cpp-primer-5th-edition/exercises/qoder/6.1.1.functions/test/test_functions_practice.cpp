#include <gtest/gtest.h>
#include <iostream>
#include <string>

// Practice problems for functions

class FunctionsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: FUNCTION PARAMETERS ==========

/**
 * Practice Problem 1: Practice different types of function parameters
 * 
 * Practice pass-by-value, pass-by-reference, and pass-by-const-reference.
 */
TEST_F(FunctionsPracticeTest, Practice1_FunctionParameters) {
    // TODO: Practice different parameter passing methods
    // Example: void func(int value), void func(int& ref), void func(const int& cref)
    
    SUCCEED() << "Implement function parameters practice problem";
}

// ========== PRACTICE PROBLEM 2: RETURN VALUES ==========

/**
 * Practice Problem 2: Practice different types of return values
 * 
 * Practice functions that return different data types and structures.
 */
TEST_F(FunctionsPracticeTest, Practice2_ReturnValues) {
    // TODO: Practice different return value types
    // Example: int func(), std::string func(), bool func(), void func()
    
    SUCCEED() << "Implement return values practice problem";
}

// ========== PRACTICE PROBLEM 3: FUNCTION OVERLOADING ==========

/**
 * Practice Problem 3: Practice function overloading
 * 
 * Create multiple functions with the same name but different parameters.
 */
TEST_F(FunctionsPracticeTest, Practice3_FunctionOverloading) {
    // TODO: Practice function overloading
    // Example: int add(int a, int b), double add(double a, double b)
    
    SUCCEED() << "Implement function overloading practice problem";
}

// ========== PRACTICE PROBLEM 4: DEFAULT PARAMETERS ==========

/**
 * Practice Problem 4: Practice functions with default parameters
 * 
 * Create functions that have default values for some parameters.
 */
TEST_F(FunctionsPracticeTest, Practice4_DefaultParameters) {
    // TODO: Practice default parameters
    // Example: void func(int a, int b = 10, int c = 20)
    
    SUCCEED() << "Implement default parameters practice problem";
}

// ========== PRACTICE PROBLEM 5: INLINE FUNCTIONS ==========

/**
 * Practice Problem 5: Practice inline functions
 * 
 * Create inline functions and understand when to use them.
 */
TEST_F(FunctionsPracticeTest, Practice5_InlineFunctions) {
    // TODO: Practice inline functions
    // Example: inline int func(int x) { return x * x; }
    
    SUCCEED() << "Implement inline functions practice problem";
}

// ========== PRACTICE PROBLEM 6: RECURSIVE FUNCTIONS ==========

/**
 * Practice Problem 6: Practice recursive functions
 * 
 * Create recursive functions to solve problems like factorial or Fibonacci.
 */
TEST_F(FunctionsPracticeTest, Practice6_RecursiveFunctions) {
    // TODO: Practice recursive functions
    // Example: int factorial(int n), int fibonacci(int n)
    
    SUCCEED() << "Implement recursive functions practice problem";
}

// ========== PRACTICE PROBLEM 7: LAMBDA FUNCTIONS ==========

/**
 * Practice Problem 7: Practice lambda functions
 * 
 * Create and use lambda functions for simple operations.
 */
TEST_F(FunctionsPracticeTest, Practice7_LambdaFunctions) {
    // TODO: Practice lambda functions
    // Example: auto lambda = [](int x) { return x * 2; }
    
    SUCCEED() << "Implement lambda functions practice problem";
}

// ========== PRACTICE PROBLEM 8: FUNCTION POINTERS ==========

/**
 * Practice Problem 8: Practice function pointers
 * 
 * Create and use function pointers to call functions dynamically.
 */
TEST_F(FunctionsPracticeTest, Practice8_FunctionPointers) {
    // TODO: Practice function pointers
    // Example: int (*func_ptr)(int, int) = add;
    
    SUCCEED() << "Implement function pointers practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}