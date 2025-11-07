# Introducing While Loops Solution
# Complete reference solution for working with while loops in Python

# Create a while loop that prints numbers from 1 to 5
# Initialize a counter variable
counter = 1

while counter <= 5:
    # Print the current value of counter
    print(f"Counter: {counter}")
    # Increment the counter
    counter += 1

# Flowchart visualization:
# Start -> counter = 1 -> Check: counter <= 5? -> True -> Print counter -> counter += 1 -> Check: counter <= 5? -> ...

print("\n--- First loop completed ---\n")

# Create a while loop that asks for user input until they enter 'quit'
# Initialize a variable to store user input
user_input = ""

while user_input != "quit":
    # Ask user for input: "Enter 'quit' to exit: "
    user_input = input("Enter 'quit' to exit: ")
    print(f"You entered: {user_input}")

# Flowchart visualization:
# Start -> user_input = "" -> Check: user_input != "quit"? -> True -> Get user input -> Check: user_input != "quit"? -> ...

print("\n--- Second loop completed ---\n")

# Create a while loop that sums numbers until the sum exceeds 20
# Initialize sum and number variables
total = 0
number = 1

while total <= 20:
    # Add number to total
    total += number
    print(f"Added {number}, total is now {total}")
    # Increment number
    number += 1

# Flowchart visualization:
# Start -> total = 0, number = 1 -> Check: total <= 20? -> True -> total += number -> number += 1 -> Check: total <= 20? -> ...

print("\n--- Third loop completed ---\n")

# Create a flag-controlled while loop
# Initialize a flag variable
active = True

while active:
    # Ask user for input: "Enter 'stop' to end: "
    user_input = input("Enter 'stop' to end: ")
    # If user enters 'stop', set active to False
    if user_input == "stop":
        active = False
        print("Loop ended by user command")
    else:
        print(f"You entered: {user_input}")

# Flowchart visualization:
# Start -> active = True -> Check: active? -> True -> Get user input -> Check input -> Set active = False -> Check: active? -> ...

print("\n--- Fourth loop completed ---\n")

# Create a while loop that demonstrates avoiding infinite loops
# Initialize a counter
count = 0

while count < 3:
    # Print current count
    print(f"Count: {count}")
    # Increment count
    count += 1
    # Add a safety check to prevent infinite loop (optional)
    if count > 10:  # Safety check
        print("Safety break activated to prevent infinite loop")
        break

# Flowchart visualization:
# Start -> count = 0 -> Check: count < 3? -> True -> Print count -> count += 1 -> Check: count < 3? -> ...

print("\n--- Fifth loop completed ---\n")

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Solution executed successfully!")