# Chapter 16: Templates and Generic Programming

This directory contains exercises for learning about templates and generic programming in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on templates and generic programming including function templates and class templates. Students will learn how to write generic code that works with different types while maintaining type safety.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Function Templates](function_templates/)** - Generic functions with templates
2. **[Class Templates](class_templates/)** - Generic classes with templates

## Learning Objectives

By completing these exercises, students will understand:
- How to define and instantiate function templates
- How template type deduction works
- How to use multiple template parameters
- How to specialize templates for specific types
- How to define and instantiate class templates
- How to use multiple template parameters with classes
- How to provide default template parameters
- Best practices for generic programming

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Functions and function overloading
- Classes and objects
- Basic understanding of types and templates

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