#!/bin/bash

# Build script for bitset_operations exercise

# Create build directory if it doesn't exist
mkdir -p build

# Navigate to build directory
cd build

# Run CMake
cmake ..

# Build the project
make

echo "Build completed successfully!"
echo "To run tests, use: ./run_tests.sh"