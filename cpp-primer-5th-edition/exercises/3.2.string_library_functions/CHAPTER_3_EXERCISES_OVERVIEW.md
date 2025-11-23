# String Library Functions Exercises Overview

This document provides an overview of all string library functions exercises created for learning C++ Primer 5th Edition concepts.

## Exercise Progression

### 3.2.1: String Basics
**Directory**: [string_basics](string_basics/)
**Focus**: String creation, initialization, and basic operations
- String initialization methods (empty, literal, copy, fill)
- String capacity and size functions (size, length, empty, max_size)
- Character access (operator[], at, front, back)
- Basic string operations (assignment, equality, comparison)

### 3.2.2: String Searching
**Directory**: [string_searching](string_searching/)
**Focus**: String searching functions
- Substring searching (find, rfind)
- Character set searching (find_first_of, find_last_of)
- Inverse searching (find_first_not_of, find_last_not_of)
- Handling search results and npos values

### 3.2.3: String Modification
**Directory**: [string_modification](string_modification/)
**Focus**: String modification functions
- String replacement (replace)
- String erasure (erase)
- String insertion (insert)
- String appending (append, operator+=)

### 3.2.4: String Conversion
**Directory**: [string_conversion](string_conversion/)
**Focus**: String conversion functions
- Converting numbers to strings (to_string)
- Converting strings to integers (stoi, stol, stoll)
- Converting strings to floating-point (stof, stod, stold)
- Complex parsing with stringstream

## Learning Path

Students should complete these exercises in order:
1. **String Basics** - Start with fundamental string creation and operations
2. **String Searching** - Learn to find content within strings
3. **String Modification** - Modify string content
4. **String Conversion** - Convert between strings and numeric types

## Key Concepts Covered

### String Creation and Initialization
- **Default initialization**: Creating empty strings
- **Copy initialization**: Initializing from other strings
- **Fill initialization**: Creating strings with repeated characters
- **Substring initialization**: Creating strings from parts of other strings

### String Searching
- **find()**: Locate first occurrence of substring
- **rfind()**: Locate last occurrence of substring
- **find_first_of()**: Find first occurrence of any character in a set
- **find_last_of()**: Find last occurrence of any character in a set
- **npos**: Special value indicating "not found"

### String Modification
- **replace()**: Substitute parts of strings
- **erase()**: Remove parts of strings
- **insert()**: Add content to strings
- **append()**: Concatenate strings
- **operator+=**: String concatenation operator

### String Conversion
- **to_string()**: Convert numbers to strings
- **stoi(), stol(), stoll()**: Convert strings to integers
- **stof(), stod(), stold()**: Convert strings to floating-point numbers
- **stringstream**: Complex parsing and formatting

## Next Topics

After completing string library functions exercises, students should progress to:
- Exercise 3.3: Array and String Algorithms
- Exercise 4.1: Expressions and Statements