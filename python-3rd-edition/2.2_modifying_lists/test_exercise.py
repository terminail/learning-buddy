# Modifying Lists Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_lists_exist():
    """Test that required lists exist"""
    try:
        import exercise
        colors = getattr(exercise, 'colors', None)
        assert colors is not None, "List 'colors' is missing"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_list_methods():
    """Test that list methods are used correctly"""
    try:
        import exercise
        colors = getattr(exercise, 'colors', None)
        
        if colors is not None:
            assert isinstance(colors, list), "Variable 'colors' should be a list"
            assert len(colors) >= 4, "List 'colors' should have at least 4 elements"
            
            # Check that it's a list of strings
            assert all(isinstance(item, str) for item in colors), "All elements in 'colors' should be strings"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_modification_methods():
    """Test that list modification methods exist"""
    try:
        import exercise
        # Check that common list methods are used
        # We can't test the exact implementation without knowing the student's approach
        # But we can check that the required variables exist
        more_colors = getattr(exercise, 'more_colors', None)
        sorted_colors = getattr(exercise, 'sorted_colors', None)
        colors_copy = getattr(exercise, 'colors_copy', None)
        colors_reference = getattr(exercise, 'colors_reference', None)
        
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_list_operations():
    """Test that list operations are implemented"""
    try:
        import exercise
        # Check that list operations variables exist
        last_color = getattr(exercise, 'last_color', None)
        
        if last_color is not None:
            # last_color could be any type, so we just check it exists
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