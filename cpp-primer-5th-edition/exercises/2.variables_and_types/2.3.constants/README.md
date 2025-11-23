# Exercise 2.1c: Constants

This exercise focuses on constants and constexpr in C++, including const variables, constexpr variables, literal constants, and the difference between const and constexpr.

## Learning Objectives

- Use const variables for runtime constants
- Apply constexpr variables for compile-time constants
- Work with literal constants and their suffixes
- Understand the difference between const and constexpr
- Recognize when each type of constant is appropriate

## Files

- [src/constants_exercises.cpp](src/constants_exercises.cpp) - Exercise template with TODO comments
- [src/constants_solutions.cpp](src/constants_solutions.cpp) - Complete solution implementation
- [test/test_constants_basics.cpp](test/test_constants_basics.cpp) - Basic unit tests
- [test/test_constants_practice.cpp](test/test_constants_practice.cpp) - Additional practice tests

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

### Const Variables
- Syntax: `const Type variable = value;`
- Must be initialized at declaration
- Cannot be modified after initialization
- Value can be determined at runtime

### Constexpr Variables
- Syntax: `constexpr Type variable = value;`
- Must be initialized with compile-time constants
- Evaluated at compile time
- Can be used in contexts requiring compile-time constants

### Literal Constants
- Integer literals: 42, 1000000L, 10000000000LL
- Floating-point literals: 3.14, 3.14f, 3.14L
- Character literals: 'A', 'Z'
- String literals: "Hello", "World"

### Const vs Constexpr
- **Const**: Runtime constants, value determined at runtime
- **Constexpr**: Compile-time constants, value must be known at compile time
- Both prevent modification after initialization
- Constexpr can be used where compile-time constants are required

## Practice Exercises

1. Experiment with constexpr functions and their compile-time evaluation
2. Work with different literal suffixes and their type implications
3. Compare const and constexpr with runtime vs compile-time initialization
4. Use constexpr for array sizes and template parameters