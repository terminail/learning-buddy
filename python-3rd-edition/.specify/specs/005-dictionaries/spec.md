# Feature Specification: Dictionaries

## Overview
This feature covers dictionaries in Python as presented in Chapter 6 of "Python Crash Course, 3rd Edition". Students will learn how to create, access, modify, and loop through dictionaries.

## Learning Objectives
By the end of this feature, students will be able to:
- Create and access dictionary values
- Add, modify, and remove key-value pairs
- Loop through dictionaries
- Nest dictionaries and lists
- Style dictionary code according to best practices

## Concepts Covered
1. **Dictionary Basics**
   - Creating dictionaries with key-value pairs
   - Accessing values in a dictionary
   - Adding new key-value pairs
   - Modifying values in a dictionary
   - Removing key-value pairs

2. **Looping Through Dictionaries**
   - Looping through all key-value pairs
   - Looping through all keys
   - Looping through all values
   - Using set() to eliminate duplicates

3. **Nesting**
   - Nesting dictionaries in lists
   - Nesting lists in dictionaries
   - Nesting dictionaries in dictionaries

4. **Dictionary Styling**
   - Following PEP 8 guidelines for dictionaries
   - Choosing appropriate data structures

## Prerequisites
- Understanding of variables and data types
- Knowledge of lists and list operations
- Basic understanding of loops

## Exercises
This feature includes the following exercises:
1. `5.1_dictionary_basics` - Creating and accessing dictionary values
2. `5.2_looping_through_dictionaries` - Iterating through dictionary key-value pairs
3. `5.3_nesting_dictionaries_lists` - Working with nested data structures
4. `5.4_dictionary_styling` - Best practices for dictionary code styling

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management

## Best Practices
- Use descriptive keys that clearly indicate their associated values
- Follow PEP 8 style guide for dictionary formatting
- Choose appropriate data structures for the task at hand
- Use meaningful variable names when looping through dictionaries
- Handle missing keys gracefully using get() method or try-except blocks
- Apply proper indentation for nested data structures

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 6: Dictionaries
- PEP 8: Style Guide for Python Code
- Python Documentation: Built-in Types - Mapping Types (dict)