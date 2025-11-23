#!/bin/bash

# Test runner script for constructors_basics exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all constructors basics tests..."
./test_constructors_basics
echo ""
./test_constructors_practice

echo ""
echo "Test execution completed!"