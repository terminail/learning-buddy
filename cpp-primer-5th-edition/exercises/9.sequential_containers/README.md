# Sequential Containers Exercises

This directory contains exercises for working with sequential containers in C++ STL, including vector, list, deque, and container adapters.

## Learning Objectives

- Understand the characteristics and use cases of different sequential containers
- Learn vector operations including initialization, element access, and modification
- Master list operations for efficient insertion and deletion
- Work with deque for double-ended operations
- Use container adapters (stack, queue, priority_queue) for specialized needs

## Exercise Structure

Each subdirectory contains:
- `src/` - Source files with exercises and solutions
- `test/` - Test files to validate implementations
- `CMakeLists.txt` - Build configuration
- `README.md` - Detailed instructions for that specific exercise
- `build.sh` - Build script for Linux environments
- `run_tests.sh` - Test execution script

## Prerequisites

Before working on these exercises, you should be familiar with:
- Basic C++ syntax
- Variables, data types, and control structures
- Functions and basic STL concepts

## Building and Running

To build and run these exercises:

```bash
# Navigate to any specific exercise directory
cd 9.1.vector_basics

# Make scripts executable
chmod +x build.sh run_tests.sh

# Build the exercise
./build.sh

# Run tests
./run_tests.sh
```

## Sequential Containers Overview

Sequential containers maintain their elements in a linear sequence:

1. **Vector** - Dynamic array with fast random access
2. **List** - Doubly-linked list with efficient insertion/deletion
3. **Deque** - Double-ended queue with fast access at both ends
4. **Container Adapters** - Specialized interfaces built on other containers

## Next Steps

After completing these sequential containers exercises, you should move on to:
- Associative Containers (map, set, etc.)
- Generic Algorithms
- Copy Control (constructors, destructors, assignment operators)