#!/bin/bash

# Test runner script for basic IO exercise

# Build first if needed
if [ ! -f "build/test_basic_io_basics" ] || [ ! -f "build/test_basic_io_practice" ]; then
    echo "Building project first..."
    ./build.sh
fi

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all basic IO tests..."
./test_basic_io_basics
echo ""
./test_basic_io_practice

echo ""
echo "Test execution completed!"