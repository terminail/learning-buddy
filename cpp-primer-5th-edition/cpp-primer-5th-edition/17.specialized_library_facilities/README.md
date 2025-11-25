# Chapter 17: Specialized Library Facilities

This directory contains exercises for learning about specialized library facilities in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on specialized library facilities including bitset operations and random number generation. Students will learn how to perform efficient bit manipulation and generate quality random numbers for various applications.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Bitset Operations](bitset_operations/)** - Bit manipulation with bitsets
2. **[Random Number Generation](random_numbers/)** - Random number generation facilities

## Learning Objectives

By completing these exercises, students will understand:
- How to create and initialize bitsets of different sizes
- How to perform bitwise operations on bitsets
- How to use bitset member functions for bit manipulation
- How to create and use random number generators
- How to use different random number distributions
- How to seed generators for reproducible results
- Best practices for bit manipulation and random number generation

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- Binary number representation
- Bitwise operators (AND, OR, XOR, NOT)
- Basic probability and statistics concepts

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