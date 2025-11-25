#!/bin/bash

# Build script for destructors basics exercise

echo "Building destructors basics exercise..."

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
echo "Run the exercises with: ./build/destructors_basics_exercises"
echo "Run the solutions with: ./build/destructors_basics_solutions"