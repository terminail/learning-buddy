# Exercise: Access Control

This exercise focuses on access specifiers in C++ classes, including public, private, and protected members, as well as friend functions and classes.

## Learning Objectives

- Understand and use public access specifier
- Work with private members and data encapsulation
- Learn about protected members and inheritance
- Use friend functions and classes appropriately
- Apply encapsulation principles for robust code design

## Files

- [src/access_control_exercises.cpp](src/access_control_exercises.cpp) - Exercise template with TODO comments
- [src/access_control_solutions.cpp](src/access_control_solutions.cpp) - Complete solution implementation
- [test/test_access_control_basics.cpp](test/test_access_control_basics.cpp) - Basic unit tests
- [test/test_access_control_practice.cpp](test/test_access_control_practice.cpp) - Additional practice tests

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

### Public Access
- Members accessible from anywhere
- Direct access without getter/setter functions
- Minimal encapsulation

### Private Access
- Members accessible only within the class
- Data encapsulation and information hiding
- Controlled access through public interface

### Protected Access
- Members accessible within the class and derived classes
- Enables inheritance while maintaining some encapsulation
- Bridge between private and public access

### Friend Functions and Classes
- Special functions/classes that can access private members
- Useful for operators and tightly coupled classes
- Should be used sparingly to maintain encapsulation

## Practice Exercises

1. Implement classes with proper encapsulation using private members
2. Work with inheritance and protected member access
3. Create friend functions for operator overloading
4. Design classes with appropriate access control for real-world scenarios