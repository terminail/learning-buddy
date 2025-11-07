# Lambda Expressions Basics Exercise

## Learning Objectives
- Understand lambda expression syntax and components
- Learn different capture modes (=, &, [var], [&, var], [=, &var])
- Practice with lambda expressions in STL algorithms
- Work with std::function to store callable objects
- Understand closure objects and their lifetime

## Topics Covered
- Lambda expression syntax: [capture](parameters) -> return_type { body }
- Capture modes: by value, by reference, mixed captures
- Generic lambdas (C++14 feature)
- Lambda expressions with STL algorithms
- std::function wrapper for callable objects
- Closure objects and their lifetime

## Prerequisites
- Basic understanding of functions and function pointers
- Familiarity with STL containers and algorithms
- Knowledge of scope and lifetime concepts

## Estimated Completion Time
- Basic exercises: 45-60 minutes
- Practice exercises: 60-90 minutes

## Exercise Files
- `src/lambda_expressions_basics_exercises.cpp` - Exercises with TODO comments for student implementation
- `src/lambda_expressions_basics_solutions.cpp` - Complete solutions for reference
- `test/test_lambda_expressions_basics_basics.cpp` - Basic functionality tests
- `test/test_lambda_expressions_basics_practice.cpp` - Advanced practice challenges

## How to Build and Run

```bash
# Build the exercises
./build.sh

# Run the exercises
./build/lambda_expressions_basics_exercises

# Run the solutions
./build/lambda_expressions_basics_solutions

# Run tests
./run_tests.sh
```