#!/bin/bash

# Build script for if statements exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/if_statements_exercises"
echo "Run the solutions with: ./build/if_statements_solutions"