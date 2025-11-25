#!/bin/bash

# Test runner script for sort_merge_algorithms exercise

# Build first if needed
if [ ! -f "build/test_sort_merge_algorithms_basics" ] || [ ! -f "build/test_sort_merge_algorithms_practice" ]; then
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
echo "Running all sort merge algorithms tests..."
./test_sort_merge_algorithms_basics
echo ""
./test_sort_merge_algorithms_practice

echo ""
echo "Test execution completed!"