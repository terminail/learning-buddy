#!/bin/bash

# Build script for array basics exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/array_basics_exercises"
echo "Run the solutions with: ./build/array_basics_solutions"