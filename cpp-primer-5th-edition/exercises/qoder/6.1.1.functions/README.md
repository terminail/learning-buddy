# Exercise 6.1.1: Functions

This exercise introduces you to C++ functions: declaration, definition, and usage. You'll learn how to create reusable code blocks that perform specific tasks.

## Learning Objectives

- Understand function declaration, definition, and calling
- Learn about function parameters and return values
- Practice creating functions with different signatures
- Understand the difference between pass-by-value and pass-by-reference
- Learn about function prototypes and scope

## Exercise Files

- [functions_exercises.cpp](src/functions_exercises.cpp) - Your exercise implementation
- [functions_solutions.cpp](src/functions_solutions.cpp) - Reference solution
- [test_functions_basics.cpp](test/test_functions_basics.cpp) - Basic tests
- [test_functions_practice.cpp](test/test_functions_practice.cpp) - Practice problems

## Instructions

1. Open [functions_exercises.cpp](src/functions_exercises.cpp)
2. Follow the TODO comments to declare and define functions
3. Compile and run your program to test the functions
4. Compare your solution with [functions_solutions.cpp](src/functions_solutions.cpp)

## Functions Overview

Functions are reusable blocks of code that perform specific tasks. They help organize code, reduce duplication, and make programs easier to understand.

### Function Declaration

```cpp
// Function prototype (declaration)
return_type function_name(parameter_list);
```

### Function Definition

```cpp
// Function definition
return_type function_name(parameter_list) {
    // Function body
    // Code to execute
    return value;  // If return_type is not void
}
```

### Function Calling

```cpp
// Calling a function
return_type result = function_name(arguments);
```

## Example Usage

```cpp
#include <iostream>
#include <string>

// Function declaration
int add(int a, int b);
void print_message(const std::string& message);
double calculate_area(double radius);

int main() {
    // Calling functions
    int sum = add(5, 3);
    std::cout << "Sum: " << sum << std::endl;
    
    print_message("Hello, World!");
    
    double area = calculate_area(2.5);
    std::cout << "Area: " << area << std::endl;
    
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

void print_message(const std::string& message) {
    std::cout << message << std::endl;
}

double calculate_area(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}
```

## Common Function Patterns

### 1. Simple Function with Parameters and Return Value
```cpp
int multiply(int a, int b) {
    return a * b;
}
```

### 2. Function with No Return Value (void)
```cpp
void greet(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}
```

### 3. Function with No Parameters
```cpp
void print_hello() {
    std::cout << "Hello!" << std::endl;
}
```

### 4. Function with Reference Parameters
```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

## Testing

To run the tests for this exercise:

```bash
mkdir build
cd build
cmake ..
make
./test_functions_basics
./test_functions_practice
```

## Next Steps

After completing this exercise, you should:
1. Understand how to declare, define, and call functions
2. Know how to use function parameters and return values
3. Be able to create functions with different signatures
4. Understand function scope and lifetime

Continue with the next exercise to learn about arrays and strings.

# Functions Exercises

## Overview
This directory contains a series of exercises focused on functions in C++, including basic function definition, parameters, return values, and function overloading. These exercises are designed to help you master one of the fundamental concepts in C++ programming.

## Exercises

### 1. Basic Functions ([basic_functions](basic_functions/))
Learn how to define, declare, and call simple functions.

**Key Concepts**:
- Function declaration and definition
- Function parameters and return values
- Void functions
- Function calls

## Getting Started

### Prerequisites
- C++ compiler (supporting C++17 or later)
- CMake (version 3.10 or later)
- Google Test framework (for running tests)

### Building Individual Exercises
Each exercise can be built separately:

```bash
cd basic_functions
mkdir build
cd build
cmake ..
make
```

### Building All Exercises
To build all exercises at once:

```bash
cd functions
mkdir build
cd build
cmake ..
make build_all_exercises
```

## Running Exercises

### Running Exercise Solutions
Each exercise includes a solution executable:

```bash
./basic_functions/build/basic_functions_solutions
```

### Running Tests
Each exercise includes tests to validate your implementation:

```bash
./basic_functions/build/test_basic_functions_basics
```

## Learning Path
It's recommended to complete the exercises in the following order:
1. [Basic Functions](basic_functions/) - Foundation for function understanding

## Resources
- [C++ Primer 5th Edition](https://www.amazon.com/Primer-5th-Stanley-Lippman/dp/0321714113) - The textbook these exercises accompany
- [FUNCTIONS_EXERCISES_SUMMARY.md](FUNCTIONS_EXERCISES_SUMMARY.md) - Detailed summary of all exercises
- [basic_functions/README.md](basic_functions/README.md) - Basic functions exercise documentation
