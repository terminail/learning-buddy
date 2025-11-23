#!/bin/bash

# Test runner script for array_manipulation exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all array manipulation tests..."
./test_array_manipulation_basics
echo ""
./test_array_manipulation_practice

echo ""
echo "Test execution completed!"