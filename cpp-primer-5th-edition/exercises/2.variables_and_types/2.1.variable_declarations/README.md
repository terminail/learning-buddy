# Exercise 2.1a: Variable Declarations

This exercise focuses on declaring variables of different types in C++, including integer types, floating-point types, character types, and boolean types.

## Learning Objectives

- Declare variables of basic data types (int, float, double, char, bool, etc.)
- Understand variable naming conventions and valid identifiers
- Work with variable scope and lifetime
- Distinguish between declaration and definition

## Files

- [src/variable_declarations_exercises.cpp](src/variable_declarations_exercises.cpp) - Exercise template with TODO comments
- [src/variable_declarations_solutions.cpp](src/variable_declarations_solutions.cpp) - Complete solution implementation
- [test/test_variable_declarations_basics.cpp](test/test_variable_declarations_basics.cpp) - Basic unit tests
- [test/test_variable_declarations_practice.cpp](test/test_variable_declarations_practice.cpp) - Additional practice tests

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

### Basic Data Types
- **Integer Types**: int, short, long, long long (signed and unsigned variants)
- **Floating-Point Types**: float, double, long double
- **Character Types**: char, wchar_t
- **Boolean Type**: bool for true/false values

### Variable Naming
- Valid identifiers: letters, digits, underscores (cannot start with digit)
- Case sensitivity: variableName ≠ VariableName
- Naming conventions: camelCase, snake_case, PascalCase
- Reserved keywords: cannot be used as identifiers

### Variable Scope
- **Global Scope**: Variables declared outside functions
- **Local Scope**: Variables declared inside functions
- **Block Scope**: Variables declared inside blocks ({} braces)
- **Scope Resolution**: Inner scopes can access outer scope variables

## Practice Exercises

1. Experiment with different integer types and their value ranges
2. Work with floating-point precision differences
3. Test variable shadowing in nested scopes
4. Practice naming conventions with various identifier patterns