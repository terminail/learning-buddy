#!/bin/bash

# Build script for function_overloading exercise

echo "Building function overloading exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"