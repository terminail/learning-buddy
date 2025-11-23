#include <iostream>
#include <string>
#include <vector>

// TODO: Implement a class with proper destructor
// Example approach:
// 1. Define a class that manages dynamic resources
// 2. Implement a destructor that properly releases resources
// 3. Demonstrate when destructors are called automatically
// 4. Show the importance of virtual destructors in inheritance

class ResourceHolder {
private:
    std::string* data;
    int id;

public:
    // TODO: Implement constructor
    // - Allocate memory for a string
    // - Initialize with some value
    // - Set the id
    
    // TODO: Implement destructor
    // - Deallocate the memory
    // - Print a message indicating the destructor was called
    
    // TODO: Implement getters for data and id (for testing)
    
    // TODO: Implement a method to display object information
};

int main() {
    // TODO: Create objects and observe when destructors are called
    // - Create objects on the stack
    // - Create objects on the heap (with new)
    // - Create a vector of objects
    // - Observe the order and timing of destructor calls
    
    return 0;
}