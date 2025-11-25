#!/bin/bash

# Test runner script for advanced sorting algorithms exercise

# Build first if needed
if [ ! -f "build/test_advanced_sorting_algorithms_basics" ] || [ ! -f "build/test_advanced_sorting_algorithms_practice" ]; then
    echo "Building project first..."
    ./build.sh > /dev/null 2>&1
fi

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all advanced sorting algorithms tests..."
./test_advanced_sorting_algorithms_basics
echo ""
./test_advanced_sorting_algorithms_practice

echo ""
echo "Test execution completed!"

# Return to original directory
cd ..