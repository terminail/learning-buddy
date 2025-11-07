# Organizing Lists Solution
# Complete reference solution for working with list organization methods in Python

# Create a list named 'places' with at least 5 places you'd like to visit
places = ["Paris", "Tokyo", "New York", "Sydney", "Rio de Janeiro"]
print(f"Original places list: {places}")

# Print the list in its original order
print("Original order:", places)

# Use sorted() to print the list in alphabetical order without modifying the original list
print("Alphabetical order:", sorted(places))

# Show that the original list is still in its original order
print("Original order confirmed:", places)

# Use sorted() to print the list in reverse alphabetical order without modifying the original list
print("Reverse alphabetical order:", sorted(places, reverse=True))

# Show that the original list is still in its original order
print("Original order confirmed again:", places)

# Use reverse() to change the order of the list
places.reverse()
print("Reversed order:", places)

# Use reverse() again to change the order back to the original
places.reverse()
print("Back to original order:", places)

# Use sort() to change the list to alphabetical order
places.sort()
print("Sorted alphabetically:", places)

# Use sort() to change the list to reverse alphabetical order
places.sort(reverse=True)
print("Sorted reverse alphabetically:", places)

# Find and print the length of the 'places' list
places_length = len(places)
print(f"Number of places in the list: {places_length}")

# Try to access an element at an index that doesn't exist
# This would cause an IndexError: list index out of range
# Uncomment the line below to see the error:
# non_existent = places[10]

# Try to access an element at a negative index that doesn't exist
# This would also cause an IndexError: list index out of range
# Uncomment the line below to see the error:
# negative_non_existent = places[-10]

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Solution executed successfully!")