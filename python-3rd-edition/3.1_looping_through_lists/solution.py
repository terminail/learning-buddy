# Looping Through Lists Solution
# Complete reference solution for list iteration methods in Python

# Create a list named 'fruits' with at least 4 fruit names
fruits = ["apple", "banana", "orange", "grape"]
print(f"Fruits list: {fruits}")

# Use a for loop to print each fruit in the list
print("\nPrinting each fruit:")
for fruit in fruits:
    print(fruit)

# Flowchart visualization:
# Start -> Get first element -> Process element -> Check: More elements? -> True -> Get next element -> Process element -> ...
#                                |
#                                | False
#                                ▼
#                              End

# Create a list named 'numbers' with integers from 1 to 5
numbers = [1, 2, 3, 4, 5]
print(f"\nNumbers list: {numbers}")

# Use a for loop with range() and len() to print each number with its index
print("\nPrinting numbers with index (using range and len):")
for i in range(len(numbers)):
    print(f"Index {i}: {numbers[i]}")

# Flowchart visualization:
# Start -> i = 0 -> Check: i < len(numbers)? -> True -> Process numbers[i] -> i += 1 -> Check: i < len(numbers)? -> ...
#                                   |
#                                   | False
#                                   ▼
#                                 End

# Use enumerate() to print each number with its index
print("\nPrinting numbers with index (using enumerate):")
for index, value in enumerate(numbers):
    print(f"Index {index}: {value}")

# Flowchart visualization:
# Start -> Get first (index, value) pair -> Process pair -> Check: More elements? -> True -> Get next (index, value) pair -> ...
#                                                |
#                                                | False
#                                                ▼
#                                              End

# Create a list of squares using list comprehension
squares = [x**2 for x in numbers]
print(f"\nSquares of numbers: {squares}")

# Use list comprehension to create a list of uppercase fruits
uppercase_fruits = [fruit.upper() for fruit in fruits]
print(f"Uppercase fruits: {uppercase_fruits}")

# Use a for loop to print a message for each fruit
print("\nMessages for each fruit:")
for fruit in fruits:
    print(f"I like {fruit}s")

# Use a for loop to calculate the sum of the numbers list
total = 0
for number in numbers:
    total += number
sum_result = total
print(f"\nSum of numbers: {sum_result}")

# Use list comprehension to filter fruits that start with a vowel
vowels = "aeiou"
vowel_fruits = [fruit for fruit in fruits if fruit[0].lower() in vowels]
print(f"Fruits that start with a vowel: {vowel_fruits}")

if __name__ == "__main__":
    # Test code to verify the implementation
    print("\nSolution executed successfully!")