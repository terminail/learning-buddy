# Comments and Documentation Solution
# Complete reference solution for writing effective comments and documentation in Python
"""
This module demonstrates how to write effective comments and documentation in Python.
It includes examples of single-line comments, multi-line comments, and docstrings.
"""

# This variable stores a person's name
name = "Alice"

# Calculate a person's age in months by multiplying by 12
age_in_months = 25 * 12  # Age in years multiplied by months per year

# This code block prints a person's favorite colors
# It demonstrates how to iterate through a list and format strings
# The list contains string values representing color names
favorite_colors = ["blue", "green", "purple"]
for color in favorite_colors:
    print(f"I like {color}")

def calculate_area(length, width):
    """
    Calculate the area of a rectangle.
    
    Args:
        length (float): The length of the rectangle
        width (float): The width of the rectangle
    
    Returns:
        float: The area of the rectangle (length * width)
    """
    # Calculate area by multiplying length by width
    area = length * width  # Area formula: length × width
    return area

# Call the calculate_area function with sample values and print the result
# 5 represents the length and 3 represents the width of a rectangle
result = calculate_area(5, 3)  # Calculate area of 5x3 rectangle

# This script demonstrates how to write effective comments and documentation in Python
# To run this script, save it as a .py file and execute it with Python
# The script will print a person's favorite colors and calculate the area of a rectangle
# This is useful for learning how to document Python code properly

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Testing comments and documentation...")
    print(f"Area calculation result: {result}")