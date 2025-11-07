# Python Crash Course, 3rd Edition: A Hands-On, Project-Based Introduction to Programming 

Welcome to a structured, beginner-friendly approach to learning Python using the principles from "Python Crash Course, 3rd Edition" by Eric Matthes.

This project uses modern Python dependency management with `pyproject.toml` as the **only** configuration file for managing dependencies and development tools. We've adopted the modern, standardized approach and removed the legacy `requirements.txt` file. The `pyproject.toml` file is used for dependency management only and is not intended for packaging this educational content.

![Python Crash Course, 3rd Edition](./python-crash-course-3rd-edition.jpg)
## About This Approach

This learning path is designed specifically for newbie students who want to learn Python programming in a structured, manageable way. Based on the proven teaching philosophy, we've broken down complex Python concepts into small, digestible exercises that build upon each other.

## Teaching Philosophy

Our approach follows these key principles:

1. **Concept Decomposition**: Each exercise focuses on one small concept to reduce cognitive load
2. **Progressive Difficulty**: Exercises gradually increase in complexity
3. **Confidence Building**: Small wins keep students motivated
4. **Clear Structure**: Consistent templates with learning objectives, guided implementation, and tests
5. **Modern Tools**: Using current Python practices and testing frameworks

For the complete teaching philosophy, see [PYTHON_TEACHING_PHILOSOPHY.md](PYTHON_TEACHING_PHILOSOPHY.md).

## Learning Path Structure

The exercises are organized to follow the book's progression while splitting complex chapters into focused topics:

1. **Variables and Simple Data Types** (Chapter 2)
2. **Introducing Lists** (Chapter 3)
3. **Working with Lists** (Chapter 4)
4. **IF Statements** (Chapter 5)
5. **Dictionaries** (Chapter 6)
6. **User Input and While Loops** (Chapter 7)
7. **Functions** (Chapter 8)
8. **Classes** (Chapter 9)
9. **Files and Exceptions** (Chapter 10)
10. **Testing Your Code** (Chapter 11)
11. **Alien Invasion Project** (Chapter 12)
12. **Data Visualization Project** (Chapter 13)
13. **Web Applications Project** (Chapter 14)
14. **Docker Environment for Rapid Learning** (Chapter 17)
15. **Standalone Docker Environment Repository** (Chapter 18)

Each topic is further divided into sub-exercises for deeper understanding.

## Getting Started

### Using Docker (Recommended)

1. Install Docker and Docker Compose on your system
2. Use the Learning Buddy VS Code extension to automatically download and set up the standalone Docker environment
3. Alternatively, navigate to the `../python-3rd-docker` directory
4. Run `./start_learning.sh` (Linux/Mac)
5. Access the environment with `docker-compose exec python-learning bash`

## Working with Exercises

### Exercise Structure

Each exercise directory contains the following files:
- `README.md` - Exercise instructions and learning objectives
- `exercise.py` - Incomplete code with TODO comments for students
- `solution.py` - Complete reference solution
- `test_exercise.py` - Test cases to verify the solution
- `run_tests.py` - Script to run tests
- `exercise_name.ipynb` - Interactive Jupyter notebook (when available)

### How to Work with Exercises

1. Choose an exercise from the list below
2. Navigate to the exercise directory
3. Read the README.md file for instructions
4. Open exercise.py and complete the TODO sections
5. Run your code with: `python exercise.py`
6. Test your solution with: `python run_tests.py`

### Interactive Notebooks

Each exercise includes an interactive Jupyter notebook for hands-on learning. We recommend using VS Code with the Jupyter extension instead of browser-based notebooks for a better development experience:

1. Install VS Code from https://code.visualstudio.com/
2. Install the "Jupyter" and "Python" extensions from the Extensions marketplace
3. Open any notebook directly in VS Code

## Project-Based Learning

After completing the foundational exercises, you'll apply your knowledge to hands-on projects as featured in the book:

1. **Alien Invasion**: A 2D game using Pygame
2. **Data Visualization**: Creating charts and graphs with Matplotlib
3. **Web Applications**: Building web apps with Django

## Available Exercises

We have completed all feature specifications and created the following exercises:

1. [1.1_variables_strings](1.1_variables_strings/) - Working with variables and string operations
2. [1.2_numbers_operations](1.2_numbers_operations/) - Mathematical operations with numbers
3. [1.3_strings_methods](1.3_strings_methods/) - Advanced string methods and operations
4. [1.4_numbers_operations](1.4_numbers_operations/) - Advanced number operations and mathematical functions
5. [1.5_comments_documentation](1.5_comments_documentation/) - Writing effective comments and documentation
6. [2.1_list_basics_indexing](2.1_list_basics_indexing/) - List creation and element access
7. [2.2_modifying_lists](2.2_modifying_lists/) - Adding, removing, and changing list elements
8. [2.3_organizing_lists](2.3_organizing_lists/) - Sorting, reversing, and organizing lists
9. [2.4_avoiding_index_errors](2.4_avoiding_index_errors/) - Safe list access and error handling
10. [3.1_looping_through_lists](3.1_looping_through_lists/) - Iterating through list elements with for loops
11. [3.2_indentation_styling](3.2_indentation_styling/) - Proper indentation and styling guidelines
12. [6.2_introducing_while_loops](6.2_introducing_while_loops/) - Introduction to while loops and flowcharts

## Interactive Notebooks

Each exercise directory contains its own Jupyter notebook for interactive learning:

1. [1.1_variables_strings/1.1_variables_strings.ipynb](1.1_variables_strings/1.1_variables_strings.ipynb) - Interactive version of variables and strings exercise
2. [1.2_numbers_operations/1.2_numbers_operations.ipynb](1.2_numbers_operations/1.2_numbers_operations.ipynb) - Interactive version of numbers and operations exercise
3. [1.3_strings_methods/1.3_strings_methods.ipynb](1.3_strings_methods/1.3_strings_methods.ipynb) - Interactive version of string methods exercise
4. [1.4_numbers_operations/1.4_numbers_operations.ipynb](1.4_numbers_operations/1.4_numbers_operations.ipynb) - Interactive version of advanced numbers operations exercise
5. [1.5_comments_documentation/1.5_comments_documentation.ipynb](1.5_comments_documentation/1.5_comments_documentation.ipynb) - Interactive version of comments and documentation exercise
6. [2.1_list_basics_indexing/2.1_list_basics_indexing.ipynb](2.1_list_basics_indexing/2.1_list_basics_indexing.ipynb) - Interactive version of list basics exercise
7. [2.2_modifying_lists/2.2_modifying_lists.ipynb](2.2_modifying_lists/2.2_modifying_lists.ipynb) - Interactive version of modifying lists exercise
8. [2.3_organizing_lists/2.3_organizing_lists.ipynb](2.3_organizing_lists/2.3_organizing_lists.ipynb) - Interactive version of organizing lists exercise
9. [2.4_avoiding_index_errors/2.4_avoiding_index_errors.ipynb](2.4_avoiding_index_errors/2.4_avoiding_index_errors.ipynb) - Interactive version of avoiding index errors exercise
10. [3.1_looping_through_lists/3.1_looping_through_lists.ipynb](3.1_looping_through_lists/3.1_looping_through_lists.ipynb) - Interactive version of looping through lists exercise
11. [3.2_indentation_styling/3.2_indentation_styling.ipynb](3.2_indentation_styling/3.2_indentation_styling.ipynb) - Interactive version of indentation styling exercise
12. [6.2_introducing_while_loops/6.2_introducing_while_loops.ipynb](6.2_introducing_while_loops/6.2_introducing_while_loops.ipynb) - Interactive version of while loops exercise

## Benefits of Our Approach

Our learning approach combines multiple modern tools and techniques to enhance your learning experience:

- **Interactive Learning**: Jupyter notebooks provide hands-on experimentation with immediate feedback
- **Test-Driven Development**: Pytest integration teaches professional testing practices from the beginning
- **Flexible Formats**: Choose between traditional scripts, interactive notebooks, or test-integrated approaches
- **Gradual Progression**: Exercises increase in complexity while building on previous knowledge
- **Professional Skills**: Exposure to industry-standard tools and practices

Check the [EXERCISE_STRUCTURE.md](EXERCISE_STRUCTURE.md) file for a complete list of planned exercises based on the book's chapters.

## Contributing

This learning approach is continuously evolving. If you have suggestions for improvements or additional exercises, please feel free to contribute.

Happy coding!