#!/bin/bash

# Build script for string basics exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/string_basics_exercises"
echo "Run the solutions with: ./build/string_basics_solutions"