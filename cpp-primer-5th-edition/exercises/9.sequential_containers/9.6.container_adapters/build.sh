#!/bin/bash

# Build script for container adapters exercise

# Create build directory if it doesn't exist
mkdir -p build

# Change to build directory
cd build

# Run CMake to generate build files
cmake ..

# Compile the project
make

# Check if build was successful
if [ $? -eq 0 ]; then
    echo "Build successful!"
else
    echo "Build failed!"
    exit 1
fi