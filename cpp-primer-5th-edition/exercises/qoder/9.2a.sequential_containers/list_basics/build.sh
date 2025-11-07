#!/bin/bash

# Build script for list basics exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/list_basics_exercises"
echo "Run the solutions with: ./build/list_basics_solutions"