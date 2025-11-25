# Chapter 10: Generic Algorithms

This directory contains exercises for learning about generic algorithms in C++ as covered in C++ Primer 5th Edition.

## Overview

These exercises focus on STL generic algorithms that work with iterators to perform operations on containers. Students will learn how to use algorithms like find, sort, transform, and accumulate with different containers.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercises Included

1. **[Find and Count Algorithms](find_count_algorithms/)** - Searching and counting elements in containers
2. **[Transform and Copy Algorithms](transform_copy_algorithms/)** - Modifying and copying container elements
3. **[Basic Sorting Algorithms](10.3a.basic_sorting_algorithms/)** - Fundamental sorting algorithms including std::sort and std::stable_sort
4. **[Advanced Sorting Algorithms](10.3b.advanced_sorting_algorithms/)** - Partial sorting and selection algorithms including std::partial_sort and std::nth_element
5. **[Merge Algorithms](10.3c.merge_algorithms/)** - Merging sorted sequences including std::merge and std::inplace_merge
6. **[Numeric Algorithms](numeric_algorithms/)** - Mathematical operations on containers

## Learning Objectives

By completing these exercises, students will understand:
- How to use non-modifying sequence algorithms (find, count, etc.)
- How to use modifying sequence algorithms (transform, copy, replace, etc.)
- How to use basic and advanced sorting algorithms
- How to use merging algorithms for sorted sequences
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

Note: These exercises are designed to run in a Linux/Docker environment. Windows batch files are provided for Windows users.

## Recent Improvements

### Exercise Splitting (November 2025)
Following our teaching philosophy, the "Sort and Merge Algorithms" exercise has been split into three focused exercises:
- **[Basic Sorting Algorithms](10.3a.basic_sorting_algorithms/)** - Fundamental sorting with std::sort and std::stable_sort
- **[Advanced Sorting Algorithms](10.3b.advanced_sorting_algorithms/)** - Partial sorting and selection with std::partial_sort and std::nth_element
- **[Merge Algorithms](10.3c.merge_algorithms/)** - Merging sorted sequences with std::merge and std::inplace_merge

See [SPLIT_EXERCISES_NOTICE.md](10.3.sort_merge_algorithms/SPLIT_EXERCISES_NOTICE.md) for more information about this improvement.
