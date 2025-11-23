#!/bin/bash

# Build script for pair_multimap exercise

# Create build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Run CMake to generate build files
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

# Check if build was successful
if [ $? -eq 0 ]; then
    echo "Build successful!"
else
    echo "Build failed!"
    exit 1
fi