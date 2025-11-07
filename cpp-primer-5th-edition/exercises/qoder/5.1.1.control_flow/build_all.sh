#!/bin/bash

# Build script for all control flow exercises

echo "Building all control flow exercises..."

# Create main build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build all exercises
make build_all_exercises

echo "All control flow exercises built successfully!"

echo ""
echo "To run individual exercises:"
echo "  ./if_statements/build/if_statements_exercises"
echo "  ./if_statements/build/if_statements_solutions"
echo "  ./loop_statements/build/loop_statements_exercises"
echo "  ./loop_statements/build/loop_statements_solutions"
echo "  ./nested_statements/build/nested_statements_exercises"
echo "  ./nested_statements/build/nested_statements_solutions"

echo ""
echo "To run tests:"
echo "  cd if_statements/build && ./test_if_statements_basics"
echo "  cd loop_statements/build && ./test_loop_statements_basics"
echo "  cd nested_statements/build && ./test_nested_statements_basics"