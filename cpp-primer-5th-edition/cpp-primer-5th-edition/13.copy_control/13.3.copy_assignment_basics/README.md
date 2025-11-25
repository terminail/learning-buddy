# Copy Assignment Operator Basics Exercise

## Learning Objectives
- Understand the purpose and implementation of copy assignment operators
- Learn how to handle self-assignment correctly
- Practice implementing proper resource management in classes
- Observe when copy assignment operators are called automatically

## Topics Covered
- Copy assignment operator syntax and implementation
- Self-assignment handling
- Dynamic memory management
- Rule of Three (destructor, copy constructor, copy assignment operator)
- Automatic copy assignment operator invocation

## Instructions
1. Implement the TODO comments in [copy_assignment_basics_exercises.cpp](src/copy_assignment_basics_exercises.cpp)
2. Build and run your solution using the provided build scripts
3. Compare your implementation with the solution in [copy_assignment_basics_solutions.cpp](src/copy_assignment_basics_solutions.cpp)

## Expected Output
When running the solution, you should see output similar to:
```
Default constructor called
Parameterized constructor called (size: 5)
Before assignment:
Array (size 5): 0 1 2 3 4 
Array (size 0): 
Copy assignment operator called
After assignment:
Array (size 5): 0 1 2 3 4 
Array (size 5): 0 1 2 3 4 
Testing self-assignment:
Copy assignment operator called
Destructor called
Destructor called
```

Note that:
1. The copy assignment operator is called when using the = operator between existing objects
2. Self-assignment is handled correctly (the check prevents unnecessary work)
3. Both objects have independent copies of the data after assignment

## Key Concepts

### Copy Assignment vs Copy Constructor
- **Copy Constructor**: Creates a new object as a copy of an existing one
- **Copy Assignment Operator**: Assigns an existing object to another existing object

### Self-Assignment Handling
Self-assignment occurs when an object is assigned to itself:
```cpp
MyClass obj;
obj = obj;  // Self-assignment
```

The copy assignment operator must handle this case correctly to avoid:
- Memory leaks
- Double deletion
- Data corruption

### Implementation Pattern
A typical copy assignment operator follows this pattern:
1. Check for self-assignment
2. Deallocate existing resources
3. Allocate new resources
4. Copy data from source to destination
5. Return *this