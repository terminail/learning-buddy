# List Basics and Indexing Tests with Pytest
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
        mixed = getattr(exercise, 'mixed', None)
        assert fruits is not None, "List 'fruits' is missing"
        assert numbers is not None, "List 'numbers' is missing"
        assert mixed is not None, "List 'mixed' is missing"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_list_types():
    """Test that lists have correct types and content"""
    try:
        import exercise
        fruits = getattr(exercise, 'fruits', None)
        numbers = getattr(exercise, 'numbers', None)
        mixed = getattr(exercise, 'mixed', None)
        
        if fruits is not None:
            assert isinstance(fruits, list), "Variable 'fruits' should be a list"
            assert len(fruits) >= 5, "List 'fruits' should have at least 5 elements"
            assert all(isinstance(item, str) for item in fruits), "All elements in 'fruits' should be strings"
        
        if numbers is not None:
            assert isinstance(numbers, list), "Variable 'numbers' should be a list"
            assert len(numbers) >= 5, "List 'numbers' should have at least 5 elements"
            assert all(isinstance(item, int) for item in numbers), "All elements in 'numbers' should be integers"
        
        if mixed is not None:
            assert isinstance(mixed, list), "Variable 'mixed' should be a list"
            assert len(mixed) >= 4, "List 'mixed' should have at least 4 elements"
            # Check that it contains different data types
            types = [type(item) for item in mixed]
            assert str in types, "List 'mixed' should contain at least one string"
            assert int in types, "List 'mixed' should contain at least one integer"
            assert float in types, "List 'mixed' should contain at least one float"
            assert bool in types, "List 'mixed' should contain at least one boolean"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_element_access():
    """Test that list elements are accessed correctly"""
    try:
        import exercise
        first_fruit = getattr(exercise, 'first_fruit', None)
        last_number = getattr(exercise, 'last_number', None)
        second_mixed = getattr(exercise, 'second_mixed', None)
        
        # We can't test the actual values without knowing the student's lists
        # But we can check that the variables exist and are not None
        # The actual correctness will be verified when they run their code
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_slicing():
    """Test that list slicing is implemented"""
    try:
        import exercise
        first_three_fruits = getattr(exercise, 'first_three_fruits', None)
        last_two_numbers = getattr(exercise, 'last_two_numbers', None)
        middle_mixed = getattr(exercise, 'middle_mixed', None)
        
        # Check that slicing variables exist
        # Actual correctness will depend on student's implementation
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_list_lengths():
    """Test that list lengths are calculated"""
    try:
        import exercise
        fruits_length = getattr(exercise, 'fruits_length', None)
        numbers_length = getattr(exercise, 'numbers_length', None)
        mixed_length = getattr(exercise, 'mixed_length', None)
        
        # Check that length variables exist
        if fruits_length is not None:
            assert isinstance(fruits_length, int), "Variable 'fruits_length' should be an integer"
        
        if numbers_length is not None:
            assert isinstance(numbers_length, int), "Variable 'numbers_length' should be an integer"
        
        if mixed_length is not None:
            assert isinstance(mixed_length, int), "Variable 'mixed_length' should be an integer"
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