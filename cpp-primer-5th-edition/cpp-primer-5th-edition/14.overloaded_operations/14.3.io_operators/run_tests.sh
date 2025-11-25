#!/bin/bash

# Test runner script for IO operators exercise

# Build first if needed
if [ ! -f "build/test_io_operators_basics" ] || [ ! -f "build/test_io_operators_practice" ]; then
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
echo "Running all IO operators tests..."
./test_io_operators_basics
echo ""
./test_io_operators_practice

echo ""
echo "Test execution completed!"