# Python Crash Course Exercise Structure

This document outlines the structure and organization of Python exercises based on "Python Crash Course, 3rd Edition" by Eric Matthes.

## Overall Structure

The exercises are organized by chapters and topics from the book, with each major topic split into smaller, focused exercises. This approach follows the same philosophy as the C++ Primer exercises but adapted for Python.

## Template Structure

Each exercise follows a consistent template:

```
exercise_name/
├── README.md              # Exercise instructions and learning objectives
├── exercise.py            # Incomplete code with TODO comments for students
├── solution.py            # Complete reference solution
├── test_exercise.py       # Test cases to verify the solution (pytest)
├── run_tests.py           # Script to run pytest tests
└── exercise_name.ipynb    # Interactive Jupyter notebook (when available)
```

## Current Exercises

1. **1.1_variables_strings** - Variables and simple data types
   - Working with string variables
   - String methods (.title(), .upper(), .lower())
   - String concatenation and f-strings

2. **1.2_numbers_operations** - Numbers and mathematical operations
   - Basic mathematical operations
   - Working with integers and floats
   - Exponents and order of operations
   - Large numbers with underscores
   - Built-in mathematical functions

3. **1.3_strings_methods** - Strings and string methods
   - String stripping methods (.strip(), .lstrip(), .rstrip())
   - Prefix and suffix removal (.removeprefix(), .removesuffix())
   - String searching (.find(), .count())
   - String replacement (.replace())

4. **1.4_numbers_operations** - Advanced numbers and operations
   - Math module functions
   - Number bases (binary, octal, hexadecimal)
   - Number formatting
   - Constants (pi, e)

5. **1.5_comments_documentation** - Comments and documentation
   - Single-line and multi-line comments
   - Docstrings for functions and modules
   - Best practices for code documentation

6. **2.1_list_basics_indexing** - List basics and indexing
   - Creating lists with different data types
   - Accessing elements with positive and negative indexing
   - List slicing to extract sublists
   - Finding list length with len()

7. **2.2_modifying_lists** - Modifying lists
   - Modifying list elements by index
   - Adding elements with append(), insert(), extend()
   - Removing elements with remove(), pop(), del
   - Sorting and reversing lists
   - Copying lists correctly

8. **2.3_organizing_lists** - Organizing lists
   - Sorting lists permanently with sort() method
   - Sorting lists temporarily with sorted() function
   - Reversing list order with reverse() method
   - Finding list length with len() function
   - Avoiding common indexing errors

9. **2.4_avoiding_index_errors** - Avoiding index errors
   - Identifying and handling IndexError exceptions
   - Using len() to avoid index errors
   - Implementing try-except blocks for error handling
   - Validating list indices before accessing elements
   - Debugging common list indexing issues

10. **3.1_looping_through_lists** - Looping through lists
   - Looping through lists using for loops
   - Using the range() function with lists
   - Using enumerate() to get both index and value
   - Creating numerical lists with range()
   - Using list comprehensions

Each exercise directory includes its own Jupyter notebook for interactive learning.

## Planned Exercises

Based on Python Crash Course, 3rd Edition, here are the planned exercises:

### Chapter 2: Variables and Simple Data Types
- ~~1.3: Strings and string methods~~ (Completed)
- ~~1.4: Numbers and numeric operations~~ (Completed)
- ~~1.5: Comments and documentation~~ (Completed)

### Chapter 3: Introducing Lists
- ~~2.1: List basics and indexing~~ (Completed)
- ~~2.2: Modifying lists~~ (Completed)
- ~~2.3: Organizing lists~~ (Completed)
- ~~2.4: Avoiding index errors~~ (Completed)

### Chapter 4: Working with Lists
- ~~3.1: Looping through lists~~ (Completed)
- 3.2: Indentation and styling
- 3.3: Making numerical lists
- 3.4: List comprehensions

### Chapter 5: IF Statements
- 4.1: Conditional tests
- 4.2: Simple if statements
- 4.3: if-elif-else chains
- 4.4: Styling if statements

### Chapter 6: Dictionaries
- 5.1: Dictionary basics
- 5.2: Looping through dictionaries
- 5.3: Nesting dictionaries and lists
- 5.4: Dictionary styling

### Chapter 7: User Input and While Loops
- 6.1: User input functions
- 6.2: Introducing while loops
- 6.3: Using break and continue
- 6.4: Working with lists and dictionaries

### Chapter 8: Functions
- 7.1: Defining functions
- 7.2: Passing arguments
- 7.3: Return values
- 7.4: Passing lists
- 7.5: Module imports

### Chapter 9: Classes
- 8.1: Creating classes
- 8.2: Working with classes and instances
- 8.3: Inheritance
- 8.4: Importing classes

### Chapter 10: Files and Exceptions
- 9.1: Reading from a file
- 9.2: Writing to a file
- 9.3: Exceptions
- 9.4: Analyzing text

### Chapter 11: Testing Your Code
- 10.1: Testing functions
- 10.2: Testing classes
- 10.3: Testing edge cases

## Project-Based Learning

After completing the foundational exercises, students will apply their knowledge to hands-on projects:

1. **Alien Invasion**: A 2D game using Pygame
2. **Data Visualization**: Creating charts and graphs with Matplotlib
3. **Web Applications**: Building web apps with Django

## Tools and Technologies

- **Language**: Python 3.x
- **Testing Framework**: pytest (modern and simple)
- **Environment**: Docker containers for consistent, isolated development environments
- **Code Style**: Following PEP 8 guidelines
- **Interactive Learning**: Jupyter notebooks for hands-on experimentation
- **Dependency Management**: Modern pyproject.toml as the sole configuration file

## Benefits of Our Approach

Our learning approach combines multiple modern tools and techniques to enhance your learning experience:

1. **Immediate Feedback**: Jupyter notebooks provide instant results as you write code
2. **Test-Driven Learning**: Pytest integration teaches professional testing practices
3. **Flexible Formats**: Choose between traditional scripts, interactive notebooks, or test-integrated approaches
4. **Engagement**: Interactive environment keeps students motivated and interested
5. **Professional Skills**: Exposure to industry-standard tools and practices
6. **Error Identification**: Tests help pinpoint exactly what's wrong with your code
7. **Safe Experimentation**: Notebooks provide a safe space to try different approaches

This structure ensures that students can learn Python concepts in a progressive, manageable way while building confidence through small wins.