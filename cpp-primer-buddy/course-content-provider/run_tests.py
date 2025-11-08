#!/usr/bin/env python3
"""
Test runner for the Course Content Provider service
"""
import subprocess
import sys
import os

def run_tests():
    """Run all tests for the Course Content Provider"""
    print("Running Course Content Provider Tests")
    print("=" * 40)
    
    # Check if we're in the right directory
    if not os.path.exists("pyproject.toml"):
        print("Error: pyproject.toml not found. Please run this script from the course-content-provider directory.")
        return False
    
    # Install dependencies if not already installed
    try:
        subprocess.run([sys.executable, "-m", "pip", "install", ".[dev]"], check=True, capture_output=True)
    except subprocess.CalledProcessError as e:
        print(f"Error installing dependencies: {e}")
        return False
    
    # Run tests
    try:
        result = subprocess.run([sys.executable, "-m", "pytest", "tests", "-v"], check=True)
        return result.returncode == 0
    except subprocess.CalledProcessError as e:
        print(f"Tests failed with return code {e.returncode}")
        return False
    except FileNotFoundError:
        print("Error: pytest not found. Please make sure it's installed.")
        return False

if __name__ == "__main__":
    success = run_tests()
    sys.exit(0 if success else 1)