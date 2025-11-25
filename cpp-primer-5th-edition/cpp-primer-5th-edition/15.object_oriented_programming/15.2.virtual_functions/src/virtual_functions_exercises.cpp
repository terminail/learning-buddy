// Exercise 15.1b: Virtual Functions
// This exercise introduces you to virtual functions and polymorphism in C++.
// Your task is to create classes that demonstrate virtual functions and dynamic binding.

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// TODO: Create a base class with virtual functions
// Example approach:
// 1. Define a base class Shape with:
//    - Protected member variables for color
//    - Virtual destructor
//    - Pure virtual functions for area() and perimeter()
//    - Virtual function for display()

// TODO: Create derived classes that override virtual functions
// Example approach:
// 1. Define Rectangle class that inherits from Shape
//    - Add member variables for width and height
//    - Implement area() and perimeter() functions
// 2. Define Circle class that inherits from Shape
//    - Add member variable for radius
//    - Implement area() and perimeter() functions

// TODO: Implement polymorphism with a vector of Shape pointers
// Example approach:
// 1. Create a vector of std::unique_ptr<Shape>
// 2. Add Rectangle and Circle objects to the vector
// 3. Iterate through the vector and call virtual functions

int main() {
    // TODO: Create instances of Rectangle and Circle
    // TODO: Store them in a vector of Shape pointers
    // TODO: Iterate through the vector and call virtual functions
    
    return 0;
}