# Numbers and Numeric Operations Solution
# Complete reference solution for the exercise

# Calculate the square root of a number
import math
sqrt_result = math.sqrt(16)

# Calculate a number raised to a power using math.pow()
power_result = math.pow(2, 3)

# Calculate the factorial of a number
factorial_result = math.factorial(5)

# Work with different number bases
binary_number = 0b1010  # Binary for 10
octal_number = 0o12     # Octal for 10
hex_number = 0xA        # Hexadecimal for 10

# Convert numbers between bases
decimal_number = 255
binary_string = bin(decimal_number)
octal_string = oct(decimal_number)
hex_string = hex(decimal_number)

# Use math functions for trigonometry
angle_in_radians = math.pi / 4  # 45 degrees
sine_value = math.sin(angle_in_radians)
cosine_value = math.cos(angle_in_radians)

# Use math functions for logarithms
log_value = math.log(10)
log10_value = math.log10(100)

# Format numbers for display
large_number = 1234567.89123
formatted_number = f"{large_number:,.2f}"

# Work with constants from the math module
pi_value = math.pi
e_value = math.e

# Print all your results to see the calculations
print(f"Square root of 16: {sqrt_result}")
print(f"2 to the power of 3: {power_result}")
print(f"Factorial of 5: {factorial_result}")
print(f"Binary number (0b1010): {binary_number}")
print(f"Octal number (0o12): {octal_number}")
print(f"Hex number (0xA): {hex_number}")
print(f"Decimal {decimal_number} in binary: {binary_string}")
print(f"Decimal {decimal_number} in octal: {octal_string}")
print(f"Decimal {decimal_number} in hex: {hex_string}")
print(f"Sine of 45 degrees: {sine_value}")
print(f"Cosine of 45 degrees: {cosine_value}")
print(f"Natural log of 10: {log_value}")
print(f"Log base 10 of 100: {log10_value}")
print(f"Formatted large number: {formatted_number}")
print(f"Pi constant: {pi_value}")
print(f"E constant: {e_value}")

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Solution executed successfully!")