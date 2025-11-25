#!/bin/bash

# Test runner script for operator_precedence exercise

# Build first if needed
if [ ! -f "build/test_operator_precedence_basics" ] || [ ! -f "build/test_operator_precedence_practice" ]; then
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
echo "Running all operator precedence tests..."
./test_operator_precedence_basics
echo ""
./test_operator_precedence_practice

echo ""
echo "Test execution completed!"