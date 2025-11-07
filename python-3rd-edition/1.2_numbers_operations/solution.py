# Numbers and Operations Solution
# Complete reference solution for the exercise

# Perform basic mathematical operations
addition = 5 + 3
subtraction = 10 - 4
multiplication = 6 * 7
division = 20 / 4

print(f"5 + 3 = {addition}")
print(f"10 - 4 = {subtraction}")
print(f"6 * 7 = {multiplication}")
print(f"20 / 4 = {division}")

# Work with exponents
power = 2 ** 3
print(f"2 to the power of 3 = {power}")

# Understand integers vs floats
integer_result = 4 / 2  # This will be a float
float_result = 0.2 + 0.1  # This might surprise you!
print(f"4 / 2 = {integer_result} (type: {type(integer_result)})")
print(f"0.2 + 0.1 = {float_result} (type: {type(float_result)})")

# Use underscores in large numbers
universe_age = 14_000_000_000
print(f"Universe age: {universe_age}")

# Apply built-in functions
absolute_value = abs(-10)
rounded_value = round(3.14159, 2)
print(f"Absolute value of -10: {absolute_value}")
print(f"3.14159 rounded to 2 decimal places: {rounded_value}")

# Multiple assignments
x, y, z = 1, 2, 3
print(f"Multiple assignments: x={x}, y={y}, z={z}")

# Constants (by convention)
MAX_CONNECTIONS = 5000
print(f"Maximum connections (constant): {MAX_CONNECTIONS}")

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Solution executed successfully!")