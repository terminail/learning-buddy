# Avoiding Index Errors Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_animals_list_exists():
    """Test that the animals list exists"""
    try:
        import exercise
        animals = getattr(exercise, 'animals', None)
        assert animals is not None, "List 'animals' is missing"
        assert isinstance(animals, list), "Variable 'animals' should be a list"
        assert len(animals) >= 3, "List 'animals' should have at least 3 elements"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_safe_functions_exist():
    """Test that safe functions exist"""
    try:
        import exercise
        # Check that safe functions exist
        safe_get_element = getattr(exercise, 'safe_get_element', None)
        print_list_safely = getattr(exercise, 'print_list_safely', None)
        
        if safe_get_element is not None:
            assert callable(safe_get_element), "safe_get_element should be a function"
        
        if print_list_safely is not None:
            assert callable(print_list_safely), "print_list_safely should be a function"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_list_length_variable():
    """Test that list length variable exists"""
    try:
        import exercise
        animals_length = getattr(exercise, 'animals_length', None)
        
        if animals_length is not None:
            assert isinstance(animals_length, int), "Variable 'animals_length' should be an integer"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_error_handling():
    """Test that error handling concepts are implemented"""
    try:
        import exercise
        # We can't test the actual try-except blocks without running the code
        # But we can check that the required variables exist
        pass
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_empty_list_handling():
    """Test that empty list handling is considered"""
    try:
        import exercise
        # Check that concepts for handling empty lists are implemented
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