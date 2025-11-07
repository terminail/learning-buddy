# Move Semantics Basics Exercise

## Learning Objectives
- Understand the difference between copy semantics and move semantics
- Learn to use std::move to enable move operations
- Implement move constructors and move assignment operators
- Understand rvalue references and perfect forwarding
- Practice with std::forward for perfect forwarding

## Topics Covered
- Rvalue references (&&)
- Move constructors and move assignment operators
- std::move function
- Perfect forwarding with std::forward
- Return value optimization (RVO)
- Move-only types

## Prerequisites
- Understanding of constructors and destructors
- Knowledge of copy constructors and copy assignment operators
- Basic understanding of lvalues and rvalues

## Estimated Completion Time
- Basic exercises: 60-90 minutes
- Practice exercises: 90-120 minutes

## Exercise Files
- `src/move_semantics_basics_exercises.cpp` - Exercises with TODO comments for student implementation
- `src/move_semantics_basics_solutions.cpp` - Complete solutions for reference
- `test/test_move_semantics_basics_basics.cpp` - Basic functionality tests
- `test/test_move_semantics_basics_practice.cpp` - Advanced practice challenges

## How to Build and Run

```bash
# Build the exercises
./build.sh

# Run the exercises
./build/move_semantics_basics_exercises

# Run the solutions
./build/move_semantics_basics_solutions

# Run tests
./run_tests.sh
```