# Exercise 8.1d: Output Formatting

## Learning Objectives
- Master the use of stream manipulators for formatting
- Control field width and fill characters effectively
- Format numeric values with precision control
- Work with different number bases (decimal, hexadecimal, octal)
- Create formatted tables and professional-looking output

## Concepts Covered
- Stream manipulators: setw, setfill, setprecision, etc.
- Number formatting: fixed, scientific, and general notation
- Base conversion: decimal, hexadecimal, and octal representation
- Text alignment: left, right, and internal alignment
- Table formatting: creating aligned, professional-looking output

## Instructions
1. Open `src/output_formatting_exercises.cpp`
2. Follow the TODO comments to implement output formatting
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/output_formatting_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Testing basic stream manipulators:
Column 1     Column 2
-------------------------
Data 1          Value 1
Data 2          Value 2

Testing numeric formatting:
Default: 3.14159
Fixed (2 decimals): 3.14
Scientific: 3.14e+00
General: 3.14159

Testing number base formatting:
Decimal: 255
Hexadecimal: ff
Octal: 377

Testing formatted tables:
Name           Age       City           
----------------------------------------
John Doe       25        New York       
Jane Smith     30        Los Angeles    
Bob Johnson    35        Chicago        
```

## Key Points to Remember
- **Stream Manipulators**: Use setw, setfill, setprecision for formatting control
- **Number Formatting**: Choose appropriate notation (fixed, scientific) for your data
- **Base Conversion**: Use dec, hex, oct for different number representations
- **Text Alignment**: Use left, right, internal for text positioning
- **State Management**: Some manipulators are sticky, others are not

## Common Mistakes to Avoid
- Forgetting that setw only affects the next output operation
- Not resetting formatting flags when switching between different formats
- Using incorrect precision settings for floating-point numbers
- Not considering the impact of fill characters on output layout
- Mixing different alignment modes without proper reset

## Next Steps
After completing this exercise, proceed to:
- Exercise 9.1: Sequential Containers
- Exercise 10.1: Generic Algorithms