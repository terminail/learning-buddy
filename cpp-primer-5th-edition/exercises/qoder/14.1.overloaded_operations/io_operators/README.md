# IO Operators Overloading Exercise

## Learning Objectives
- Understand how to overload stream insertion (<<) and extraction (>>) operators
- Learn why IO operators are typically implemented as non-member functions
- Practice implementing proper IO operations for custom classes
- Understand the importance of returning stream references for chaining

## Topics Covered
- Stream insertion operator (<<)
- Stream extraction operator (>>)
- Friend functions for IO operators
- Stream state management
- Error handling in IO operations
- Chaining of IO operations

## Instructions
1. Implement the TODO comments in [io_operators_exercises.cpp](src/io_operators_exercises.cpp)
2. Build and run your solution using the provided build scripts
3. Compare your implementation with the solution in [io_operators_solutions.cpp](src/io_operators_solutions.cpp)

## Expected Output
When running the solution, you should see output similar to:
```
Output using operator<<:
Person(Name: Alice, Age: 25)
Person(Name: , Age: 0)

Chaining output operators:
Person(Name: Alice, Age: 25) and Person(Name: , Age: 0)

Enter name and age for second person: Bob 30
Updated person information:
Person(Name: Alice, Age: 25)
Person(Name: Bob, Age: 30)
```

## Key Concepts

### Why IO Operators Are Non-Member Functions
IO operators are typically implemented as non-member functions (often friends) because:
1. The left operand is the stream object, not the class object
2. We cannot modify the stream classes to add member functions
3. Symmetry with built-in types (we can write `cout << obj`)

### Friend Functions
IO operators are often declared as friend functions to access private members:
```cpp
class MyClass {
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);
    friend std::istream& operator>>(std::istream& is, MyClass& obj);
    // ...
};
```

### Return Stream References
IO operators should return stream references to enable chaining:
```cpp
// Allows chaining like: cout << obj1 << obj2 << obj3;
std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    // Output object data
    return os;  // Return the stream
}
```

### Stream State Management
Good IO operators should handle stream state properly:
- Leave the stream in a valid state
- Handle input errors gracefully
- Don't modify the object on input failure

## Best Practices

### Output Operator (<<)
```cpp
std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << obj.data;  // Output object data
    return os;       // Return stream for chaining
}
```

### Input Operator (>>)
```cpp
std::istream& operator>>(std::istream& is, MyClass& obj) {
    is >> obj.data;  // Read object data
    return is;       // Return stream for chaining
}
```

### Error Handling
For robust input operators, consider checking stream state:
```cpp
std::istream& operator>>(std::istream& is, MyClass& obj) {
    std::string temp;
    if (is >> temp) {  // Check if read was successful
        obj.setData(temp);
    }
    return is;
}
```

## Common Patterns

### Formatting Output
Consider providing clear, readable output formats:
```cpp
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Person(Name: " << person.name << ", Age: " << person.age << ")";
    return os;
}
```

This makes debugging easier and provides clear information to users.