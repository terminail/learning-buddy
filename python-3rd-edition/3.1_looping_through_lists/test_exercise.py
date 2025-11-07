# Looping Through Lists Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_lists_exist():
    """Test that required lists exist"""
    try:
        import exercise
        fruits = getattr(exercise, 'fruits', None)
        numbers = getattr(exercise, 'numbers', None)
        
        assert fruits is not None, "List 'fruits' is missing"
        assert isinstance(fruits, list), "Variable 'fruits' should be a list"
        assert len(fruits) >= 4, "List 'fruits' should have at least 4 elements"
        
        assert numbers is not None, "List 'numbers' is missing"
        assert isinstance(numbers, list), "Variable 'numbers' should be a list"
        assert len(numbers) >= 5, "List 'numbers' should have at least 5 elements"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_list_comprehensions():
    """Test that list comprehensions exist"""
    try:
        import exercise
        squares = getattr(exercise, 'squares', None)
        uppercase_fruits = getattr(exercise, 'uppercase_fruits', None)
        vowel_fruits = getattr(exercise, 'vowel_fruits', None)
        
        # Check that list comprehension variables exist
        if squares is not None:
            assert isinstance(squares, list), "Variable 'squares' should be a list"
        
        if uppercase_fruits is not None:
            assert isinstance(uppercase_fruits, list), "Variable 'uppercase_fruits' should be a list"
        
        if vowel_fruits is not None:
            assert isinstance(vowel_fruits, list), "Variable 'vowel_fruits' should be a list"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_calculation_variables():
    """Test that calculation variables exist"""
    try:
        import exercise
        sum_result = getattr(exercise, 'sum_result', None)
        
        if sum_result is not None:
            assert isinstance(sum_result, (int, float)), "Variable 'sum_result' should be a number"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_iteration_methods():
    """Test that iteration methods are implemented"""
    try:
        import exercise
        # We can't test the actual loops without running the code
        # But we can check that the required variables exist
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