# Basic Input/Output Operations Exercise - Usage Guide

This guide explains how to use the basic input/output operations exercise for learning C++.

## Quick Start

1. Navigate to the exercise directory:
   ```bash
   cd cpp_primer_5th_deepseek/exercises/qoder/2.2.1.basic_io
   ```

2. Open [src/basic_io_exercises.cpp](src/basic_io_exercises.cpp) in your editor

3. Follow the TODO comments to complete the exercise

4. Compile and run your solution:
   ```bash
   g++ -std=c++17 src/basic_io_exercises.cpp -o basic_io_exercise
   ./basic_io_exercise
   ```

5. Compare with the reference solution in [src/basic_io_solutions.cpp](src/basic_io_solutions.cpp)

## Exercise Structure

This exercise follows a simple structure since it focuses on basic I/O concepts:

- **Source Files**: Simple .cpp files with main() functions
- **Header Files**: Empty headers (this is a simple exercise)
- **Test Files**: Google Test files for verification
- **Build System**: CMake configuration

## When to Use Empty Headers

This exercise uses empty header files because:
- It's a simple introductory exercise on I/O operations
- No complex class structures are needed
- The focus is on learning cin/cout operations
- Students are building on their variable knowledge

For more complex exercises with classes, you would use full header files with class declarations.

## Compilation and Running

### Simple Compilation
```bash
g++ -std=c++17 src/basic_io_exercises.cpp -o basic_io_exercise
./basic_io_exercise
```

### Using CMake (Recommended)
```bash
mkdir build
cd build
cmake ..
make
./basic_io_exercises
```

## Testing

Run the tests to verify your understanding:

```bash
mkdir build
cd build
cmake ..
make
./test_basic_io_basics
./test_basic_io_practice
```

## Learning Path

This exercise is part of a progressive learning path:

1. **1.1.1.hello_world** - Introduction to C++
2. **2.1.1.variables_types** - Variables and basic types
3. **2.2.1.basic_io** - Current exercise (input/output operations)
4. Next: Control structures (if/else, loops)
5. Then: Functions and scope

## Customization

To create your own version of this exercise:

1. Copy the entire exercise directory
2. Rename the directory (e.g., `2.2.2.advanced_io`)
3. Update the CMakeLists.txt file with new project name
4. Modify the source files with your own requirements
5. Update documentation files as needed

## Troubleshooting

### Common Issues:

1. **Mixing cin >> and getline()**:
   - Problem: getline() reads leftover newline
   - Solution: Use `cin.ignore()` between operations

2. **Input buffer issues**:
   - Problem: Previous input affects subsequent input
   - Solution: Clear buffer with `cin.clear()` and `cin.ignore()`

3. **Missing prompts**:
   - Problem: User doesn't know what to enter
   - Solution: Always prompt before requesting input

4. **Invalid input handling**:
   - Problem: Program crashes on invalid input
   - Solution: Check `cin.fail()` and handle errors

### Getting Help:

1. Check the reference solution in [src/basic_io_solutions.cpp](src/basic_io_solutions.cpp)
2. Review the detailed guide in [EXERCISE_NAME_GUIDE.md](EXERCISE_NAME_GUIDE.md)
3. Run the tests to identify specific issues
4. Ask for help if concepts are unclear

## Best Practices Learned

From this exercise, you should learn:

1. Always prompt users before requesting input
2. Handle input buffer issues properly
3. Use appropriate input methods for different data types
4. Validate user input when possible
5. Format output for better user experience
6. Test with various input scenarios

## Next Steps

After completing this exercise:
1. Try the practice problems in [test/test_basic_io_practice.cpp](test/test_basic_io_practice.cpp)
2. Experiment with different input scenarios and error conditions
3. Proceed to the next exercise on control structures
4. Review any concepts that were challenging