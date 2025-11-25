# Pair and Multiset Exercises

This directory contains exercises that combine std::pair and std::multiset concepts, showing how these two container types work together in C++.

## Learning Objectives

- Understand how to create and use std::pair objects
- Learn to work with multiset containers
- Practice inserting duplicate pairs into multisets
- Access and iterate through pairs in multisets

## Exercise Files

### Basic Exercises ([test/test_pair_multiset_basics.cpp](test/test_pair_multiset_basics.cpp))
Focus on fundamental pair and multiset operations:
- Creating pairs with different initialization methods
- Inserting pairs into multisets
- Accessing elements with iterators and key-based operations
- Counting and finding pairs in multisets

### Practice Exercises ([test/test_pair_multiset_practice.cpp](test/test_pair_multiset_practice.cpp))
Application-focused challenges:
- Analyzing data with word positions using pairs
- Finding the most frequent word-position pairs

## Key Concepts

### Pair and Multiset Integration
- **Pair Creation**: Multiple ways to create std::pair objects
- **Multiset Insertion**: Using pairs to insert key-value pairs into multisets
- **Element Access**: Iterating through multisets using range-based loops
- **Duplicate Handling**: Understanding how multisets handle duplicate pairs

### Practical Applications
- Storing multiple occurrences of the same key-value combination
- Building frequency tables with position information
- Managing data where both key and value matter for uniqueness

## Prerequisites

Before working on these exercises, you should be familiar with:
- Basic C++ syntax
- Standard library containers
- Iterators
- Pair containers
- Multiset containers

## Building and Running

```bash
# Make the build script executable
chmod +x build.sh
chmod +x run_tests.sh

# Build the exercises
./build.sh

# Run the basic tests
./build/test_pair_multiset_basics

# Run the practice tests
./build/test_pair_multiset_practice

# Or run all tests
./run_tests.sh
```

## Directory Structure

```
pair_multiset/
├── src/
│   ├── pair_multiset_exercises.cpp     # Exercise template with TODO comments
│   └── pair_multiset_solutions.cpp     # Complete solutions
├── test/
│   ├── test_pair_multiset_basics.cpp   # Basic functionality tests
│   └── test_pair_multiset_practice.cpp # Practice problem tests
├── CMakeLists.txt                      # Build configuration
├── README.md                           # This file
├── build.sh                            # Build script
└── run_tests.sh                        # Test runner script
```