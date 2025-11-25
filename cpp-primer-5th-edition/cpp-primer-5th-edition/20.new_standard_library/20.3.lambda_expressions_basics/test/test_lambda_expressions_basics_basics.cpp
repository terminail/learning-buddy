#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

// Basic test for lambda expressions
TEST(LambdaExpressionsBasicsTest, BasicLambdaExpressions) {
    // Test simple lambda with no parameters
    auto simple_lambda = []() { return 42; };
    EXPECT_EQ(simple_lambda(), 42);
    
    // Test lambda with parameters
    auto add_lambda = [](int a, int b) { return a + b; };
    EXPECT_EQ(add_lambda(5, 3), 8);
    EXPECT_EQ(add_lambda(-1, 1), 0);
    
    // Test lambda with explicit return type
    auto divide_lambda = [](int a, int b) -> double {
        if (b != 0) {
            return static_cast<double>(a) / b;
        }
        return 0.0;
    };
    EXPECT_DOUBLE_EQ(divide_lambda(10, 3), 10.0/3.0);
    EXPECT_DOUBLE_EQ(divide_lambda(7, 0), 0.0);
}

// Basic test for capture modes
TEST(LambdaExpressionsBasicsTest, CaptureModes) {
    int x = 10;
    int y = 20;
    
    // Test capture by value
    auto capture_by_value = [=]() {
        return x + y;  // x and y are captured by value
    };
    EXPECT_EQ(capture_by_value(), 30);
    
    // Modify original variables
    x = 15;
    y = 25;
    
    // Captured values should remain unchanged
    EXPECT_EQ(capture_by_value(), 30);  // Still uses original captured values
    
    // Test capture by reference
    auto capture_by_reference = [&]() {
        return x + y;  // x and y are captured by reference
    };
    EXPECT_EQ(capture_by_reference(), 40);  // Uses current values
    
    // Test specific variable capture
    auto capture_specific = [x, &y]() {
        return x + y;  // x by value, y by reference
    };
    
    x = 100;  // Change x
    y = 200;  // Change y
    EXPECT_EQ(capture_specific(), 215);  // x=15 (captured by value), y=200 (captured by reference)
}

// Basic test for STL algorithms with lambdas
TEST(LambdaExpressionsBasicsTest, STLAlgorithmsWithLambdas) {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test std::find_if with lambda
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 5 && n % 2 == 0;
    });
    ASSERT_NE(it, numbers.end());
    EXPECT_EQ(*it, 6);
    
    // Test std::transform with lambda
    std::vector<int> squares;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squares),
                   [](int n) { return n * n; });
    EXPECT_EQ(squares.size(), numbers.size());
    EXPECT_EQ(squares[0], 1);
    EXPECT_EQ(squares[1], 4);
    EXPECT_EQ(squares[9], 100);
    
    // Test std::sort with lambda
    std::vector<std::string> words = {"apple", "pie", "cherry", "banana"};
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
    EXPECT_EQ(words[0], "pie");
    EXPECT_EQ(words[3], "banana");
}

// Basic test for std::function
TEST(LambdaExpressionsBasicsTest, StdFunction) {
    // Test storing lambda in std::function
    std::function<int(int, int)> add_func = [](int a, int b) { return a + b; };
    EXPECT_EQ(add_func(5, 3), 8);
    
    // Test storing function pointer in std::function
    int (*multiply_ptr)(int, int) = [](int a, int b) { return a * b; };
    std::function<int(int, int)> multiply_func = multiply_ptr;
    EXPECT_EQ(multiply_func(5, 3), 15);
    
    // Test storing different callable objects in std::function
    std::function<int(int)> operations[] = {
        [](int x) { return x * 2; },
        [](int x) { return x + 10; },
        [](int x) { return x * x; }
    };
    
    EXPECT_EQ(operations[0](5), 10);
    EXPECT_EQ(operations[1](5), 15);
    EXPECT_EQ(operations[2](5), 25);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}