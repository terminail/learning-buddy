#!/bin/bash

# Test runner script for transform_copy_algorithms exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all transform and copy algorithms tests..."
./test_transform_copy_algorithms_basics
echo ""
./test_transform_copy_algorithms_practice

echo ""
echo "Test execution completed!"