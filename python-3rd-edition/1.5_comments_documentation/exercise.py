# Comments and Documentation Exercise
# Learning how to write effective comments and documentation in Python

# TODO 1: Write a single-line comment above this line to explain what this variable represents
name = "Alice"

# TODO 2: Write a single-line comment at the end of this line to explain the calculation
age_in_months = 25 * 12  # 

# TODO 3: Write a multi-line comment to explain the purpose of the following code block
# 
# 
# 
favorite_colors = ["blue", "green", "purple"]
for color in favorite_colors:
    print(f"I like {color}")

# TODO 4: Write a function called 'calculate_area' that takes length and width parameters
# Add a docstring that describes what the function does, its parameters, and what it returns
def calculate_area(length, width):
    # TODO 5: Add inline comments to explain the calculation
    area = length * width  # 
    return area

# TODO 6: Write a docstring for this module at the top of the file (above the first comment)

# TODO 7: Call the calculate_area function with sample values and print the result
# Add an inline comment to explain what the values represent
result = calculate_area(5, 3)  # 

# TODO 8: Write a multi-line comment that explains how to run this script and what it does
# 
# 
# 

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Testing comments and documentation...")
    print(f"Area calculation result: {result}")