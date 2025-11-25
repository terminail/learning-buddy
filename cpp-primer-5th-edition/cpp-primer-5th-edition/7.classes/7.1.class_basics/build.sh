#!/bin/bash

# Build script for class basics exercise

echo "Building class basics exercise..."

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
echo "Run the exercises with: ./build/class_basics_exercises"
echo "Run the solutions with: ./build/class_basics_solutions"