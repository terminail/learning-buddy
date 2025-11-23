#!/bin/bash

# Build script for vector algorithms exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
# Check if ninja is available, otherwise use make
if command -v ninja &> /dev/null; then
    ninja
else
    make
fi

echo "Build completed successfully!"
echo "Run the exercises with: ./build/vector_algorithms_exercises"
echo "Run the solutions with: ./build/vector_algorithms_solutions"