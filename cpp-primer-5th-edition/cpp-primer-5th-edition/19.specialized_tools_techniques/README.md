# Chapter 19: Specialized Tools and Techniques

This directory contains exercises for learning about specialized tools and techniques in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on specialized tools and techniques including Run-Time Type Identification (RTTI) and multiple inheritance. Students will learn advanced features that provide powerful capabilities for complex software design.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[RTTI](rtti/)** - Run-Time Type Identification
2. **[Multiple Inheritance](multiple_inheritance/)** - Inheriting from multiple base classes

## Learning Objectives

By completing these exercises, students will understand:
- How to use the typeid operator for type identification
- How to use dynamic_cast for safe downcasting
- How to handle the diamond problem with virtual inheritance
- How to use multiple inheritance for mixins and interface combination
- Best practices for using these specialized features

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Inheritance and polymorphism
- Virtual functions
- Pointers and references

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