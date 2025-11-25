# Exercise: Destructors Basics

This exercise focuses on class destructors in C++, including basic destructors, resource management, destructor order, and exception safety.

## Learning Objectives

- Understand and implement basic destructors
- Work with resource management in destructors
- Understand destructor order in inheritance hierarchies
- Learn about exception safety in destructors
- Apply the Rule of Three for proper resource management

## Files

- [src/destructors_basics_exercises.cpp](src/destructors_basics_exercises.cpp) - Exercise template with TODO comments
- [src/destructors_basics_solutions.cpp](src/destructors_basics_solutions.cpp) - Complete solution implementation
- [test/test_destructors_basics.cpp](test/test_destructors_basics.cpp) - Basic unit tests
- [test/test_destructors_practice.cpp](test/test_destructors_practice.cpp) - Additional practice tests

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

### Basic Destructors
- Automatically generated if not explicitly defined
- Called when objects go out of scope or are deleted
- Used for cleanup operations

### Resource Management
- Properly clean up dynamically allocated memory
- Follow the Rule of Three (destructor, copy constructor, copy assignment)
- Prevent memory leaks and resource leaks

### Destructor Order
- Destructors called in reverse order of construction
- In inheritance: derived class destructor called before base class destructor
- Importance of virtual destructors in polymorphic hierarchies

### Exception Safety
- Destructors should never throw exceptions
- Handle potential errors in cleanup code gracefully
- Ensure program stability during stack unwinding

## Practice Exercises

1. Implement classes with proper resource management and destructors
2. Work with inheritance hierarchies and virtual destructors
3. Test destructor order with complex object relationships
4. Create exception-safe destructors for robust code