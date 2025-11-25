#!/bin/bash

# Build script for access control exercise

echo "Building access control exercise..."

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
echo "Run the exercises with: ./build/access_control_exercises"
echo "Run the solutions with: ./build/access_control_solutions"