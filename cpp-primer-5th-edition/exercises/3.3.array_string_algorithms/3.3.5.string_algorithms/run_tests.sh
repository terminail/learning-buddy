#!/bin/bash

# Test runner script for string_algorithms exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all string algorithms tests..."
./test_string_algorithms_basics
echo ""
./test_string_algorithms_practice

echo ""
echo "Test execution completed!"