// Solution to Exercise 2.2.1: Basic Input/Output Operations

#include <iostream>
#include <string>

int main() {
    // Declare variables to store user information
    std::string name;
    int age;
    double height;
    
    // Prompt user for their name and read it
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    // Prompt user for their age and read it
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    // Prompt user for their height and read it
    std::cout << "Enter your height (in meters): ";
    std::cin >> height;
    
    // Display all the collected information
    std::cout << "\n--- User Information ---" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << " years" << std::endl;
    std::cout << "Height: " << height << " meters" << std::endl;
    
    return 0;
}