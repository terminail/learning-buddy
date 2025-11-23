#!/bin/bash

# Test runner script for numeric_algorithms exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all numeric algorithms tests..."
./test_numeric_algorithms_basics
echo ""
./test_numeric_algorithms_practice

echo ""
echo "Test execution completed!"