# Exercise 3.3a: Algorithms Practice

## Learning Objectives
- Understand how to use common STL algorithms with arrays and strings
- Learn about transformation, searching, and sorting algorithms
- Practice implementing algorithms for data manipulation
- Implement programs that process arrays and strings using library algorithms

## Concepts Covered
- Transformation algorithms (transform, toupper, tolower)
- Searching algorithms (find, count, binary_search)
- Sorting algorithms (sort with comparators)
- Array manipulation algorithms (reverse, unique, remove)
- String-specific algorithms (replace, remove_if)

## Instructions
1. Open `src/algorithms_practice_exercises.cpp`
2. Follow the TODO comments to implement the algorithms
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/algorithms_practice_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Original text: "Hello, World! Welcome to C++ Programming!"
Uppercase text: "HELLO, WORLD! WELCOME TO C++ PROGRAMMING!"
Lowercase text: "hello, world! welcome to c++ programming!"
Custom transformed text: "hELLO, wORLD! wELCOME TO c++ pROGRAMMING!"
Original numbers: 3 1 4 1 5 9 2 6 5 3 5 
Found 5 at position: 4
Count of 5s: 3
Binary search for 6 in sorted array: found
Original words: banana apple cherry date elderberry 
Sorted words (ascending): apple banana cherry date elderberry 
Sorted words (descending): elderberry date cherry banana apple 
Sorted by length: date apple cherry banana elderberry 
Original data: 1 2 2 3 3 3 4 5 5 
Reversed data: 5 5 4 3 3 3 2 2 1 
Unique data: 1 2 3 4 5 
Data with 3s removed: 1 2 2 4 5 5 
Original sentence: "The quick brown fox jumps over the lazy dog"
With 'o' replaced by '0': "The quick br0wn f0x jumps 0ver the lazy d0g"
Without punctuation: "The quick brown fox jumps over the lazy dog"
Number of vowels: 11
```

## Key Points to Remember
- **Transformation**: Use `std::transform` with functions or lambdas to modify elements
- **Searching**: Use `std::find`, `std::count`, `std::binary_search` for efficient searching
- **Sorting**: Use `std::sort` with custom comparators for specific ordering
- **Manipulation**: Use `std::reverse`, `std::unique`, `std::remove` for array operations
- **String Processing**: Combine algorithms with predicates for text processing
- **Lambda Functions**: Use lambdas for custom algorithm behavior
- **Erase-Remove Idiom**: Remember to use `erase` with `remove` for actual element removal

## Common Mistakes to Avoid
- Forgetting to include `<algorithm>` header for STL algorithms
- Not understanding that some algorithms modify the original container
- Incorrectly using iterators with algorithms
- Forgetting the erase-remove idiom when removing elements
- Not handling the case when an element is not found in search operations
- Misunderstanding how custom comparators work with sorting algorithms

## Next Steps
After completing this exercise, proceed to:
- Exercise 4.1: Expressions and Statements
- Review all Chapter 3 exercises