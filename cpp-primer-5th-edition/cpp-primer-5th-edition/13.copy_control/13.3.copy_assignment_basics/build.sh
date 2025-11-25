#!/bin/bash

# Build script for copy assignment basics exercise

echo "Building copy assignment basics exercise..."

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
echo "Run exercises with: ./build/copy_assignment_basics_exercises"
echo "Run solutions with: ./build/copy_assignment_basics_solutions"
echo "Run tests with: ./build/test_copy_assignment_basics"