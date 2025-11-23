#!/bin/bash

# Test runner script for logical_operators exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all logical operators tests..."
./test_logical_operators_basics
echo ""
./test_logical_operators_practice

echo ""
echo "Test execution completed!"