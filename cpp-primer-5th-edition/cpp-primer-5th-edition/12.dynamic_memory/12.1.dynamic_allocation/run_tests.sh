#!/bin/bash

# Test runner script for dynamic_allocation exercise

# Build first if needed
if [ ! -f "build/test_dynamic_allocation_basics" ] || [ ! -f "build/test_dynamic_allocation_practice" ]; then
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
echo "Running all dynamic allocation tests..."
./test_dynamic_allocation_basics
echo ""
./test_dynamic_allocation_practice

echo ""
echo "Test execution completed!"