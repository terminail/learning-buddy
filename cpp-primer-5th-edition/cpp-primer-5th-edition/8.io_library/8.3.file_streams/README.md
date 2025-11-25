# Exercise 8.1c: File Streams

## Learning Objectives
- Understand how to open files for reading and writing
- Learn how to read data from text files line by line
- Practice writing data to text files
- Work with binary files and their special considerations
- Implement proper file handling and error management

## Concepts Covered
- File streams: std::ifstream for reading, std::ofstream for writing
- File opening modes and error checking
- Reading text files line by line with std::getline
- Writing formatted data to text files
- Binary file operations with std::ios::binary
- Proper file closing and resource management

## Instructions
1. Open `src/file_streams_exercises.cpp`
2. Follow the TODO comments to implement file stream operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/file_streams_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Testing file reading...
Line 1: This is the first line
Line 2: This is the second line
Line 3: This is the third line

Testing file writing...
Data written to test_output.txt

Testing binary file operations...
Binary data written successfully
Binary data read: 1 2 3 4 5
```

## Key Points to Remember
- **File Opening**: Always check if files open successfully using is_open()
- **File Closing**: Close files explicitly or use RAII principles
- **Error Handling**: Handle file operation errors gracefully
- **Binary Mode**: Use std::ios::binary for binary file operations
- **Resource Management**: Ensure files are properly closed to prevent resource leaks

## Common Mistakes to Avoid
- Forgetting to check if files opened successfully
- Not closing files after use, leading to resource leaks
- Mixing text and binary operations on the same file
- Not handling file permission errors
- Using incorrect file paths

## Next Steps
After completing this exercise, proceed to:
- Exercise 8.1d: Output Formatting
- Exercise 9.1: Sequential Containers