#!/bin/bash

# Test runner script for file streams exercise

# Build first if needed
if [ ! -f "build/test_file_streams_basics" ] || [ ! -f "build/test_file_streams_practice" ]; then
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
echo "Running all file streams tests..."
./test_file_streams_basics
echo ""
./test_file_streams_practice

echo ""
echo "Test execution completed!"