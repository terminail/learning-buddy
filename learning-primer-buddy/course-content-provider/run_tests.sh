#!/bin/bash

# Test runner for the Course Content Provider service

echo "Running Course Content Provider Tests"
echo "===================================="

# Check if we're in the right directory
if [ ! -f "pyproject.toml" ]; then
    echo "Error: pyproject.toml not found. Please run this script from the course-content-provider directory."
    exit 1
fi

# Install dependencies if not already installed
echo "Installing dependencies..."
pip install -e .[dev]

# Run tests
echo "Running tests..."
python -m pytest tests -v

echo "Tests completed."