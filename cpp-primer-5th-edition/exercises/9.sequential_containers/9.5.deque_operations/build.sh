#!/bin/bash

# Build script for deque_operations exercise

echo "Building deque operations exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"