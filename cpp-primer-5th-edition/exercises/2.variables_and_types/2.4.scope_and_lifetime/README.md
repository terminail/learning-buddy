# Exercise 2.1d: Scope and Lifetime

This exercise focuses on variable scope and lifetime in C++, including global scope, local scope, block scope, and static variables.

## Learning Objectives

- Work with global scope variables and their lifetime
- Understand local scope variables and their accessibility
- Implement block scope with nested scopes and variable shadowing
- Use static variables for persistence across function calls
- Recognize variable lifetime and memory management

## Files

- [src/scope_and_lifetime_exercises.cpp](src/scope_and_lifetime_exercises.cpp) - Exercise template with TODO comments
- [src/scope_and_lifetime_solutions.cpp](src/scope_and_lifetime_solutions.cpp) - Complete solution implementation
- [test/test_scope_and_lifetime_basics.cpp](test/test_scope_and_lifetime_basics.cpp) - Basic unit tests
- [test/test_scope_and_lifetime_practice.cpp](test/test_scope_and_lifetime_practice.cpp) - Additional practice tests

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

### Global Scope
- Variables declared outside functions
- Lifetime: Entire program execution
- Accessibility: From any function (with proper declarations)
- Memory: Stored in data segment

### Local Scope
- Variables declared inside functions
- Lifetime: Function execution duration
- Accessibility: Only within the function
- Memory: Stored on stack

### Block Scope
- Variables declared inside blocks ({} braces)
- Lifetime: Block execution duration
- Accessibility: Only within the block
- Variable shadowing: Inner scope variables can hide outer scope variables

### Static Variables
- Variables with static storage duration
- Lifetime: Entire program execution
- Initialization: Only once, first time control passes through declaration
- Persistence: Retains value between function calls

## Practice Exercises

1. Experiment with nested scopes and variable shadowing
2. Test static variable behavior across multiple function calls
3. Work with global variables and their modification
4. Observe undefined behavior with accessing destroyed local variables