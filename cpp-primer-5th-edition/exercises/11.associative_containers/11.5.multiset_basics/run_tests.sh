#!/bin/bash

# Test runner script for multiset basics exercise

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
echo "Running basic multiset basics tests..."
./build/test_multiset_basics_basics

# Run practice tests
echo "Running practice multiset basics tests..."
./build/test_multiset_basics_practice

echo "All tests completed!"