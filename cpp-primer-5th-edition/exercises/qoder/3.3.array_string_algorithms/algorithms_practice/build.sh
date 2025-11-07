#!/bin/bash

# Build script for algorithms practice exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/algorithms_practice_exercises"
echo "Run the solutions with: ./build/algorithms_practice_solutions"