// Solution to Exercise 2.1.1: Variables and Basic Types

#include <iostream>
#include <string>

int main() {
    // Declare and initialize variables of different types
    int age = 25;
    double height = 1.75;
    char grade = 'A';
    bool isStudent = true;
    std::string name = "John";
    
    // Print all variables to the console
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << " meters" << std::endl;
    std::cout << "Grade: " << grade << std::endl;
    std::cout << "Is Student: " << (isStudent ? "Yes" : "No") << std::endl;
    
    return 0;
}