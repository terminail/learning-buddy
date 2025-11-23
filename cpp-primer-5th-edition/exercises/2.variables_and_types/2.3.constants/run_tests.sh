#!/bin/bash

# Test runner script for constants exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all constants tests..."
./test_constants_basics
echo ""
./test_constants_practice

echo ""
echo "Test execution completed!"