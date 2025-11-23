#!/bin/bash

# Build script for relational_operators exercise

echo "Building relational operators exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"