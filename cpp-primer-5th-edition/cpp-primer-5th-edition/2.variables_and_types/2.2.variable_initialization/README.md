# Exercise 2.1b: Variable Initialization

This exercise focuses on different methods of variable initialization in C++, including copy initialization, direct initialization, list initialization, and default initialization.

## Learning Objectives

- Use copy initialization with the = syntax
- Apply direct initialization with parentheses syntax
- Implement list initialization with brace syntax (C++11)
- Understand default initialization behavior
- Recognize narrowing conversions and prevention

## Files

- [src/variable_initialization_exercises.cpp](src/variable_initialization_exercises.cpp) - Exercise template with TODO comments
- [src/variable_initialization_solutions.cpp](src/variable_initialization_solutions.cpp) - Complete solution implementation
- [test/test_variable_initialization_basics.cpp](test/test_variable_initialization_basics.cpp) - Basic unit tests
- [test/test_variable_initialization_practice.cpp](test/test_variable_initialization_practice.cpp) - Additional practice tests

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

### Copy Initialization
- Syntax: `Type variable = value;`
- Uses copy constructor or assignment operator
- Common for simple value assignments

### Direct Initialization
- Syntax: `Type variable(value);`
- Uses constructors directly
- More explicit about initialization method

### List Initialization (C++11)
- Syntax: `Type variable{value};` or `Type variable = {value};`
- Uniform initialization syntax
- Prevents narrowing conversions
- Works with containers and aggregates

### Default Initialization
- Built-in types: uninitialized (contains garbage)
- Class types: initialized using default constructor
- Important to understand undefined behavior

## Practice Exercises

1. Compare different initialization methods with various data types
2. Work with narrowing conversion prevention in list initialization
3. Practice aggregate initialization with arrays and structs
4. Test default initialization behavior with different types