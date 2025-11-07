#!/usr/bin/env python3

# Test runner script for the Python exercise with pytest
# This script runs the pytest tests

import subprocess
import sys
import os

def run_tests():
    """Run the exercise tests with pytest"""
    print("Running tests with pytest...")
    
    # Try to run pytest
    try:
        result = subprocess.run([sys.executable, '-m', 'pytest', 'test_exercise.py', '-v'], 
                              capture_output=True, text=True, check=True)
        print(result.stdout)
        return True
    except subprocess.CalledProcessError as e:
        print("Tests failed:")
        print(e.stdout)
        print(e.stderr)
        return False
    except FileNotFoundError:
        # If pytest is not available, try to install it
        print("Pytest not found. Trying to install...")
        try:
            subprocess.run([sys.executable, '-m', 'pip', 'install', 'pytest'], 
                          capture_output=True, text=True, check=True)
            print("Pytest installed successfully!")
            # Try running tests again
            result = subprocess.run([sys.executable, '-m', 'pytest', 'test_exercise.py', '-v'], 
                                  capture_output=True, text=True, check=True)
            print(result.stdout)
            return True
        except subprocess.CalledProcessError as e:
            print("Failed to install or run pytest:")
            print(e.stdout)
            print(e.stderr)
            return False

if __name__ == "__main__":
    print("Running Python exercise tests with pytest...")
    success = run_tests()
    if success:
        print("All tests passed!")
    else:
        print("Some tests failed.")
        sys.exit(1)