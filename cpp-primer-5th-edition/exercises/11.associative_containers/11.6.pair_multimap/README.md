# Pair and Multimap Exercises

This directory contains exercises that combine std::pair and std::multimap concepts, showing how these two container types work together in C++.

## Learning Objectives

- Understand how to create and use std::pair objects
- Learn to work with multimap containers
- Practice inserting multiple values for the same key using pairs
- Access and iterate through elements in multimaps

## Exercise Files

### Basic Exercises ([test/test_pair_multimap_basics.cpp](test/test_pair_multimap_basics.cpp))
Focus on fundamental pair and multimap operations:
- Creating pairs with different initialization methods
- Inserting pairs into multimaps
- Accessing elements with iterators and key-based operations
- Counting and finding elements with specific keys

### Practice Exercises ([test/test_pair_multimap_practice.cpp](test/test_pair_multimap_practice.cpp))
Application-focused challenges:
- Grouping data by key using pairs
- Finding all values associated with a key and returning them as pairs

## Key Concepts

### Pair and Multimap Integration
- **Pair Creation**: Multiple ways to create std::pair objects
- **Multimap Insertion**: Using pairs to insert key-value pairs into multimaps
- **Element Access**: Iterating through multimaps using range-based loops
- **Key Searching**: Finding all values associated with a specific key

### Practical Applications
- Storing multiple related values for the same key
- Grouping data by categories
- Building frequency tables with additional metadata

## Prerequisites

Before working on these exercises, you should be familiar with:
- Basic C++ syntax
- Standard library containers
- Iterators
- Pair containers
- Multimap containers

## Building and Running

```bash
# Make the build script executable
chmod +x build.sh
chmod +x run_tests.sh

# Build the exercises
./build.sh

# Run the basic tests
./build/test_pair_multimap_basics

# Run the practice tests
./build/test_pair_multimap_practice

# Or run all tests
./run_tests.sh
```

## Directory Structure

```
pair_multimap/
├── src/
│   ├── pair_multimap_exercises.cpp     # Exercise template with TODO comments
│   └── pair_multimap_solutions.cpp     # Complete solutions
├── test/
│   ├── test_pair_multimap_basics.cpp   # Basic functionality tests
│   └── test_pair_multimap_practice.cpp # Practice problem tests
├── CMakeLists.txt                      # Build configuration
├── README.md                           # This file
├── build.sh                            # Build script
└── run_tests.sh                        # Test runner script
```