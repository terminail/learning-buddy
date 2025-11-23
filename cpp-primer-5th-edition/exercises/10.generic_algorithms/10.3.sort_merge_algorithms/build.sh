#!/bin/bash

# Build script for sort_merge_algorithms exercise

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to build directory
cd build

# Run CMake
# Run CMake with explicit compiler paths
# This fixes issues where CMake tries to use cc instead of gcc
cmake .. -DCMAKE_C_COMPILER=C:/msys64/mingw64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe

# Build the project
# Check if ninja is available, otherwise use make
if command -v ninja &> /dev/null; then
    ninja
else
    make
fi

echo "Build completed successfully!"
echo "To run tests, use: ./run_tests.sh"