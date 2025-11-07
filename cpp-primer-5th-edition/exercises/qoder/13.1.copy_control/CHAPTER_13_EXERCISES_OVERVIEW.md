# Chapter 13: Copy Control Exercises Overview

This directory contains exercises for Chapter 13 of C++ Primer 5th Edition, which covers copy control mechanisms in C++ classes.

## Copy Control Mechanisms Covered

1. **Copy Constructor** - Controls how objects are copied when created from existing objects
2. **Copy Assignment Operator** - Controls how existing objects are assigned to other existing objects
3. **Destructor** - Controls how objects are cleaned up when destroyed
4. **Move Constructor** (advanced) - Efficiently transfers resources from temporary objects
5. **Move Assignment Operator** (advanced) - Efficiently transfers resources between existing objects

## Learning Objectives

By completing these exercises, students will understand:
- The Rule of Three (and Rule of Five in C++11)
- When each copy control mechanism is automatically invoked
- How to implement proper resource management in classes
- The difference between deep copy and shallow copy
- How to handle self-assignment safely
- The importance of virtual destructors in inheritance hierarchies
- Exception safety in copy control operations

## Exercise Structure

Each exercise follows the standard template structure:
- `src/` - Contains exercise and solution source files
- `test/` - Contains basic and practice test files
- `CMakeLists.txt` - Build configuration
- `README.md` - Detailed instructions and learning objectives
- `build.sh` - Build script for Linux/Docker environments
- `run_tests.sh` - Test execution script

## Exercises

### 1. Copy Constructor Basics
Focuses on implementing and understanding copy constructors:
- Creating deep copies of dynamically allocated resources
- Understanding when copy constructors are called
- Distinguishing copy constructors from copy assignment operators

### 2. Copy Assignment Operator Basics
Covers implementing copy assignment operators:
- Proper resource management during assignment
- Self-assignment handling
- Distinguishing copy assignment from copy construction

### 3. Destructor Basics
Explores destructor implementation and behavior:
- Proper resource cleanup
- Understanding when destructors are called
- Order of destruction
- Virtual destructors in inheritance

## Key Concepts

### The Rule of Three
If a class needs a custom:
1. Destructor
2. Copy constructor
3. Copy assignment operator

Then it likely needs all three.

### The Rule of Five (C++11)
With move semantics, the rule extends to five special member functions:
1. Destructor
2. Copy constructor
3. Copy assignment operator
4. Move constructor
5. Move assignment operator

### Automatic Invocation
- **Copy Constructor**: `MyClass obj2 = obj1;` or `MyClass obj2(obj1);`
- **Copy Assignment**: `obj2 = obj1;` (both objects already exist)
- **Destructor**: When objects go out of scope or are deleted

### Resource Management
Proper copy control is essential for classes that manage resources:
- Dynamically allocated memory
- File handles
- Network connections
- Other system resources

## Prerequisites

Students should be familiar with:
- Basic C++ syntax and object-oriented programming
- Dynamic memory allocation with new/delete
- Class constructors and destructors
- Basic understanding of stack vs heap memory

## Building and Running

Each exercise can be built and run using the provided shell scripts:

```bash
# Build the exercise
./build.sh

# Run the exercise solution
./build/destructor_basics_solutions

# Run tests
./run_tests.sh
```

Note: These exercises are designed to run in a Linux/Docker environment. Windows batch files are not provided.