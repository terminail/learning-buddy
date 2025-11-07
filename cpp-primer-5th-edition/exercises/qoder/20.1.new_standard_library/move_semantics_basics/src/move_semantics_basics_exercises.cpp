#include <iostream>
#include <vector>
#include <string>
#include <utility>

// Simple class to demonstrate move semantics
class SimpleString {
private:
    char* data;
    size_t len;

public:
    // TODO: Implement constructors
    // - Default constructor
    // - Parameterized constructor that takes a const char*
    // - Copy constructor
    // - Move constructor (NEW - this is what we're learning!)
    
    // TODO: Implement assignment operators
    // - Copy assignment operator
    // - Move assignment operator (NEW - this is what we're learning!)
    
    // TODO: Implement destructor
    // - Properly clean up allocated memory
    
    // TODO: Implement utility functions
    // - length() to return the string length
    // - c_str() to return the C-string
    
    // TODO: Implement a print function to show when constructors/destructors are called
};

// TODO: Work with std::move to enable move operations
// Example approach:
// 1. Create objects and observe copy operations
// 2. Use std::move to convert lvalues to rvalues
// 3. Observe move operations instead of copy operations

void move_function_exercises() {
    std::cout << "=== Move Function Exercises ===" << std::endl;
    
    // TODO 1: Observe copy operations
    // - Create a SimpleString object
    // - Create another SimpleString object by copying the first one
    // - Observe that the copy constructor is called
    
    // TODO 2: Use std::move to enable move operations
    // - Create a SimpleString object
    // - Use std::move to convert it to an rvalue
    // - Create another SimpleString object from the moved object
    // - Observe that the move constructor is called instead of copy constructor
    
    // TODO 3: Work with containers and move operations
    // - Create a vector of SimpleString objects
    // - Add objects to the vector
    // - Use std::move to transfer objects into the vector
    // - Observe the difference in performance
}

// TODO: Work with std::forward for perfect forwarding
// Example approach:
// 1. Create template functions that forward arguments
// 2. Use std::forward to preserve value categories
// 3. Understand the difference between std::move and std::forward

template<typename T>
void wrapper_function(T&& param) {
    // TODO: Use std::forward to perfectly forward the parameter
    // - Forward the parameter to another function
    // - Preserve whether it's an lvalue or rvalue
}

void perfect_forwarding_exercises() {
    std::cout << "\n=== Perfect Forwarding Exercises ===" << std::endl;
    
    // TODO 1: Understand the difference between std::move and std::forward
    // - Create lvalue and rvalue objects
    // - Use std::move on both (always produces rvalue)
    // - Use std::forward on both (preserves original value category)
    
    // TODO 2: Create a factory function using perfect forwarding
    // - Create a template factory function
    // - Use std::forward to pass arguments to constructors
    // - Demonstrate that it works with both lvalue and rvalue arguments
    
    // TODO 3: Work with variadic templates and perfect forwarding
    // - Create a function template that accepts variable arguments
    // - Use parameter packs and perfect forwarding
    // - Forward all arguments to a constructor
}

// TODO: Practice with move-only types
// Example approach:
// 1. Create classes that are move-only (no copy operations)
// 2. Work with std::unique_ptr (which is move-only)
// 3. Understand when move-only types are useful

void move_only_exercises() {
    std::cout << "\n=== Move-Only Type Exercises ===" << std::endl;
    
    // TODO 1: Create a move-only class
    // - Define a class with move constructor but no copy constructor
    // - Try to copy an object (should cause compilation error)
    // - Successfully move an object
    
    // TODO 2: Work with std::unique_ptr (which is move-only)
    // - Create unique_ptr objects
    // - Transfer ownership using move operations
    // - Try to copy a unique_ptr (should cause compilation error)
    
    // TODO 3: Understand when move-only types are useful
    // - Create scenarios where exclusive ownership is important
    // - Demonstrate resource management with move-only types
}

int main() {
    std::cout << "Chapter 20.1: Move Semantics Basics Exercise" << std::endl;
    std::cout << "============================================" << std::endl;
    
    move_function_exercises();
    perfect_forwarding_exercises();
    move_only_exercises();
    
    std::cout << "\nExercise completed!" << std::endl;
    return 0;
}