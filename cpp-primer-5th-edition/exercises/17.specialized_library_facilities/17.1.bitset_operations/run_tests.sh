#!/bin/bash

# Test runner script for bitset_operations exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all bitset operations tests..."
./test_bitset_operations_basics
echo ""
./test_bitset_operations_practice

echo ""
echo "Test execution completed!"