#!/bin/bash

# Test runner script for string_algorithms exercise

# Build first if needed
if [ ! -f "build/test_string_algorithms_basics" ] || [ ! -f "build/test_string_algorithms_practice" ]; then
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
echo "Running all string algorithms tests..."
./test_string_algorithms_basics
echo ""
./test_string_algorithms_practice

echo ""
echo "Test execution completed!"