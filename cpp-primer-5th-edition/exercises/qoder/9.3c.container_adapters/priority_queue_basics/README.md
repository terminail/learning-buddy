# Exercise 9.3c: Priority Queue Basics

## Learning Objectives
- Understand how to create and use std::priority_queue container adapters
- Learn about priority queue operations like push and pop with priority ordering
- Practice implementing priority-based data structures
- Implement programs that use priority queues for algorithmic problem solving

## Concepts Covered
- Priority queue declaration and initialization
- Priority queue operations (push, pop, top)
- Priority ordering (max-heap by default)
- Container adapters and their underlying containers
- Heap data structure concepts

## Instructions
1. Open `src/priority_queue_basics_exercises.cpp`
2. Follow the TODO comments to implement the priority queue operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/priority_queue_basics_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Empty priority queue size: 0
Priority queue size after pushing 5 elements: 5
Top element (highest priority): 50
Removing elements from priority queue (highest priority first):
Top element: 50
Top element: 40
Top element: 30
Top element: 20
Top element: 10
Priority queue is now empty
Final priority queue size: 0
```

## Key Points to Remember
- **Priority Queue declaration**: `std::priority_queue<type> name;`
- **Push operation**: Use `push()` to add elements (automatically ordered by priority)
- **Pop operation**: Use `pop()` to remove the highest priority element (no return value)
- **Top access**: Use `top()` to access the highest priority element without removing it
- **Default ordering**: Max-heap (largest element has highest priority)
- **Custom ordering**: Can specify custom comparator for min-heap or other orderings
- **Empty check**: Use `empty()` to check if priority queue has no elements
- **Size check**: Use `size()` to get the number of elements

## Common Mistakes to Avoid
- Forgetting to include the `<queue>` header
- Calling `top()` or `pop()` on an empty priority queue (undefined behavior)
- Confusing `pop()` (removes element) with `top()` (accesses element)
- Not understanding that `pop()` doesn't return the removed element
- Trying to iterate through a priority queue (priority queues don't support iteration)

## Next Steps
After completing this exercise, proceed to:
- Review all Container exercises
- Associative Containers (map, set)
- Generic Algorithms