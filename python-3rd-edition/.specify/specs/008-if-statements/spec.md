# Feature Specification: If Statements

## Overview
This feature covers conditional statements in Python as presented in Chapter 5 of "Python Crash Course, 3rd Edition". Students will learn how to write conditional tests, use if statements, and handle multiple conditions.

## Learning Objectives
By the end of this feature, students will be able to:
- Write conditional tests using comparison operators
- Use simple if statements to control program flow
- Handle multiple conditions with if-elif-else chains
- Use conditional expressions in list comprehensions
- Check for special values in lists
- Compare lists and other data structures
- Apply styling guidelines for conditional statements

## Concepts Covered
1. **Conditional Tests**
   - Simple comparisons (==, !=, <, >, <=, >=)
   - Checking multiple conditions (and, or)
   - Checking whether values are in a list (in, not in)
   - Boolean expressions and values

2. **Simple If Statements**
   - if statements for basic conditional execution
   - if-else statements for binary choices
   - if-elif-else chains for multiple conditions
   - Using pass statement for empty code blocks

3. **Advanced Conditional Logic**
   - Nested if statements
   - Complex boolean expressions
   - Short-circuit evaluation
   - Conditional assignments with ternary operators

4. **Working with Lists in Conditions**
   - Checking if a list is empty
   - Checking for special items in lists
   - Processing lists with conditional logic
   - Filtering lists based on conditions

5. **Styling Conditional Statements**
   - PEP 8 recommendations for conditional formatting
   - Proper indentation and line breaks
   - Choosing meaningful condition variable names
   - Commenting complex conditions

## Prerequisites
- Understanding of variables and data types (Chapter 2)
- Basic knowledge of lists (Chapter 3)
- Understanding of basic programming concepts

## Exercises
This feature includes the following exercises:
1. `5.1_conditional_tests` - Writing and evaluating conditional expressions
2. `5.2_simple_if_statements` - Using basic if and if-else statements
3. `5.3_if_elif_else_chains` - Handling multiple conditions with if-elif-else
4. `5.4_conditional_lists` - Processing lists with conditional logic
5. `5.5_styling_conditions` - Applying PEP 8 guidelines to conditional statements

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management

## Best Practices
- Write clear, readable conditional expressions
- Use parentheses to group complex conditions for clarity
- Choose meaningful variable names that indicate what is being tested
- Follow PEP 8 style guide for Python code, especially indentation
- Avoid deeply nested conditional statements
- Consider using early returns to reduce nesting
- Use boolean variables to store complex condition results

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 5: If Statements
- PEP 8: Style Guide for Python Code
- Python Documentation: Built-in Types - Boolean Values