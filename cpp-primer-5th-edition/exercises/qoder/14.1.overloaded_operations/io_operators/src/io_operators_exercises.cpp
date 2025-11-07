#include <iostream>
#include <string>

// TODO: Implement a class with overloaded IO operators
// Example approach:
// 1. Define a class representing an entity that needs input/output (e.g., Person)
// 2. Implement overloaded stream insertion operator (<<)
// 3. Implement overloaded stream extraction operator (>>)
// 4. Understand the difference between member and non-member IO operators

class Person {
private:
    std::string name;
    int age;

public:
    // TODO: Implement constructors
    // - Default constructor
    // - Parameterized constructor
    
    // TODO: Declare overloaded IO operators as friend functions
    // - operator<< (stream insertion)
    // - operator>> (stream extraction)
    
    // TODO: Implement getters for name and age
    
    // TODO: Implement setters for name and age (needed for extraction operator)
    
    // TODO: Implement a display method to print person information
};

// TODO: Implement non-member operator<< function
// - Should output person information in a readable format
// - Should return the stream object to allow chaining

// TODO: Implement non-member operator>> function
// - Should read person information from the stream
// - Should return the stream object to allow chaining
// - Consider error handling for invalid input

int main() {
    // TODO: Create Person objects and demonstrate IO operators
    // - Create objects using different constructors
    // - Use operator<< to output person information
    // - Use operator>> to input person information
    // - Demonstrate chaining of IO operations
    
    return 0;
}