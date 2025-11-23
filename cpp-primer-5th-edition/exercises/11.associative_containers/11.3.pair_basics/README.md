# Pair Basics Exercises

This directory contains exercises for working with std::pair in C++, which is a simple container for storing two values of potentially different types.

## Learning Objectives

- Understand how to create and initialize pairs
- Learn to access and modify pair elements
- Practice using pairs with associative containers
- Master pair comparison and assignment operations

## Exercise Files

### Basic Exercises ([test/test_pair_basics_basics.cpp](test/test_pair_basics_basics.cpp))
Focus on fundamental pair operations:
- Creating pairs with different initialization methods
- Accessing first and second elements
- Comparing pairs using relational operators
- Assigning values to pair elements

### Practice Exercises ([test/test_pair_basics_practice.cpp](test/test_pair_basics_practice.cpp))
Application-focused challenges:
- Creating template functions that work with pairs
- Implementing pair manipulation utilities
- Extracting pairs from associative containers

## Key Concepts

### Pair Creation
- **Direct initialization**: `std::pair<int, double> p(1, 3.14);`
- **Brace initialization**: `std::pair<int, int> p{10, 20};`
- **make_pair function**: `auto p = std::make_pair("hello", 42);`

### Pair Access
- **first**: Access the first element
- **second**: Access the second element

### Pair Operations
- **Comparison**: Pairs support ==, !=, <, >, <=, >= operators
- **Assignment**: Pairs can be assigned to each other
- **Copy semantics**: Pairs are copied element-wise

## Prerequisites

Before working on these exercises, you should be familiar with:
- Basic C++ syntax
- Template concepts
- Associative containers (map, set)
- Function templates

## Building and Running

```bash
# Make the build script executable
chmod +x build.sh
chmod +x run_tests.sh

# Build the exercises
./build.sh

# Run the basic tests
./build/test_pair_basics_basics

# Run the practice tests
./build/test_pair_basics_practice

# Or run all tests
./run_tests.sh
```

## Directory Structure

```
pair_basics/
├── src/
│   ├── pair_basics_exercises.cpp     # Exercise template with TODO comments
│   └── pair_basics_solutions.cpp     # Complete solutions
├── test/
│   ├── test_pair_basics_basics.cpp   # Basic functionality tests
│   └── test_pair_basics_practice.cpp # Practice problem tests
├── CMakeLists.txt                    # Build configuration
├── README.md                         # This file
├── build.sh                          # Build script
└── run_tests.sh                      # Test runner script
```