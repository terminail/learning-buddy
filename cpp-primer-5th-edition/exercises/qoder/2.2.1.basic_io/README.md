# Exercise 2.2.1: Basic Input/Output Operations

This exercise introduces you to C++ input/output operations using cin and cout. You'll learn how to interact with users by reading input and displaying output.

## Learning Objectives

- Understand C++ I/O streams (cin, cout, cerr)
- Learn how to prompt users for input and read different data types
- Practice displaying formatted output to the console
- Understand the difference between cin >> and getline() for string input

## Exercise Files

- [basic_io_exercises.cpp](src/basic_io_exercises.cpp) - Your exercise implementation
- [basic_io_solutions.cpp](src/basic_io_solutions.cpp) - Reference solution
- [test_basic_io_basics.cpp](test/test_basic_io_basics.cpp) - Basic tests
- [test_basic_io_practice.cpp](test/test_basic_io_practice.cpp) - Practice problems

## Instructions

1. Open [basic_io_exercises.cpp](src/basic_io_exercises.cpp)
2. Follow the TODO comments to create a program that collects user information
3. Compile and run your program to test the input/output operations
4. Compare your solution with [basic_io_solutions.cpp](src/basic_io_solutions.cpp)

## Basic I/O Operations Overview

In C++, input/output operations are performed using streams:

- `std::cin` - Standard input stream (keyboard)
- `std::cout` - Standard output stream (console)
- `std::cerr` - Standard error stream (console)

### Output Operations

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name = "John";
    int age = 25;
    
    // Basic output
    std::cout << "Hello, World!" << std::endl;
    
    // Output with variables
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
    
    return 0;
}
```

### Input Operations

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;
    
    // Prompt and read string (single word)
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Prompt and read integer
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    return 0;
}
```

### Reading Full Lines

```cpp
#include <iostream>
#include <string>

int main() {
    std::string fullName;
    
    // Read entire line including spaces
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);
    
    return 0;
}
```

## Example Usage

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;
    double height;
    
    // Prompt user for their name and read it
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    // Prompt user for their age and read it
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    // Prompt user for their height and read it
    std::cout << "Enter your height (in meters): ";
    std::cin >> height;
    
    // Display all the collected information
    std::cout << "\n--- User Information ---" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << " years" << std::endl;
    std::cout << "Height: " << height << " meters" << std::endl;
    
    return 0;
}
```

## Common Issues and Solutions

### Issue 1: Mixing cin >> and getline()
**Problem**: getline() reads the leftover newline character
**Solution**: Use cin.ignore() to clear the buffer

```cpp
std::cin >> age;        // Leaves newline in buffer
std::cin.ignore();      // Clear the buffer
std::getline(std::cin, name);  // Now works correctly
```

### Issue 2: Input Buffer Problems
**Problem**: Previous input affects subsequent input
**Solution**: Clear the input buffer when needed

```cpp
std::cin.clear();       // Clear error flags
std::cin.ignore(10000, '\n');  // Ignore until newline
```

## Testing

To run the tests for this exercise:

```bash
mkdir build
cd build
cmake ..
make
./test_basic_io_basics
./test_basic_io_practice
```

## Next Steps

After completing this exercise, you should:
1. Understand how to perform basic input/output operations
2. Know the difference between cin >> and getline()
3. Be able to handle common I/O issues
4. Understand input buffer management

Continue with the next exercise to learn about control structures (if/else statements and loops).