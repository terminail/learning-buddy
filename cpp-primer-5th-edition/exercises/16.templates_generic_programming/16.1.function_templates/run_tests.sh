#!/bin/bash

# Test runner script for function_templates exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all function templates tests..."
./test_function_templates_basics
echo ""
./test_function_templates_practice

echo ""
echo "Test execution completed!"