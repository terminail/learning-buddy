# Variables and Basic Types Exercise - Usage Guide

This guide explains how to use the variables and basic types exercise for learning C++.

## Quick Start

1. Navigate to the exercise directory:
   ```bash
   cd cpp_primer_5th_deepseek/exercises/qoder/2.1.1.variables_types
   ```

2. Open [src/variables_types_exercises.cpp](src/variables_types_exercises.cpp) in your editor

3. Follow the TODO comments to complete the exercise

4. Compile and run your solution:
   ```bash
   g++ -std=c++17 src/variables_types_exercises.cpp -o variables_exercise
   ./variables_exercise
   ```

5. Compare with the reference solution in [src/variables_types_solutions.cpp](src/variables_types_solutions.cpp)

## Exercise Structure

This exercise follows a simple structure since it focuses on basic concepts:

- **Source Files**: Simple .cpp files with main() functions
- **Header Files**: Empty headers (this is a simple exercise)
- **Test Files**: Google Test files for verification
- **Build System**: CMake configuration

## When to Use Empty Headers

This exercise uses empty header files because:
- It's a simple introductory exercise
- No complex class structures are needed
- The focus is on basic variable declarations
- Students are just learning fundamental concepts

For more complex exercises, you would use full header files with class declarations.

## Compilation and Running

### Simple Compilation
```bash
g++ -std=c++17 src/variables_types_exercises.cpp -o variables_exercise
./variables_exercise
```

### Using CMake (Recommended)
```bash
mkdir build
cd build
cmake ..
make
./variables_types_exercises
```

## Testing

Run the tests to verify your understanding:

```bash
mkdir build
cd build
cmake ..
make
./test_variables_types_basics
./test_variables_types_practice
```

## Learning Path

This exercise is part of a progressive learning path:

1. **2.1.1.variables_types** - Current exercise (variables and basic types)
2. Next: Operators and expressions
3. Then: Control structures (if/else, loops)
4. Followed by: Functions and scope

## Customization

To create your own version of this exercise:

1. Copy the entire exercise directory
2. Rename the directory (e.g., `2.1.2.variables_practice`)
3. Update the CMakeLists.txt file with new project name
4. Modify the source files with your own requirements
5. Update documentation files as needed

## Troubleshooting

### Common Issues:

1. **Missing string header**: 
   - Error: `error: 'string' in namespace 'std' does not name a type`
   - Solution: Add `#include <string>` at the top of your file

2. **Character vs String confusion**:
   - Error: Cannot assign "A" to char variable
   - Solution: Use single quotes for chars: 'A' instead of "A"

3. **Uninitialized variables**:
   - Warning: Variables contain garbage values
   - Solution: Always initialize variables when declaring them

### Getting Help:

1. Check the reference solution in [src/variables_types_solutions.cpp](src/variables_types_solutions.cpp)
2. Review the detailed guide in [EXERCISE_NAME_GUIDE.md](EXERCISE_NAME_GUIDE.md)
3. Run the tests to identify specific issues
4. Ask for help if concepts are unclear

## Best Practices Learned

From this exercise, you should learn:

1. Always include necessary headers
2. Initialize variables when declaring them
3. Use appropriate data types for your data
4. Use meaningful variable names
5. Test your code with different values
6. Follow consistent coding style

## Next Steps

After completing this exercise:
1. Try the practice problems in [test/test_variables_types_practice.cpp](test/test_variables_types_practice.cpp)
2. Experiment with different data types and values
3. Proceed to the next exercise on operators and expressions
4. Review any concepts that were challenging