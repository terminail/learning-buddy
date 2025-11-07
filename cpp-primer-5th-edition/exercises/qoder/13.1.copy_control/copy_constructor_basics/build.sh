#!/bin/bash

# Build script for copy constructor basics exercise

# Create build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Generate build files with CMake
cmake ..

# Compile the project
make

echo "Build complete!"
echo "Run exercises with: ./build/copy_constructor_basics_exercises"
echo "Run solutions with: ./build/copy_constructor_basics_solutions"
echo "Run tests with: ./build/test_copy_constructor_basics"