# Exercise 2.2.1: Basic Input/Output Operations - Implementation Guide

This guide provides detailed instructions for implementing the basic input/output operations exercise.

## Exercise Overview

This exercise focuses on C++ input/output operations using streams. Students will learn how to interact with users through console input and output.

## Learning Objectives

By completing this exercise, students will be able to:
- Use std::cin and std::cout for basic I/O operations
- Read different data types from user input
- Display formatted output to the console
- Understand and handle input buffer issues
- Differentiate between cin >> and getline() for string input

## Detailed Implementation Steps

### Step 1: Understanding I/O Streams

C++ provides several standard streams:
- `std::cin` - for input (keyboard)
- `std::cout` - for output (console)
- `std::cerr` - for error messages (console)
- `std::clog` - for logging messages (console)

### Step 2: Basic Output Operations

Output is performed using the insertion operator (<<):

```cpp
std::cout << "Hello, World!" << std::endl;
std::cout << "Value: " << variable << std::endl;
```

### Step 3: Basic Input Operations

Input is performed using the extraction operator (>>):

```cpp
int number;
std::cout << "Enter a number: ";
std::cin >> number;
```

### Step 4: Reading Strings

For single words:
```cpp
std::string word;
std::cin >> word;  // Stops at whitespace
```

For full lines:
```cpp
std::string line;
std::getline(std::cin, line);  // Reads entire line
```

## Common Mistakes and Tips

### Common Mistakes:
1. Forgetting to include `<string>` header when using `std::string`
2. Mixing `cin >>` and `getline()` without clearing the buffer
3. Not handling input errors or invalid data
4. Forgetting to prompt users before requesting input

### Tips:
1. Always prompt users before requesting input
2. Use `std::getline()` for strings that may contain spaces
3. Clear the input buffer when mixing different input methods
4. Validate user input when possible

## Exercise Requirements

Complete the TODO comments in [basic_io_exercises.cpp](src/basic_io_exercises.cpp):

1. Declare variables to store user information (name, age, height)
2. Prompt user for their name and read it using getline()
3. Prompt user for their age and read it
4. Prompt user for their height and read it
5. Display all the collected information in a formatted way

## Solution Verification

To verify your solution:

1. Compile the exercise:
   ```bash
   g++ -std=c++17 src/basic_io_exercises.cpp -o basic_io_exercise
   ```

2. Run the executable and test with various inputs:
   ```bash
   ./basic_io_exercise
   ```

3. Compare your output with the reference solution in [basic_io_solutions.cpp](src/basic_io_solutions.cpp)

## Advanced Challenges

For students who want additional practice:

1. Add input validation to ensure age is reasonable (0-150)
2. Add input validation to ensure height is reasonable (0.1-3.0 meters)
3. Handle multiple users in one program run
4. Add error handling for invalid input types

## Input Buffer Management

Understanding input buffers is crucial:

```cpp
int age;
std::string name;

std::cout << "Enter age: ";
std::cin >> age;           // Leaves newline in buffer

std::cin.ignore();         // Clear the newline

std::cout << "Enter name: ";
std::getline(std::cin, name);  // Now works correctly
```

## Testing

Run the provided tests to verify your implementation:

```bash
mkdir build
cd build
cmake ..
make
./test_basic_io_basics
./test_basic_io_practice
```

## Next Exercise

After completing this exercise, proceed to learn about control structures (if/else statements and loops), which will build upon your understanding of variables and I/O operations.