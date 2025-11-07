#!/bin/bash

# Build script for basic functions exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/basic_functions_exercises"
echo "Run the solutions with: ./build/basic_functions_solutions"