# Chapter 14: Overloaded Operations and Conversions

This directory contains exercises for learning about overloaded operations and conversions in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on operator overloading and type conversions. Students will learn how to define overloaded operators for their classes and understand conversion operators and constructors.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Arithmetic Operators](arithmetic_operators/)** - Overloading arithmetic operators (+, -, *, /)
2. **[Comparison Operators](comparison_operators/)** - Overloading comparison operators (==, !=, <, >, <=, >=)
3. **[IO Operators](io_operators/)** - Overloading input and output operators (<<, >>)

## Learning Objectives

By completing these exercises, students will understand:
- How to overload arithmetic operators for custom classes
- How to overload comparison operators for object comparison
- How to overload IO operators for object input and output
- When to define operators as member functions vs non-member functions
- How to define friend functions for operator overloading
- Best practices for operator overloading
- Type conversions and conversion operators

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Classes and objects
- Constructors and destructors
- Function overloading
- Basic understanding of operators

## Building and Testing

Each exercise can be built and tested using the provided shell scripts:

```bash
# Navigate to any exercise directory
cd exercise_name

# Build the exercise
./build.sh

# Run the exercise solution
./build/exercise_name_solutions

# Run tests
./run_tests.sh
```

Note: These exercises are designed to run in a Linux/Docker environment. Windows batch files are not provided.