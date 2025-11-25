# Exercise 7.1a: Class Basics

## Learning Objectives
- Understand how to define classes in C++
- Learn about class members (data members and member functions)
- Practice using access specifiers (public, private)
- Implement programs that use classes to model real-world entities

## Concepts Covered
- Class definition syntax
- Data members and member functions
- Access specifiers (public, private)
- Constructors and initialization
- Getter and setter functions
- Object creation and usage

## Instructions
1. Open `src/class_basics_exercises.cpp`
2. Follow the TODO comments to implement the class and its functionality
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/class_basics_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Initial student information:
Student Name: Alice, Age: 20
Using getter functions:
Name: Alice
Age: 20
Updated student information:
Student Name: Alice Smith, Age: 21
Second student information:
Student Name: Bob, Age: 19
```

## Key Points to Remember
- **Class Definition**: Use `class` keyword followed by class name and body in braces
- **Access Specifiers**: Use `public` for accessible members, `private` for hidden members
- **Constructors**: Special functions that initialize objects when they're created
- **Member Functions**: Functions that belong to a class and can access its members
- **Getter/Setter Functions**: Public functions to access and modify private data
- **Object Creation**: Create objects using class name followed by parentheses

## Common Mistakes to Avoid
- Forgetting to use access specifiers (default is private in classes)
- Not providing constructors for proper initialization
- Making data members public instead of using getter/setter functions
- Forgetting to include the `<string>` header for string operations
- Not using const correctness for getter functions that don't modify data

## Next Steps
After completing this exercise, proceed to:
- Exercise 7.1b: Class with Separate Files
- Exercise 7.2: Class Constructors and Destructors