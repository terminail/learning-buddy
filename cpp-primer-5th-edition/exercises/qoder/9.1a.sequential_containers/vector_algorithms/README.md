# Exercise 9.1c: Vector Algorithms

## Learning Objectives
- Understand how to use common STL algorithms with std::vector
- Learn about sorting, searching, and modifying vector elements
- Practice using algorithms like std::sort, std::find, std::accumulate
- Implement programs that perform operations on vector data

## Concepts Covered
- Vector algorithms (sorting, searching, accumulation)
- Iterator usage with algorithms
- The erase-remove idiom for element removal
- Algorithm complexity and performance considerations

## Instructions
1. Open `src/vector_algorithms_exercises.cpp`
2. Follow the TODO comments to implement the vector algorithms
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/vector_algorithms_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Original vector: 5 2 8 1 9 3 
Sorted vector: 1 2 3 5 8 9 
Found element 8 at position: 4
Sum of elements: 28
Reversed vector: 9 8 5 3 2 1 
Vector before removing 1s: 9 8 5 3 2 1 1 1 
Vector after removing 1s: 9 8 5 3 2 
```

## Key Points to Remember
- **Sorting**: Use `std::sort(begin, end)` to sort vector elements
- **Searching**: Use `std::find(begin, end, value)` to search for elements
- **Accumulation**: Use `std::accumulate(begin, end, init)` to sum elements
- **Reversing**: Use `std::reverse(begin, end)` to reverse element order
- **Removing elements**: Use the erase-remove idiom: `vec.erase(std::remove(begin, end, value), end)`

## Common Mistakes to Avoid
- Forgetting to include the `<algorithm>` header for STL algorithms
- Not understanding that some algorithms modify the original vector
- Incorrectly using iterators with algorithms
- Forgetting the erase-remove idiom when removing elements
- Not handling the case when an element is not found in search operations

## Next Steps
After completing this exercise, proceed to:
- Exercise 9.2: Other Sequential Containers (list, deque)
- Exercise 9.3: Container Adapters (stack, queue)