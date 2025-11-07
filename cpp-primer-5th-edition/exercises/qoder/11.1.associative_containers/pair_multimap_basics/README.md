# Pair and Multimap Basics Exercise

## Learning Objectives
- Understand how to create and use std::pair objects
- Learn how to work with multimap containers
- Practice inserting multiple values for the same key
- Access and iterate through elements in multimaps

## Topics Covered
- std::pair creation and usage
- Multimap declaration and initialization
- Element insertion in multimaps
- Using equal_range() to find all values for a key
- Iterating through multimaps

## Instructions
1. Implement the TODO comments in [pair_multimap_basics_exercises.cpp](src/pair_multimap_basics_exercises.cpp)
2. Build and run your solution using the provided build scripts
3. Compare your implementation with the solution in [pair_multimap_basics_solutions.cpp](src/pair_multimap_basics_solutions.cpp)

## Expected Output
When running the solution, you should see output similar to:
```
Pair 1: apple -> 3
Pair 2: banana -> 5
Children in Smith family:
  2 children
  4 children
  1 children

All families:
Johnson: 1 children
Smith: 2 children
Smith: 4 children
Smith: 1 children
Williams: 3 children
```

Note that:
1. Elements in a multimap are also automatically sorted by key
2. Multiple values can be associated with the same key
3. equal_range() returns a pair of iterators defining a range of elements with the same key