# Exercise: Operator Precedence and Associativity

This exercise focuses on operator precedence and associativity in C++, including how operators are evaluated in complex expressions and how to use parentheses to control evaluation order.

## Learning Objectives

- Understand operator precedence for arithmetic, relational, and logical operators
- Learn about operator associativity (left-to-right vs right-to-left)
- Practice using parentheses to override natural precedence
- Work with complex expressions combining multiple operator types

## Files

- [src/operator_precedence_exercises.cpp](src/operator_precedence_exercises.cpp) - Exercise template with TODO comments
- [src/operator_precedence_solutions.cpp](src/operator_precedence_solutions.cpp) - Complete solution implementation
- [test/test_operator_precedence_basics.cpp](test/test_operator_precedence_basics.cpp) - Basic unit tests
- [test/test_operator_precedence_practice.cpp](test/test_operator_precedence_practice.cpp) - Additional practice tests

## Building and Running

1. Build the exercise:
   ```bash
   ./build.sh
   ```

2. Run the tests:
   ```bash
   ./run_tests.sh
   ```

## Key Concepts Covered

### Operator Precedence
- Arithmetic operators: *, /, % have higher precedence than +, -
- Relational operators: <, >, <=, >= have higher precedence than ==, !=
- Logical operators: ! has highest precedence, then &&, then ||
- Mixed operators: Arithmetic > Relational > Logical

### Operator Associativity
- Left-to-right associativity for most operators (+, -, *, /, %, <, >, etc.)
- Right-to-left associativity for assignment operators (=, +=, -=, etc.)
- How associativity affects expressions with operators of the same precedence

### Parentheses Usage
- Overriding natural precedence with parentheses
- Making precedence explicit for better code readability
- Grouping subexpressions for clarity

## Practice Exercises

1. Evaluate complex expressions with multiple operator types
2. Use parentheses to control evaluation order in expressions
3. Work with expressions that demonstrate left-to-right associativity
4. Create expressions that show the difference between natural precedence and explicit grouping