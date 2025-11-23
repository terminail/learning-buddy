# Exercise 6.1d: Function Overloading

This exercise focuses on function overloading in C++, including overloaded functions with different parameter counts, types, and orders, as well as overload resolution.

## Learning Objectives

- Create overloaded functions with different parameter counts
- Implement overloaded functions with different parameter types
- Work with overloaded functions with different parameter orders
- Understand overload resolution and ambiguity resolution
- Apply function overloading for intuitive interfaces

## Files

- [src/function_overloading_exercises.cpp](src/function_overloading_exercises.cpp) - Exercise template with TODO comments
- [src/function_overloading_solutions.cpp](src/function_overloading_solutions.cpp) - Complete solution implementation
- [test/test_function_overloading_basics.cpp](test/test_function_overloading_basics.cpp) - Basic unit tests
- [test/test_function_overloading_practice.cpp](test/test_function_overloading_practice.cpp) - Additional practice tests

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

### Overloading by Parameter Count
- Functions with the same name but different number of parameters
- Compiler selects overload based on argument count
- Enables intuitive function interfaces

### Overloading by Parameter Types
- Functions with the same name but different parameter types
- Type matching in overload resolution
- Works with built-in and user-defined types

### Overloading by Parameter Order
- Functions with the same name but different parameter orders
- Parameter order matters in overload resolution
- Enables flexible function interfaces

### Overload Resolution
- **Exact Match**: No conversion required
- **Promotion**: Integral and floating-point promotions
- **Conversion**: Standard and user-defined conversions
- **Ambiguity**: When no best match can be determined

## Practice Exercises

1. Experiment with complex overload resolution scenarios
2. Work with user-defined types in function overloading
3. Test const overloading for member functions
4. Resolve ambiguity with explicit casting and careful design