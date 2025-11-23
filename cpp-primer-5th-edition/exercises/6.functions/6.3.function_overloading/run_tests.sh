#!/bin/bash

# Test runner script for function_overloading exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all function overloading tests..."
./test_function_overloading_basics
echo ""
./test_function_overloading_practice

echo ""
echo "Test execution completed!"