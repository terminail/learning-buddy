# Chapter 11: Associative Containers

This directory contains exercises for learning about associative containers in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on associative containers including map, set, multimap, and multiset. Students will learn how to use these containers to store and retrieve key-value pairs and unique elements efficiently.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Map Basics](map_basics/)** - Working with std::map containers
2. **[Set Basics](set_basics/)** - Working with std::set containers
3. **[Pair and Multimap Basics](pair_multimap_basics/)** - Working with std::pair and std::multimap

## Learning Objectives

By completing these exercises, students will understand:
- How to create and use map containers for key-value storage
- How to create and use set containers for unique element storage
- How to work with pairs and multimap containers
- How to iterate through associative containers
- How to perform common operations like insertion, deletion, and lookup
- Performance characteristics of associative containers

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- STL sequential containers (vector, list, deque)
- Iterators
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