#!/bin/bash

# Build script for class basics exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/class_basics_exercises"
echo "Run the solutions with: ./build/class_basics_solutions"