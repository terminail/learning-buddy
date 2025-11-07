# C++ Primer Exercise Template

## Overview

This template provides a comprehensive system for creating C++ Primer exercises that follow Test-Driven Development methodology with clear question-answer separation. The template follows a flatter, more practical structure with clear question-answer pattern using student files for implementation and solution files for reference.

## Quick Start

### Step 1: Use the Template Structure

Copy the template to create a new exercise directory:

```bash
# Copy the template to create a new exercise
# Use the chapter.section.exercise_number format to organize exercises
# Example: 4.5.2 for Chapter 4, Section 5, Exercise 2
cp -r cpp_template 4.5.2.your_exercise_name
```

The chapter numbering system:
- First number (4) = Chapter number (corresponding to C++ Primer 5th Edition chapters)
- Second number (5) = Section number (corresponding to subsections within chapters)
- Third number (2) = Exercise number (exercise sequence within the subsection)

This naming convention helps:
1. Organize exercises according to the C++ Primer textbook structure
2. Progressive learning from basic concepts to advanced topics
3. Easily locate exercises related to textbook content

### Step 2: Rename Files

Update all files following this pattern:

```bash
Original → New
──────────────────────────────────────
exercise_name_exercises.h → your_exercise_exercises.h
exercise_name_solutions.h → your_exercise_solutions.h
exercise_name_exercises.cpp → your_exercise_exercises.cpp
exercise_name_solutions.cpp → your_exercise_solutions.cpp
test_exercise_name_basics.cpp → test_your_exercise_basics.cpp
test_exercise_name_practice.cpp → test_your_exercise_practice.cpp
```

### Step 3: Update Content

#### Update Header Files
In `include/exercise_name_exercises.h`:
```cpp
// Change class name
class YourExerciseName {
    // Update function names and documentation
    std::string basic_operation(const std::string& input);
    // ... other functions
};
```

In `include/exercise_name_solutions.h`:
```cpp
class YourExerciseNameSolutions {
    // Complete implementations
};
```

#### Update Implementation Files
In `src/exercise_name_exercises.cpp`:
```cpp
#include "exercise_name_exercises.h"

namespace cpp_primer {

// Update class name in all function definitions
std::string YourExerciseName::basic_operation(const std::string& input) {
    // TODO: Implement
}

} // namespace cpp_primer
```

#### Update Test Files
In `test/test_exercise_name_basics.cpp`:
```cpp
#include "exercise_name_exercises.h"

using namespace cpp_primer;

// Update class name in all tests
TEST_F(YourExerciseNameTest, BasicOperation) {
    YourExerciseName exercise;
    EXPECT_EQ(exercise.basic_operation("test"), "test_processed");
}
```

### Step 4: Update CMakeLists.txt
Update the project name and file references:
```cmake
project(your_exercise_name)

# Update library and executable names
add_library(your_exercise_exercises src/your_exercise_exercises.cpp)
add_library(your_exercise_solutions src/your_exercise_solutions.cpp)

add_executable(test_your_exercise_basics test/test_your_exercise_basics.cpp)
add_executable(test_your_exercise_practice test/test_your_exercise_practice.cpp)
```

## Template Structure

```
cpp_template/
├── README.md                    # This file
├── USAGE_GUIDE.md               # Detailed usage instructions
├── CMakeLists.txt               # Build configuration with custom targets
├── include/
│   ├── empty_exercise_name_exercises.h  # Empty student header template
│   ├── empty_exercise_name_solutions.h  # Empty solution header template
│   ├── exercise_name_exercises.h        # Student header (TODO comments)
│   └── exercise_name_solutions.h        # Solution header (complete)
├── src/
│   ├── exercise_name_exercises.cpp      # Student implementation (with starter code)
│   └── exercise_name_solutions.cpp      # Complete solution implementations
└── test/
    ├── test_exercise_name_basics.cpp    # Core functionality tests
    └── test_exercise_name_practice.cpp  # Advanced practice challenges
```

## Key Features

### Improved Flat Structure
- **Practical Naming**: `chapter.section.exercise_name` format (e.g., `3.1.2.string_basics`)
- **Clear File Suffixes**: `_exercises` for student work, `_solutions` for reference

### Question-Answer Pattern
- **Student Files** (`*_exercises.*`): Contain TODO comments for implementation
- **Solution Files** (`*_solutions.*`): Complete reference implementations
- **Clear Separation**: Students learn by comparing their work with solutions

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

## Choosing the Right Template Approach

### For Complex Exercises (Classes, Multiple Functions)
Use the full template with class declarations in header files:
1. Keep the existing header files (`exercise_name_exercises.h`, `exercise_name_solutions.h`)
2. Implement class methods in the source files
3. Add function declarations in headers, implementations in source files

### For Simple Exercises (Basic Syntax, Single Functions)
Use empty headers for simpler exercises:
1. Copy empty header templates:
   ```bash
   cp include/empty_exercise_name_exercises.h include/your_exercise_name_exercises.h
   cp include/empty_exercise_name_solutions.h include/your_exercise_name_solutions.h
   ```
2. Implement directly in source files without class declarations
3. Example for a "Hello World" exercise:
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