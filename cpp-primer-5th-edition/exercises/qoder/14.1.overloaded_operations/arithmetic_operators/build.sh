#!/bin/bash

# Build script for arithmetic operators overloading exercise

# Create build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Generate build files with CMake
cmake ..

# Compile the project
make

echo "Build complete!"
echo "Run exercises with: ./build/arithmetic_operators_exercises"
echo "Run solutions with: ./build/arithmetic_operators_solutions"
echo "Run tests with: ./build/test_arithmetic_operators"