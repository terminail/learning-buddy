# Exercise 3.2a: String Operations

## Learning Objectives
- Understand how to use common string library functions
- Learn about string searching and substring extraction
- Practice string comparison and modification operations
- Implement programs that manipulate strings using library functions

## Concepts Covered
- String searching functions (find, rfind)
- Substring extraction (substr)
- String comparison (operators, compare method)
- String modification (replace, erase)
- String conversion (to_string, stoi, stof)

## Instructions
1. Open `src/string_operations_exercises.cpp`
2. Follow the TODO comments to implement the string operations
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/string_operations_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Original text: "Hello, World! Welcome to C++ Programming!"
Found 'World' at position: 7
Last 'o' found at position: 37
'Java' not found (pos == npos)
Substring from position 7, length 5: "World"
Substring from position 13 to end: "! Welcome to C++ Programming!"
Out of range error when extracting substring: basic_string::substr: __pos (which is 100) > this->size() (which is 42)
"apple" equals "apple"
"apple" comes before "banana" lexicographically
"apple" comes before "banana" (compare result: -1)
Before replacement: "Hello, World!"
After replacing 'World' with 'C++': "Hello, C++!"
After erasing characters at position 5, length 2: "Hello C++!"
Integer 42 as string: "42"
Double 3.14159 as string: "3.141590"
String "123" as integer: 123
String "45.67" as float: 45.67
Cannot convert "abc" to integer: stoi: no conversion
```

## Key Points to Remember
- **Searching**: Use `find()` and `rfind()` to locate substrings, check for `std::string::npos` when not found
- **Substrings**: Use `substr(pos, len)` to extract parts of strings, handle out-of-bounds exceptions
- **Comparison**: Use operators for simple comparisons, `compare()` for detailed results
- **Modification**: Use `replace()` and `erase()` to modify string content
- **Conversion**: Use `std::to_string()` for numbers to strings, `std::stoi()/std::stof()` for strings to numbers
- **Error Handling**: Always handle exceptions when working with string operations

## Common Mistakes to Avoid
- Forgetting to check for `std::string::npos` when searching
- Not handling out-of-bounds exceptions in substring operations
- Confusing lexicographical ordering with string length
- Not handling conversion errors when converting strings to numbers
- Forgetting to include `<string>` header for string operations

## Next Steps
After completing this exercise, proceed to:
- Exercise 3.2b: Advanced String Operations
- Exercise 3.3: Array and String Algorithms