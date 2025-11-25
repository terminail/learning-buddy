# Exercise 9.1a: Vector Basics

## Learning Objectives
- Understand how to create and initialize std::vector containers
- Learn about different ways to initialize vectors
- Practice accessing vector elements and getting vector size
- Implement programs that use vectors to store collections of data

## Concepts Covered
- Vector declaration and initialization
- Vector size and capacity
- Element access using index
- Adding elements to vectors
- Vector iterators (basic)

## Instructions
1. Open `src/vector_basics_exercises.cpp`
2. Follow the TODO comments to implement the vector operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/vector_basics_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Empty vector size: 0
Zero vector size: 5
Zero vector elements: 0 0 0 0 0 
Specific vector size: 5
Specific vector elements: 1 2 3 4 5 
String vector size: 3
String vector elements: Hello World Vector 
```

## Key Points to Remember
- **Vector declaration**: `std::vector<type> name;`
- **Vector initialization**: Multiple ways including size, initializer lists
- **Adding elements**: Use `push_back()` to add elements to the end
- **Accessing elements**: Use index notation `vector[index]` or `at()` method
- **Vector size**: Use `size()` method to get number of elements

## Common Mistakes to Avoid
- Accessing elements outside the vector bounds
- Forgetting to include the `<vector>` header
- Confusing vector size with capacity
- Not initializing vectors properly

## Next Steps
After completing this exercise, proceed to:
- Exercise 9.1b: Vector Operations
- Exercise 9.1c: Vector Algorithms