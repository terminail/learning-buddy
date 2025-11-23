#!/bin/bash

# Build script for logical_operators exercise

echo "Building logical operators exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"