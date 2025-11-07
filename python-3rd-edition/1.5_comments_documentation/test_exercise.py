# Comments and Documentation Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess
import ast

def test_comments_exist():
    """Test that required comments exist in the exercise file"""
    try:
        with open(os.path.join(os.path.dirname(__file__), 'exercise.py'), 'r') as f:
            content = f.read()
        
        # Check for single-line comments
        assert '#' in content, "Should have at least one single-line comment"
        
        # Check for multi-line comment pattern (multiple # in succession)
        lines = content.split('\n')
        multiline_comment_count = 0
        for line in lines:
            if line.strip().startswith('#'):
                multiline_comment_count += 1
        
        assert multiline_comment_count >= 3, "Should have at least 3 comment lines"
        
    except FileNotFoundError:
        pytest.fail("Could not find exercise.py file")

def test_function_exists():
    """Test that the calculate_area function exists"""
    try:
        import exercise
        assert hasattr(exercise, 'calculate_area'), "Function 'calculate_area' is missing"
        assert callable(exercise.calculate_area), "calculate_area should be a function"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_function_docstring():
    """Test that the calculate_area function has a docstring"""
    try:
        import exercise
        func = getattr(exercise, 'calculate_area', None)
        if func is not None:
            assert func.__doc__ is not None, "Function 'calculate_area' should have a docstring"
            assert len(func.__doc__.strip()) > 0, "Function docstring should not be empty"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_module_docstring():
    """Test that the module has a docstring"""
    try:
        with open(os.path.join(os.path.dirname(__file__), 'exercise.py'), 'r') as f:
            tree = ast.parse(f.read())
        
        # Check if the module has a docstring
        docstring = ast.get_docstring(tree)
        assert docstring is not None, "Module should have a docstring"
        assert len(docstring.strip()) > 0, "Module docstring should not be empty"
    except FileNotFoundError:
        pytest.fail("Could not find exercise.py file")
    except SyntaxError as e:
        pytest.fail(f"Syntax error in exercise.py: {e}")

def test_function_parameters():
    """Test that the calculate_area function has correct parameters"""
    try:
        import exercise
        func = getattr(exercise, 'calculate_area', None)
        if func is not None:
            import inspect
            sig = inspect.signature(func)
            params = list(sig.parameters.keys())
            assert 'length' in params, "Function should have a 'length' parameter"
            assert 'width' in params, "Function should have a 'width' parameter"
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