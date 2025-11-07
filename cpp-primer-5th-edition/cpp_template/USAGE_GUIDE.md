# C++ Primer Exercise Template - Usage Guide

## Overview

This guide provides step-by-step instructions for using the C++ Primer exercise template to create new exercises. The template follows a flatter, more practical structure with clear question-answer pattern using student files for implementation and solution files for reference.

## Quick Start: Creating a New Exercise

### 1. Copy the Template
```bash
# Navigate to the template directory
cd cpp_primer_5th_deepseek

# Copy the template to create your new exercise
cp -r cpp_template exercises/1.1.1.hello_world
```

### 2. Rename Files
```bash
# Navigate to your new exercise directory
cd exercises/1.1.1.hello_world

# Rename files according to your exercise name
mv include/exercise_name_exercises.h include/hello_world_exercises.h
mv include/exercise_name_solutions.h include/hello_world_solutions.h
mv src/exercise_name_exercises.cpp src/hello_world_exercises.cpp
mv src/exercise_name_solutions.cpp src/hello_world_solutions.cpp
mv test/test_exercise_name_basics.cpp test/test_hello_world_basics.cpp
mv test/test_exercise_name_practice.cpp test/test_hello_world_practice.cpp
```

### 3. Update CMakeLists.txt
Edit `CMakeLists.txt` and change the project name:
```cmake
project(hello_world)
```

Update target names in the CMakeLists.txt file:
```cmake
add_library(hello_world_exercises src/hello_world_exercises.cpp)
add_library(hello_world_solutions src/hello_world_solutions.cpp)
add_executable(test_hello_world_basics test/test_hello_world_basics.cpp)
add_executable(test_hello_world_practice test/test_hello_world_practice.cpp)
```

## Example: Creating a String Operations Exercise

### Step 1: Copy and Rename
```bash
cp -r cpp_template exercises/3.2.1.string_operations
cd exercises/3.2.1.string_operations
mv include/exercise_name_exercises.h include/string_operations_exercises.h
mv include/exercise_name_solutions.h include/string_operations_solutions.h
mv src/exercise_name_exercises.cpp src/string_operations_exercises.cpp
mv src/exercise_name_solutions.cpp src/string_operations_solutions.cpp
mv test/test_exercise_name_basics.cpp test/test_string_operations_basics.cpp
mv test/test_exercise_name_practice.cpp test/test_string_operations_practice.cpp
```

### Step 2: Update Class Names
In `string_operations_exercises.h`:
```cpp
class StringOperations {
public:
    // Keep the same function signatures
    std::string basic_operation(const std::string& input);
    std::string combine_strings(const std::string& str1, const std::string& str2);
    // ... etc
};
```

### Step 3: Update Implementation Files
Update the class name in all function definitions in `string_operations_exercises.cpp`.

### Step 4: Update Tests
Update all test files to use `StringOperations` instead of `ExerciseName`.

### Step 5: Update CMakeLists.txt
```cmake
project(string_operations)

# Update library and executable names
add_library(string_operations_exercises src/string_operations_exercises.cpp)
add_library(string_operations_solutions src/string_operations_solutions.cpp)

add_executable(test_string_operations_basics test/test_string_operations_basics.cpp)
add_executable(test_string_operations_practice test/test_string_operations_practice.cpp)
```

### Step 6: Build and Test
```bash
mkdir build && cd build
cmake ..
make
./test_string_operations_basics
./test_string_operations_practice
```

## Best Practices

### File Naming Conventions
- Use descriptive names: `vector_operations`, `file_handling`, `class_design`
- Follow snake_case for file names
- Use consistent naming across all files

### Template Structure
The exercise template contains several key components:

**Header Files**
- `include/exercise_name_exercises.h`: Student header with TODO comments and function declarations
- `include/exercise_name_solutions.h`: Complete reference implementation
- `include/empty_exercise_name_*.h`: Minimal headers for simple exercises

**Source Files**
- `src/exercise_name_exercises.cpp`: Starter code with TODO comments for students
- `src/exercise_name_solutions.cpp`: Complete implementations

**Test Files**
- `test/test_exercise_name_basics.cpp`: Core functionality tests
- `test/test_exercise_name_practice.cpp`: Advanced challenges

### Exercise Design
- Start with simple functions, progress to complex ones
- Include comprehensive test coverage
- Add practice problems for extension
- Follow C++ best practices and modern standards

### Platform Considerations
Since the learning environment is containerized with Docker using Linux, only Linux shell scripts (.sh) are needed. All Windows .bat scripts are unnecessary and should be removed. Focus exclusively on pedagogical content and C++ concepts, not on environment setup or tooling instructions.

### Choosing the Right Template Approach

**For Complex Exercises (Classes, Multiple Functions)**
Use the full template with class declarations in header files:
1. Keep the existing header files (`exercise_name_exercises.h`, `exercise_name_solutions.h`)
2. Implement class methods in the source files
3. Add function declarations in headers, implementations in source files

**For Simple Exercises (Basic Syntax, Single Functions)**
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

### Documentation
- Update README.md with exercise-specific information
- Include learning objectives and prerequisites
- Document success criteria and next steps

### Educational Content Design
- Avoid providing complete code solutions in comments
- Use plain English explanations to guide students toward solutions
- Focus on explaining concepts and approaches rather than implementation details
- Encourage active learning by requiring students to write their own code
- Provide hints as conceptual guidance rather than copy-paste solutions

## Exercise Design Guidelines

### Learning Objectives
1. Focus on 1-3 specific C++ concepts per exercise
2. Progress from basic to advanced within the same topic
3. Include real-world applications of the concepts

### Code Quality
1. Follow modern C++ best practices (C++17)
2. Include proper error handling
3. Use meaningful variable and function names
4. Add comprehensive comments for solutions

### Testing Strategy
1. Test basic functionality with typical inputs
2. Include edge cases (empty inputs, boundary conditions)
3. Test error conditions and exception handling
4. Provide performance tests for complex algorithms

## Troubleshooting

### Common Issues

**Build Errors:**
- Check CMakeLists.txt file references
- Verify all file names match
- Ensure Google Test is installed

**Test Failures:**
- Review function implementations
- Check test expectations
- Compare with solution files

**File Not Found:**
- Verify file paths in includes
- Check CMake include directories
- Ensure proper file naming

### Getting Help
1. Review the solution files for reference implementations
2. Run tests frequently to catch issues early
3. Use debugger for complex problems

## Advanced Usage

### Custom Exercise Types
You can extend the template for different types of exercises:

**Algorithm Exercises:**
- Focus on data structures and algorithms
- Include performance testing
- Add complexity analysis

**Class Design Exercises:**
- Emphasize OOP principles
- Include inheritance and polymorphism
- Test encapsulation and abstraction

**Template Exercises:**
- Teach C++ template programming
- Include specialization examples
- Test generic programming concepts

### Integration with IDEs

The template works well with:
- Visual Studio Code with C++ extensions
- CLion with CMake integration
- Any IDE that supports CMake and Google Test

## Next Steps

After creating your exercise:
1. Test thoroughly with various inputs
2. Review with peers for feedback
3. Update documentation as needed
4. Consider creating additional practice problems
5. Share your exercise with the learning community

This guide provides everything needed to create effective C++ Primer exercises using the template system.