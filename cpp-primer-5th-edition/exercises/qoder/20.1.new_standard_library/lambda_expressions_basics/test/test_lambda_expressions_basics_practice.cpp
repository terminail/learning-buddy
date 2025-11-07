#include <gtest/gtest.h>
#include <functional>
#include <vector>
#include <algorithm>

// Practice test for lambda expressions - students need to implement these
TEST(LambdaExpressionsBasicsPracticeTest, GenericLambdas) {
    // TODO: Create tests for generic lambdas (C++14 feature)
    // - Create a generic lambda that works with different types
    // - Test with various data types (int, double, string)
    // - Demonstrate auto parameters in lambda expressions
    
    // Example:
    // auto generic_lambda = [](auto a, auto b) {
    //     return a + b;
    // };
    // generic_lambda(1, 2);      // Works with integers
    // generic_lambda(1.5, 2.5);  // Works with doubles
    // generic_lambda("Hello", "World"); // Works with strings (concatenation)
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(LambdaExpressionsBasicsPracticeTest, MutableLambdas) {
    // TODO: Create tests for mutable lambdas
    // - Create a lambda with the mutable keyword
    // - Show how it can modify captured values
    // - Demonstrate the difference between mutable and non-mutable lambdas
    
    // Example:
    // int x = 10;
    // auto mutable_lambda = [x]() mutable {
    //     x += 5;  // This modifies the captured copy
    //     return x;
    // };
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(LambdaExpressionsBasicsPracticeTest, RecursiveLambdas) {
    // TODO: Create tests for recursive lambdas
    // - Show how to create a recursive lambda using std::function
    // - Implement a recursive algorithm (e.g., factorial, Fibonacci)
    // - Demonstrate the Y combinator pattern
    
    // Example:
    // std::function<int(int)> factorial = [&factorial](int n) -> int {
    //     return (n <= 1) ? 1 : n * factorial(n - 1);
    // };
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(LambdaExpressionsBasicsPracticeTest, PerformanceComparison) {
    // TODO: Create tests that compare performance of different callable objects
    // - Compare regular functions, function pointers, lambdas, and std::function
    // - Measure execution time for each approach
    // - Test with simple operations and complex operations
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(LambdaExpressionsBasicsPracticeTest, ClosureLifetime) {
    // TODO: Create tests that demonstrate closure object lifetime
    // - Create lambdas that capture variables
    // - Store lambdas in containers
    // - Demonstrate when captured variables are destroyed
    
    SUCCEED(); // Placeholder - replace with actual tests
}