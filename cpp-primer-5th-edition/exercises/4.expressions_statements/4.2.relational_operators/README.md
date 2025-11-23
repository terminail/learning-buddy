# Exercise: Relational Operators

This exercise focuses on relational operators in C++, including equality operators, comparison operators, and their behavior with different data types.

## Learning Objectives

- Understand and use equality operators (==, !=)
- Work with relational operators (<, >, <=, >=)
- Learn about lexicographical ordering for strings
- Practice with mixed-type comparisons
- Understand floating-point comparison challenges

## Files

- [src/relational_operators_exercises.cpp](src/relational_operators_exercises.cpp) - Exercise template with TODO comments
- [src/relational_operators_solutions.cpp](src/relational_operators_solutions.cpp) - Complete solution implementation
- [test/test_relational_operators_basics.cpp](test/test_relational_operators_basics.cpp) - Basic unit tests
- [test/test_relational_operators_practice.cpp](test/test_relational_operators_practice.cpp) - Additional practice tests

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

### Equality Operators
- Equal to (==) and Not equal to (!=)
- Difference between assignment (=) and equality (==)
- Boolean results of equality comparisons

### Relational Operators
- Less than (<), Greater than (>)
- Less than or equal to (<=), Greater than or equal to (>=)
- Return boolean values (true or false)

### Data Type Considerations
- Character comparisons using ASCII values
- String comparisons using lexicographical ordering
- Mixed-type comparisons with implicit conversions
- Floating-point comparison challenges and epsilon-based comparisons

## Practice Exercises

1. Implement comparisons between different data types
2. Work with string lexicographical ordering
3. Handle floating-point equality with epsilon comparisons
4. Create complex relational expressions with logical operators