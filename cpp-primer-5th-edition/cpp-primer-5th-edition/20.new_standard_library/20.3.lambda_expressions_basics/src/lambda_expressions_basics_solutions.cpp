#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

// Solution: Work with basic lambda expressions
void basic_lambda_exercises() {
    std::cout << "=== Basic Lambda Exercises ===" << std::endl;
    
    // Solution 1: Create a simple lambda with no parameters
    auto simple_lambda = []() {
        std::cout << "Hello from lambda!" << std::endl;
    };
    simple_lambda();
    
    // Solution 2: Create a lambda with parameters
    auto add_lambda = [](int a, int b) -> int {
        return a + b;
    };
    std::cout << "5 + 3 = " << add_lambda(5, 3) << std::endl;
    std::cout << "10 + 20 = " << add_lambda(10, 20) << std::endl;
    
    // Solution 3: Specify return types explicitly
    auto divide_lambda = [](int a, int b) -> double {
        if (b != 0) {
            return static_cast<double>(a) / b;
        }
        return 0.0;
    };
    std::cout << "10 / 3 = " << divide_lambda(10, 3) << std::endl;
}

// Solution: Work with different capture modes
void capture_mode_exercises() {
    std::cout << "\n=== Capture Mode Exercises ===" << std::endl;
    
    int x = 10;
    int y = 20;
    
    // Solution 1: Capture by value [=]
    auto capture_by_value = [=]() {
        std::cout << "Captured by value - x: " << x << ", y: " << y << std::endl;
        // x = 15;  // This would cause a compilation error - captured by value
        // y = 25;  // This would cause a compilation error - captured by value
    };
    capture_by_value();
    std::cout << "Original values - x: " << x << ", y: " << y << std::endl;
    
    // Solution 2: Capture by reference [&]
    auto capture_by_reference = [&]() {
        std::cout << "Captured by reference - x: " << x << ", y: " << y << std::endl;
        x += 5;
        y += 5;
        std::cout << "Modified captured values - x: " << x << ", y: " << y << std::endl;
    };
    capture_by_reference();
    std::cout << "Original values after modification - x: " << x << ", y: " << y << std::endl;
    
    // Solution 3: Capture specific variables
    x = 10;
    y = 20;
    auto capture_specific = [x, &y]() {
        std::cout << "Specific capture - x: " << x << ", y: " << y << std::endl;
        // x = 15;  // This would cause a compilation error - x captured by value
        y += 10;   // y captured by reference, so this works
    };
    capture_specific();
    std::cout << "Values after specific capture - x: " << x << ", y: " << y << std::endl;
    
    // Solution 4: Mixed capture modes
    x = 10;
    y = 20;
    int z = 30;
    
    auto mixed_capture1 = [=, &y, &z]() {
        std::cout << "Mixed capture [=, &y, &z] - x: " << x << ", y: " << y << ", z: " << z << std::endl;
        // x = 15;  // Error - captured by value
        y += 5;     // OK - captured by reference
        z += 5;     // OK - captured by reference
    };
    
    auto mixed_capture2 = [&, x]() {
        std::cout << "Mixed capture [&, x] - x: " << x << ", y: " << y << ", z: " << z << std::endl;
        // x = 15;     // Error - captured by value
        y += 5;     // OK - captured by reference
        z += 5;     // OK - captured by reference
        std::cout << "After modification - x: " << x << ", y: " << y << ", z: " << z << std::endl;
    };
    
    mixed_capture1();
    mixed_capture2();
}

// Regular function for std::function exercises
int multiply(int a, int b) {
    return a * b;
}

// Solution: Work with lambda expressions and STL algorithms
void stl_algorithm_exercises() {
    std::cout << "\n=== STL Algorithm Exercises ===" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Solution 1: Use lambda with std::find_if
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    if (it != numbers.end()) {
        std::cout << "First even number: " << *it << std::endl;
    }
    
    // Solution 2: Use lambda with std::transform
    std::vector<int> squares;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squares),
                   [](int n) { return n * n; });
    std::cout << "Squares: ";
    for (const auto& n : squares) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // Solution 3: Use lambda with std::sort
    std::vector<std::string> words = {"apple", "pie", "cherry", "banana", "a"};
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
    std::cout << "Words sorted by length: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    // Solution 4: Use lambda with std::for_each
    std::cout << "Numbers: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;
}

// Solution: Work with std::function to store callable objects
void std_function_exercises() {
    std::cout << "\n=== std::function Exercises ===" << std::endl;
    
    // Solution 1: Store lambda expressions in std::function
    std::function<int(int, int)> add_func = [](int a, int b) { return a + b; };
    std::cout << "Add function result: " << add_func(5, 3) << std::endl;
    
    // Solution 2: Store function pointers in std::function
    std::function<int(int, int)> multiply_func = multiply;
    std::cout << "Multiply function result: " << multiply_func(5, 3) << std::endl;
    
    // Solution 3: Create a function that takes std::function parameters
    auto apply_operation = [](int a, int b, std::function<int(int, int)> op) {
        return op(a, b);
    };
    
    int result1 = apply_operation(10, 5, add_func);
    int result2 = apply_operation(10, 5, multiply_func);
    int result3 = apply_operation(10, 5, [](int a, int b) { return a - b; });
    
    std::cout << "Apply operation results: " << result1 << ", " << result2 << ", " << result3 << std::endl;
    
    // Solution 4: Work with std::function in containers
    std::vector<std::function<int(int)>> operations;
    operations.push_back([](int x) { return x * 2; });
    operations.push_back([](int x) { return x + 10; });
    operations.push_back([](int x) { return x * x; });
    
    int value = 5;
    std::cout << "Applying operations to " << value << ": ";
    for (const auto& op : operations) {
        std::cout << op(value) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Chapter 20.1: Lambda Expressions Basics Solution" << std::endl;
    std::cout << "==============================================" << std::endl;
    
    basic_lambda_exercises();
    capture_mode_exercises();
    stl_algorithm_exercises();
    std_function_exercises();
    
    std::cout << "\nSolution completed!" << std::endl;
    return 0;
}