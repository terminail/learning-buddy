#!/bin/bash

# Test runner script for access_control exercise

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