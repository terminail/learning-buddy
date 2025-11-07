# Feature Specification: Lists

## Overview
This feature covers the fundamental concepts of lists in Python as presented in Chapter 3 of "Python Crash Course, 3rd Edition". Students will learn how to create, access, modify, and organize lists in Python.

## Learning Objectives
By the end of this feature, students will be able to:
- Create lists with different data types
- Access list elements using indexing (positive and negative)
- Use list slicing to extract sublists
- Modify list elements by index
- Add and remove elements using various methods
- Sort and reverse lists
- Avoid common indexing errors
- Understand list copying and references

## Concepts Covered
1. **List Basics**
   - Creating lists with square brackets `[]`
   - Lists with mixed data types
   - Accessing elements by index (0-based indexing)
   - Negative indexing

2. **List Slicing**
   - Extracting sublists with `[:]` syntax
   - Understanding slice boundaries
   - Using step values in slicing

3. **Modifying Lists**
   - Changing elements by index
   - Adding elements with `append()`, `insert()`, `extend()`
   - Removing elements with `remove()`, `pop()`, `del`
   - List concatenation and repetition

4. **Organizing Lists**
   - Sorting with `sort()` and `sorted()`
   - Reversing with `reverse()`
   - Finding list length with `len()`

5. **Error Handling**
   - Understanding IndexError exceptions
   - Validating list indices before access
   - Using try-except blocks for error handling

## Prerequisites
- Understanding of variables and data types
- Basic knowledge of mathematical operations

## Exercises
This feature includes the following exercises:
1. `2.1_list_basics_indexing` - List creation and element access
2. `2.2_modifying_lists` - Adding, removing, and changing list elements
3. `2.3_organizing_lists` - Sorting, reversing, and organizing lists
4. `2.4_avoiding_index_errors` - Safe list access and error handling

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management

## Best Practices
- Use descriptive list names that indicate their contents
- Validate indices before accessing list elements
- Use list comprehensions for creating new lists from existing ones
- Understand the difference between shallow and deep copying
- Handle IndexError exceptions gracefully
- Follow PEP 8 style guide for Python code

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 3: Introducing Lists
- PEP 8: Style Guide for Python Code
- Python Documentation: Built-in Types - Lists