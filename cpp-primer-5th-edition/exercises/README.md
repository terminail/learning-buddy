# C++ Primer 5th Edition Exercises (Qoder Directory)

This directory contains comprehensive exercises for C++ Primer 5th Edition, organized by chapter and topic. All exercises follow modern C++ practices and the pedagogical approach of the teaching philosophy.

## Overview

These exercises are designed to help students learn C++ concepts through hands-on practice. Each exercise provides conceptual guidance in TODO comments rather than code solutions, encouraging active learning through implementation.

All exercises are designed to run in a Linux/Docker environment and follow the pedagogical approach of providing conceptual guidance in TODO comments rather than code solutions, helping students learn through active implementation.

## Exercise Structure

Each exercise follows a consistent template structure:
- `src/` - Contains exercise and solution source files
- `test/` - Contains basic and practice test files
- `CMakeLists.txt` - Build configuration
- `README.md` - Detailed instructions and learning objectives
- `build.sh` - Build script for Linux/Docker environments
- `run_tests.sh` - Test execution script

## Prerequisites

Before building and running these exercises, you need to install the required tools:
- [Windows Setup Instructions](PREREQUISITES_WINDOWS.md)
- [macOS Setup Instructions](PREREQUISITES_MACOS.md)
- [Linux/WSL Setup Instructions](PREREQUISITES_LINUX.md)

## Chapters with Exercises

### Chapter 1: Getting Started
- [1 Hello World](1.hello_world/)

### Chapter 2: Variables and Basic Types
- [2 Variables and Types](2.variables_and_types/)

### Chapter 3: Strings, Vectors, and Arrays
- [3.1 Arrays and Strings](3.1.arrays_strings/)
- [3.2 String Library Functions](3.2.string_library_functions/)
- [3.3 Array and String Algorithms](3.3.array_string_algorithms/)

### Chapter 4: Expressions
- [4 Expressions and Statements](4.expressions_statements/)

### Chapter 5: Statements
- [5 Control Flow](5.control_flow/)

### Chapter 6: Functions
- [6 Functions](6.functions/)

### Chapter 7: Classes
- [7 Classes](7.classes/)

### Chapter 8: The IO Library
- [8 IO Library](8.io_library/)

### Chapter 9: Sequential Containers
- [9 Sequential Containers](9.sequential_containers/)

### Chapter 10: Generic Algorithms
- [10 Generic Algorithms](10.generic_algorithms/)

### Chapter 11: Associative Containers
- [11 Associative Containers](11.associative_containers/)

### Chapter 13: Copy Control
- [13 Copy Control](13.copy_control/)

### Chapter 14: Overloaded Operations and Conversions
- [14 Overloaded Operations](14.overloaded_operations/)

### Chapter 20: The New Standard Library
- [20 New Standard Library](20.new_standard_library/)

## Building and Testing

Each exercise can be built and tested using the provided shell scripts:

```bash
# Navigate to any exercise directory
cd chapter.section.exercise_name

# Build the exercise
./build.sh

# Run the exercise solution
./build/exercise_name_solutions

# Run tests
./run_tests.sh
```

Note: These exercises are designed to run in a Linux/Docker environment. Windows batch files are not provided.