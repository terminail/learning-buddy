#!/bin/bash

# Build script for arithmetic operators overloading exercise

echo "Building arithmetic operators exercise..."

# Clean any existing build directory to avoid path conflicts
rm -rf build

# Create build directory
mkdir -p build
cd build

# Configure with CMake using Unix Makefiles generator explicitly
# This avoids issues with ninja in WSL environments
# Use default compiler detection for Linux/macOS/WSL
cmake .. -G "Unix Makefiles"

# Build the project
make

echo "Build complete!"
echo "Run exercises with: ./build/arithmetic_operators_exercises"
echo "Run solutions with: ./build/arithmetic_operators_solutions"
echo "Run tests with: ./build/test_arithmetic_operators"