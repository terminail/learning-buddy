#!/bin/bash

# Build script for variable_initialization exercise

echo "Building variable initialization exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"