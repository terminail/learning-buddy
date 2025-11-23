# Chapter 10: Generic Algorithms

This directory contains exercises for learning about generic algorithms in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on STL generic algorithms that work with iterators to perform operations on containers. Students will learn how to use algorithms like find, sort, transform, and accumulate with different containers.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Find and Count Algorithms](find_count_algorithms/)** - Searching and counting elements in containers
2. **[Transform and Copy Algorithms](transform_copy_algorithms/)** - Modifying and copying container elements
3. **[Sort and Merge Algorithms](sort_merge_algorithms/)** - Sorting containers and merging sequences
4. **[Numeric Algorithms](numeric_algorithms/)** - Mathematical operations on containers

## Learning Objectives

By completing these exercises, students will understand:
- How to use non-modifying sequence algorithms (find, count, etc.)
- How to use modifying sequence algorithms (transform, copy, replace, etc.)
- How to use sorting and merging algorithms
- How to use numeric algorithms for mathematical operations
- How to work with different container types and iterator categories
- Best practices for algorithm usage and performance considerations

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- STL containers (vector, list, etc.)
- Iterators
- Lambda expressions
- Basic understanding of templates

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