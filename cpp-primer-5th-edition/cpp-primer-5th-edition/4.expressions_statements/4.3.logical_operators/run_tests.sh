#!/bin/bash

# Test runner script for logical_operators exercise

# Build first if needed
if [ ! -f "build/test_logical_operators_basics" ] || [ ! -f "build/test_logical_operators_practice" ]; then
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
echo "Running all logical operators tests..."
./test_logical_operators_basics
echo ""
./test_logical_operators_practice

echo ""
echo "Test execution completed!"