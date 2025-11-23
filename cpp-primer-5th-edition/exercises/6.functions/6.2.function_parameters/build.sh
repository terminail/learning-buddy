#!/bin/bash

# Build script for function_parameters exercise

echo "Building function parameters exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"