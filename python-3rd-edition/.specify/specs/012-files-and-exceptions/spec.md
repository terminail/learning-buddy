# Feature Specification: Files and Exceptions

## Overview
This feature covers file handling and exception management in Python as presented in Chapter 10 of "Python Crash Course, 3rd Edition". Students will learn how to read from and write to files, and how to handle errors gracefully using exceptions.

## Learning Objectives
By the end of this feature, students will be able to:
- Read data from text files
- Write data to text files
- Handle file paths and directories
- Use exceptions to handle errors gracefully
- Handle different types of exceptions
- Store and analyze data using JSON format
- Apply styling guidelines for file operations

## Concepts Covered
1. **Reading from a File**
   - Opening files with the open() function
   - Reading an entire file with read()
   - Reading line by line with a for loop
   - Using rstrip() to remove whitespace
   - File paths and working directories
   - Using pathlib for cross-platform file paths

2. **Writing to a File**
   - Writing to an empty file
   - Writing multiple lines
   - Appending to a file
   - File modes (read, write, append)
   - Using with blocks for automatic file closing

3. **Exceptions**
   - Using try-except blocks to handle exceptions
   - Handling FileNotFoundError
   - Handling ZeroDivisionError and ValueError
   - Using else blocks with try-except
   - Handling multiple exceptions
   - Failing silently with pass

4. **Storing Data with JSON**
   - Using json.dump() to store data
   - Using json.load() to read data
   - Refactoring code to use JSON storage
   - Handling JSONDecodeError exceptions
   - Storing user data between program runs

5. **File and Exception Styling Guidelines**
   - PEP 8 recommendations for file operations
   - Proper error handling patterns
   - Choosing appropriate exception types
   - Writing meaningful error messages
   - Using context managers for file operations

## Prerequisites
- Understanding of functions (Chapter 8)
- Knowledge of classes (Chapter 9)
- Understanding of lists and dictionaries (Chapters 3 and 6)
- Basic understanding of conditional statements and loops (Chapters 5 and 7)

## Exercises
This feature includes the following exercises:
1. `10.1_reading_files` - Reading data from text files
2. `10.2_writing_files` - Writing data to text files
3. `10.3_handling_exceptions` - Using try-except blocks for error handling
4. `10.4_json_storage` - Storing and retrieving data with JSON
5. `10.5_file_exception_styling` - Applying PEP 8 guidelines to file operations

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management
- pathlib for cross-platform file path handling

## Best Practices
- Always use with blocks when working with files
- Handle exceptions appropriately for your use case
- Provide meaningful error messages to users
- Use JSON for simple data storage needs
- Validate data before storing it
- Follow PEP 8 style guide for Python code
- Use pathlib for cross-platform file path handling
- Close files properly (automatically with with blocks)

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 10: Files and Exceptions
- PEP 8: Style Guide for Python Code
- Python Documentation: Built-in Functions - open()
- Python Documentation: pathlib module
- Python Documentation: json module