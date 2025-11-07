# Exercise 9.3a: Stack Basics

## Learning Objectives
- Understand how to create and use std::stack container adapters
- Learn about stack operations like push, pop, and top
- Practice implementing LIFO (Last In, First Out) data structures
- Implement programs that use stacks for algorithmic problem solving

## Concepts Covered
- Stack declaration and initialization
- Stack operations (push, pop, top)
- Stack capacity and empty checking
- LIFO (Last In, First Out) principle
- Container adapters and their underlying containers

## Instructions
1. Open `src/stack_basics_exercises.cpp`
2. Follow the TODO comments to implement the stack operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/stack_basics_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Empty stack size: 0
Stack size after pushing 5 elements: 5
Top element: 50
Removing elements from stack:
Popping: 50
Popping: 40
Popping: 30
Popping: 20
Popping: 10
Stack is now empty
Final stack size: 0
```

## Key Points to Remember
- **Stack declaration**: `std::stack<type> name;`
- **Push operation**: Use `push()` to add elements to the top
- **Pop operation**: Use `pop()` to remove the top element (no return value)
- **Top access**: Use `top()` to access the top element without removing it
- **Empty check**: Use `empty()` to check if stack has no elements
- **Size check**: Use `size()` to get the number of elements

## Common Mistakes to Avoid
- Forgetting to include the `<stack>` header
- Calling `top()` or `pop()` on an empty stack (undefined behavior)
- Confusing `pop()` (removes element) with `top()` (accesses element)
- Not understanding that `pop()` doesn't return the removed element
- Trying to iterate through a stack (stacks don't support iteration)

## Next Steps
After completing this exercise, proceed to:
- Exercise 9.3b: Queue Basics
- Exercise 9.3c: Priority Queue Basics