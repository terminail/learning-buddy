# Chapter 15: Object-Oriented Programming

This directory contains exercises for learning about object-oriented programming in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on object-oriented programming concepts including inheritance, virtual functions, and polymorphism. Students will learn how to create class hierarchies and use polymorphism to write flexible and extensible code.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Inheritance Basics](inheritance_basics/)** - Introduction to inheritance in C++
2. **[Virtual Functions](virtual_functions/)** - Virtual functions and polymorphism

## Learning Objectives

By completing these exercises, students will understand:
- How to create base classes and derived classes
- How inheritance promotes code reuse
- How to declare and implement virtual functions
- The difference between static binding and dynamic binding
- How virtual functions enable polymorphism
- How to create abstract base classes with pure virtual functions

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Classes and objects
- Member functions and access specifiers
- Constructors and destructors

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