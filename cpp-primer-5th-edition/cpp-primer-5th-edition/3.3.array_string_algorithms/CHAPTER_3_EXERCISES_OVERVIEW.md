# Array and String Algorithms Exercises Overview

This document provides an overview of all array and string algorithms exercises created for learning C++ Primer 5th Edition concepts.

## Exercise Progression

### 3.3.1: Transformation Algorithms
**Directory**: [transformation_algorithms](transformation_algorithms/)
**Focus**: Applying functions to container elements
- Function pointers with std::transform
- Lambda functions with std::transform
- Custom functions and functors
- String transformations

### 3.3.2: Searching Algorithms
**Directory**: [searching_algorithms](searching_algorithms/)
**Focus**: Finding elements in containers
- Linear searching with std::find and std::find_if
- Counting with std::count and std::count_if
- Binary searching with std::binary_search
- String searching with std::search and std::find_end

### 3.3.3: Sorting Algorithms
**Directory**: [sorting_algorithms](sorting_algorithms/)
**Focus**: Ordering container elements
- Default sorting with std::sort
- Custom comparators and lambda functions
- Stable sorting with std::stable_sort
- Partial sorting with std::partial_sort and std::nth_element

### 3.3.4: Array Manipulation Algorithms
**Directory**: [array_manipulation](array_manipulation/)
**Focus**: Modifying container structure
- Reversing with std::reverse and std::reverse_copy
- Removing duplicates with std::unique and std::unique_copy
- Element removal with std::remove and std::remove_if
- Rotation and shuffling

### 3.3.5: String-Specific Algorithms
**Directory**: [string_algorithms](string_algorithms/)
**Focus**: Text processing and string operations
- Character replacement with std::replace
- String transformation with std::transform
- Text processing and whitespace handling
- String accumulation and concatenation

## Learning Path

Students should complete these exercises in order:
1. **Transformation Algorithms** - Start with applying functions to elements
2. **Searching Algorithms** - Learn to find elements efficiently
3. **Sorting Algorithms** - Understand ordering and comparison
4. **Array Manipulation Algorithms** - Modify container structure
5. **String-Specific Algorithms** - Process text and strings

## Key Concepts Covered

### Transformation Algorithms
- **transform()**: Apply functions to container elements
- **Function pointers**: Use existing functions as transformations
- **Lambda functions**: Inline function definitions for transformations
- **Functors**: Function objects with state

### Searching Algorithms
- **find()**: Locate first occurrence of value
- **find_if()**: Locate first element meeting criteria
- **count()**: Count occurrences of value
- **count_if()**: Count elements meeting criteria
- **binary_search()**: Efficient search in sorted containers
- **lower_bound()/upper_bound()**: Boundary searches

### Sorting Algorithms
- **sort()**: General-purpose sorting
- **stable_sort()**: Maintain relative order of equal elements
- **partial_sort()**: Sort only portions of containers
- **nth_element()**: Quick selection of elements
- **Custom comparators**: Define specific sorting criteria

### Array Manipulation Algorithms
- **reverse()**: Reverse element order
- **unique()**: Remove consecutive duplicates
- **remove()**: Mark elements for removal (erase-remove idiom)
- **rotate()**: Rotate elements around a midpoint
- **shuffle()**: Randomize element order

### String-Specific Algorithms
- **replace()**: Substitute characters or substrings
- **replace_if()**: Conditional character replacement
- **Text processing**: Whitespace handling and formatting
- **accumulate()**: String concatenation and aggregation

## Next Topics

After completing array and string algorithms exercises, students should progress to:
- Exercise 4.1: Expressions and Statements
- Exercise 5.1: Control Flow Statements