# Numbers and Operations Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_variables_exist():
    """Test that required variables exist"""
    try:
        import exercise
        # Basic operations
        addition = getattr(exercise, 'addition', None)
        subtraction = getattr(exercise, 'subtraction', None)
        multiplication = getattr(exercise, 'multiplication', None)
        division = getattr(exercise, 'division', None)
        
        # Exponents
        power = getattr(exercise, 'power', None)
        
        # Number types
        integer_result = getattr(exercise, 'integer_result', None)
        float_result = getattr(exercise, 'float_result', None)
        
        # Large numbers
        universe_age = getattr(exercise, 'universe_age', None)
        
        # Built-in functions
        absolute_value = getattr(exercise, 'absolute_value', None)
        rounded_value = getattr(exercise, 'rounded_value', None)
        
        # Multiple assignments
        x = getattr(exercise, 'x', None)
        y = getattr(exercise, 'y', None)
        z = getattr(exercise, 'z', None)
        
        # Constants
        MAX_CONNECTIONS = getattr(exercise, 'MAX_CONNECTIONS', None)
        
        # Check that all variables exist
        assert addition is not None, "Variable 'addition' is missing"
        assert subtraction is not None, "Variable 'subtraction' is missing"
        assert multiplication is not None, "Variable 'multiplication' is missing"
        assert division is not None, "Variable 'division' is missing"
        assert power is not None, "Variable 'power' is missing"
        assert integer_result is not None, "Variable 'integer_result' is missing"
        assert float_result is not None, "Variable 'float_result' is missing"
        assert universe_age is not None, "Variable 'universe_age' is missing"
        assert absolute_value is not None, "Variable 'absolute_value' is missing"
        assert rounded_value is not None, "Variable 'rounded_value' is missing"
        assert x is not None, "Variable 'x' is missing"
        assert y is not None, "Variable 'y' is missing"
        assert z is not None, "Variable 'z' is missing"
        assert MAX_CONNECTIONS is not None, "Variable 'MAX_CONNECTIONS' is missing"
        
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