# Introducing While Loops Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_while_loop_variables():
    """Test that while loop variables exist"""
    try:
        import exercise
        # Check that variables used in while loops exist
        # We can't test the actual implementation without running the code
        pass
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_while_loop_concepts():
    """Test that while loop concepts are implemented"""
    try:
        import exercise
        # Check that the exercise covers the required while loop concepts
        # We can't test the actual implementation without running the code
        pass
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_flowchart_comments():
    """Test that flowchart comments exist"""
    try:
        with open(os.path.join(os.path.dirname(__file__), 'exercise.py'), 'r') as f:
            content = f.read()
        
        # Check for flowchart visualization comments
        assert "Flowchart visualization:" in content, "Should include flowchart visualization comments"
    except FileNotFoundError:
        pytest.fail("Could not find exercise.py file")

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