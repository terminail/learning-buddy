# Indentation and Code Styling Solution
# Complete reference solution for practicing proper Python indentation and code styling

# Create a list of numbers from 1 to 5
numbers = [1, 2, 3, 4, 5]
print(f"Numbers list: {numbers}")

# Use a for loop to print each number (properly indented)
print("\nPrinting each number:")
for number in numbers:
    print(number)

# Create a nested loop with proper indentation
print("\nNested loop example:")
for i in range(3):
    print(f"Outer loop: {i}")
    for j in range(2):
        print(f"  Inner loop: {j}")

# Create a function with proper indentation
def calculate_square(n):
    # Calculate and return the square of n
    # Make sure the return statement is properly indented
    return n ** 2

# Test the function
print(f"\nSquare of 5: {calculate_square(5)}")

# Use an if statement inside a loop with proper indentation
print("\nEven and odd numbers:")
for number in numbers:
    if number % 2 == 0:
        # Print even numbers
        print(f"{number} is even")
    else:
        # Print odd numbers
        print(f"{number} is odd")

# Fix the indentation error in this code:
print("\nFixed indentation error example:")
for i in range(3):
    print(f"Number: {i}")  # This line is now properly indented

# Fix the indentation error in this nested loop:
print("\nFixed nested loop indentation:")
for x in range(2):
    for y in range(2):
        print(f"Coordinates: ({x}, {y})")  # This line now has correct indentation

# Create a try-except block with proper indentation
print("\nTry-except block example:")
try:
    # Attempt to convert a string to integer
    result = int("abc")
except ValueError:
    # Handle the ValueError with proper indentation
    print("Error: Could not convert 'abc' to integer")

if __name__ == "__main__":
    # Test code to verify the implementation
    print("\nSolution executed successfully!")