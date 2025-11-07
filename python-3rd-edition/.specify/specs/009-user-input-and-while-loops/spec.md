# Feature Specification: User Input and While Loops

## Overview
This feature covers user input and while loops in Python as presented in Chapter 7 of "Python Crash Course, 3rd Edition". Students will learn how to accept user input, use while loops for repeated actions, and control loop execution.

## Learning Objectives
By the end of this feature, students will be able to:
- Accept and process user input using the input() function
- Convert string input to numerical values
- Use while loops for repeated execution
- Control loop execution with break and continue statements
- Use while loops with lists and dictionaries
- Handle common input validation scenarios
- Apply styling guidelines for input and loop operations

## Concepts Covered
1. **User Input**
   - Using the input() function to get user input
   - Displaying prompts to guide user input
   - Converting string input to integers and floats
   - Handling input errors and exceptions

2. **While Loops**
   - Basic while loop syntax and structure
   - Setting and modifying loop conditions
   - Infinite loops and how to avoid them
   - Using flags to control loop execution

3. **Loop Control**
   - Using break to exit loops
   - Using continue to skip iterations
   - Choosing between for and while loops
   - Nested loops and complex control flow

4. **Working with Lists and Dictionaries in Loops**
   - Modifying lists while looping through them
   - Moving items between lists
   - Removing items from lists with while loops
   - Filling dictionaries with user input

5. **Input Validation**
   - Validating user input within loops
   - Providing feedback for invalid input
   - Creating robust input processing functions
   - Handling edge cases in user input

6. **Styling Guidelines**
   - PEP 8 recommendations for input and loop usage
   - Proper indentation and line breaks in loops
   - Choosing meaningful variable names for loop control
   - Commenting complex loop logic

## Prerequisites
- Understanding of variables and data types (Chapter 2)
- Knowledge of lists (Chapter 3)
- Understanding of conditional statements (Chapter 5)
- Basic understanding of loops and control structures

## Exercises
This feature includes the following exercises:
1. `7.1_user_input_basics` - Accepting and processing basic user input
2. `7.2_while_loop_fundamentals` - Using while loops for repeated execution
3. `7.3_loop_control_statements` - Controlling loop execution with break and continue
4. `7.4_lists_dictionaries_loops` - Working with collections in while loops
5. `7.5_input_validation` - Validating and processing user input
6. `7.6_styling_input_loops` - Applying PEP 8 guidelines to input and loop operations

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management

## Best Practices
- Always validate user input before processing
- Use clear, descriptive prompts for user input
- Provide meaningful feedback for invalid input
- Use flags to make complex loop conditions more readable
- Avoid infinite loops by ensuring loop conditions can be met
- Follow PEP 8 style guide for Python code, especially indentation
- Consider using functions to encapsulate complex input processing logic

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 7: User Input and While Loops
- PEP 8: Style Guide for Python Code
- Python Documentation: Built-in Functions - input()