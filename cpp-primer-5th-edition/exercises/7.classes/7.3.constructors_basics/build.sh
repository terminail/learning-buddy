#!/bin/bash

# Build script for constructors_basics exercise

echo "Building constructors basics exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"