#!/bin/bash

# Build script for set basics exercise

# Create build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Generate build files with CMake
# Run CMake with explicit compiler paths
# This fixes issues where CMake tries to use cc instead of gcc
cmake .. -DCMAKE_C_COMPILER=C:/msys64/mingw64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe

# Compile the project
# Check if ninja is available, otherwise use make
if command -v ninja &> /dev/null; then
    ninja
else
    make
fi

echo "Build complete!"
echo "Run exercises with: ./build/set_basics_exercises"
echo "Run solutions with: ./build/set_basics_solutions"
echo "Run tests with: ./build/test_set_basics"