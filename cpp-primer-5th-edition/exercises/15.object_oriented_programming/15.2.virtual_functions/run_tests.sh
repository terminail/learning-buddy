#!/bin/bash

# Test runner script for virtual_functions exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all virtual functions tests..."
./test_virtual_functions_basics
echo ""
./test_virtual_functions_practice

echo ""
echo "Test execution completed!"