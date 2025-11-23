#!/bin/bash

# Test runner script for hello_world exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all hello world tests..."
./test_hello_world_basics
echo ""
./test_hello_world_practice

echo ""
echo "Test execution completed!"