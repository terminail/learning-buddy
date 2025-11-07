# Exercise 6.1.1: Functions - Implementation Guide

This guide provides detailed instructions for implementing the functions exercise.

## Exercise Overview

This exercise focuses on C++ functions including declaration, definition, and usage. Students will learn how to create reusable code blocks that perform specific tasks.

## Learning Objectives

By completing this exercise, students will be able to:
- Declare and define functions with proper signatures
- Use function parameters and return values effectively
- Understand the difference between pass-by-value and pass-by-reference
- Create functions with different combinations of parameters and return types
- Use function prototypes to enable forward declarations

## Detailed Implementation Steps

### Step 1: Understanding Function Declaration

Function declarations (prototypes) tell the compiler about a function's name, return type, and parameters:

```cpp
// Function prototype
return_type function_name(parameter_type parameter_name);
```

Example:
```cpp
int add(int a, int b);
void print_message(const std::string& message);
double calculate_area(double radius);
```

### Step 2: Understanding Function Definition

Function definitions provide the actual implementation of the function:

```cpp
return_type function_name(parameter_list) {
    // Function body
    // Code to execute
    return value;  // If return_type is not void
}
```

Example:
```cpp
int add(int a, int b) {
    return a + b;
}

void print_message(const std::string& message) {
    std::cout << message << std::endl;
}
```

### Step 3: Understanding Function Calling

To use a function, you call it with appropriate arguments:

```cpp
// Calling a function
return_type result = function_name(arguments);
```

Example:
```cpp
int sum = add(5, 3);
print_message("Hello, World!");
```

## Common Mistakes and Tips

### Common Mistakes:
1. Forgetting to declare function prototypes when defining functions after main()
2. Mismatching function signatures between declaration and definition
3. Forgetting to return a value in non-void functions
4. Not handling parameter passing correctly (value vs reference)
5. Using undefined functions (forgetting to define them)

### Tips:
1. Always declare function prototypes before using them
2. Match function signatures exactly between declaration and definition
3. Use const references for large objects to avoid copying
4. Use meaningful function and parameter names
5. Keep functions focused on a single task

## Exercise Requirements

Complete the TODO comments in [functions_exercises.cpp](src/functions_exercises.cpp):

1. Declare function prototypes for several functions
2. Define those functions with appropriate implementations
3. Call your functions from the main() function
4. Test with user input where appropriate

## Solution Verification

To verify your solution:

1. Compile the exercise:
   ```bash
   g++ -std=c++17 src/functions_exercises.cpp -o functions_exercise
   ```

2. Run the executable and test with various inputs:
   ```bash
   ./functions_exercise
   ```

3. Compare your output with the reference solution in [functions_solutions.cpp](src/functions_solutions.cpp)

## Advanced Challenges

For students who want additional practice:

1. Implement function overloading with different parameter types
2. Create recursive functions to solve problems like factorial
3. Use default parameters in function declarations
4. Practice pass-by-reference vs pass-by-value with different data types

## Parameter Passing Methods

### Pass-by-Value
```cpp
void func(int value) {
    // Changes to 'value' don't affect the original variable
}
```

### Pass-by-Reference
```cpp
void func(int& ref) {
    // Changes to 'ref' affect the original variable
}
```

### Pass-by-Const-Reference
```cpp
void func(const int& cref) {
    // Can read 'cref' but cannot modify it
    // More efficient than pass-by-value for large objects
}
```

## Testing

Run the provided tests to verify your implementation:

```bash
mkdir build
cd build
cmake ..
make
./test_functions_basics
./test_functions_practice
```

## Next Exercise

After completing this exercise, proceed to learn about arrays and strings, which will build upon your understanding of functions.