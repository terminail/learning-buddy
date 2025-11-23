#!/bin/bash

# Test runner script for pair basics exercise

# Build the project first
echo "Building project..."
./build.sh

# Check if build was successful
if [ $? -ne 0 ]; then
    echo "Build failed! Please fix compilation errors before running tests."
    exit 1
fi

# Run the tests
echo "Running tests..."

# Run basic tests
echo "Running basic pair basics tests..."
./build/test_pair_basics_basics

# Run practice tests
echo "Running practice pair basics tests..."
./build/test_pair_basics_practice

echo "All tests completed!"