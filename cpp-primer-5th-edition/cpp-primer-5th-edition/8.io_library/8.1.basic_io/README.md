# Exercise 8.1a: Basic IO Operations

## Learning Objectives
- Understand how to perform basic input/output operations in C++
- Learn about stream classes for console and file I/O
- Practice handling stream states and errors
- Implement programs that read from and write to files

## Concepts Covered
- Console I/O with std::cin and std::cout
- File I/O with std::ifstream and std::ofstream
- String streams with std::istringstream and std::ostringstream
- Stream state checking and error handling
- Input validation and data parsing

## Instructions
1. Open `src/basic_io_exercises.cpp`
2. Follow the TODO comments to implement the IO operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/basic_io_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Enter your name: John Doe
Hello, John Doe!
Enter your age: 25
You are 25 years old.
Data written to output.txt
Contents of output.txt:
Name: John Doe
Age: 25
This is a sample output file.
Enter a number: 42
You entered: 42
Parsed data:
Name: John
Age: 25
Major: Computer
The number is: 42
```

## Key Points to Remember
- **Console I/O**: Use `std::cin` for input and `std::cout` for output
- **File I/O**: Use `std::ifstream` for reading and `std::ofstream` for writing
- **String Streams**: Use `std::istringstream` and `std::ostringstream` for string parsing
- **Stream States**: Check `good()`, `fail()`, `eof()` to handle errors
- **File Handling**: Always check if files open successfully and close them when done
- **Input Buffer**: Use `ignore()` to clear the input buffer when needed

## Common Mistakes to Avoid
- Forgetting to check if files opened successfully
- Not handling stream errors and states properly
- Forgetting to close files after use
- Not clearing the input buffer after mixed input types
- Using `cin >>` with strings containing spaces (use `getline` instead)

## Next Steps
After completing this exercise, proceed to:
- Exercise 8.1b: Advanced IO Operations
- Exercise 8.2: File Stream Operations