#!/bin/bash

# Build script for queue basics exercise

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "Run the exercises with: ./build/queue_basics_exercises"
echo "Run the solutions with: ./build/queue_basics_solutions"