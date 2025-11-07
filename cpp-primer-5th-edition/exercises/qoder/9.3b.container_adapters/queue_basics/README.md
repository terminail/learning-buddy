# Exercise 9.3b: Queue Basics

## Learning Objectives
- Understand how to create and use std::queue container adapters
- Learn about queue operations like push, pop, front, and back
- Practice implementing FIFO (First In, First Out) data structures
- Implement programs that use queues for algorithmic problem solving

## Concepts Covered
- Queue declaration and initialization
- Queue operations (push, pop, front, back)
- Queue capacity and empty checking
- FIFO (First In, First Out) principle
- Container adapters and their underlying containers

## Instructions
1. Open `src/queue_basics_exercises.cpp`
2. Follow the TODO comments to implement the queue operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/queue_basics_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Empty queue size: 0
Queue size after pushing 5 elements: 5
Front element: 10
Back element: 50
Removing elements from queue:
Front element: 10
Front element: 20
Front element: 30
Front element: 40
Front element: 50
Queue is now empty
Final queue size: 0
```

## Key Points to Remember
- **Queue declaration**: `std::queue<type> name;`
- **Push operation**: Use `push()` to add elements to the back
- **Pop operation**: Use `pop()` to remove the front element (no return value)
- **Front access**: Use `front()` to access the front element without removing it
- **Back access**: Use `back()` to access the back element without removing it
- **Empty check**: Use `empty()` to check if queue has no elements
- **Size check**: Use `size()` to get the number of elements

## Common Mistakes to Avoid
- Forgetting to include the `<queue>` header
- Calling `front()`, `back()`, or `pop()` on an empty queue (undefined behavior)
- Confusing `pop()` (removes element) with `front()` (accesses element)
- Not understanding that `pop()` doesn't return the removed element
- Trying to iterate through a queue (queues don't support iteration)

## Next Steps
After completing this exercise, proceed to:
- Exercise 9.3c: Priority Queue Basics
- Review all Sequential Containers exercises