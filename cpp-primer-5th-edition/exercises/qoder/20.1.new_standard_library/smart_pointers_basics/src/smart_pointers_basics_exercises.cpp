#include <iostream>
#include <memory>
#include <string>

// TODO: Work with std::unique_ptr for exclusive ownership
// Example approach:
// 1. Create a unique_ptr to manage a dynamically allocated object
// 2. Use the pointer to access and modify the object
// 3. Transfer ownership using std::move
// 4. Observe that the original pointer becomes empty after transfer

void unique_ptr_exercises() {
    std::cout << "=== Unique Pointer Exercises ===" << std::endl;
    
    // TODO 1: Create a std::unique_ptr to an integer
    // - Initialize it with a value using std::make_unique
    // - Access and print the value using the * operator
    // - Modify the value through the pointer
    
    // TODO 2: Transfer ownership of a unique_ptr
    // - Create another unique_ptr and transfer ownership from the first one
    // - Use std::move to perform the transfer
    // - Verify that the original pointer is now empty (nullptr)
    
    // TODO 3: Create a unique_ptr to a custom object
    // - Define a simple class with a constructor and destructor that print messages
    // - Create a unique_ptr to an instance of this class
    // - Observe when the destructor is called
    
    // TODO 4: Use unique_ptr with arrays
    // - Create a unique_ptr to an array of integers
    // - Initialize array elements
    // - Access array elements using the [] operator
}

// TODO: Work with std::shared_ptr for shared ownership
// Example approach:
// 1. Create a shared_ptr to manage a dynamically allocated object
// 2. Create multiple shared_ptr instances pointing to the same object
// 3. Observe the reference count
// 4. See how the object is destroyed when the last shared_ptr is destroyed

void shared_ptr_exercises() {
    std::cout << "\n=== Shared Pointer Exercises ===" << std::endl;
    
    // TODO 1: Create a std::shared_ptr to a string
    // - Initialize it with a value using std::make_shared
    // - Access and print the value
    // - Check and print the reference count using use_count()
    
    // TODO 2: Share ownership with multiple shared_ptr instances
    // - Create additional shared_ptr instances that share ownership
    // - Observe how the reference count changes
    // - Verify that the object is only destroyed when the last shared_ptr is destroyed
    
    // TODO 3: Use shared_ptr with custom objects
    // - Define a simple class with a constructor and destructor that print messages
    // - Create shared_ptr instances to instances of this class
    // - Observe when the destructor is called as reference count changes
    
    // TODO 4: Compare performance of make_shared vs shared_ptr constructor
    // - Create objects using both methods
    // - Understand the memory allocation difference
}

// TODO: Practice with factory functions
// Example approach:
// 1. Use std::make_unique for efficient unique_ptr creation
// 2. Use std::make_shared for efficient shared_ptr creation
// 3. Understand why these factory functions are preferred

void factory_function_exercises() {
    std::cout << "\n=== Factory Function Exercises ===" << std::endl;
    
    // TODO 1: Use std::make_unique
    // - Create unique_ptr instances using make_unique
    // - Pass constructor arguments to make_unique
    // - Compare with direct unique_ptr construction
    
    // TODO 2: Use std::make_shared
    // - Create shared_ptr instances using make_shared
    // - Pass constructor arguments to make_shared
    // - Understand the performance benefits
    
    // TODO 3: Work with custom classes and factory functions
    // - Create classes with multiple constructors
    // - Use factory functions with different constructor arguments
    // - Observe exception safety benefits
}

int main() {
    std::cout << "Chapter 20.1: Smart Pointers Basics Exercise" << std::endl;
    std::cout << "=============================================" << std::endl;
    
    unique_ptr_exercises();
    shared_ptr_exercises();
    factory_function_exercises();
    
    std::cout << "\nExercise completed!" << std::endl;
    return 0;
}