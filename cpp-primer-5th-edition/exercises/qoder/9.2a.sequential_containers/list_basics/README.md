# Exercise 9.2a: List Basics

## Learning Objectives
- Understand how to create and initialize std::list containers
- Learn about list-specific operations like push_front, push_back, and insert
- Practice iterating through lists using iterators
- Implement programs that use lists for efficient insertion and deletion

## Concepts Covered
- List declaration and initialization
- List insertion and deletion operations
- Iterator usage with lists
- Bidirectional iteration (forward and backward)
- List-specific member functions

## Instructions
1. Open `src/list_basics_exercises.cpp`
2. Follow the TODO comments to implement the list operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/list_basics_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Empty list size: 0
Initial list: 1 2 3 4 5 
List after adding front and back: 0 1 2 3 4 5 6 
List after inserting 99 at position 3: 0 1 2 99 3 4 5 6 
List elements using iterators: 0 1 2 99 3 4 5 6 
List after removing front and back: 1 2 99 3 4 5 
```

## Key Points to Remember
- **List declaration**: `std::list<type> name;`
- **List initialization**: Multiple ways including initializer lists
- **Adding elements**: Use `push_front()` and `push_back()` for efficient insertion
- **Inserting elements**: Use `insert()` with iterators for insertion at specific positions
- **Removing elements**: Use `pop_front()` and `pop_back()` for efficient removal
- **Iteration**: Use iterators for traversal (lists don't support random access)

## Common Mistakes to Avoid
- Trying to access list elements using index notation (lists don't support random access)
- Forgetting to include the `<list>` header
- Not understanding the performance characteristics of list operations
- Incorrectly using iterators with list operations
- Confusing list operations with vector operations

## Next Steps
After completing this exercise, proceed to:
- Exercise 9.2b: List Algorithms
- Exercise 9.3: Container Adapters (stack, queue)