#!/bin/bash

# Test runner script for random_numbers exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all random numbers tests..."
./test_random_numbers_basics
echo ""
./test_random_numbers_practice

echo ""
echo "Test execution completed!"