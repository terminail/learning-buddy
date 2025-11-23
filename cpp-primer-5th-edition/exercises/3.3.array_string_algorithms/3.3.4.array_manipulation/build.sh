#!/bin/bash

# Build script for array_manipulation exercise

echo "Building array manipulation exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"