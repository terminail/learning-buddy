#!/bin/bash

# Build script for scope_and_lifetime exercise

echo "Building scope and lifetime exercise..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
# Check if ninja is available, otherwise use make
if command -v ninja &> /dev/null; then
    ninja
else
    make
fi

echo "Build completed!"
echo "To run tests: ./run_tests.sh"