# Arithmetic Operators Overloading Exercise

## Learning Objectives
- Understand how to overload arithmetic operators in C++ classes
- Learn the difference between member and non-member operator functions
- Practice implementing compound assignment operators
- Understand the relationship between compound and simple operators

## Topics Covered
- Operator overloading syntax
- Member vs non-member operator functions
- Compound assignment operators (+=, -=, *=, /=)
- Simple arithmetic operators (+, -, *, /)
- Return value optimization
- Const correctness in operator overloading

## Instructions
1. Implement the TODO comments in [arithmetic_operators_exercises.cpp](src/arithmetic_operators_exercises.cpp)
2. Build and run your solution using the provided build scripts
3. Compare your implementation with the solution in [arithmetic_operators_solutions.cpp](src/arithmetic_operators_solutions.cpp)

## Expected Output
When running the solution, you should see output similar to:
```
c1: 3 + 4i
c2: 1 + 2i
c1 + c2: 4 + 6i
c1 - c2: 2 + 2i
c1 * c2: -5 + 10i
c1 / c2: 2.2 + 0.4i
```

## Key Concepts

### Member vs Non-Member Operators
- **Member operators**: Have access to private members, `*this` is the left operand
- **Non-member operators**: Need friend access for private members, both operands are parameters

### Compound Assignment vs Simple Operators
Best practice is to implement compound assignment operators as members and simple operators as non-members:

```cpp
// Member - modifies *this
MyClass& operator+=(const MyClass& other);

// Non-member - creates new object
MyClass operator+(const MyClass& lhs, const MyClass& rhs) {
    MyClass result = lhs;  // Copy lhs
    result += rhs;         // Use compound assignment
    return result;
}
```

### Return Types
- **Compound assignment operators**: Return `MyClass&` (reference to *this)
- **Simple arithmetic operators**: Return `MyClass` (new object by value)

### Const Correctness
Operators that don't modify the object should be const:
```cpp
MyClass operator+(const MyClass& other) const;
```

## Common Patterns

### Implementing Arithmetic Operators
1. Implement compound assignment operators as members
2. Implement simple operators as non-members using compound assignment
3. Make operators const-correct
4. Return appropriate types (references for compound, values for simple)