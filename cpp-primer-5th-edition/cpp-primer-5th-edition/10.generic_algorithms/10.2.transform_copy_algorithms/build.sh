#!/bin/bash

# Build script for transform_copy_algorithms exercise

echo "Building transform copy algorithms exercise..."

# Clean any existing build directory to avoid path conflicts
rm -rf build

# Create build directory
mkdir -p build
cd build

# Configure with CMake using Unix Makefiles generator explicitly
# This avoids issues with ninja in WSL environments
# Use default compiler detection for Linux/macOS/WSL
cmake .. -G "Unix Makefiles"

# Build the project
make

echo "Build completed successfully!"
echo "To run tests, use: ./run_tests.sh"