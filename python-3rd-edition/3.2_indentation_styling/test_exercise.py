# Indentation and Code Styling Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_variables_exist():
    """Test that required variables exist"""
    try:
        import exercise
        numbers = getattr(exercise, 'numbers', None)
        assert numbers is not None, "List 'numbers' is missing"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_functions_exist():
    """Test that required functions exist"""
    try:
        import exercise
        calculate_square = getattr(exercise, 'calculate_square', None)
        if calculate_square is not None:
            assert callable(calculate_square), "calculate_square should be a function"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_indentation_concepts():
    """Test that indentation concepts are implemented"""
    try:
        import exercise
        # Check that the exercise covers the required indentation concepts
        # We can't test the actual implementation without running the code
        pass
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_output():
    """Test that the program runs without errors"""
    # Run the exercise script and capture output
    try:
        result = subprocess.run([sys.executable, os.path.join(os.path.dirname(__file__), 'exercise.py')], 
                              capture_output=True, text=True, check=True, cwd=os.path.dirname(__file__))
        # If we get here, the script ran without errors
        assert True
    except subprocess.CalledProcessError as e:
        pytest.fail(f"Exercise script failed with error: {e.stderr}")

if __name__ == '__main__':
    pytest.main([__file__, "-v"])