# Feature Specification: Classes

## Overview
This feature covers object-oriented programming with classes in Python as presented in Chapter 9 of "Python Crash Course, 3rd Edition". Students will learn how to create classes, define methods, and work with instances.

## Learning Objectives
By the end of this feature, students will be able to:
- Create classes to define custom data types
- Define methods to give classes functionality
- Create and work with class instances
- Use attributes to store data in instances
- Work with inheritance to create specialized classes
- Import classes from modules
- Apply styling guidelines for class definitions

## Concepts Covered
1. **Class Basics**
   - Defining classes with the class keyword
   - Creating instances from classes
   - Accessing attributes with dot notation
   - Calling methods on instances
   - The __init__() method for initialization
   - Setting default values for attributes

2. **Working with Classes**
   - Modifying attribute values directly
   - Modifying attributes through methods
   - Incrementing attribute values through methods
   - Controlling access to attributes
   - Adding class-level attributes and methods

3. **Inheritance**
   - Creating subclasses that inherit from parent classes
   - The super() function for calling parent methods
   - Defining attributes and methods for subclasses
   - Overriding methods from the parent class
   - Instances as attributes for complex classes

4. **Importing Classes**
   - Storing classes in modules
   - Importing single classes
   - Storing multiple classes in a module
   - Importing multiple classes from a module
   - Importing an entire module
   - Using aliases for classes and modules

5. **Python Standard Library Classes**
   - Using OrderedDict for ordered dictionaries
   - Working with other classes from the standard library
   - Understanding when to use standard library classes

6. **Class Styling Guidelines**
   - PEP 8 recommendations for class definitions
   - Naming conventions for classes (CamelCase)
   - Choosing descriptive class and method names
   - Writing effective docstrings for classes
   - Proper indentation and line breaks in classes

## Prerequisites
- Understanding of functions (Chapter 8)
- Knowledge of variables and data types (Chapter 2)
- Understanding of lists and dictionaries (Chapters 3 and 6)
- Basic understanding of conditional statements and loops (Chapters 5 and 7)

## Exercises
This feature includes the following exercises:
1. `9.1_class_basics` - Defining classes and creating instances
2. `9.2_working_with_attributes` - Managing instance attributes
3. `9.3_inheritance_basics` - Creating subclasses with inheritance
4. `9.4_working_with_instances` - Using instances as attributes
5. `9.5_importing_classes` - Storing and importing classes from modules
6. `9.6_class_styling` - Applying PEP 8 guidelines to class definitions

## Tools and Technologies
- Python 3.x
- **pytest** as the sole testing framework for all exercises (replacing traditional unittest)
- **Jupyter notebooks** for interactive learning experiences
- pyproject.toml for dependency management

## Best Practices
- Use descriptive class names that indicate what the class represents
- Follow the single responsibility principle - each class should have one clear purpose
- Use docstrings to document classes and their methods
- Keep classes focused and avoid making them too complex
- Use inheritance judiciously and only when it makes sense
- Follow PEP 8 style guide for Python code, especially naming conventions
- Initialize all attributes in the __init__ method
- Use private attributes (with leading underscore) when appropriate

## Assessment
Students will be assessed through:
- Automated tests using **pytest** as the exclusive testing framework
- Code review for style and best practices
- Practical exercises that reinforce learning objectives
- **Jupyter notebook** interactive challenges with integrated pytest testing

## References
- Python Crash Course, 3rd Edition, Chapter 9: Classes
- PEP 8: Style Guide for Python Code
- Python Documentation: Classes