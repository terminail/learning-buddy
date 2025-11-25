#!/bin/bash

# Test runner script for copy assignment basics exercise

# Build first if needed
if [ ! -f "build/test_copy_assignment_basics_basics" ] || [ ! -f "build/test_copy_assignment_basics_practice" ]; then
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
echo "Running all copy assignment basics tests..."
./test_copy_assignment_basics_basics
echo ""
./test_copy_assignment_basics_practice

echo ""
echo "Test execution completed!"