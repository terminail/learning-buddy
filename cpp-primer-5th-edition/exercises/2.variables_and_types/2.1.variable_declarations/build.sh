#!/bin/bash

# Build script for variable_declarations exercise

echo "Building variable declarations exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"