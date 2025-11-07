#!/bin/bash

# Build script for nested statements exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/nested_statements_exercises"
echo "Run the solutions with: ./build/nested_statements_solutions"