#!/bin/bash

# Build script for destructors_basics exercise

echo "Building destructors basics exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"