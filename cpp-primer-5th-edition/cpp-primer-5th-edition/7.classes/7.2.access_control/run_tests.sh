#!/bin/bash

# Test runner script for access control exercise

# Build first if needed
if [ ! -f "build/test_access_control_basics" ] || [ ! -f "build/test_access_control_practice" ]; then
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
echo "Running all access control tests..."
./test_access_control_basics
echo ""
./test_access_control_practice

echo ""
echo "Test execution completed!"