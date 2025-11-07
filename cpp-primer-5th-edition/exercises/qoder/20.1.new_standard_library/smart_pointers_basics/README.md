# Smart Pointers Basics Exercise

## Learning Objectives
- Understand the purpose and benefits of smart pointers
- Learn to use std::unique_ptr for exclusive ownership
- Learn to use std::shared_ptr for shared ownership
- Practice using std::make_unique and std::make_shared factory functions
- Understand the difference between unique_ptr and shared_ptr

## Topics Covered
- Automatic memory management
- RAII (Resource Acquisition Is Initialization)
- Exclusive ownership with unique_ptr
- Shared ownership with shared_ptr
- Factory functions make_unique and make_shared
- Automatic cleanup and exception safety

## Prerequisites
- Basic understanding of C++ pointers
- Knowledge of dynamic memory allocation with new/delete
- Familiarity with constructors and destructors

## Estimated Completion Time
- Basic exercises: 45-60 minutes
- Practice exercises: 60-90 minutes

## Exercise Files
- `src/smart_pointers_basics_exercises.cpp` - Exercises with TODO comments for student implementation
- `src/smart_pointers_basics_solutions.cpp` - Complete solutions for reference
- `test/test_smart_pointers_basics_basics.cpp` - Basic functionality tests
- `test/test_smart_pointers_basics_practice.cpp` - Advanced practice challenges

## How to Build and Run

```bash
# Build the exercises
./build.sh

# Run the exercises
./build/smart_pointers_basics_exercises

# Run the solutions
./build/smart_pointers_basics_solutions

# Run tests
./run_tests.sh
```