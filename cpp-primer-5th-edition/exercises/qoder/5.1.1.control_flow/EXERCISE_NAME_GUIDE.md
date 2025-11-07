# Exercise 5.1.1: Control Flow Statements - Implementation Guide

This guide provides detailed instructions for implementing the control flow statements exercise.

## Exercise Overview

This exercise focuses on C++ control flow statements including conditional statements (if/else) and loops (for, while). Students will learn how to control program execution flow.

## Learning Objectives

By completing this exercise, students will be able to:
- Use if, else if, and else statements for decision making
- Implement different types of loops (for, while, do-while)
- Create nested control structures
- Use loop control statements (break, continue)
- Solve problems using control flow patterns

## Detailed Implementation Steps

### Step 1: Understanding Conditional Statements

Conditional statements allow your program to make decisions:

```cpp
// Basic if statement
if (condition) {
    // Execute this code if condition is true
}

// If-else statement
if (condition) {
    // Execute this code if condition is true
} else {
    // Execute this code if condition is false
}

// Multiple conditions
if (condition1) {
    // Code for condition1
} else if (condition2) {
    // Code for condition2
} else {
    // Code for all other cases
}
```

### Step 2: Understanding Loops

Loops allow you to repeat code multiple times:

```cpp
// For loop - used when you know the number of iterations
for (int i = 0; i < 10; i++) {
    // Code to repeat
}

// While loop - used when you don't know the number of iterations
int counter = 0;
while (counter < 5) {
    // Code to repeat
    counter++;
}

// Do-while loop - executes at least once
int value = 0;
do {
    // Code to execute
    value++;
} while (value < 3);
```

### Step 3: Loop Control Statements

```cpp
// Break - exits the loop completely
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;  // Exit loop when i equals 5
    }
    std::cout << i << " ";
}

// Continue - skips to the next iteration
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        continue;  // Skip iteration when i equals 5
    }
    std::cout << i << " ";
}
```

## Common Mistakes and Tips

### Common Mistakes:
1. Forgetting curly braces {} for multi-line if/else blocks
2. Using = (assignment) instead of == (comparison) in conditions
3. Off-by-one errors in loop conditions
4. Infinite loops due to incorrect loop update statements
5. Not initializing loop variables

### Tips:
1. Always use curly braces {} even for single-line blocks
2. Use meaningful variable names for loop counters
3. Double-check loop conditions to avoid infinite loops
4. Test edge cases (0, 1, negative numbers)
5. Use debugger to step through loops

## Exercise Requirements

Complete the TODO comments in [control_flow_exercises.cpp](src/control_flow_exercises.cpp):

1. Create a program that determines if a number is positive, negative, or zero
2. Create a program that prints numbers from 1 to 10 using a for loop
3. Create a program that calculates the sum of numbers from 1 to n using a while loop
4. Create a program that prints a pattern of stars using nested loops

## Solution Verification

To verify your solution:

1. Compile the exercise:
   ```bash
   g++ -std=c++17 src/control_flow_exercises.cpp -o control_flow_exercise
   ```

2. Run the executable and test with various inputs:
   ```bash
   ./control_flow_exercise
   ```

3. Compare your output with the reference solution in [control_flow_solutions.cpp](src/control_flow_solutions.cpp)

## Advanced Challenges

For students who want additional practice:

1. Implement a program that finds prime numbers up to a given limit
2. Create a menu-driven program using switch statements
3. Implement a number guessing game with loop control
4. Create more complex patterns using nested loops

## Testing

Run the provided tests to verify your implementation:

```bash
mkdir build
cd build
cmake ..
make
./test_control_flow_basics
./test_control_flow_practice
```

## Next Exercise

After completing this exercise, proceed to learn about functions and scope, which will build upon your understanding of control flow.