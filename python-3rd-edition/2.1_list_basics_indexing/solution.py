# List Basics and Indexing Solution
# Complete reference solution for working with lists and indexing in Python

# Create a list named 'fruits' with at least 5 different fruit names as strings
fruits = ["apple", "banana", "orange", "grape", "mango"]

# Create a list named 'numbers' with at least 5 different integers
numbers = [10, 25, 30, 45, 50]

# Create a list named 'mixed' with different data types (string, int, float, bool)
mixed = ["hello", 42, 3.14, True, "world"]

# Access and print the first element of the 'fruits' list
first_fruit = fruits[0]
print(f"First fruit: {first_fruit}")

# Access and print the last element of the 'numbers' list using negative indexing
last_number = numbers[-1]
print(f"Last number: {last_number}")

# Access and print the second element of the 'mixed' list
second_mixed = mixed[1]
print(f"Second mixed element: {second_mixed}")

# Use slicing to get the first three elements of the 'fruits' list
first_three_fruits = fruits[0:3]  # or fruits[:3]
print(f"First three fruits: {first_three_fruits}")

# Use slicing to get the last two elements of the 'numbers' list
last_two_numbers = numbers[-2:]  # Get from second to last to end
print(f"Last two numbers: {last_two_numbers}")

# Use slicing to get elements from index 1 to 3 (not including 3) from the 'mixed' list
middle_mixed = mixed[1:3]
print(f"Middle mixed elements: {middle_mixed}")

# Find and print the length of each list using the len() function
fruits_length = len(fruits)
numbers_length = len(numbers)
mixed_length = len(mixed)
print(f"Fruits list length: {fruits_length}")
print(f"Numbers list length: {numbers_length}")
print(f"Mixed list length: {mixed_length}")

# Try to access an element that doesn't exist (e.g., index 10 in fruits list)
# This would cause an IndexError: list index out of range
# Uncomment the line below to see the error:
# non_existent = fruits[10]

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Solution executed successfully!")