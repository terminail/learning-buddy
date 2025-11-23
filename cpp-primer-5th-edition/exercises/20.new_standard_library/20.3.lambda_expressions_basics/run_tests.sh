#!/bin/bash

# Test runner script for lambda expressions basics exercise

# Build first
./build.sh

# Change to build directory
cd build

# Run basic tests
echo "Running basic tests..."
./test_lambda_expressions_basics_basics

# Run practice tests
echo "Running practice tests..."
./test_lambda_expressions_basics_practice

echo "All tests completed!"