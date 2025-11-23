#!/bin/bash

# Test runner script for namespaces exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all namespaces tests..."
./test_namespaces_basics
echo ""
./test_namespaces_practice

echo ""
echo "Test execution completed!"