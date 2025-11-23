# Chapter Exercise Template

## Overview

This template provides a complete structure for creating C++ Primer exercises following the question-answer pattern with student/solution file pairs. It includes build configuration, unit tests, and a structured learning approach.

For detailed instructions on how to use this template to create exercises, see [USAGE_GUIDE.md](USAGE_GUIDE.md).

## Quick Start

### 1. Copy Template
```bash
# Copy to create a new exercise (use chapter.section.exercise_name format)
cp -r chapter.exercise_name 3.1.2.string_operations
```

### 2. Customize Project Name
Update the project name in `CMakeLists.txt`:
```cmake
project(string_operations)  # Replace with your exercise name
```

### 2. Rename Files
Update all files following this pattern (example for a string operations exercise):
- `exercise_name_exercises.*` → `string_operations_exercises.*`
- `exercise_name_solutions.*` → `string_operations_solutions.*`
- `test_exercise_name_basics.cpp` → `test_string_operations_basics.cpp`
- `test_exercise_name_practice.cpp` → `test_string_operations_practice.cpp`

具体示例：
```bash
# 重命名头文件
mv include/exercise_name_exercises.h include/string_operations_exercises.h
mv include/exercise_name_solutions.h include/string_operations_solutions.h

# For empty header files (simpler exercises):
cp include/empty_exercise_name_exercises.h include/string_operations_exercises.h
cp include/empty_exercise_name_solutions.h include/string_operations_solutions.h

# 重命名源文件
mv src/exercise_name_exercises.cpp src/string_operations_exercises.cpp
mv src/exercise_name_solutions.cpp src/string_operations_solutions.cpp

# 重命名测试文件
mv test/test_exercise_name_basics.cpp test/test_string_operations_basics.cpp
mv test/test_exercise_name_practice.cpp test/test_string_operations_practice.cpp
```

### 4. Update Content
- Modify class names and function declarations in header files (or leave empty for simple exercises)
- Update test cases for your specific exercise requirements
- Customize CMakeLists.txt with new target names

## File Structure

```
chapter.exercise_name/
├── README.md                    # Project overview and instructions
├── USAGE_GUIDE.md               # Detailed usage instructions for creating exercises
├── EXERCISE_NAME_GUIDE.md       # Implementation guide for exercise content
├── CMakeLists.txt               # Build configuration with custom targets
├── include/
│   ├── empty_exercise_name_exercises.h  # Empty student header template
│   ├── empty_exercise_name_solutions.h  # Empty solution header template
│   ├── exercise_name_exercises.h        # Student header (TODO comments)
│   └── exercise_name_solutions.h        # Solution header (complete implementations)
├── src/
│   ├── exercise_name_exercises.cpp      # Student implementation (with starter code)
│   └── exercise_name_solutions.cpp      # Complete solution implementations
└── test/
    ├── test_exercise_name_basics.cpp    # Core functionality tests
    └── test_exercise_name_practice.cpp  # Advanced practice challenges
```

## Template Features

### Question-Answer Pattern
- **Student Files** (`*_exercises.*`): Contain TODO comments for student implementation
- **Solution Files** (`*_solutions.*`): Complete reference implementations
- **Clear Separation**: Students learn by implementing and comparing with solutions

### Comprehensive Testing
- **Google Test Integration**: Full TDD workflow support
- **Multiple Test Categories**: Basic functionality, edge cases, performance
- **Practice Problems**: Additional challenges in practice tests
- **Custom Test Targets**: Run specific test categories (basics, practice, all)

### Modern C++ Standards
- **C++17 Compliance**: Uses modern language features
- **Best Practices**: RAII, smart pointers, error handling
- **Code Quality**: Compiler warnings enabled

## Custom Build and Test Commands

The template includes custom CMake targets for efficient workflow:

- `cmake --build .` - Build all executables
- `make run_tests` or `ninja run_tests` - Run all tests with detailed output
- `make run_basics` or `ninja run_basics` - Run basic tests only
- `make run_practice` or `ninja run_practice` - Run practice tests only
- `ctest -L basics` - Run tests labeled as "basics"
- `ctest -L practice` - Run tests labeled as "practice"

## Implementation Workflow

1. **Setup**: Copy template and customize names
2. **Student Implementation**: Complete functions in `*_exercises.*` files
3. **Test Validation**: Run `make run_tests` to check correctness
4. **Compare Solutions**: Review `*_solutions.*` for optimal implementations
5. **Practice Extension**: Solve additional problems in practice tests

## Naming Convention

### Directory Structure
```
chapter.section.exercise_name/
Examples:
3.1.2.string_basics/          # Chapter 3, Section 1, Exercise 2
4.2.1.vector_operations/      # Chapter 4, Section 2, Exercise 1
5.3.3.class_design/           # Chapter 5, Section 3, Exercise 3
```

### File Naming
```
*_exercises.h/.cpp     # Student implementation files
*_solutions.h/.cpp     # Solution reference files
test_*_basics.cpp      # Main test suite
test_*_practice.cpp    # Practice problems
```

## Getting Started

1. **Copy Template**: Use the chapter.section.exercise_name naming convention
2. **Customize**: Update project name, file names, and content for your exercise
3. **Build & Test**: Verify the exercise builds and tests pass
4. **Implement**: Students follow TODO comments and test frequently
5. **Extend**: Add custom functions and tests as needed for your specific exercise

## Simple Exercises

For very simple exercises (e.g., basic syntax exercises like "hello world"), you can use empty header files:

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

## Common Exercise Types

The template works well for various C++ concept exercises:
- Basic syntax and control structures
- String and vector operations
- Class design and member functions
- Template and generic programming
- STL algorithms and containers
- Memory management and RAII
- Exception handling

This template provides a solid foundation for creating effective C++ learning exercises that support progressive skill development and testing-driven learning.