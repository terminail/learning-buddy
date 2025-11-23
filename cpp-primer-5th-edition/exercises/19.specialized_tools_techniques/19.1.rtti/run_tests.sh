#!/bin/bash

# Test runner script for RTTI exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all RTTI tests..."
./test_rtti_basics
echo ""
./test_rtti_practice

echo ""
echo "Test execution completed!"