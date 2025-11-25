#!/bin/bash

# Test runner script for container adapters exercise

# Build first if needed
if [ ! -f "build/test_container_adapters_basics" ] || [ ! -f "build/test_container_adapters_practice" ]; then
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
echo "Running all container adapters tests..."
./test_container_adapters_basics
echo ""
./test_container_adapters_practice

echo ""
echo "Test execution completed!"