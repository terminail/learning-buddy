#!/bin/bash

# Test runner script for string_searching exercise

# Build first if needed
if [ ! -f "build/test_string_searching_basics" ] || [ ! -f "build/test_string_searching_practice" ]; then
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
echo "Running all string searching tests..."
./test_string_searching_basics
echo ""
./test_string_searching_practice

echo ""
echo "Test execution completed!"