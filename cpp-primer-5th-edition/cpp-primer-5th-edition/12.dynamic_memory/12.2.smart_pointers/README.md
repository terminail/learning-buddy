# Chapter 12.1b: Smart Pointers

This directory contains exercises for learning about smart pointers in C++ as covered in C++ Primer 5th Edition.

## Exercise Structure

### Smart Pointers
**Directory**: [src/](src/)

## Learning Objectives

By completing these exercises, students will understand:
- How to use std::unique_ptr for exclusive ownership
- How to use std::shared_ptr for shared ownership
- How to use std::weak_ptr to break circular references
- The benefits of automatic memory management
- How smart pointers prevent memory leaks
- Best practices for smart pointer usage

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Pointers and references
- Dynamic memory allocation with new and delete
- Object-oriented programming concepts

## Building and Testing

```bash
# Build the exercise
./build.sh

# Run tests
./run_tests.sh
```