#!/bin/bash

# Test runner script for pair multiset exercise

# Build first if needed
if [ ! -f "build/test_pair_multiset_basics" ] || [ ! -f "build/test_pair_multiset_practice" ]; then
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
echo "Running all pair multiset tests..."
./test_pair_multiset_basics
echo ""
./test_pair_multiset_practice

echo ""
echo "Test execution completed!"