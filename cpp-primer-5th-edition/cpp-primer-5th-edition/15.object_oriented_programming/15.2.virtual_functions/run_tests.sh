#!/bin/bash

# Test runner script for virtual_functions exercise

# Build first if needed
if [ ! -f "build/test_virtual_functions_basics" ] || [ ! -f "build/test_virtual_functions_practice" ]; then
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
echo "Running all virtual functions tests..."
./test_virtual_functions_basics
echo ""
./test_virtual_functions_practice

echo ""
echo "Test execution completed!"