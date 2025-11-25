#!/bin/bash

# Test runner script for string_conversion exercise

# Build first if needed
if [ ! -f "build/test_string_conversion_basics" ] || [ ! -f "build/test_string_conversion_practice" ]; then
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
echo "Running all string conversion tests..."
./test_string_conversion_basics
echo ""
./test_string_conversion_practice

echo ""
echo "Test execution completed!"