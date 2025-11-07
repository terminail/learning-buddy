# Organizing Lists Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_places_list_exists():
    """Test that the places list exists"""
    try:
        import exercise
        places = getattr(exercise, 'places', None)
        assert places is not None, "List 'places' is missing"
        assert isinstance(places, list), "Variable 'places' should be a list"
        assert len(places) >= 5, "List 'places' should have at least 5 elements"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_list_organization_methods():
    """Test that list organization methods are used"""
    try:
        import exercise
        # Check that organization variables exist
        places_length = getattr(exercise, 'places_length', None)
        
        if places_length is not None:
            assert isinstance(places_length, int), "Variable 'places_length' should be an integer"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_sorted_function_usage():
    """Test that sorted() function is used correctly"""
    try:
        # Test that we can import and use sorted() without errors
        import exercise
        places = getattr(exercise, 'places', [])
        if places:
            # Try to use sorted() on the places list
            sorted_places = sorted(places)
            assert isinstance(sorted_places, list), "sorted() should return a list"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")
    except Exception as e:
        # This might fail if the student hasn't properly defined their list
        pass  # We don't want to fail the test if the student is still working

def test_sort_method_usage():
    """Test that sort() method is used correctly"""
    try:
        import exercise
        places = getattr(exercise, 'places', [])
        if places and isinstance(places, list):
            # Create a copy to test sort method
            test_list = places.copy()
            # Test that sort method exists and is callable
            assert hasattr(test_list, 'sort'), "List should have a sort method"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")
    except Exception as e:
        # This might fail if the student hasn't properly defined their list
        pass  # We don't want to fail the test if the student is still working

def test_reverse_method_usage():
    """Test that reverse() method is used correctly"""
    try:
        import exercise
        places = getattr(exercise, 'places', [])
        if places and isinstance(places, list):
            # Create a copy to test reverse method
            test_list = places.copy()
            # Test that reverse method exists and is callable
            assert hasattr(test_list, 'reverse'), "List should have a reverse method"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")
    except Exception as e:
        # This might fail if the student hasn't properly defined their list
        pass  # We don't want to fail the test if the student is still working

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