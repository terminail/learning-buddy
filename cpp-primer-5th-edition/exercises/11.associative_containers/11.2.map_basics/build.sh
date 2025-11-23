#!/bin/bash

# Build script for map basics exercise

# Create build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Generate build files with CMake
cmake ..

# Compile the project
# Check if ninja is available, otherwise use make
if command -v ninja &> /dev/null; then
    ninja
else
    make
fi

echo "Build complete!"
echo "Run exercises with: ./build/map_basics_exercises"
echo "Run solutions with: ./build/map_basics_solutions"
echo "Run tests with: ./build/test_map_basics"