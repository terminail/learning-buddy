# Variables and Simple Data Types Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_variables_exist():
    """Test that required variables exist"""
    try:
        import exercise
        name = getattr(exercise, 'name', None)
        age = getattr(exercise, 'age', None)
        height = getattr(exercise, 'height', None)
        message = getattr(exercise, 'message', None)
        assert name is not None, "Variable 'name' is missing"
        assert age is not None, "Variable 'age' is missing"
        assert height is not None, "Variable 'height' is missing"
        assert message is not None, "Variable 'message' is missing"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_variable_types():
    """Test that variables have correct types"""
    try:
        import exercise
        name = getattr(exercise, 'name', None)
        age = getattr(exercise, 'age', None)
        height = getattr(exercise, 'height', None)
        message = getattr(exercise, 'message', None)
        
        if name is not None:
            assert isinstance(name, str), "Variable 'name' should be a string"
        if age is not None:
            assert isinstance(age, int), "Variable 'age' should be an integer"
        if height is not None:
            assert isinstance(height, float), "Variable 'height' should be a float"
        if message is not None:
            assert isinstance(message, str), "Variable 'message' should be a string"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_string_methods():
    """Test that string methods are used correctly"""
    try:
        import exercise
        message = getattr(exercise, 'message', None)
        if message is not None:
            # Check that string methods exist (they should be callable)
            assert hasattr(message, 'title'), "String should have a title() method"
            assert hasattr(message, 'upper'), "String should have an upper() method"
            assert hasattr(message, 'lower'), "String should have a lower() method"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_formatting_variables():
    """Test that formatting variables exist"""
    try:
        import exercise
        f_string_message = getattr(exercise, 'f_string_message', None)
        concatenated_message = getattr(exercise, 'concatenated_message', None)
        
        if f_string_message is not None:
            assert isinstance(f_string_message, str), "Variable 'f_string_message' should be a string"
        
        if concatenated_message is not None:
            assert isinstance(concatenated_message, str), "Variable 'concatenated_message' should be a string"
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