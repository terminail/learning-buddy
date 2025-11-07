# Control Flow Statements Exercise - Usage Guide

This guide explains how to use the control flow statements exercise for learning C++.

## Quick Start

1. Navigate to the exercise directory:
   ```bash
   cd cpp_primer_5th_deepseek/exercises/qoder/5.1.1.control_flow
   ```

2. Open [src/control_flow_exercises.cpp](src/control_flow_exercises.cpp) in your editor

3. Follow the TODO comments to complete the exercise

4. Compile and run your solution:
   ```bash
   g++ -std=c++17 src/control_flow_exercises.cpp -o control_flow_exercise
   ./control_flow_exercise
   ```

5. Compare with the reference solution in [src/control_flow_solutions.cpp](src/control_flow_solutions.cpp)

## Exercise Structure

This exercise follows a simple structure since it focuses on control flow concepts:

- **Source Files**: Simple .cpp files with main() functions
- **Header Files**: Empty headers (this is a simple exercise)
- **Test Files**: Google Test files for verification
- **Build System**: CMake configuration

## When to Use Empty Headers

This exercise uses empty header files because:
- It's a simple exercise focusing on control flow statements
- No complex class structures are needed
- The focus is on learning if/else and loop constructs
- Students are building on their previous knowledge

For more complex exercises with classes, you would use full header files with class declarations.

## Compilation and Running

### Simple Compilation
```bash
g++ -std=c++17 src/control_flow_exercises.cpp -o control_flow_exercise
./control_flow_exercise
```

### Using CMake (Recommended)
```bash
mkdir build
cd build
cmake ..
make
./control_flow_exercises
```

## Testing

Run the tests to verify your understanding:

```bash
mkdir build
cd build
cmake ..
make
./test_control_flow_basics
./test_control_flow_practice
```

## Learning Path

This exercise is part of a progressive learning path:

1. **1.1.1.hello_world** - Introduction to C++
2. **2.1.1.variables_types** - Variables and basic types
3. **2.2.1.basic_io** - Input/output operations
4. **5.1.1.control_flow** - Current exercise (control flow statements)
5. Next: Functions and scope
6. Then: Arrays and strings
7. Followed by: Classes and objects

## Customization

To create your own version of this exercise:

1. Copy the entire exercise directory
2. Rename the directory (e.g., `5.1.2.advanced_control_flow`)
3. Update the CMakeLists.txt file with new project name
4. Modify the source files with your own requirements
5. Update documentation files as needed

## Troubleshooting

### Common Issues:

1. **Infinite loops**:
   - Problem: Loop condition never becomes false
   - Solution: Check loop update statement and condition

2. **Off-by-one errors**:
   - Problem: Loop runs one time too many or too few
   - Solution: Carefully check loop conditions (<= vs <)

3. **Missing curly braces**:
   - Problem: Only first statement executes in if/else blocks
   - Solution: Always use curly braces, even for single statements

4. **Assignment vs Comparison**:
   - Problem: Using = instead of == in conditions
   - Solution: Use == for comparison, = for assignment

### Getting Help:

1. Check the reference solution in [src/control_flow_solutions.cpp](src/control_flow_solutions.cpp)
2. Review the detailed guide in [EXERCISE_NAME_GUIDE.md](EXERCISE_NAME_GUIDE.md)
3. Run the tests to identify specific issues
4. Ask for help if concepts are unclear

## Best Practices Learned

From this exercise, you should learn:

1. Always use curly braces for if/else blocks
2. Initialize loop variables properly
3. Check loop conditions to avoid infinite loops
4. Use meaningful variable names
5. Test edge cases (0, 1, negative numbers)
6. Use debugger to step through complex control flow

## Next Steps

After completing this exercise:
1. Try the practice problems in [test/test_control_flow_practice.cpp](test/test_control_flow_practice.cpp)
2. Experiment with different control flow patterns
3. Proceed to the next exercise on functions and scope
4. Review any concepts that were challenging