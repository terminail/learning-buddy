# Modifying Lists Solution
# Complete reference solution for working with list modification methods in Python

# Create a list named 'colors' with at least 4 color names as strings
colors = ["red", "blue", "green", "yellow"]
print(f"Original colors: {colors}")

# Modify the first element of the 'colors' list to a different color
colors[0] = "purple"
print(f"After modifying first element: {colors}")

# Add a new color to the end of the 'colors' list using append()
colors.append("orange")
print(f"After appending 'orange': {colors}")

# Insert a new color at index 2 of the 'colors' list using insert()
colors.insert(2, "pink")
print(f"After inserting 'pink' at index 2: {colors}")

# Create another list named 'more_colors' with 2 additional colors
more_colors = ["black", "white"]
print(f"More colors to add: {more_colors}")

# Add all elements from 'more_colors' to 'colors' using extend()
colors.extend(more_colors)
print(f"After extending with more colors: {colors}")

# Remove a specific color from the 'colors' list using remove()
colors.remove("blue")
print(f"After removing 'blue': {colors}")

# Remove and return the last element from the 'colors' list using pop()
last_color = colors.pop()
print(f"Popped last color: {last_color}")
print(f"After popping last color: {colors}")

# Remove the first element from the 'colors' list using del
del colors[0]
print(f"After deleting first element: {colors}")

# Sort the 'colors' list alphabetically using sort()
colors.sort()
print(f"After sorting: {colors}")

# Create a sorted copy of the 'colors' list without modifying the original using sorted()
sorted_colors = sorted(colors)
print(f"Sorted copy: {sorted_colors}")
print(f"Original colors (unchanged): {colors}")

# Reverse the order of the 'colors' list using reverse()
colors.reverse()
print(f"After reversing: {colors}")

# Create a copy of the 'colors' list using the copy() method
colors_copy = colors.copy()
print(f"Copy of colors: {colors_copy}")

# Try to create a copy by assignment (this creates a reference, not a copy)
colors_reference = colors
print(f"Reference to colors: {colors_reference}")

# Modify colors_reference and observe what happens to colors
colors_reference.append("brown")
print(f"After appending 'brown' to reference:")
print(f"Colors reference: {colors_reference}")
print(f"Original colors (also changed!): {colors}")

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Solution executed successfully!")