# Exercise 6.1c: Function Parameters

This exercise focuses on function parameters in C++, including pass-by-value, pass-by-reference, pass-by-pointer, and const parameters.

## Learning Objectives

- Use pass-by-value parameters for copying data
- Apply pass-by-reference parameters for modifying original variables
- Implement pass-by-pointer parameters for flexible memory access
- Work with const parameters for safety and efficiency
- Understand parameter passing efficiency considerations

## Files

- [src/function_parameters_exercises.cpp](src/function_parameters_exercises.cpp) - Exercise template with TODO comments
- [src/function_parameters_solutions.cpp](src/function_parameters_solutions.cpp) - Complete solution implementation
- [test/test_function_parameters_basics.cpp](test/test_function_parameters_basics.cpp) - Basic unit tests
- [test/test_function_parameters_practice.cpp](test/test_function_parameters_practice.cpp) - Additional practice tests

## Building and Running

1. Build the exercise:
   ```bash
   ./build.sh
   ```

2. Run the tests:
   ```bash
   ./run_tests.sh
   ```

## Key Concepts Covered

### Pass-by-Value
- Syntax: `void function(int value)`
- Copies the argument value to the parameter
- Modifications to parameter don't affect original argument
- Suitable for small, simple data types

### Pass-by-Reference
- Syntax: `void function(int& ref)`
- Parameter refers directly to the original argument
- Modifications to parameter affect original argument
- No copying overhead, but changes original data

### Pass-by-Pointer
- Syntax: `void function(int* ptr)`
- Parameter receives the address of the argument
- Must dereference pointer to access value
- Can be null, requires null checking
- Arrays decay to pointers when passed to functions

### Const Parameters
- Syntax: `void function(const Type& param)`
- Prevents modification of parameter
- Enables compiler optimizations
- Essential for reference parameters that shouldn't modify data
- Important for efficiency with large objects

## Practice Exercises

1. Compare performance of different parameter passing methods
2. Work with const correctness in function interfaces
3. Handle null pointers safely in pointer parameters
4. Understand array parameter decay to pointers