#!/bin/bash

# Build script for scope_and_lifetime exercise

echo "Building scope and lifetime exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"