#!/bin/bash

# Build script for stack basics exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/stack_basics_exercises"
echo "Run the solutions with: ./build/stack_basics_solutions"