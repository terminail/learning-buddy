#!/bin/bash

# Test runner script for destructors_basics exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all destructors basics tests..."
./test_destructors_basics
echo ""
./test_destructors_practice

echo ""
echo "Test execution completed!"