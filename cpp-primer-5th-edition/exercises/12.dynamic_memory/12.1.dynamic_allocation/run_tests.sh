#!/bin/bash

# Test runner script for dynamic_allocation exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all dynamic allocation tests..."
./test_dynamic_allocation_basics
echo ""
./test_dynamic_allocation_practice

echo ""
echo "Test execution completed!"