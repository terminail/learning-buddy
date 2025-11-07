# Functions Exercise - Usage Guide

This guide explains how to use the functions exercise for learning C++.

## Quick Start

1. Navigate to the exercise directory:
   ```bash
   cd cpp_primer_5th_deepseek/exercises/qoder/6.1.1.functions
   ```

2. Open [src/functions_exercises.cpp](src/functions_exercises.cpp) in your editor

3. Follow the TODO comments to complete the exercise

4. Compile and run your solution:
   ```bash
   g++ -std=c++17 src/functions_exercises.cpp -o functions_exercise
   ./functions_exercise
   ```

5. Compare with the reference solution in [src/functions_solutions.cpp](src/functions_solutions.cpp)

## Exercise Structure

This exercise introduces functions, so we start using header files:

- **Source Files**: .cpp files with function implementations
- **Header Files**: Empty headers (simple exercise) or full headers for complex exercises
- **Test Files**: Google Test files for verification
- **Build System**: CMake configuration

## When to Use Empty Headers

This exercise uses empty header files because:
- It's an introductory exercise on functions
- No complex class structures are needed
- The focus is on learning function declaration/definition
- Students are building on their previous knowledge

For more complex exercises with classes, you would use full header files with class declarations.

## Compilation and Running

### Simple Compilation
```bash
g++ -std=c++17 src/functions_exercises.cpp -o functions_exercise
./functions_exercise
```

### Using CMake (Recommended)
```bash
mkdir build
cd build
cmake ..
make
./functions_exercises
```

## Testing

Run the tests to verify your understanding:

```bash
mkdir build
cd build
cmake ..
make
./test_functions_basics
./test_functions_practice
```

## Learning Path

This exercise is part of a progressive learning path:

1. **1.1.1.hello_world** - Introduction to C++
2. **2.1.1.variables_types** - Variables and basic types
3. **2.2.1.basic_io** - Input/output operations
4. **5.1.1.control_flow** - Control flow statements
5. **6.1.1.functions** - Current exercise (functions)
6. Next: Arrays and strings
7. Then: Classes and objects
8. Followed by: Advanced topics

## Customization

To create your own version of this exercise:

1. Copy the entire exercise directory
2. Rename the directory (e.g., `6.1.2.advanced_functions`)
3. Update the CMakeLists.txt file with new project name
4. Modify the source files with your own requirements
5. Update documentation files as needed

## Troubleshooting

### Common Issues:

1. **Undefined reference errors**:
   - Problem: Function declared but not defined
   - Solution: Implement all declared functions

2. **Function signature mismatches**:
   - Problem: Declaration doesn't match definition
   - Solution: Ensure exact match between declaration and definition

3. **Missing function prototypes**:
   - Problem: Using functions before declaring them
   - Solution: Add function prototypes before main()

4. **Return value issues**:
   - Problem: Forgetting to return value in non-void functions
   - Solution: Always return appropriate value

### Getting Help:

1. Check the reference solution in [src/functions_solutions.cpp](src/functions_solutions.cpp)
2. Review the detailed guide in [EXERCISE_NAME_GUIDE.md](EXERCISE_NAME_GUIDE.md)
3. Run the tests to identify specific issues
4. Ask for help if concepts are unclear

## Best Practices Learned

From this exercise, you should learn:

1. Always declare function prototypes before using functions
2. Match function signatures exactly between declaration and definition
3. Use const references for large objects to avoid copying
4. Keep functions focused on a single task
5. Use meaningful function and parameter names
6. Test functions with various input values

## Next Steps

After completing this exercise:
1. Try the practice problems in [test/test_functions_practice.cpp](test/test_functions_practice.cpp)
2. Experiment with different function signatures and parameter types
3. Proceed to the next exercise on arrays and strings
4. Review any concepts that were challenging