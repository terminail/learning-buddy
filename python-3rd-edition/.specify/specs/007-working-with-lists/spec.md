# Feature Specification: Working with Lists

## Overview
This feature covers advanced concepts of working with lists in Python as presented in Chapter 4 of "Python Crash Course, 3rd Edition". Students will learn how to loop through lists, create numerical lists, use list comprehensions, and work with tuples.

## Learning Objectives
By the end of this feature, students will be able to:
- Loop through lists using for loops
- Create numerical lists using the range() function
- Use list comprehensions to create lists in one line
- Work with parts of lists using slicing
- Copy lists properly to avoid reference issues
- Understand and use tuples (immutable lists)
- Apply styling guidelines for working with lists

## Concepts Covered
1. **Looping Through Lists**
   - Using for loops to iterate through list elements
   - Performing actions on each list element
   - Using meaningful variable names in loops
   - Indentation and code formatting in loops

2. **Numerical Lists**
   - Creating lists of numbers using range()
   - Converting range objects to lists
   - Using range() with start, stop, and step values
   - Simple statistics with numerical lists (min, max, sum)

3. **List Comprehensions**
   - Creating lists using list comprehensions
   - Applying expressions in list comprehensions
   - Adding conditions to list comprehensions
   - Comparing list comprehensions to traditional loops

4. **Working with Parts of Lists**
   - Slicing lists to extract sublists
   - Copying lists using slicing
   - Understanding shallow vs. deep copying
   - Avoiding common slicing mistakes

5. **Tuples**
   - Creating and accessing tuples
   - Understanding immutability
   - Looping through tuples
   - Assigning new values to tuple variables

6. **Styling Guidelines**
   - PEP 8 recommendations for list usage
   - Choosing between lists and tuples
   - Proper indentation in complex list operations

## Prerequisites
- Understanding of basic list operations (Chapter 3)
- Knowledge of variables and data types (Chapter 2)
- Basic understanding of loops and control structures

## Exercises
This feature includes the following exercises:
1. `4.1_looping_through_lists` - Iterating through list elements with for loops
2. `4.2_numerical_lists` - Creating and working with numerical lists using range()
3. `4.3_list_comprehensions` - Using list comprehensions to create lists efficiently
4. `4.4_working_with_parts` - Slicing lists and copying list portions
5. `4.5_tuples` - Working with immutable sequences (tuples)
6. `4.6_styling_guidelines` - Applying PEP 8 guidelines to list operations

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management

## Best Practices
- Use meaningful variable names in loops that describe the elements being processed
- Apply list comprehensions for simple transformations and filtering
- Use tuples when data should not change after creation
- Follow PEP 8 style guide for Python code, especially indentation
- Use slicing for copying lists instead of direct assignment
- Consider performance implications of large list operations

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 4: Working with Lists
- PEP 8: Style Guide for Python Code
- Python Documentation: Built-in Types - Lists and Tuples