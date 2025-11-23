# Chapter 13: Copy Control

This directory contains exercises for learning about copy control in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on copy control including copy constructors, copy-assignment operators, and destructors. Students will learn how to properly manage resources in classes and understand the Rule of Three (now Rule of Five in C++11).

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Copy Constructor Basics](copy_constructor_basics/)** - Understanding and implementing copy constructors
2. **[Copy Assignment Basics](copy_assignment_basics/)** - Understanding and implementing copy-assignment operators
3. **[Destructor Basics](destructor_basics/)** - Understanding and implementing destructors

## Learning Objectives

By completing these exercises, students will understand:
- How to implement copy constructors for proper object copying
- How to implement copy-assignment operators for object assignment
- How to implement destructors for proper resource cleanup
- The Rule of Three/Five and when to use it
- The difference between deep copy and shallow copy
- How to prevent copying when appropriate
- Best practices for resource management

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Classes and objects
- Constructors and destructors
- Dynamic memory allocation
- Basic understanding of RAII

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