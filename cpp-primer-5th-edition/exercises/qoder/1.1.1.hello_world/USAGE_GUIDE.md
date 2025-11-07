# Template Usage Guide

This guide explains how to use the exercise template to create new C++ learning exercises for the C++ Primer course.

## Quick Start: Creating a New Exercise

### 1. Copy the Template
```bash
# Navigate to the template directory
cd cpp_primer_5th_deepseek/template

# Copy the template to create your new exercise
cp -r chapter.exercise_name ../exercises/1.1.1.hello_world
```

### 2. Rename Files
```bash
# Navigate to your new exercise directory
cd ../exercises/1.1.1.hello_world

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

## Customizing Your Exercise

### 1. Update Header Files (for complex exercises)
Edit `include/your_exercise_name_exercises.h`:
- Change class name from `ExerciseName` to your exercise name
- Update function declarations for your specific learning objectives
- Add/remove member variables as needed

### 2. Implement Student Code
Edit `src/your_exercise_name_exercises.cpp`:
- Implement functions with TODO comments
- Add student instructions in comments
- Keep implementations incomplete for students to complete

### 3. Create Solution Code
Edit `src/your_exercise_name_solutions.cpp`:
- Implement complete, correct solutions
- Add detailed comments explaining the approach
- Include multiple solution approaches if applicable

### 4. Write Tests
Edit `test/test_your_exercise_basics.cpp`:
- Replace `ExerciseName` with your class name
- Add test cases for basic functionality
- Include edge cases and error conditions

Edit `test/test_your_exercise_practice.cpp`:
- Add advanced practice problems
- Include more complex test scenarios
- Provide extension challenges for advanced students

## Naming Conventions

### Directory Names
Use the format: `chapter.section.subsection_exercise_topic`
Examples:
- `1.1.1.hello_world`
- `2.3.2.string_operations`
- `5.2.1.class_design`

### File Names
- Headers: `exercise_topic_exercises.h` and `exercise_topic_solutions.h`
- Sources: `exercise_topic_exercises.cpp` and `exercise_topic_solutions.cpp`
- Tests: `test_exercise_topic_basics.cpp` and `test_exercise_topic_practice.cpp`

## Building and Testing

### Build the Exercise
```bash
mkdir build
cd build
cmake ..
make
```

### Run Tests
```bash
# Run all tests
make run_tests

# Run basic tests only
make run_basics

# Run practice tests only
make run_practice
```

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

## Example: Creating a String Operations Exercise

### 1. Copy and Rename
```bash
cp -r chapter.exercise_name ../exercises/3.2.1.string_reverse
cd ../exercises/3.2.1.string_reverse
mv include/exercise_name_exercises.h include/string_reverse_exercises.h
# ... rename other files similarly
```

### 2. Update Header File
```cpp
// include/string_reverse_exercises.h
class StringReverse {
public:
    std::string reverse(const std::string& input);
    std::string reverse_words(const std::string& input);
};
```

### 3. Implement Student Template
```cpp
// src/string_reverse_exercises.cpp
std::string StringReverse::reverse(const std::string& input) {
    // TODO: Implement string reversal
    // Return the reversed string
}

std::string StringReverse::reverse_words(const std::string& input) {
    // TODO: Implement word reversal
    // Reverse the order of words, not the words themselves
}
```

### 4. Create Solution
```cpp
// src/string_reverse_solutions.cpp
std::string StringReverse::reverse(const std::string& input) {
    return std::string(input.rbegin(), input.rend());
}

std::string StringReverse::reverse_words(const std::string& input) {
    // Implementation here
}
```

This approach ensures consistency across all exercises while providing flexibility for different complexity levels.