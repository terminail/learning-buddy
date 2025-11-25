#!/bin/bash

# Build script for array and string operations exercise

# Clean any existing build directory to avoid path conflicts
rm -rf build

# Create build directory
mkdir -p build
cd build

# Check if we're in a MinGW environment (Windows)
if command -v mingw32-make &> /dev/null; then
    # Configure with CMake using MinGW Makefiles generator explicitly
    cmake .. -G "MinGW Makefiles"
    
    # Build the project with mingw32-make
    mingw32-make
else
    # Configure with CMake using Unix Makefiles generator explicitly
    # This avoids issues with ninja in WSL environments
    cmake .. -G "Unix Makefiles"
    
    # Build the project with make
    make
fi

echo "Build completed successfully!"
echo "To run tests: ./run_tests.sh"