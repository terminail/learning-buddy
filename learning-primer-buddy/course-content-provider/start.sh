#!/bin/bash

# Course Content Provider Startup Script

echo "Course Content Provider - Startup Script"
echo "========================================"

# Check if conda is available
if ! command -v conda &> /dev/null; then
    echo "Error: Conda is not installed or not in PATH"
    echo "Please install Miniconda or Anaconda first"
    exit 1
fi

# Check if conda environment exists
if conda env list | grep -q liugejiao; then
    echo "Conda environment 'liugejiao' already exists"
else
    echo "Creating conda environment 'liugejiao'"
    conda create -n liugejiao python=3.12 -y
fi

# Activate conda environment
echo "Activating conda environment 'liugejiao'"
eval "$(conda shell.bash hook)"
conda activate liugejiao

# Install dependencies using pyproject.toml
echo "Installing dependencies from pyproject.toml"
pip install .

# Check if Podman is available
if command -v podman &> /dev/null; then
    echo "Podman is available. You can also run the service in a container:"
    echo "  podman build -t course-content-provider -f Podmanfile ."
    echo "  podman run -p 8000:8000 course-content-provider"
    echo ""
fi

# Start the service
echo "Starting Course Content Provider service"
echo "Service will be available at http://localhost:8000"
echo "Press Ctrl+C to stop the service"
echo ""

course-content-provider