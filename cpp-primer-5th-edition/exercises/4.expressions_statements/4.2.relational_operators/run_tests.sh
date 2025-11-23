#!/bin/bash

# Test runner script for relational_operators exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all relational operators tests..."
./test_relational_operators_basics
echo ""
./test_relational_operators_practice

echo ""
echo "Test execution completed!"