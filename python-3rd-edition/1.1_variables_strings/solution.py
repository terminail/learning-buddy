# Variables and Simple Data Types Solution
# Complete reference solution for the exercise

# Create a variable named 'name' and assign your name to it as a string
name = "Alice"

# Create a variable named 'age' and assign your age to it as an integer
age = 25

# Create a variable named 'height' and assign your height to it as a float
height = 5.5

# Print a message using the variables above
print(f"My name is {name}, I am {age} years old, and I am {height} feet tall.")

# Create a variable named 'message' and assign a string with your favorite quote
message = "To be or not to be, that is the question."

# Print the quote in title case, upper case, and lower case
print("Title case:", message.title())
print("Upper case:", message.upper())
print("Lower case:", message.lower())

# Use an f-string to print a formatted message with your variables
f_string_message = f"My name is {name} and I am {age} years old."
print("F-string message:", f_string_message)

# Try string concatenation with your name and age
concatenated_message = "My name is " + name + " and I am " + str(age) + " years old."
print("Concatenated message:", concatenated_message)

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Solution executed successfully!")