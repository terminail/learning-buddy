#!/bin/bash

# Build script for algorithms practice exercise

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
echo "Run the exercises with: ./build/algorithms_practice_exercises"
echo "Run the solutions with: ./build/algorithms_practice_solutions"