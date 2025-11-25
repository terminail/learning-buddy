#!/bin/bash

# Test runner script for constructors basics exercise

# Build first if needed
if [ ! -f "build/test_constructors_basics" ] || [ ! -f "build/test_constructors_practice" ]; then
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
echo "Running all constructors basics tests..."
./test_constructors_basics
echo ""
./test_constructors_practice

echo ""
echo "Test execution completed!"