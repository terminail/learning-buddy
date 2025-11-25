#!/bin/bash

# Test runner script for exception_handling exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all exception handling tests..."
./test_exception_handling_basics
echo ""
./test_exception_handling_practice

echo ""
echo "Test execution completed!"