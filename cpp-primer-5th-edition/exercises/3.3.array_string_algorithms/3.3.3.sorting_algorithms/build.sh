#!/bin/bash

# Build script for sorting_algorithms exercise

echo "Building sorting algorithms exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"