# Feature Specification: User Input and While Loops

## Overview
This feature covers user input functions and while loops in Python as presented in Chapter 7 of "Python Crash Course, 3rd Edition". Students will learn how to get input from users and use while loops to repeat code blocks until certain conditions are met.

## Learning Objectives
By the end of this feature, students will be able to:
- Use the input() function to get user input
- Convert string input to other data types
- Create while loops that repeat until a condition is met
- Use break and continue statements to control loop execution
- Work with lists and dictionaries in while loops
- Visualize loop execution flow using flowcharts
- Understand the difference between for and while loop execution patterns

## Concepts Covered
1. **User Input Functions**
   - Using the input() function
   - Converting input to integers and floats
   - Handling input validation
   - Creating interactive programs

2. **While Loops**
   - Basic while loop syntax
   - Setting flags for loop control
   - Using break to exit loops
   - Using continue to skip iterations
   - Avoiding infinite loops
   - **Understanding while loop flow with flowcharts**

3. **Working with Lists and Dictionaries**
   - Modifying lists in while loops
   - Moving items between lists
   - Filling dictionaries with user input

## Prerequisites
- Understanding of variables and data types
- Knowledge of lists and list operations
- Basic understanding of conditional statements (if statements)

## Exercises
This feature includes the following exercises:
1. `6.1_user_input_functions` - Getting and processing user input
2. `6.2_introducing_while_loops` - Basic while loop usage with flowchart visualization
3. `6.3_using_break_and_continue` - Controlling loop execution with break and continue
4. `6.4_working_with_lists_and_dictionaries` - Using while loops with data structures

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management

## Best Practices
- Always validate user input
- Use clear prompts when requesting input
- Set clear conditions for while loop termination
- Use break statements judiciously
- Avoid infinite loops by ensuring loop conditions can be met
- Use flags for complex loop control logic
- Follow PEP 8 style guide for Python code

## Exercise Development Guidelines
All exercises for this feature must follow the TEMPLATE_GUIDE.md specification to ensure consistency and alignment with learning objectives. Key requirements include:
- Providing clear TODO comments in exercise.py
- Including detailed flowchart visualizations for while loop concepts
- Emphasizing industrial tools (pytest, Jupyter notebooks)
- Following the standard directory structure and file naming conventions

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 7: User Input and While Loops
- PEP 8: Style Guide for Python Code
- Python Documentation: Built-in Functions (input)