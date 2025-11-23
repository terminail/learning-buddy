#!/bin/bash

# Test runner script for scope_and_lifetime exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all scope and lifetime tests..."
./test_scope_and_lifetime_basics
echo ""
./test_scope_and_lifetime_practice

echo ""
echo "Test execution completed!"