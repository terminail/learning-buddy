#!/bin/bash

# Build script for nested statements exercise

echo "Building nested statements exercise..."

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
echo "Run the exercises with: ./build/nested_statements_exercises"
echo "Run the solutions with: ./build/nested_statements_solutions"