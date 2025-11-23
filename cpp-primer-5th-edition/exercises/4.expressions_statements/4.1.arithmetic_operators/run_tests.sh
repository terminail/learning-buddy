#!/bin/bash

# Test runner script for arithmetic_operators exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all arithmetic operators tests..."
./test_arithmetic_operators_basics
echo ""
./test_arithmetic_operators_practice

echo ""
echo "Test execution completed!"