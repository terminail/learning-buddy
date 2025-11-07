# Python Crash Course, 3rd Edition - Learning Path Specification

## Overview
This specification outlines the complete learning path for Python programming based on "Python Crash Course, 3rd Edition: A Hands-On, Project-Based Introduction to Programming" by Eric Matthes. The learning path is designed to take students from absolute beginners to proficient Python developers through a series of focused, progressive features.

**Note**: All specifications must be created following the chapter order defined in SPECIFICATION_REQUIREMENTS.md to ensure proper learning progression.

## Learning Philosophy
The learning approach follows these core principles:
1. **Concept Decomposition**: Large concepts are broken into small, manageable pieces
2. **Progressive Difficulty**: Each feature builds on previous knowledge while introducing only one new concept at a time
3. **Confidence Building**: Frequent successes through small, achievable exercises
4. **Industrial Tools**: Exclusive use of **pytest** for testing (replacing traditional unittest) and **Jupyter notebooks** for interactive learning
5. **Interactive Learning**: Multiple formats (scripts, notebooks, tests) to accommodate different learning styles
6. **Test-Driven Development**: Early introduction to professional testing practices using industry-standard **pytest** framework

## Features Structure
The learning path is organized into the following features:

### 1. Variables and Simple Data Types (Chapter 2)
- Working with variables, strings, and numbers
- String operations and methods
- Comments and documentation
- Basic data types and operations

### 2. Lists (Chapter 3)
- Creating and accessing lists
- Modifying list elements
- Organizing and sorting lists
- Safe list access and error handling

### 3. Working with Lists (Chapter 4)
- Looping through lists
- Creating numerical lists
- List comprehensions
- Advanced list operations
- **Visualizing loop execution flow using flowcharts**

### 4. If Statements (Chapter 5)
- Conditional tests
- Simple and complex conditional logic
- Styling conditional statements

### 5. Dictionaries (Chapter 6)
- Dictionary basics and operations
- Looping through dictionaries
- Nesting dictionaries and lists
- Dictionary styling best practices

### 6. User Input and While Loops (Chapter 7)
- User input functions
- **While loops with flowchart visualizations**
- Using break and continue statements
- Working with lists and dictionaries in loops

### 7. Functions (Chapter 8)
- Defining and calling functions
- Passing information to functions
- Returning values from functions
- Passing lists and arbitrary arguments
- Storing functions in modules

### 8. Classes (Chapter 9)
- Creating classes and instances
- Working with attributes and methods
- Inheritance and importing classes
- Standard library classes

### 9. Files and Exceptions (Chapter 10)
- Reading and writing files
- Exception handling with try-except
- Storing data with JSON

### 10. Testing Your Code (Chapter 11)
- Testing functions with pytest
- Testing classes and methods
- Advanced testing techniques

### 11. Alien Invasion Project (Chapter 12)
- Creating games with Pygame
- Implementing game mechanics
- Adding sound and visual effects

### 12. Data Visualization Project (Chapter 13)
- Creating charts with Matplotlib
- Working with different data sources
- Generating random walks

### 13. Web Applications Project (Chapter 14)
- Building web apps with Django
- User authentication and deployment
- Enhancing web applications

### 14. Docker Environment for Rapid Learning
- Containerized development environment
- Automated setup and dependency management
- Integration with exercise files
- Jupyter notebook support in containers

### 15. Standalone Docker Environment Repository
- Extension-driven environment provisioning
- On-demand Docker repository downloading
- Separation of environment from learning materials
- VS Code extension integration for automatic setup

## Tools and Technologies
- **Language**: Python 3.x
- **Testing Framework**: **pytest** as the sole testing framework (replacing traditional unittest)
- **Interactive Environment**: **Jupyter notebooks** with integrated pytest testing
- **Dependency Management**: pyproject.toml
- **Code Style**: PEP 8 compliance
- **Development Environment**: VS Code with Python and Jupyter extensions

## Exercise Structure
Each feature contains multiple exercises following a consistent template. All exercises must follow the TEMPLATE_GUIDE.md specification which ensures consistency and alignment with feature requirements:
```
exercise_name/
├── README.md              # Exercise instructions and learning objectives
├── exercise.py            # Incomplete code with TODO comments for students
├── solution.py            # Complete reference solution
├── test_exercise.py       # Test cases to verify the solution (pytest)
├── run_tests.py           # Script to run pytest tests
└── exercise_name.ipynb    # Interactive Jupyter notebook
```

The template guide must be updated whenever feature specifications change to ensure exercises remain aligned with learning objectives and requirements.

## Template Guide Maintenance
The TEMPLATE_GUIDE.md document serves as the authoritative guide for exercise development. It must be updated when:
- Feature specifications change
- Industrial tools evolve
- Pedagogical approaches improve
- Best practices change

This ensures all exercises remain consistent and aligned with current requirements.

## Assessment Strategy
Students are assessed through:
1. **Automated Testing**: Each exercise includes **pytest** tests for immediate feedback
2. **Code Review**: Emphasis on style, best practices, and clean code
3. **Progressive Challenges**: Exercises increase in complexity within each feature
4. **Multiple Formats**: Support for different learning preferences (scripts, **Jupyter notebooks** with integrated **pytest** testing, tests)

## Project-Based Learning
After completing the foundational features, students will apply their knowledge to hands-on projects:
1. **Alien Invasion**: A 2D game using Pygame
2. **Data Visualization**: Creating charts and graphs with Matplotlib
3. **Web Applications**: Building web apps with Django

## References
- Python Crash Course, 3rd Edition by Eric Matthes
- PEP 8: Style Guide for Python Code
- Python Documentation