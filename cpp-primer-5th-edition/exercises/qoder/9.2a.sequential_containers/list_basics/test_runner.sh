#!/bin/bash

# Test runner script for list basics exercise

# Build the project first
echo "Building project..."
./build.sh > /dev/null 2>&1

# Check if build was successful
if [ $? -ne 0 ]; then
    echo "Build failed. Please check your code."
    exit 1
fi

echo "Build successful!"

# Run the Google Test executables
echo "Running basic tests..."
cd build
./test_list_basics_basics

echo ""
echo "Running practice tests..."
./test_list_basics_practice

echo ""
echo "All tests completed!"