# Comparison Operators Overloading Exercise

## Learning Objectives
- Understand how to overload comparison operators in C++ classes
- Learn best practices for implementing comparison operators
- Practice deriving some operators from others
- Understand the importance of consistency in comparison operations

## Topics Covered
- Equality operators (==, !=)
- Relational operators (<, >, <=, >=)
- Const correctness in comparison operators
- Member vs non-member operator functions
- Operator implementation strategies

## Instructions
1. Implement the TODO comments in [comparison_operators_exercises.cpp](src/comparison_operators_exercises.cpp)
2. Build and run your solution using the provided build scripts
3. Compare your implementation with the solution in [comparison_operators_solutions.cpp](src/comparison_operators_solutions.cpp)

## Expected Output
When running the solution, you should see output similar to:
```
Comparing students:
Student: Alice, GPA: 3.8
Student: Bob, GPA: 3.9
Student: Charlie, GPA: 3.8
Student: Alice, GPA: 3.8

Comparison results:
s1 == s2: false
s1 == s4: true
s1 != s2: true
s1 < s2: true
s1 > s2: false
s1 <= s3: true
s2 >= s1: true
```

## Key Concepts

### Best Practice Implementation Strategy
Rather than implementing all comparison operators, it's more efficient to:
1. Implement `==` and `<` as primary operators
2. Derive all other operators from these two

```cpp
bool operator==(const MyClass& other) const { /* ... */ }
bool operator<(const MyClass& other) const { /* ... */ }

bool operator!=(const MyClass& other) const { return !(*this == other); }
bool operator>(const MyClass& other) const { return other < *this; }
bool operator<=(const MyClass& other) const { return !(*this > other); }
bool operator>=(const MyClass& other) const { return !(*this < other); }
```

### Member vs Non-Member Functions
- **Equality operators (==, !=)**: Usually implemented as non-member functions or friends
- **Relational operators (<, >, <=, >=)**: Can be implemented as members or non-members

### Const Correctness
All comparison operators should be const since they don't modify the object:
```cpp
bool operator==(const MyClass& other) const;
bool operator<(const MyClass& other) const;
```

### Consistency Requirements
Comparison operators should be consistent with each other:
- If `a == b` is true, then `a < b` and `a > b` should both be false
- If `a < b` is true, then `b > a` should be true
- Transitivity: if `a < b` and `b < c`, then `a < c`

## Common Patterns

### Implementing Comparison Logic
When comparing objects with multiple data members, compare them in order of significance:
```cpp
bool operator<(const Student& other) const {
    if (gpa != other.gpa) {
        return gpa < other.gpa;  // Primary criterion
    }
    return name < other.name;    // Secondary criterion
}
```

This approach ensures a consistent and meaningful ordering.