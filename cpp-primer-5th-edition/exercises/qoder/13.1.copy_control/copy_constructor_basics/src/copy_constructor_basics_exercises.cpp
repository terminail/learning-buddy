#include <iostream>
#include <string>

// TODO: Implement a class with proper copy constructor
// Example approach:
// 1. Define a class that manages dynamic memory
// 2. Implement a copy constructor that performs deep copy
// 3. Demonstrate the difference between shallow and deep copy

class MyString {
private:
    char* data;
    size_t len;

public:
    // TODO: Implement default constructor
    // - Allocate memory for an empty string
    // - Initialize len to 0
    
    // TODO: Implement parameterized constructor
    // - Allocate memory for the string plus null terminator
    // - Copy the input string to the allocated memory
    // - Set len to the length of the input string
    
    // TODO: Implement copy constructor
    // - Allocate new memory for the copied string
    // - Copy the content from the source object
    // - Set len to match the source object
    
    // TODO: Implement destructor
    // - Deallocate the memory
    
    // TODO: Implement a display method to print the string
    
    // TODO: Implement getters for len and data (for testing)
};

int main() {
    // TODO: Create objects using different constructors
    // - Create an object using the parameterized constructor
    // - Create a copy using the copy constructor
    // - Display both objects
    
    return 0;
}