# Multimap Basics Exercises

This directory contains exercises for working with std::multimap in C++, which is an associative container that stores key-value pairs allowing duplicate keys.

## Learning Objectives

- Understand how multimaps differ from maps
- Learn to create and initialize multimaps
- Master multimap element access and traversal
- Practice multimap insertion and deletion operations

## Exercise Files

### Basic Exercises ([test/test_multimap_basics_basics.cpp](test/test_multimap_basics_basics.cpp))
Focus on fundamental multimap operations:
- Creating multimaps with different initialization methods
- Inserting elements using various techniques
- Accessing elements with iterators and key-based operations
- Counting and finding elements with specific keys

### Practice Exercises ([test/test_multimap_basics_practice.cpp](test/test_multimap_basics_practice.cpp))
Application-focused challenges:
- Grouping data by key in a multimap
- Finding all values associated with a key
- Removing duplicate entries while preserving structure

## Key Concepts

### Multimap Characteristics
- **Duplicate Keys**: Unlike map, multimap allows multiple elements with the same key
- **Sorted Order**: Elements are automatically sorted by key
- **Key-Value Pairs**: Stores pairs of key and mapped values

### Multimap Operations
- **insert()**: Add elements to the multimap
- **equal_range()**: Get range of elements with specific key
- **count()**: Count elements with specific key
- **erase()**: Remove elements by key or iterator
- **find()**: Find first element with specific key

### Multimap vs Map
- **Map**: Each key appears only once
- **Multimap**: Multiple elements can have the same key
- **Access**: Map uses operator[], multimap requires iterators

## Prerequisites

Before working on these exercises, you should be familiar with:
- Basic C++ syntax
- Standard library containers
- Iterators
- Pair containers
- Map containers

## Building and Running

```bash
# Make the build script executable
chmod +x build.sh
chmod +x run_tests.sh

# Build the exercises
./build.sh

# Run the basic tests
./build/test_multimap_basics_basics

# Run the practice tests
./build/test_multimap_basics_practice

# Or run all tests
./run_tests.sh
```

## Directory Structure

```
multimap_basics/
├── src/
│   ├── multimap_basics_exercises.cpp     # Exercise template with TODO comments
│   └── multimap_basics_solutions.cpp     # Complete solutions
├── test/
│   ├── test_multimap_basics_basics.cpp   # Basic functionality tests
│   └── test_multimap_basics_practice.cpp # Practice problem tests
├── CMakeLists.txt                        # Build configuration
├── README.md                             # This file
├── build.sh                              # Build script
└── run_tests.sh                          # Test runner script
```