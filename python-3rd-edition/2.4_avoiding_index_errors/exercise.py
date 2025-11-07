# Avoiding Index Errors Exercise
# Working with safe list access and error handling in Python

# TODO 1: Create a list named 'animals' with at least 3 animal names
# animals = 

# TODO 2: Try to access the element at index 10 (this will cause an IndexError)
# What happens when you run this code? Comment out after testing
# error_element = animals[10]

# TODO 3: Use len() to check the length of the 'animals' list
# animals_length = 

# TODO 4: Write a safe function to access list elements that checks bounds first
# def safe_get_element(lst, index):
#     # Check if index is within bounds
#     # Return the element if safe, otherwise return None

# TODO 5: Use the safe_get_element function to access elements safely
# safe_element = safe_get_element(animals, 10)

# TODO 6: Implement try-except to handle IndexError gracefully
# try:
#     # Try to access an element at an invalid index
#     element = animals[10]
# except IndexError:
#     # Handle the error gracefully
#     print("Error: Index out of range")

# TODO 7: Write a function that prints all elements in a list using a safe approach
# def print_list_safely(lst):
#     # Use a loop with range and len to print all elements
#     # Handle empty lists properly

# TODO 8: Test your functions with various indices (valid and invalid)
# Test with negative indices as well

# TODO 9: Create an empty list and try to access elements (this will also cause issues)
# empty_list = []
# What happens when you try to access elements in an empty list?

if __name__ == "__main__":
    # You can add any test code here to verify your implementation
    print("Testing avoiding index errors...")
    # Add your test code here