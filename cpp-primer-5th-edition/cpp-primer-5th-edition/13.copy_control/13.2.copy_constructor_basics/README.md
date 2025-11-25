# Copy Constructor Basics Exercise

## Learning Objectives
- Understand the purpose and implementation of copy constructors
- Learn the difference between shallow copy and deep copy
- Practice implementing proper resource management in classes
- Observe when copy constructors are called automatically

## Topics Covered
- Copy constructor syntax and implementation
- Deep copy vs shallow copy
- Dynamic memory management
- Rule of Three (destructor, copy constructor, copy assignment operator)
- Automatic copy constructor invocation

## Instructions
1. Implement the TODO comments in [copy_constructor_basics_exercises.cpp](src/copy_constructor_basics_exercises.cpp)
2. Build and run your solution using the provided build scripts
3. Compare your implementation with the solution in [copy_constructor_basics_solutions.cpp](src/copy_constructor_basics_solutions.cpp)

## Expected Output
When running the solution, you should see output similar to:
```
Original string: String: Hello World, Length: 11
Copy constructor called
Copied string: String: Hello World, Length: 11
Both strings after creation:
String: Hello World, Length: 11
String: Hello World, Length: 11
Destructor called
Destructor called
```

Note that:
1. The copy constructor is automatically called when creating str2 from str1
2. Both objects have independent copies of the data
3. Both destructors are called when the objects go out of scope

## Key Concepts

### When Copy Constructors Are Called
- When initializing an object with another object of the same type
- When passing objects by value to functions
- When returning objects by value from functions
- When throwing or catching exceptions by value

### Shallow vs Deep Copy
- **Shallow Copy**: Copies only the pointer values, not the data they point to
- **Deep Copy**: Allocates new memory and copies the actual data

### Rule of Three
If a class needs a custom destructor, it likely also needs:
1. A custom copy constructor
2. A custom copy assignment operator