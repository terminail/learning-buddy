#!/bin/bash

# Test runner script for variable_declarations exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all variable declarations tests..."
./test_variable_declarations_basics
echo ""
./test_variable_declarations_practice

echo ""
echo "Test execution completed!"