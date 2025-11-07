# Exercise 4.1a: Conditional Expressions

## Learning Objectives
- Understand how to use conditional expressions and statements in C++
- Learn about ternary operators, if-else statements, and switch statements
- Practice evaluating complex expressions with operator precedence
- Implement programs that make decisions using conditional logic

## Concepts Covered
- Conditional (ternary) operators (?:)
- If-else statements with multiple conditions
- Switch statements with fall-through cases
- Operator precedence and associativity
- Short-circuit evaluation with logical operators

## Instructions
1. Open `src/conditional_expressions_exercises.cpp`
2. Follow the TODO comments to implement the conditional expressions
3. Compile and run your program to verify it works correctly
4. Compare your solution with `src/conditional_expressions_solutions.cpp`

## Expected Output
Example output when running the solution:
```
Score: 85
Grade (ternary): B
Grade (if-else): B
Age: 25, Has license: Yes, Has insurance: Yes
Can drive legally
Fully qualified driver
Day number: 3
Wednesday
Choice: B
Choice is A, B, or C
a = 5, b = 3, c = 2
a + b * c = 11
(a + b) * c = 14
a / b (integer) = 1
a / b (floating) = 1.66667
condition1: true, condition2: false, value: 10
First condition true, value incremented to: 11
Second condition true, value incremented to: 12
Pointer is null, avoiding dereference
Vector size: 5, Index: 10
Index out of bounds or value not positive
```

## Key Points to Remember
- **Ternary Operator**: Use `condition ? value_if_true : value_if_false` for simple conditions
- **If-Else Chains**: Use `if-else if-else` for complex conditions with multiple branches
- **Switch Statements**: Use for discrete value matching, remember to include `break` statements
- **Operator Precedence**: Understand which operators are evaluated first (multiplication before addition, etc.)
- **Short-Circuit Evaluation**: `&&` and `||` operators stop evaluating as soon as the result is determined
- **Safe Programming**: Use short-circuiting to prevent errors like null pointer dereferencing

## Common Mistakes to Avoid
- Forgetting to include `break` statements in switch cases (fall-through behavior)
- Misunderstanding operator precedence leading to unexpected results
- Not considering short-circuit evaluation in logical expressions
- Using assignment (=) instead of comparison (==) in conditions
- Creating deeply nested if statements that are hard to read

## Next Steps
After completing this exercise, proceed to:
- Exercise 4.1b: Expression Evaluation
- Exercise 5.1: Control Flow Statements