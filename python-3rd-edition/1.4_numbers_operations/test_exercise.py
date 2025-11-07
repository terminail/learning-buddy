# Numbers and Numeric Operations Tests with Pytest
# Test cases to verify the exercise solution

import pytest
import sys
import os
import subprocess

def test_math_import():
    """Test that math module is imported"""
    try:
        import exercise
        math_module = getattr(exercise, 'math', None)
        assert math_module is not None, "math module should be imported"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_basic_math_operations():
    """Test that basic math operations work correctly"""
    try:
        import exercise
        sqrt_result = getattr(exercise, 'sqrt_result', None)
        power_result = getattr(exercise, 'power_result', None)
        factorial_result = getattr(exercise, 'factorial_result', None)
        
        assert sqrt_result is not None, "Variable 'sqrt_result' is missing"
        assert power_result is not None, "Variable 'power_result' is missing"
        assert factorial_result is not None, "Variable 'factorial_result' is missing"
        
        # Test that calculations are correct
        assert sqrt_result == 4.0, "Square root of 16 should be 4.0"
        assert power_result == 8.0, "2 to the power of 3 should be 8.0"
        assert factorial_result == 120, "Factorial of 5 should be 120"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_number_bases():
    """Test that number bases work correctly"""
    try:
        import exercise
        binary_number = getattr(exercise, 'binary_number', None)
        octal_number = getattr(exercise, 'octal_number', None)
        hex_number = getattr(exercise, 'hex_number', None)
        
        assert binary_number is not None, "Variable 'binary_number' is missing"
        assert octal_number is not None, "Variable 'octal_number' is missing"
        assert hex_number is not None, "Variable 'hex_number' is missing"
        
        # Test that all number bases equal 10
        assert binary_number == 10, "Binary 0b1010 should equal 10"
        assert octal_number == 10, "Octal 0o12 should equal 10"
        assert hex_number == 10, "Hex 0xA should equal 10"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_base_conversions():
    """Test that base conversions work correctly"""
    try:
        import exercise
        binary_string = getattr(exercise, 'binary_string', None)
        octal_string = getattr(exercise, 'octal_string', None)
        hex_string = getattr(exercise, 'hex_string', None)
        
        assert binary_string is not None, "Variable 'binary_string' is missing"
        assert octal_string is not None, "Variable 'octal_string' is missing"
        assert hex_string is not None, "Variable 'hex_string' is missing"
        
        # Test that conversions are correct
        assert binary_string == '0b11111111', "Binary representation of 255 should be '0b11111111'"
        assert octal_string == '0o377', "Octal representation of 255 should be '0o377'"
        assert hex_string == '0xff', "Hex representation of 255 should be '0xff'"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_trigonometry():
    """Test that trigonometry functions work correctly"""
    try:
        import exercise
        sine_value = getattr(exercise, 'sine_value', None)
        cosine_value = getattr(exercise, 'cosine_value', None)
        
        assert sine_value is not None, "Variable 'sine_value' is missing"
        assert cosine_value is not None, "Variable 'cosine_value' is missing"
        
        # Test that trigonometry values are approximately correct
        assert abs(sine_value - 0.707) < 0.01, "Sine of 45 degrees should be approximately 0.707"
        assert abs(cosine_value - 0.707) < 0.01, "Cosine of 45 degrees should be approximately 0.707"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_logarithms():
    """Test that logarithm functions work correctly"""
    try:
        import exercise
        log_value = getattr(exercise, 'log_value', None)
        log10_value = getattr(exercise, 'log10_value', None)
        
        assert log_value is not None, "Variable 'log_value' is missing"
        assert log10_value is not None, "Variable 'log10_value' is missing"
        
        # Test that logarithm values are correct
        assert abs(log_value - 2.303) < 0.01, "Natural log of 10 should be approximately 2.303"
        assert log10_value == 2.0, "Log base 10 of 100 should be 2.0"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_number_formatting():
    """Test that number formatting works correctly"""
    try:
        import exercise
        formatted_number = getattr(exercise, 'formatted_number', None)
        
        assert formatted_number is not None, "Variable 'formatted_number' is missing"
        assert isinstance(formatted_number, str), "Variable 'formatted_number' should be a string"
        assert formatted_number == "1,234,567.89", "Formatted number should be '1,234,567.89'"
    except ImportError as e:
        pytest.fail(f"Could not import exercise.py: {e}")

def test_constants():
    """Test that math constants work correctly"""
    try:
        import exercise
        pi_value = getattr(exercise, 'pi_value', None)
        e_value = getattr(exercise, 'e_value', None)
        
        assert pi_value is not None, "Variable 'pi_value' is missing"
        assert e_value is not None, "Variable 'e_value' is missing"
        
        # Test that constants are approximately correct
        assert abs(pi_value - 3.14159) < 0.001, "Pi should be approximately 3.14159"
        assert abs(e_value - 2.71828) < 0.001, "E should be approximately 2.71828"
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