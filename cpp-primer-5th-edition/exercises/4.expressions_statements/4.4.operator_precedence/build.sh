#!/bin/bash

# Build script for operator_precedence exercise

echo "Building operator precedence exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"