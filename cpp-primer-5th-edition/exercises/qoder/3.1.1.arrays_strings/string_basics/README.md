# Exercise 3.1.1b: String Basics

## Learning Objectives
- Understand how to declare and initialize std::string objects
- Learn about string indexing and character access
- Practice performing operations on strings
- Implement programs that use strings to store and manipulate text data

## Concepts Covered
- String declaration and initialization
- String indexing and character access
- String concatenation and modification
- String information methods (length, size, empty)
- String manipulation methods (assign, insert, erase)

## Instructions
1. Open `src/string_basics_exercises.cpp`
2. Follow the TODO comments to implement the string operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/string_basics_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Empty string: ''
Hello string: 'Hello'
World string: 'World'
Copy string: 'Hello'
Characters in 'C++ Programming':
sample[0] = 'C'
sample[1] = '+'
sample[2] = '+'
sample[3] = ' '
sample[4] = 'P'
...
First character using at(): 'C'
Last character using at(): 'g'
Concatenated with +: 'Hello World'
Appended with +=: 'Hello C++'
Appended with append(): 'Hello Students'
Length of 'Hello World': 11
Size of 'Hello World': 11
Is empty string empty? Yes
First character: 'H'
Last character: 'd'
Before modification: 'Original'
After assign(): 'New Content'
After insert(): 'New Great Content'
After erase(): 'New Content'
```

## Key Points to Remember
- **String declaration**: `std::string name;`
- **String initialization**: Multiple ways including literals, constructors, and copying
- **Character access**: Use index notation or at() method (with bounds checking)
- **Concatenation**: Use + operator, += operator, or append() method
- **String information**: Use length()/size(), empty(), front(), back()
- **String modification**: Use assign(), insert(), erase() methods

## Common Mistakes to Avoid
- Accessing characters outside the string bounds
- Forgetting to include the `<string>` header
- Confusing length() and size() methods (they're identical)
- Not understanding that at() throws exceptions for out-of-bounds access
- Using C-style string functions on std::string objects unnecessarily

## Next Steps
After completing this exercise, proceed to:
- Exercise 3.1.1c: Array and String Operations
- Exercise 3.2: String Library Functions