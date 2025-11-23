#!/bin/bash

# Test runner script for stream_states exercise

# Check if build directory exists
if [ ! -d "build" ]; then
    echo "Build directory not found. Please run build.sh first."
    exit 1
fi

# Navigate to build directory
cd build

# Run all tests
echo "Running all stream states tests..."
./test_stream_states_basics
echo ""
./test_stream_states_practice

echo ""
echo "Test execution completed!"