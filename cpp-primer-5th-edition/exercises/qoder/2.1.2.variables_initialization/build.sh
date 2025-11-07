#!/bin/bash

# Build script for variables initialization exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/variables_initialization_exercises"
echo "Run the solutions with: ./build/variables_initialization_solutions"