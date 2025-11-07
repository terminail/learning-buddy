# Exercise Template Implementation Guide

## Template Overview

This guide explains how to implement content within the exercise template. For instructions on how to use the template to create new exercises, see [USAGE_GUIDE.md](USAGE_GUIDE.md).

## Template Structure

### 1. Header Files
- **Student Header** (`include/exercise_name_exercises.h`): Contains TODO comments for student implementation with function declarations
- **Solution Header** (`include/exercise_name_solutions.h`): Complete reference implementation with fully documented code
- **Empty Templates** (`include/empty_exercise_name_*.h`): Minimal header files for simpler exercises

### 2. Source Files
- **Student Source** (`src/exercise_name_exercises.cpp`): Starter implementations with TODO comments for student to complete
- **Solution Source** (`src/exercise_name_solutions.cpp`): Complete implementations (often just includes header with inline implementations)

### 3. Test Files
- **Basic Tests** (`test/test_exercise_name_basics.cpp`): Core functionality tests covering basic operations and edge cases
- **Practice Tests** (`test/test_exercise_name_practice.cpp`): Extended challenges for advanced learners

## Customization Steps

### 1. Rename Files and Directories
Update all file names following this pattern (example for string operations exercise):
- Directory: `chapter.exercise_name` → `3.1.2.string_operations`
- Files: `exercise_name_exercises.*` → `string_operations_exercises.*`
- Files: `exercise_name_solutions.*` → `string_operations_solutions.*`
- Tests: `test_exercise_name_basics.cpp` → `test_string_operations_basics.cpp`
- Tests: `test_exercise_name_practice.cpp` → `test_string_operations_practice.cpp`

具体示例：
```bash
# 重命名目录
mv chapter.exercise_name 3.1.2.string_operations
cd 3.1.2.string_operations

# 重命名头文件 (full template)
mv include/exercise_name_exercises.h include/string_operations_exercises.h
mv include/exercise_name_solutions.h include/string_operations_solutions.h

# Or use empty header files for simpler exercises:
cp include/empty_exercise_name_exercises.h include/string_operations_exercises.h
cp include/empty_exercise_name_solutions.h include/string_operations_solutions.h

# 重命名源文件
mv src/exercise_name_exercises.cpp src/string_operations_exercises.cpp
mv src/exercise_name_solutions.cpp src/string_operations_solutions.cpp

# 重命名测试文件
mv test/test_exercise_name_basics.cpp test/test_string_operations_basics.cpp
mv test/test_exercise_name_practice.cpp test/test_string_operations_practice.cpp
```

### 2. Update Content
- **Class Names**: Change `ExerciseName` to `StringOperations`
- **Function Declarations**: Update for your specific exercise requirements
- **Test Cases**: Modify to test your exercise's functionality with appropriate assertions
- **CMakeLists.txt**: Update project name and target names

### 3. Add Exercise-Specific Content
- **Learning Objectives**: Define 2-4 specific learning goals
- **Prerequisites**: List required C++ concepts (e.g., strings, vectors, classes)
- **Estimated Time**: Set realistic time expectations (30-60 minutes for basics, 60-90 for practice)
- **Success Criteria**: Define what constitutes successful completion

## Implementation Workflow

1. **Setup**: Copy template and customize names
2. **Student Implementation**: Complete functions in `*_exercises.*` files following TODO comments
3. **Test Validation**: Run `make run_tests` to check correctness incrementally
4. **Learning Comparison**: Review `*_solutions.*` for optimal implementations and best practices
5. **Practice Extension**: Solve additional problems in practice tests for deeper understanding

## Best Practices

### File Organization
- Use consistent naming conventions matching the directory name
- Separate student and solution code clearly to prevent accidental copying
- Include comprehensive test coverage for both basic and edge cases
- Follow C++ best practices and modern standards (C++17 features)

### Learning Design
- Start with simple concepts and progress to complex ones in a logical sequence
- Include both basic and advanced operations to accommodate different skill levels
- Provide clear TODO comments with specific implementation guidance
- Include practice problems that extend beyond basic requirements

### Testing Strategy
- Test basic functionality with typical inputs
- Include edge cases (empty inputs, special characters, boundary conditions)
- Provide practice problems for additional challenges
- Ensure tests are clear, informative, and provide meaningful feedback

## Template File Structure

```
chapter.exercise_name/
├── CMakeLists.txt               # Build configuration with custom targets
├── USAGE_GUIDE.md               # Instructions for using the template to create exercises
├── EXERCISE_NAME_GUIDE.md       # This implementation guide
├── README.md                    # Project overview and instructions
├── include/
│   ├── empty_exercise_name_exercises.h  # Empty student header template
│   ├── empty_exercise_name_solutions.h  # Empty solution header template
│   ├── exercise_name_exercises.h        # Student header (TODO comments)
│   └── exercise_name_solutions.h        # Solution header (complete implementations)
├── src/
│   ├── exercise_name_exercises.cpp      # Student implementation (starter code)
│   └── exercise_name_solutions.cpp      # Solution implementation
└── test/
    ├── test_exercise_name_basics.cpp    # Core functionality tests
    └── test_exercise_name_practice.cpp  # Advanced practice challenges
```

## Quick Start Example

To create a new exercise for Chapter 3, Section 1, Exercise 2 on string operations:

```bash
# Copy template with proper naming convention
cp -r chapter.exercise_name 3.1.2.string_operations

# Navigate to the new directory
cd 3.1.2.string_operations

# For a full exercise with class declarations:
mv include/exercise_name_exercises.h include/string_operations_exercises.h
mv include/exercise_name_solutions.h include/string_operations_solutions.h

# For a simple exercise with empty headers:
# cp include/empty_exercise_name_exercises.h include/string_operations_exercises.h
# cp include/empty_exercise_name_solutions.h include/string_operations_solutions.h

# Rename source and test files
mv src/exercise_name_exercises.cpp src/string_operations_exercises.cpp
mv src/exercise_name_solutions.cpp src/string_operations_solutions.cpp
mv test/test_exercise_name_basics.cpp test/test_string_operations_basics.cpp
mv test/test_exercise_name_practice.cpp test/test_string_operations_practice.cpp

# Update content in all files:
# 1. Change ExerciseName class to StringOperations
# 2. Update function declarations for string operations (reverse, count, etc.)
# 3. Modify test cases to match your exercise requirements
# 4. Update CMakeLists.txt with project(string_operations) and new target names
```

## Simple Exercises with Empty Headers

For very simple exercises that don't require class declarations (e.g., basic syntax exercises like "hello world"), you can use the empty header templates:

1. Copy the empty header templates:
   ```bash
   cp include/empty_exercise_name_exercises.h include/your_exercise_name_exercises.h
   cp include/empty_exercise_name_solutions.h include/your_exercise_name_solutions.h
   ```

2. Implement your solution directly in the source files without class declarations

Example for a simple "hello world" exercise:
```cpp
// In src/hello_world_exercises.cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

This approach is suitable for:
- Basic syntax introduction exercises
- Simple input/output exercises
- Early learning exercises focusing on fundamentals
- Quick practice problems without complex class design

## When to Use Empty Headers

Use the empty header files for:
- Very simple exercises focusing on basic syntax
- Quick practice problems without class design
- Introductory exercises for beginners
- Exercises where header/source separation is not the learning objective

Use the full template headers for:
- Complex exercises with multiple classes
- Exercises teaching proper header/source organization
- Advanced topics requiring detailed class design
- Exercises where students need to learn header file structure

## Common Exercise Patterns

### String Operations Exercise
- Functions: reverse, count characters, remove duplicates, find substrings
- Concepts: String manipulation, loops, conditionals, standard algorithms

### Container Operations Exercise
- Functions: Add/remove elements, find/search, sort/filter
- Concepts: STL containers (vector, list, map), iterators, algorithms

### Class Design Exercise
- Functions: Constructor/destructor, member functions, operators
- Concepts: RAII, encapsulation, resource management

### Template Exercise
- Functions: Generic algorithms, type traits
- Concepts: Templates, generic programming, SFINAE

## Testing Guidelines

1. **Basic Tests**: Cover core functionality with typical inputs
2. **Edge Cases**: Handle empty inputs, boundary conditions, error conditions
3. **Performance Tests**: Include tests for efficiency with larger inputs
4. **Practice Tests**: Provide challenges that extend beyond basic requirements

This template provides a solid foundation for creating effective C++ learning exercises that support progressive skill development through test-driven learning and solution comparison.

# Exercise 2.1.1: Variables and Basic Types - Implementation Guide

This guide provides detailed instructions for implementing the variables and basic types exercise.

## Exercise Overview

This exercise focuses on C++ variables and basic data types. Students will learn how to declare, initialize, and use variables of different types in simple programs.

## Learning Objectives

By completing this exercise, students will be able to:
- Declare variables of different basic types (int, double, char, bool, string)
- Initialize variables with appropriate values
- Use variables in expressions and output statements
- Understand the differences between basic data types

## Detailed Implementation Steps

### Step 1: Understanding Variable Declaration

Variables must be declared before they can be used. The syntax is:
```cpp
type variable_name;
```

Examples:
```cpp
int age;
double height;
char grade;
bool isStudent;
std::string name;
```

### Step 2: Variable Initialization

Variables can be initialized when declared:
```cpp
type variable_name = value;
```

Examples:
```cpp
int age = 25;
double height = 1.75;
char grade = 'A';
bool isStudent = true;
std::string name = "John";
```

### Step 3: Using Variables

Variables can be used in expressions, assignments, and output statements:
```cpp
std::cout << "Name: " << name << std::endl;
int nextYear = age + 1;
```

## Common Mistakes and Tips

### Common Mistakes:
1. Forgetting to include `<string>` header when using `std::string`
2. Using single quotes for strings (should be double quotes)
3. Using double quotes for characters (should be single quotes)
4. Not initializing variables before using them

### Tips:
1. Always initialize variables when declaring them
2. Use meaningful variable names
3. Include necessary headers (`<string>` for std::string)
4. Use `std::endl` or `\n` to end output lines

## Exercise Requirements

Complete the TODO comments in [variables_types_exercises.cpp](src/variables_types_exercises.cpp):

1. Declare an integer variable named 'age' and initialize it with your age
2. Declare a double variable named 'height' and initialize it with your height in meters
3. Declare a char variable named 'grade' and initialize it with your grade (A, B, C, D, or F)
4. Declare a bool variable named 'isStudent' and initialize it appropriately
5. Declare a string variable named 'name' and initialize it with your name
6. Print all variables to the console

## Solution Verification

To verify your solution:

1. Compile the exercise:
   ```bash
   g++ -std=c++17 src/variables_types_exercises.cpp -o variables_exercise
   ```

2. Run the executable:
   ```bash
   ./variables_exercise
   ```

3. Compare your output with the reference solution in [variables_types_solutions.cpp](src/variables_types_solutions.cpp)

## Advanced Challenges

For students who want additional practice:

1. Try declaring variables without initialization and observe what values they contain
2. Experiment with different data types and their ranges
3. Try mixing different types in expressions and observe implicit conversions
4. Practice with const variables: `const int max_value = 100;`

## Testing

Run the provided tests to verify your implementation:

```bash
mkdir build
cd build
cmake ..
make
./test_variables_types_basics
./test_variables_types_practice
```

## Next Exercise

After completing this exercise, proceed to learn about operators and expressions, which will build upon your understanding of variables.