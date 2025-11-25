#!/bin/bash

# Build script for basic sorting algorithms exercise
# This script builds the exercise using CMake and Make

echo "Building basic sorting algorithms exercise..."

# Remove any existing build directory
rm -rf build

# Create build directory
mkdir build
cd build

# Configure with CMake using Unix Makefiles
cmake .. -G "Unix Makefiles"

# Build the project
make

echo "Build completed successfully!"
echo "To run tests, use: ./run_tests.sh"