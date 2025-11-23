# Exercise: Constructors Basics

This exercise focuses on class constructors in C++, including default constructors, parameterized constructors, constructor initializer lists, and copy constructors.

## Learning Objectives

- Understand and implement default constructors
- Work with parameterized constructors and constructor overloading
- Use constructor initializer lists for efficient initialization
- Implement and understand copy constructors
- Distinguish between initialization and assignment

## Files

- [src/constructors_basics_exercises.cpp](src/constructors_basics_exercises.cpp) - Exercise template with TODO comments
- [src/constructors_basics_solutions.cpp](src/constructors_basics_solutions.cpp) - Complete solution implementation
- [test/test_constructors_basics.cpp](test/test_constructors_basics.cpp) - Basic unit tests
- [test/test_constructors_practice.cpp](test/test_constructors_practice.cpp) - Additional practice tests

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

### Default Constructors
- Automatically generated if no constructors are defined
- Can be explicitly defined for custom initialization
- Called when objects are created without arguments

### Parameterized Constructors
- Constructors that take parameters for initialization
- Support constructor overloading
- Enable flexible object creation

### Constructor Initializer Lists
- More efficient than assignment in constructor body
- Required for const and reference members
- Syntax: Constructor(params) : member1(value1), member2(value2) { }

### Copy Constructors
- Special constructor for creating objects from existing objects
- Automatically called in specific situations
- Important for proper resource management

## Practice Exercises

1. Implement classes with multiple constructor overloads
2. Work with constructor initializer lists for complex member initialization
3. Create copy constructors for classes with dynamically allocated resources
4. Understand when different constructors are automatically called