#!/bin/bash

# Test runner script for move semantics basics exercise

# Build first
./build.sh

# Change to build directory
cd build

# Run basic tests
echo "Running basic tests..."
./test_move_semantics_basics_basics

# Run practice tests
echo "Running practice tests..."
./test_move_semantics_basics_practice

echo "All tests completed!"