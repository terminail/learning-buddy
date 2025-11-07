#!/bin/bash

# Build script for array and string operations exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/array_string_operations_exercises"
echo "Run the solutions with: ./build/array_string_operations_solutions"