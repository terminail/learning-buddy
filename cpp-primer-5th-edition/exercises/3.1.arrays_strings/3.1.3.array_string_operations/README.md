# Exercise 3.1.1c: Array and String Operations

## Learning Objectives
- Understand how to work with arrays of strings
- Learn about processing collections of strings
- Practice working with both std::string and C-style strings
- Implement programs that combine arrays and string operations

## Concepts Covered
- Arrays of std::string objects
- String array processing and manipulation
- C-style strings (character arrays)
- Converting between std::string and C-style strings
- String array comparison and searching

## Instructions
1. Open `src/array_string_operations_exercises.cpp`
2. Follow the TODO comments to implement the array and string operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/array_string_operations_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Fruit array:
fruits[0] = "apple"
fruits[1] = "banana"
fruits[2] = "cherry"
fruits[3] = "date"
fruits[4] = "elderberry"
Longest fruit name: "elderberry" (length: 10)
Number of fruits starting with 'c': 1
All fruits: "apple, banana, cherry, date, elderberry"
Length of "Hello": 5
Copied string: "Hello"
Concatenated string: "Hello World"
C++ string: "C++ String"
C-style string: "C++ String"
New C++ string: "C++ String"
Array1 and Array2 are equal
Common strings between Array1 and Array3:
  "red"
  "blue"
```

## Key Points to Remember
- **Arrays of strings**: `std::string array_name[size];`
- **String array processing**: Use loops to iterate through string arrays
- **C-style strings**: Null-terminated character arrays (`char array[]`)
- **String conversion**: Use `c_str()` to convert std::string to C-style string
- **String functions**: Include `<cstring>` for C-style string functions
- **Array comparison**: Compare element by element for array equality

## Common Mistakes to Avoid
- Forgetting to include `<cstring>` for C-style string functions
- Confusing std::string length() with C-style string strlen()
- Not null-terminating C-style strings properly
- Accessing array elements outside bounds
- Forgetting that C-style string functions modify the original string

## Next Steps
After completing this exercise, proceed to:
- Exercise 3.2: String Library Functions
- Exercise 3.3: Array and String Algorithms