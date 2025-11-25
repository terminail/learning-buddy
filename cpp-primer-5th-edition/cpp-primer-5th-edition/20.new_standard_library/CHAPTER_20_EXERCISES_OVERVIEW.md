# Chapter 20.1: The New Standard Library Exercises Overview

This directory contains exercises for Chapter 20 of C++ Primer 5th Edition, which covers new standard library features introduced in C++11 and C++14.

## New C++11/14 Features Covered

1. **Smart Pointers** - Automatic memory management with std::unique_ptr and std::shared_ptr
2. **Move Semantics** - Efficient resource transfer with rvalue references and std::move
3. **Lambda Expressions** - Anonymous functions for concise code
4. **Concurrency Support** - std::thread, std::mutex, and related facilities
5. **New Container Functions** - emplace, shrink_to_fit, and more
6. **Perfect Forwarding** - Efficient argument passing with std::forward
7. **Auto and Decltype** - Type deduction features
8. **Range-based For Loops** - Simplified iteration syntax

## Learning Objectives

By completing these exercises, students will understand:
- How to use smart pointers for automatic memory management
- The difference between copy semantics and move semantics
- How to implement move constructors and move assignment operators
- How to use lambda expressions for concise code
- Basic concurrency with std::thread
- Perfect forwarding with std::forward
- New container functions and their benefits
- Modern C++ best practices

## Exercise Structure

Each exercise follows the standard template structure:
- `src/` - Contains exercise and solution source files
- `test/` - Contains basic and practice test files
- `CMakeLists.txt` - Build configuration
- `README.md` - Detailed instructions and learning objectives
- `build.sh` - Build script for Linux/Docker environments
- `run_tests.sh` - Test execution script

## Exercises

### 1. Smart Pointers Basics
Focuses on automatic memory management:
- std::unique_ptr for exclusive ownership
- std::shared_ptr for shared ownership
- Factory functions std::make_unique and std::make_shared
- Custom deleters and exception safety

### 2. Move Semantics Basics
Covers efficient resource transfer:
- Rvalue references (&&)
- Move constructors and move assignment operators
- std::move function
- Perfect forwarding with std::forward
- Move-only types

### 3. Lambda Expressions Basics
Focuses on anonymous functions and callable objects:
- Lambda expression syntax and components
- Different capture modes (=, &, [var], etc.)
- Using lambdas with STL algorithms
- std::function wrapper for callable objects

## Key Concepts

### Smart Pointers
Smart pointers automatically manage memory and prevent leaks:
- **std::unique_ptr**: Exclusive ownership, lightweight, no overhead
- **std::shared_ptr**: Shared ownership with reference counting
- **std::weak_ptr**: Non-owning reference to shared_ptr objects

### Move Semantics
Move semantics enable efficient transfer of resources:
- **Rvalue references**: Enable move operations for temporary objects
- **Move constructors**: Transfer resources instead of copying
- **std::move**: Convert lvalues to rvalues to enable moving
- **Perfect forwarding**: Preserve value categories when forwarding arguments

### Lambda Expressions
Lambda expressions provide concise inline functions:
```cpp
auto lambda = [](int x, int y) { return x + y; };
```

### Concurrency Support
Basic threading support in the standard library:
- std::thread for creating and managing threads
- std::mutex for synchronization
- std::async for asynchronous operations

## Prerequisites

Students should be familiar with:
- Basic C++ syntax and object-oriented programming
- Dynamic memory management with new/delete
- Constructors, destructors, and copy semantics
- Templates (basic understanding)
- Standard library containers

## Building and Running

Each exercise can be built and run using the provided shell scripts:

```bash
# Build the exercise
./build.sh

# Run the exercise solution
./build/smart_pointers_basics_solutions

# Run tests
./run_tests.sh
```

Note: These exercises are designed to run in a Linux/Docker environment. Windows batch files are not provided.