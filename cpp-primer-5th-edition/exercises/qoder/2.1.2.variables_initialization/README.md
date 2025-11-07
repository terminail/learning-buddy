# Exercise 2.1.2: Variable Initialization Methods

## Learning Objectives
- Understand different ways to initialize variables in C++
- Learn about copy initialization, direct initialization, and uniform initialization
- Practice using the auto keyword for type deduction
- Compare different initialization syntaxes

## Concepts Covered
- Variable initialization methods
- Copy initialization (`int x = 5;`)
- Direct initialization (`int x(5);`)
- Uniform initialization (`int x{5};`)
- Auto keyword for type deduction

## Instructions
1. Open `src/variables_initialization_exercises.cpp`
2. Follow the TODO comments to declare and initialize variables using different methods
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/variables_initialization_solutions.cpp`

## Expected Output
```
Count: 10
Price: 19.99
Grade: A
Is Complete: false
Message: Hello
```

## Key Points to Remember
- **Copy initialization**: `int x = 5;` - Most common and readable
- **Direct initialization**: `int x(5);` - Function-like syntax
- **Uniform initialization**: `int x{5};` - Modern C++ preferred method, helps prevent narrowing conversions
- **Auto keyword**: `auto x = 5;` - Compiler deduces the type from the initializer

## Common Mistakes to Avoid
- Confusing declaration with initialization
- Using wrong syntax for different initialization methods
- Forgetting to include the `<string>` header when using `std::string`
- Using incorrect syntax for character literals (use single quotes for char)

## Next Steps
After completing this exercise, proceed to:
- Exercise 2.1.3: Constants and Constexpr
- Exercise 2.1.4: Scope and Lifetime