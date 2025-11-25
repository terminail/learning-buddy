#!/bin/bash

# Build script for IO operators overloading exercise

echo "Building IO operators exercise..."

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
echo "Run exercises with: ./build/io_operators_exercises"
echo "Run solutions with: ./build/io_operators_solutions"
echo "Run tests with: ./build/test_io_operators"