#!/bin/bash

# Build script for all functions exercises

echo "Building all functions exercises..."

# Create main build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build all exercises
make build_all_exercises

echo "All functions exercises built successfully!"

echo ""
echo "To run individual exercises:"
echo "  ./basic_functions/build/basic_functions_exercises"
echo "  ./basic_functions/build/basic_functions_solutions"

echo ""
echo "To run tests:"
echo "  cd basic_functions/build && ./test_basic_functions_basics"