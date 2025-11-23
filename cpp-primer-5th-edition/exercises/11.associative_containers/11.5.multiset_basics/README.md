# Multiset Basics Exercises

This directory contains exercises for working with std::multiset in C++, which is an associative container that stores elements in sorted order and allows duplicate elements.

## Learning Objectives

- Understand how multisets differ from sets
- Learn to create and initialize multisets
- Master multiset element access and traversal
- Practice multiset insertion and deletion operations

## Exercise Files

### Basic Exercises ([test/test_multiset_basics_basics.cpp](test/test_multiset_basics_basics.cpp))
Focus on fundamental multiset operations:
- Creating multisets with different initialization methods
- Inserting elements using various techniques
- Accessing elements with iterators
- Counting and finding elements

### Practice Exercises ([test/test_multiset_basics_practice.cpp](test/test_multiset_basics_practice.cpp))
Application-focused challenges:
- Analyzing frequency distributions with multisets
- Finding statistical information from data sets
- Working with multisets in algorithms

## Key Concepts

### Multiset Characteristics
- **Duplicate Elements**: Unlike set, multiset allows multiple elements with the same value
- **Sorted Order**: Elements are automatically sorted
- **Unique Keys**: Each element is its own key

### Multiset Operations
- **insert()**: Add elements to the multiset
- **count()**: Count occurrences of specific elements
- **find()**: Find first occurrence of an element
- **equal_range()**: Get range of equal elements
- **erase()**: Remove elements by value or iterator

### Multiset vs Set
- **Set**: Each element appears only once
- **Multiset**: Multiple copies of the same element are allowed
- **Access**: Both provide similar interface but handle duplicates differently

## Prerequisites

Before working on these exercises, you should be familiar with:
- Basic C++ syntax
- Standard library containers
- Iterators
- Set containers

## Building and Running

```bash
# Make the build script executable
chmod +x build.sh
chmod +x run_tests.sh

# Build the exercises
./build.sh

# Run the basic tests
./build/test_multiset_basics_basics

# Run the practice tests
./build/test_multiset_basics_practice

# Or run all tests
./run_tests.sh
```

## Directory Structure

```
multiset_basics/
├── src/
│   ├── multiset_basics_exercises.cpp     # Exercise template with TODO comments
│   └── multiset_basics_solutions.cpp     # Complete solutions
├── test/
│   ├── test_multiset_basics_basics.cpp   # Basic functionality tests
│   └── test_multiset_basics_practice.cpp # Practice problem tests
├── CMakeLists.txt                        # Build configuration
├── README.md                             # This file
├── build.sh                              # Build script
└── run_tests.sh                          # Test runner script
```