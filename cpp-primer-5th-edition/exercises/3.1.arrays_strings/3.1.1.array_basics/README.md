# Exercise 3.1.1a: Array Basics

## Learning Objectives
- Understand how to declare and initialize C-style arrays
- Learn about array indexing and element access
- Practice performing operations on array elements
- Implement programs that use arrays to store collections of data

## Concepts Covered
- Array declaration and initialization
- Array indexing and element access
- Array traversal using loops
- Basic array operations (sum, find maximum)
- Array modification

## Instructions
1. Open `src/array_basics_exercises.cpp`
2. Follow the TODO comments to implement the array operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/array_basics_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Array elements:
numbers[0] = 1
numbers[1] = 2
numbers[2] = 3
numbers[3] = 4
numbers[4] = 5
Sum of elements: 15
Largest element: 5
Array elements after multiplying by 2:
numbers[0] = 2
numbers[1] = 4
numbers[2] = 6
numbers[3] = 8
numbers[4] = 10
```

## Key Points to Remember
- **Array declaration**: `type name[size];`
- **Array initialization**: Multiple ways including size-based, initializer lists
- **Indexing**: Use square brackets to access elements (0-based indexing)
- **Bounds**: No automatic bounds checking - accessing out-of-bounds elements is undefined behavior
- **Fixed size**: Arrays have a fixed size determined at compile time

## Common Mistakes to Avoid
- Accessing elements outside the array bounds
- Forgetting that array indices start at 0
- Confusing array size with the last valid index
- Not initializing arrays properly
- Trying to copy arrays using assignment operator

## Next Steps
After completing this exercise, proceed to:
- Exercise 3.1.1b: String Basics
- Exercise 3.1.1c: Array and String Operations