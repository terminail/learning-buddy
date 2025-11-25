# Exercise: Logical Operators

This exercise focuses on logical operators in C++, including AND, OR, and NOT operators, short-circuit evaluation, and operator precedence.

## Learning Objectives

- Understand and use logical AND (&&), OR (||), and NOT (!) operators
- Learn about short-circuit evaluation behavior
- Work with operator precedence and parentheses
- Practice with De Morgan's laws
- Create complex logical expressions

## Files

- [src/logical_operators_exercises.cpp](src/logical_operators_exercises.cpp) - Exercise template with TODO comments
- [src/logical_operators_solutions.cpp](src/logical_operators_solutions.cpp) - Complete solution implementation
- [test/test_logical_operators_basics.cpp](test/test_logical_operators_basics.cpp) - Basic unit tests
- [test/test_logical_operators_practice.cpp](test/test_logical_operators_practice.cpp) - Additional practice tests

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

### Logical Operators
- Logical AND (&&) - Returns true only if both operands are true
- Logical OR (||) - Returns true if at least one operand is true
- Logical NOT (!) - Negates the boolean value of its operand

### Short-Circuit Evaluation
- With &&: If the first operand is false, the second is not evaluated
- With ||: If the first operand is true, the second is not evaluated
- Performance and safety benefits of short-circuit evaluation

### Operator Precedence
- NOT (!) has the highest precedence
- AND (&&) has higher precedence than OR (||)
- Use parentheses to make precedence explicit and improve readability

### De Morgan's Laws
- !(p && q) is equivalent to !p || !q
- !(p || q) is equivalent to !p && !q
- Useful for simplifying complex logical expressions

## Practice Exercises

1. Implement logical expressions with short-circuit evaluation
2. Work with complex logical expressions using parentheses
3. Apply De Morgan's laws to simplify expressions
4. Create conditional statements with multiple logical conditions