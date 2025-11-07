# Strings and String Methods Solution
# Complete reference solution for the exercise

# Create a variable named 'name' with leading and trailing whitespace
name = "  Alice  "

# Use .strip() to remove whitespace from both sides
stripped_name = name.strip()

# Use .lstrip() to remove whitespace from the left side
left_stripped_name = name.lstrip()

# Use .rstrip() to remove whitespace from the right side
right_stripped_name = name.rstrip()

# Create a URL variable and use .removeprefix() to remove "https://"
url = "https://example.com"
domain = url.removeprefix("https://")

# Create a filename variable and use .removesuffix() to remove ".txt"
filename = "document.txt"
name_only = filename.removesuffix(".txt")

# Create a sentence and use .find() to locate a word
sentence = "Python is a powerful programming language"
position = sentence.find("powerful")

# Use .count() to count occurrences of a letter
letter_count = sentence.count("a")

# Use .replace() to replace words in a sentence
new_sentence = sentence.replace("powerful", "versatile")

# Print all your results to see the transformations
print(f"Original name: '{name}'")
print(f"Stripped name: '{stripped_name}'")
print(f"Left stripped name: '{left_stripped_name}'")
print(f"Right stripped name: '{right_stripped_name}'")
print(f"URL: {url}")
print(f"Domain: {domain}")
print(f"Filename: {filename}")
print(f"Name only: {name_only}")
print(f"Sentence: {sentence}")
print(f"Position of 'powerful': {position}")
print(f"Count of 'a': {letter_count}")
print(f"New sentence: {new_sentence}")

if __name__ == "__main__":
    # Test code to verify the implementation
    print("Solution executed successfully!")