# Feature Specification: Working with Lists

## Overview
This feature covers advanced concepts of working with lists in Python as presented in Chapter 4 of "Python Crash Course, 3rd Edition". Students will learn how to iterate through lists, create numerical lists, and use list comprehensions.

## Learning Objectives
By the end of this feature, students will be able to:
- Loop through lists using for loops
- Use the range() function to generate numerical sequences
- Use enumerate() to get both index and value during iteration
- Create numerical lists with range()
- Apply list comprehensions for concise list creation
- Work with slices of lists
- Copy lists properly
- **Visualize loop execution flow using flowcharts**
- **Understand the difference between for and while loop execution patterns**

## Concepts Covered
1. **Looping Through Lists**
   - Basic for loops with lists
   - Doing more work within loops
   - Avoiding indentation errors
   - Making numerical lists with range()
   - **Understanding for loop flow with flowcharts**

2. **Advanced List Operations**
   - Using range() function for numerical sequences
   - Using enumerate() for index-value pairs
   - List comprehensions for concise code
   - Working with part of a list (slicing)

3. **List Copying**
   - Shallow vs deep copying
   - Proper list copying techniques
   - Understanding list references

## Prerequisites
- Understanding of basic list operations
- Knowledge of variables and data types
- Basic understanding of loops and control structures

## Exercises
This feature includes the following exercises:
1. `3.1_looping_through_lists` - Iterating through lists with for loops
2. `3.2_indentation_styling` - Proper indentation and code styling
3. `3.3_making_numerical_lists` - Creating and working with numerical lists
4. `3.4_list_comprehensions` - Using list comprehensions for efficient code

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management

## Best Practices
- Use meaningful variable names in loops
- Follow PEP 8 indentation guidelines (4 spaces per level)
- Use list comprehensions for simple transformations
- Understand when to use enumerate() vs range(len())
- Apply proper error handling for empty lists
- Follow Python naming conventions for all identifiers

## Exercise Development Guidelines
All exercises for this feature must follow the TEMPLATE_GUIDE.md specification to ensure consistency and alignment with learning objectives. Key requirements include:
- Providing clear TODO comments in exercise.py
- Including flowchart visualizations for loop concepts
- Emphasizing industrial tools (pytest, Jupyter notebooks)
- Following the standard directory structure and file naming conventions

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 4: Working with Lists
- PEP 8: Style Guide for Python Code
- Python Documentation: Built-in Functions (range, enumerate)