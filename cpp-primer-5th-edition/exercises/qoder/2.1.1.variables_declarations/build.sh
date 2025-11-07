#!/bin/bash

# Build script for variables declarations exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/variables_declarations_exercises"
echo "Run the solutions with: ./build/variables_declarations_solutions"