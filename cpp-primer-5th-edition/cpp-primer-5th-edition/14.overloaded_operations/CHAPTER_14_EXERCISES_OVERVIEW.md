# Chapter 14: Overloaded Operations and Conversions Exercises Overview

This directory contains exercises for Chapter 14 of C++ Primer 5th Edition, which covers overloaded operations and conversions in C++.

## Operator Overloading Types Covered

1. **Arithmetic Operators** - Mathematical operations (+, -, *, /, +=, -=, *=, /=)
2. **Comparison Operators** - Relational operations (==, !=, <, >, <=, >=)
3. **IO Operators** - Stream insertion (<<) and extraction (>>)
4. **Increment/Decrement Operators** - Prefix and postfix (++, --)
5. **Function Call Operator** - Making objects callable like functions
6. **Subscript Operator** - Array-like access ([] operator)
7. **Dereference Operators** - Pointer-like behavior (*, ->)

## Learning Objectives

By completing these exercises, students will understand:
- How to overload operators for custom classes
- The difference between member and non-member operator functions
- Best practices for implementing various types of operators
- When to implement operators as members vs friends vs non-members
- The importance of consistency in operator overloading
- How to enable objects to work with standard library algorithms and containers

## Exercise Structure

Each exercise follows the standard template structure:
- `src/` - Contains exercise and solution source files
- `test/` - Contains basic and practice test files
- `CMakeLists.txt` - Build configuration
- `README.md` - Detailed instructions and learning objectives
- `build.sh` - Build script for Linux/Docker environments
- `run_tests.sh` - Test execution script

## Exercises

### 1. Arithmetic Operators
Focuses on implementing mathematical operators:
- Addition, subtraction, multiplication, division
- Compound assignment operators
- Relationship between simple and compound operators

### 2. Comparison Operators
Covers implementing relational operators:
- Equality and inequality operators
- Ordering operators
- Best practices for deriving operators
- Consistency requirements

### 3. IO Operators
Explores stream input and output:
- Stream insertion (<<) operator
- Stream extraction (>>) operator
- Friend functions for IO
- Error handling in IO operations

## Key Concepts

### Member vs Non-Member Operators
- **Member operators**: Have access to private members, `*this` is the left operand
- **Non-member operators**: Need friend access for private members, both operands are parameters
- **Friend operators**: Non-member functions with access to private members

### Best Practices
1. **Arithmetic operators**: Implement compound assignment as member, simple operators as non-member
2. **Comparison operators**: Implement == and <, derive others
3. **IO operators**: Implement as non-member friend functions
4. **Increment/Decrement**: Implement both prefix and postfix versions

### Return Types
- **Compound assignment**: Return `MyClass&` (reference to *this)
- **Simple arithmetic**: Return `MyClass` (new object by value)
- **Comparison operators**: Return `bool`
- **Stream operators**: Return stream reference for chaining

### Const Correctness
Operators that don't modify the object should be const:
```cpp
bool operator==(const MyClass& other) const;
MyClass operator+(const MyClass& other) const;
```

## Prerequisites

Students should be familiar with:
- Basic C++ syntax and object-oriented programming
- Class constructors and destructors
- Friend functions
- Standard library streams (iostream)
- Basic understanding of operator precedence

## Building and Running

Each exercise can be built and run using the provided shell scripts:

```bash
# Build the exercise
./build.sh

# Run the exercise solution
./build/io_operators_solutions

# Run tests
./run_tests.sh
```

Note: These exercises are designed to run in a Linux/Docker environment. Windows batch files are not provided.