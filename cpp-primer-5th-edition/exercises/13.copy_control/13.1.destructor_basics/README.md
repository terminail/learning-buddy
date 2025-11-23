# Destructor Basics Exercise

## Learning Objectives
- Understand the purpose and implementation of destructors
- Learn when destructors are called automatically
- Practice implementing proper resource cleanup
- Understand the importance of virtual destructors

## Topics Covered
- Destructor syntax and implementation
- Automatic destructor invocation
- Resource management and cleanup
- Order of destruction
- Virtual destructors

## Instructions
1. Implement the TODO comments in [destructor_basics_exercises.cpp](src/destructor_basics_exercises.cpp)
2. Build and run your solution using the provided build scripts
3. Compare your implementation with the solution in [destructor_basics_solutions.cpp](src/destructor_basics_solutions.cpp)

## Expected Output
When running the solution, you should see output similar to:
```
Creating stack object:
Constructor called for object #0 with data: Stack Object

Creating heap object:
Constructor called for object #1 with data: Heap Object

Creating vector of objects:
Constructor called for object #2 with data: Vector Object 1
Copy constructor called
Destructor called for object #2 with data: Vector Object 1
Constructor called for object #3 with data: Vector Object 2
Copy constructor called
Copy constructor called
Destructor called for object #3 with data: Vector Object 2
Destructor called for object #4 with data: Vector Object 1

About to delete heap object:
Destructor called for object #1 with data: Heap Object

End of main - stack objects and vector will be destroyed:
Destructor called for object #5 with data: Vector Object 2
Destructor called for object #4 with data: Vector Object 1
Destructor called for object #0 with data: Stack Object
```

Note that:
1. Destructors are called automatically when objects go out of scope
2. The order of destruction is the reverse of construction
3. For vector elements, temporary objects are created and destroyed during push_back operations
4. Heap objects must be explicitly deleted to call their destructors

## Key Concepts

### When Destructors Are Called
- When objects go out of scope (local variables)
- When objects are explicitly deleted (heap objects)
- When containers are destroyed (destruction of contained objects)
- When the program terminates (global/static objects)

### Destructor Implementation
- Named with a tilde (~) followed by the class name
- Takes no parameters and returns no value
- Should release any resources acquired by the object
- Automatically called - never called explicitly (except for heap objects with delete)

### Virtual Destructors
In inheritance hierarchies, base class destructors should be virtual to ensure proper cleanup:
```cpp
class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {
private:
    int* data;
public:
    ~Derived() { delete[] data; }
};
```

Without a virtual destructor, deleting a Derived object through a Base pointer would not call Derived's destructor.