# Exercise 10.3: Sort and Merge Algorithms (Deprecated)

This directory contains the original combined sort and merge algorithms exercise. 
As part of our improved teaching approach following the TEACHING_PHILOSOPHY.md guidelines, 
this exercise has been split into smaller, more focused exercises:

## New Exercises

### 10.3a: Basic Sorting Algorithms
**Directory**: [../10.3a.basic_sorting_algorithms](../10.3a.basic_sorting_algorithms/)
**Focus**: Fundamental sorting algorithms including std::sort and std::stable_sort

### 10.3b: Advanced Sorting Algorithms
**Directory**: [../10.3b.advanced_sorting_algorithms](../10.3b.advanced_sorting_algorithms/)
**Focus**: Partial sorting and selection algorithms including std::partial_sort and std::nth_element

### 10.3c: Merge Algorithms
**Directory**: [../10.3c.merge_algorithms](../10.3c.merge_algorithms/)
**Focus**: Merging sorted sequences including std::merge and std::inplace_merge

## Recommendation

Students are encouraged to use the new split exercises for a better learning experience.
This directory is maintained for backward compatibility but will not be updated further.

## Exercise Structure

### Sort and Merge Algorithms
**Directory**: [src/](src/)

## Learning Objectives

By completing these exercises, students will understand:
- How to use std::sort to sort containers in different orders
- How to use std::stable_sort to maintain relative order of equivalent elements
- How to sort containers of custom objects with custom comparators
- How to use std::merge to combine sorted sequences
- How to use std::inplace_merge to merge adjacent sorted sequences
- Best practices for sorting and merging container elements

## Prerequisites

Students should be familiar with:
- Basic C++ syntax
- STL containers (vector, list, etc.)
- Iterators
- Lambda expressions
- Basic understanding of templates
- Comparison functions and operators

## Building and Testing
