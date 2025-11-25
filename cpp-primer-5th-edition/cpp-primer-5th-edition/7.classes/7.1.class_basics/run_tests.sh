#!/bin/bash

# Test runner script for class basics exercise

# Build first if needed
if [ ! -f "build/test_class_basics_basics" ] || [ ! -f "build/test_class_basics_practice" ]; then
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
echo "Running all class basics tests..."
./test_class_basics_basics
echo ""
./test_class_basics_practice

echo ""
echo "Test execution completed!"