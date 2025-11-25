#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

// TODO: Work with basic lambda expressions
// Example approach:
// 1. Create simple lambda expressions with no capture
// 2. Use lambdas with parameters
// 3. Specify return types when necessary

void basic_lambda_exercises() {
    std::cout << "=== Basic Lambda Exercises ===" << std::endl;
    
    // TODO 1: Create a simple lambda with no parameters
    // - Define a lambda that prints a message
    // - Call the lambda
    
    // TODO 2: Create a lambda with parameters
    // - Define a lambda that takes two integers and returns their sum
    // - Call the lambda with different values
    
    // TODO 3: Specify return types explicitly
    // - Create a lambda that needs an explicit return type
    // - Use the -> syntax to specify the return type
}

// TODO: Work with different capture modes
// Example approach:
// 1. Capture by value [=]
// 2. Capture by reference [&]
// 3. Capture specific variables [var]
// 4. Mixed capture modes [&, var] and [=, &var]

void capture_mode_exercises() {
    std::cout << "\n=== Capture Mode Exercises ===" << std::endl;
    
    int x = 10;
    int y = 20;
    
    // TODO 1: Capture by value [=]
    // - Create a lambda that captures all variables by value
    // - Modify the captured variables inside the lambda
    // - Observe that the original variables are unchanged
    
    // TODO 2: Capture by reference [&]
    // - Create a lambda that captures all variables by reference
    // - Modify the captured variables inside the lambda
    // - Observe that the original variables are changed
    
    // TODO 3: Capture specific variables
    // - Create a lambda that captures only specific variables
    // - Use [x] to capture only x by value
    // - Use [&y] to capture only y by reference
    
    // TODO 4: Mixed capture modes
    // - Create a lambda that captures most variables by value but some by reference: [=, &y]
    // - Create a lambda that captures most variables by reference but some by value: [&, x]
}

// TODO: Work with lambda expressions and STL algorithms
// Example approach:
// 1. Use lambdas with std::find_if
// 2. Use lambdas with std::transform
// 3. Use lambdas with std::sort
// 4. Use lambdas with std::for_each

void stl_algorithm_exercises() {
    std::cout << "\n=== STL Algorithm Exercises ===" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // TODO 1: Use lambda with std::find_if
    // - Find the first even number in the vector
    // - Use a lambda as the predicate
    
    // TODO 2: Use lambda with std::transform
    // - Square each element in the vector
    // - Store results in another vector
    
    // TODO 3: Use lambda with std::sort
    // - Sort a vector of strings by length
    // - Use a lambda as the comparison function
    
    // TODO 4: Use lambda with std::for_each
    // - Print each element in the vector
    // - Use a lambda to perform the printing
}

// TODO: Work with std::function to store callable objects
// Example approach:
// 1. Store lambda expressions in std::function
// 2. Store function pointers in std::function
// 3. Store callable objects in std::function
// 4. Use std::function as function parameters

void std_function_exercises() {
    std::cout << "\n=== std::function Exercises ===" << std::endl;
    
    // TODO 1: Store lambda expressions in std::function
    // - Create a lambda expression
    // - Store it in a std::function variable
    // - Call the std::function
    
    // TODO 2: Store function pointers in std::function
    // - Create a regular function
    // - Store its pointer in a std::function variable
    // - Call the std::function
    
    // TODO 3: Create a function that takes std::function parameters
    // - Define a function that accepts std::function parameters
    // - Call this function with different callable objects
    
    // TODO 4: Work with std::function in containers
    // - Create a vector of std::function objects
    // - Store different lambdas in the vector
    // - Call each function in the vector
}

int main() {
    std::cout << "Chapter 20.1: Lambda Expressions Basics Exercise" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    basic_lambda_exercises();
    capture_mode_exercises();
    stl_algorithm_exercises();
    std_function_exercises();
    
    std::cout << "\nExercise completed!" << std::endl;
    return 0;
}