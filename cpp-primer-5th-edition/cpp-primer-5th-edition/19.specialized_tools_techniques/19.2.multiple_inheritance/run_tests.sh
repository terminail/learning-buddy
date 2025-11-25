#!/bin/bash

# Test runner script for multiple_inheritance exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all multiple inheritance tests..."
./test_multiple_inheritance_basics
echo ""
./test_multiple_inheritance_practice

echo ""
echo "Test execution completed!"