#!/bin/bash

# Build script for conditional expressions exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/conditional_expressions_exercises"
echo "Run the solutions with: ./build/conditional_expressions_solutions"