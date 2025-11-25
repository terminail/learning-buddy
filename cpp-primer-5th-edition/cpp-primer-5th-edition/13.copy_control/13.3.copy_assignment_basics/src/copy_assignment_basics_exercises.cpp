#include <iostream>
#include <string>
#include <cstring>

// TODO: Implement a class with proper copy assignment operator
// Example approach:
// 1. Define a class that manages dynamic memory
// 2. Implement a copy assignment operator that performs deep copy
// 3. Handle self-assignment correctly
// 4. Demonstrate the difference between copy constructor and copy assignment

class MyArray {
private:
    int* data;
    size_t size;

public:
    // TODO: Implement default constructor
    // - Initialize data to nullptr and size to 0
    
    // TODO: Implement parameterized constructor
    // - Allocate memory for the array
    // - Initialize elements (e.g., with their index values)
    // - Set size to the specified size
    
    // TODO: Implement copy constructor
    // - Allocate new memory for the copied array
    // - Copy the content from the source object
    // - Set size to match the source object
    
    // TODO: Implement copy assignment operator
    // - Check for self-assignment
    // - Deallocate existing memory
    // - Allocate new memory and copy data
    // - Return *this
    
    // TODO: Implement destructor
    // - Deallocate the memory
    
    // TODO: Implement a display method to print the array
    
    // TODO: Implement getters for size and data (for testing)
};

int main() {
    // TODO: Create objects and demonstrate copy assignment
    // - Create objects using different constructors
    // - Use copy assignment operator to assign one object to another
    // - Display objects to verify correct behavior
    
    return 0;
}