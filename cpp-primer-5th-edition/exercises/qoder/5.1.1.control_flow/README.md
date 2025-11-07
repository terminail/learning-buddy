# Exercise 5.1.1: Control Flow Statements

This exercise introduces you to C++ control flow statements: if/else conditions and loops. You'll learn how to make decisions in your programs and repeat actions.

## Learning Objectives

- Understand conditional statements (if, else if, else)
- Learn different types of loops (for, while, do-while)
- Practice creating nested control structures
- Understand loop control statements (break, continue)
- Learn to create patterns and solve problems using control flow

## Exercise Files

- [control_flow_exercises.cpp](src/control_flow_exercises.cpp) - Your exercise implementation
- [control_flow_solutions.cpp](src/control_flow_solutions.cpp) - Reference solution
- [test_control_flow_basics.cpp](test/test_control_flow_basics.cpp) - Basic tests
- [test_control_flow_practice.cpp](test/test_control_flow_practice.cpp) - Practice problems

## Instructions

1. Open [control_flow_exercises.cpp](src/control_flow_exercises.cpp)
2. Follow the TODO comments to implement various control flow structures
3. Compile and run your program to test the control flow operations
4. Compare your solution with [control_flow_solutions.cpp](src/control_flow_solutions.cpp)

## Control Flow Statements Overview

Control flow statements allow you to control the execution flow of your program based on conditions or repetition.

### Conditional Statements

```cpp
// Simple if statement
if (condition) {
    // Code to execute if condition is true
}

// If-else statement
if (condition) {
    // Code to execute if condition is true
} else {
    // Code to execute if condition is false
}

// If-else if-else chain
if (condition1) {
    // Code for condition1
} else if (condition2) {
    // Code for condition2
} else {
    // Code for all other cases
}
```

### Loops

```cpp
// For loop
for (initialization; condition; increment) {
    // Code to repeat
}

// While loop
while (condition) {
    // Code to repeat while condition is true
}

// Do-while loop
do {
    // Code to execute at least once
} while (condition);
```

## Example Usage

```cpp
#include <iostream>

int main() {
    // Conditional statement example
    int number = 5;
    if (number > 0) {
        std::cout << "Positive number" << std::endl;
    } else if (number < 0) {
        std::cout << "Negative number" << std::endl;
    } else {
        std::cout << "Zero" << std::endl;
    }
    
    // For loop example
    std::cout << "Counting from 1 to 5: ";
    for (int i = 1; i <= 5; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // While loop example
    int counter = 0;
    while (counter < 3) {
        std::cout << "Counter: " << counter << std::endl;
        counter++;
    }
    
    return 0;
}
```

## Common Control Flow Patterns

### 1. Number Classification
```cpp
if (number > 0) {
    std::cout << "Positive" << std::endl;
} else if (number < 0) {
    std::cout << "Negative" << std::endl;
} else {
    std::cout << "Zero" << std::endl;
}
```

### 2. Counting Loop
```cpp
for (int i = 1; i <= 10; i++) {
    std::cout << i << " ";
}
```

### 3. Summation Loop
```cpp
int sum = 0;
for (int i = 1; i <= n; i++) {
    sum += i;
}
```

### 4. Pattern Generation
```cpp
for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= i; j++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}
```

## Testing

To run the tests for this exercise:

```bash
mkdir build
cd build
cmake ..
make
./test_control_flow_basics
./test_control_flow_practice
```

## Next Steps

After completing this exercise, you should:
1. Understand how to use conditional statements for decision making
2. Know how to implement different types of loops
3. Be able to create nested control structures
4. Understand loop control statements (break, continue)

Continue with the next exercise to learn about functions and scope.

# Control Flow Exercises

## Overview
This directory contains a series of exercises focused on control flow statements in C++, including if statements, loops, and nested control structures. These exercises are designed to help you master decision making and repetition in C++ programs.

## Exercises

### 1. If Statements ([if_statements](if_statements/))
Learn how to make decisions in your programs using conditional statements.

**Key Concepts**:
- Basic if statements
- if/else statements
- if/else if/else chains
- Comparison operators

### 2. Loop Statements ([loop_statements](loop_statements/))
Learn how to repeat actions using different types of loops.

**Key Concepts**:
- For loops
- While loops
- Do-while loops
- Loop control

### 3. Nested Control Statements ([nested_statements](nested_statements/))
Learn how to combine multiple control structures for complex logic.

**Key Concepts**:
- Nested loops
- Nested if statements
- Complex control flow patterns

## Getting Started

### Prerequisites
- C++ compiler (supporting C++17 or later)
- CMake (version 3.10 or later)
- Google Test framework (for running tests)

### Building Individual Exercises
Each exercise can be built separately:

```bash
cd if_statements
mkdir build
cd build
cmake ..
make
```

### Building All Exercises
To build all exercises at once:

```bash
cd control_flow
mkdir build
cd build
cmake ..
make build_all_exercises
```

## Running Exercises

### Running Exercise Solutions
Each exercise includes a solution executable:

```bash
./if_statements/build/if_statements_solutions
./loop_statements/build/loop_statements_solutions
./nested_statements/build/nested_statements_solutions
```

### Running Tests
Each exercise includes tests to validate your implementation:

```bash
./if_statements/build/test_if_statements_basics
./loop_statements/build/test_loop_statements_basics
./nested_statements/build/test_nested_statements_basics
```

## Learning Path
It's recommended to complete the exercises in the following order:
1. [If Statements](if_statements/) - Foundation for decision making
2. [Loop Statements](loop_statements/) - Foundation for repetition
3. [Nested Control Statements](nested_statements/) - Combining control structures

## Resources
- [C++ Primer 5th Edition](https://www.amazon.com/Primer-5th-Stanley-Lippman/dp/0321714113) - The textbook these exercises accompany
- [CONTROL_FLOW_EXERCISES_SUMMARY.md](CONTROL_FLOW_EXERCISES_SUMMARY.md) - Detailed summary of all exercises
- [if_statements/README.md](if_statements/README.md) - If statements exercise documentation
- [loop_statements/README.md](loop_statements/README.md) - Loop statements exercise documentation
- [nested_statements/README.md](nested_statements/README.md) - Nested statements exercise documentation
