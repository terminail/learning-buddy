# Chapter 12: Dynamic Memory

This directory contains exercises for learning about dynamic memory management in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on dynamic memory management including manual memory allocation with new/delete and automatic memory management with smart pointers. Students will learn how to properly manage memory to prevent leaks and ensure exception safety.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Dynamic Memory Allocation](dynamic_allocation/)** - Basic dynamic memory allocation with new and delete
2. **[Smart Pointers](smart_pointers/)** - Automatic memory management with smart pointers

## Learning Objectives

By completing these exercises, students will understand:
- How to allocate and deallocate dynamic memory using new and delete
- How to allocate and deallocate dynamic arrays using new[] and delete[]
- The difference between stack and heap allocation
- How to prevent memory leaks with proper deallocation
- How to use std::unique_ptr for exclusive ownership
- How to use std::shared_ptr for shared ownership
- How to use std::weak_ptr to break circular references
- The benefits of automatic memory management

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Pointers and references
- Arrays and basic data structures
- Object-oriented programming concepts

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