#!/bin/bash

# Build script for variable_initialization exercise

echo "Building variable initialization exercise..."

# Clean any existing build directory to avoid path conflicts
rm -rf build

# Create build directory
mkdir -p build
cd build

# Configure with CMake using Unix Makefiles generator explicitly
# This avoids issues with ninja in WSL environments
cmake .. -G "Unix Makefiles"

# Build the project
make

echo "Build completed!"
echo "To run tests: ./run_tests.sh"