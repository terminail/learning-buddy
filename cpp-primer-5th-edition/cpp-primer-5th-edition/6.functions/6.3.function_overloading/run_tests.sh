#!/bin/bash

# Test runner script for function overloading exercise

# Build first if needed
if [ ! -f "build/test_function_overloading_basics" ] || [ ! -f "build/test_function_overloading_practice" ]; then
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
echo "Running all function overloading tests..."
./test_function_overloading_basics
echo ""
./test_function_overloading_practice

echo ""
echo "Test execution completed!"