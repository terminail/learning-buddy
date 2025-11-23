#!/bin/bash

# Build script for array_manipulation exercise

echo "Building array manipulation exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
# Run CMake with explicit compiler paths
# This fixes issues where CMake tries to use cc instead of gcc
cmake .. -DCMAKE_C_COMPILER=C:/msys64/mingw64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe

# Build
# Check if ninja is available, otherwise use make
if command -v ninja &> /dev/null; then
    ninja
else
    make
fi

echo "Build completed!"
echo "To run tests: ./run_tests.sh"