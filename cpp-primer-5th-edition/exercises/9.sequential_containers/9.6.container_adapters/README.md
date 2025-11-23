# Container Adapters Exercises

This directory contains exercises for working with container adapters in C++ STL, including stack, queue, and priority_queue.

## Learning Objectives

- Understand the concept of container adapters
- Learn how to use std::stack for LIFO (Last In, First Out) operations
- Learn how to use std::queue for FIFO (First In, First Out) operations
- Learn how to use std::priority_queue for priority-based operations
- Understand the underlying container requirements for each adapter
- Practice with different underlying container types (vector, deque, list)

## Exercise Files

### Basic Exercises ([test/test_container_adapters_basics.cpp](test/test_container_adapters_basics.cpp))
Focus on fundamental operations:
- Creating and initializing container adapters
- Basic operations (push, pop, top/front/back)
- Checking size and empty status
- Understanding different underlying containers

### Practice Exercises ([test/test_container_adapters_practice.cpp](test/test_container_adapters_practice.cpp))
Application-focused challenges:
- String reversal using stack
- Balanced parentheses checking
- Printer queue simulation

## Key Concepts

### Container Adapters
- **Stack**: LIFO data structure
- **Queue**: FIFO data structure
- **Priority Queue**: Elements ordered by priority

### Underlying Containers
- **Stack**: Typically uses deque (default), but can use vector or deque
- **Queue**: Typically uses deque (default)
- **Priority Queue**: Typically uses vector (default)

## Prerequisites

Before working on these exercises, you should be familiar with:
- Basic C++ syntax
- Sequential containers (vector, deque, list)
- Basic STL concepts
- Function templates

## Building and Running

```bash
# Make the build script executable
chmod +x build.sh
chmod +x run_tests.sh

# Build the exercises
./build.sh

# Run the basic tests
./build/test_container_adapters_basics

# Run the practice tests
./build/test_container_adapters_practice

# Or run all tests
./run_tests.sh
```

## Directory Structure

```
container_adapters/
├── src/
│   ├── container_adapters_exercises.cpp     # Exercise template with TODO comments
│   └── container_adapters_solutions.cpp     # Complete solutions
├── test/
│   ├── test_container_adapters_basics.cpp   # Basic functionality tests
│   └── test_container_adapters_practice.cpp # Practice problem tests
├── CMakeLists.txt                           # Build configuration
├── README.md                                # This file
├── build.sh                                 # Build script
└── run_tests.sh                             # Test runner script
```