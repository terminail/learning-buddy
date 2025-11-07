# Chapter 11: Associative Containers Exercises Overview

This directory contains exercises for Chapter 11 of C++ Primer 5th Edition, which covers associative containers in the C++ Standard Library.

## Container Types Covered

1. **std::map** - Collection of key-value pairs, sorted by key
2. **std::set** - Collection of unique keys, sorted
3. **std::multimap** - Collection of key-value pairs allowing duplicate keys
4. **std::multiset** - Collection of keys allowing duplicates
5. **std::pair** - Simple container for two values

## Learning Objectives

By completing these exercises, students will understand:
- How to create and initialize associative containers
- Different methods for inserting elements
- How to access and iterate through container elements
- The difference between map and multimap behavior
- The automatic sorting and uniqueness properties of these containers
- Practical applications of associative containers

## Exercise Structure

Each exercise follows the standard template structure:
- `src/` - Contains exercise and solution source files
- `test/` - Contains basic and practice test files
- `CMakeLists.txt` - Build configuration
- `README.md` - Detailed instructions and learning objectives
- `build.sh` - Build script for Linux/Docker environments
- `run_tests.sh` - Test execution script

## Exercises

### 1. Map Basics
Focuses on fundamental map operations:
- Creating and initializing maps
- Inserting key-value pairs using different methods
- Accessing values by key
- Iterating through map elements

### 2. Set Basics
Covers fundamental set operations:
- Creating and initializing sets
- Inserting elements
- Checking for element existence
- Iterating through set elements

### 3. Pair and Multimap Basics
Explores more advanced associative container features:
- Working with std::pair objects
- Using multimap for multiple values per key
- Finding ranges of elements with equal keys
- Understanding the difference between map and multimap

## Key Concepts

1. **Automatic Sorting** - All associative containers automatically maintain elements in sorted order
2. **Key Uniqueness** - In map and set, each key can appear only once
3. **Multiple Values** - Multimap and multiset allow duplicate keys
4. **Efficient Lookup** - O(log n) time complexity for search, insert, and delete operations
5. **Iterator Validity** - Iterators remain valid after insertions and deletions (unlike sequential containers)

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Standard library containers (vector, string)
- Iterators
- Basic template concepts

## Building and Running

Each exercise can be built and run using the provided shell scripts:

```bash
# Build the exercise
./build.sh

# Run the exercise solution
./build/map_basics_solutions

# Run tests
./run_tests.sh
```

Note: These exercises are designed to run in a Linux/Docker environment. Windows batch files are not provided.