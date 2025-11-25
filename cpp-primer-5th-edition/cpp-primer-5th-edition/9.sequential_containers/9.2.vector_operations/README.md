# Exercise 9.1b: Vector Operations

## Learning Objectives
- Understand how to modify vectors by adding and removing elements
- Learn about different methods for inserting elements at specific positions
- Practice iterating through vectors using various techniques
- Implement programs that manipulate vector contents dynamically

## Concepts Covered
- Adding elements with push_back() and insert()
- Removing elements with pop_back(), erase(), and clear()
- Vector iterators and their usage
- Different iteration methods (index, range-based, iterator-based)

## Instructions
1. Open `src/vector_operations_exercises.cpp`
2. Follow the TODO comments to implement the vector operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/vector_operations_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Initial vector: 1 2 3 4 5 
After adding elements: 1 2 3 4 5 6 7 
After inserting elements: 10 1 2 20 3 4 5 6 7 
After removing elements: 10 4 6 
After clearing, vector size: 0
Iteration with index: Hello Vector World 
Range-based for loop: Hello Vector World 
Iterator-based loop: Hello Vector World 
```

## Key Points to Remember
- **Adding elements**: push_back() adds to end, insert() adds at specific position
- **Removing elements**: pop_back() removes from end, erase() removes at specific position, clear() removes all
- **Iteration methods**: Index-based, range-based for loops, iterator-based loops
- **Iterator safety**: Be careful with iterator invalidation after modifications

## Common Mistakes to Avoid
- Accessing elements outside vector bounds
- Using invalidated iterators after vector modifications
- Forgetting to include the `<vector>` header
- Not handling empty vectors properly

## Next Steps
After completing this exercise, proceed to:
- Exercise 9.1c: Vector Algorithms
- Exercise 9.1a: Vector Basics (review if needed)