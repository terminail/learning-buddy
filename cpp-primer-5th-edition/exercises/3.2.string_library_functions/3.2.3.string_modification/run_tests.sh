#!/bin/bash

# Test runner script for string_modification exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all string modification tests..."
./test_string_modification_basics
echo ""
./test_string_modification_practice

echo ""
echo "Test execution completed!"