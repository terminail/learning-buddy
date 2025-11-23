#!/bin/bash

# Build script for arithmetic_operators exercise

echo "Building arithmetic operators exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"