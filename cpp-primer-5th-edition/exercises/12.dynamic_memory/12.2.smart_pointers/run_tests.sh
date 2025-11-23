#!/bin/bash

# Test runner script for smart_pointers exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all smart pointers tests..."
./test_smart_pointers_basics
echo ""
./test_smart_pointers_practice

echo ""
echo "Test execution completed!"