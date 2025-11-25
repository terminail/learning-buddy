#!/bin/bash

# Build script for deque operations exercise

echo "Building deque operations exercise..."

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

echo "Build completed successfully!"
echo "Run the exercises with: ./build/deque_operations_exercises"
echo "Run the solutions with: ./build/deque_operations_solutions"