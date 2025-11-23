#!/bin/bash

# Build script for comparison operators overloading exercise

# Create build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Generate build files with CMake
cmake ..

# Compile the project
# Check if ninja is available, otherwise use make
if command -v ninja &> /dev/null; then
    ninja
else
    make
fi

echo "Build complete!"
echo "Run exercises with: ./build/comparison_operators_exercises"
echo "Run solutions with: ./build/comparison_operators_solutions"
echo "Run tests with: ./build/test_comparison_operators"