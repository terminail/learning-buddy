# Chapter 20: The New Standard Library Exercises

This directory contains exercises for Chapter 20 of C++ Primer 5th Edition, covering new standard library features introduced in C++11 and C++14.

## Overview

These exercises focus on modern C++ features that make programming safer, more efficient, and more expressive. Students will learn about automatic memory management with smart pointers, efficient resource transfer with move semantics, and concise code with lambda expressions.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Smart Pointers Basics](smart_pointers_basics/)** - Automatic memory management with std::unique_ptr and std::shared_ptr
2. **[Move Semantics Basics](move_semantics_basics/)** - Efficient resource transfer with rvalue references and std::move
3. **[Lambda Expressions Basics](lambda_expressions_basics/)** - Anonymous functions and callable objects

## Learning Objectives

By completing these exercises, students will understand:
- How to use smart pointers for automatic memory management
- The difference between copy semantics and move semantics
- How to implement move constructors and move assignment operators
- How to use lambda expressions for concise code
- Perfect forwarding with std::forward
- Modern C++ best practices

## Prerequisites

Students should be familiar with:
- Basic C++ syntax and object-oriented programming
- Dynamic memory management with new/delete
- Constructors, destructors, and copy semantics
- Standard library containers
- Templates (basic understanding)

## Building and Running

Each exercise can be built and run using the provided shell scripts:

```bash
# Navigate to any exercise directory
cd smart_pointers_basics

# Build the exercise
./build.sh

# Run the exercise solution
./build/smart_pointers_basics_solutions

# Run tests
./run_tests.sh
```

Note: These exercises are designed to run in a Linux/Docker environment. Windows batch files are not provided.