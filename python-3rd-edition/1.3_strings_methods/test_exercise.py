# Strings and String Methods Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_string_variables_exist():
    """Test that required string variables exist"""
    try:
        import exercise
        name = getattr(exercise, 'name', None)
        assert name is not None, "Variable 'name' is missing"
        assert isinstance(name, str), "Variable 'name' should be a string"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_string_stripping():
    """Test that string stripping methods work correctly"""
    try:
        import exercise
        name = getattr(exercise, 'name', None)
        stripped_name = getattr(exercise, 'stripped_name', None)
        left_stripped_name = getattr(exercise, 'left_stripped_name', None)
        right_stripped_name = getattr(exercise, 'right_stripped_name', None)
        
        assert name is not None, "Variable 'name' is missing"
        assert stripped_name is not None, "Variable 'stripped_name' is missing"
        assert left_stripped_name is not None, "Variable 'left_stripped_name' is missing"
        assert right_stripped_name is not None, "Variable 'right_stripped_name' is missing"
        
        # Test that stripping works correctly
        assert name.strip() == stripped_name, "strip() method not implemented correctly"
        assert name.lstrip() == left_stripped_name, "lstrip() method not implemented correctly"
        assert name.rstrip() == right_stripped_name, "rstrip() method not implemented correctly"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_prefix_suffix_removal():
    """Test that prefix and suffix removal methods work correctly"""
    try:
        import exercise
        domain = getattr(exercise, 'domain', None)
        name_only = getattr(exercise, 'name_only', None)
        
        assert domain is not None, "Variable 'domain' is missing"
        assert name_only is not None, "Variable 'name_only' is missing"
        
        # Test that prefix/suffix removal works correctly
        assert isinstance(domain, str), "Variable 'domain' should be a string"
        assert isinstance(name_only, str), "Variable 'name_only' should be a string"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_string_searching():
    """Test that string searching methods work correctly"""
    try:
        import exercise
        position = getattr(exercise, 'position', None)
        letter_count = getattr(exercise, 'letter_count', None)
        
        assert position is not None, "Variable 'position' is missing"
        assert letter_count is not None, "Variable 'letter_count' is missing"
        
        # Test that searching works correctly
        assert isinstance(position, int), "Variable 'position' should be an integer"
        assert isinstance(letter_count, int), "Variable 'letter_count' should be an integer"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_string_replacement():
    """Test that string replacement works correctly"""
    try:
        import exercise
        new_sentence = getattr(exercise, 'new_sentence', None)
        
        assert new_sentence is not None, "Variable 'new_sentence' is missing"
        assert isinstance(new_sentence, str), "Variable 'new_sentence' should be a string"
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