# Avoiding Index Errors Solution
# Complete reference solution for safe list access and error handling in Python

# Create a list named 'animals' with at least 3 animal names
animals = ["cat", "dog", "elephant"]
print(f"Animals list: {animals}")

# Try to access the element at index 10 (this will cause an IndexError)
# Uncomment the line below to see the error:
# error_element = animals[10]

# Use len() to check the length of the 'animals' list
animals_length = len(animals)
print(f"Length of animals list: {animals_length}")

# Write a safe function to access list elements that checks bounds first
def safe_get_element(lst, index):
    """Safely get an element from a list by index, returning None if index is out of bounds"""
    # Check if index is within bounds
    if 0 <= index < len(lst):
        return lst[index]
    elif -len(lst) <= index < 0:
        # Handle negative indices
        return lst[index]
    else:
        return None

# Use the safe_get_element function to access elements safely
safe_element = safe_get_element(animals, 10)
print(f"Safe access of index 10: {safe_element}")

# Implement try-except to handle IndexError gracefully
try:
    # Try to access an element at an invalid index
    element = animals[10]
    print(f"Element at index 10: {element}")
except IndexError:
    # Handle the error gracefully
    print("Error: Index out of range")

# Write a function that prints all elements in a list using a safe approach
def print_list_safely(lst):
    """Print all elements in a list using a safe approach"""
    # Handle empty lists
    if not lst:
        print("List is empty")
        return
    
    # Use a loop with range and len to print all elements
    print("List elements:")
    for i in range(len(lst)):
        print(f"  Index {i}: {lst[i]}")

# Test the print_list_safely function
print_list_safely(animals)
print_list_safely([])  # Test with empty list

# Test your functions with various indices (valid and invalid)
print("\nTesting various indices:")
print(f"Index 0: {safe_get_element(animals, 0)}")
print(f"Index 1: {safe_get_element(animals, 1)}")
print(f"Index 2: {safe_get_element(animals, 2)}")
print(f"Index 3: {safe_get_element(animals, 3)}")  # Out of bounds
print(f"Index -1: {safe_get_element(animals, -1)}")  # Last element
print(f"Index -2: {safe_get_element(animals, -2)}")  # Second to last
print(f"Index -4: {safe_get_element(animals, -4)}")  # Out of bounds

# Create an empty list and try to access elements (this will also cause issues)
empty_list = []
print(f"\nEmpty list: {empty_list}")
print(f"Length of empty list: {len(empty_list)}")
empty_element = safe_get_element(empty_list, 0)
print(f"Safe access of index 0 in empty list: {empty_element}")

try:
    # Try to access an element in an empty list
    element = empty_list[0]
    print(f"Element at index 0: {element}")
except IndexError:
    # Handle the error gracefully
    print("Error: Cannot access elements in an empty list")

if __name__ == "__main__":
    # Test code to verify the implementation
    print("\nSolution executed successfully!")