#!/bin/bash

# Test runner script for deque_operations exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all deque operations tests..."
./test_deque_operations_basics
echo ""
./test_deque_operations_practice

echo ""
echo "Test execution completed!"