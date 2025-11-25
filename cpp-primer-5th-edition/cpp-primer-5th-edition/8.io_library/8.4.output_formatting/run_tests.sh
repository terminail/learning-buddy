#!/bin/bash

# Test runner script for output formatting exercise

# Build first if needed
if [ ! -f "build/test_output_formatting_basics" ] || [ ! -f "build/test_output_formatting_practice" ]; then
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
echo "Running all output formatting tests..."
./test_output_formatting_basics
echo ""
./test_output_formatting_practice

echo ""
echo "Test execution completed!"