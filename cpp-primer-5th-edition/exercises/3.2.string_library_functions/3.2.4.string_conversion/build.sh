#!/bin/bash

# Build script for string_conversion exercise

echo "Building string conversion exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"