#!/bin/bash

# Test runner script for searching_algorithms exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all searching algorithms tests..."
./test_searching_algorithms_basics
echo ""
./test_searching_algorithms_practice

echo ""
echo "Test execution completed!"