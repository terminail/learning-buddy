#!/bin/bash

# Build script for destructor basics exercise

# Create build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Generate build files with CMake
cmake ..

# Compile the project
make

echo "Build complete!"
echo "Run exercises with: ./build/destructor_basics_exercises"
echo "Run solutions with: ./build/destructor_basics_solutions"
echo "Run tests with: ./build/test_destructor_basics"