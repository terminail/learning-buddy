// Solution 9.1a: Vector Basics
// This exercise demonstrates the std::vector container in C++.

#include <iostream>
#include <vector>
#include <string>

int main() {
    // Solution: Create an empty vector of integers
    std::vector<int> empty_vector;
    std::cout << "Empty vector size: " << empty_vector.size() << std::endl;
    
    // Solution: Create a vector of 5 integers, all initialized to 0
    std::vector<int> zero_vector(5);
    std::cout << "Zero vector size: " << zero_vector.size() << std::endl;
    std::cout << "Zero vector elements: ";
    for (size_t i = 0; i < zero_vector.size(); i++) {
        std::cout << zero_vector[i] << " ";
    }
    std::cout << std::endl;
    
    // Solution: Create a vector with specific initial values {1, 2, 3, 4, 5}
    std::vector<int> specific_vector = {1, 2, 3, 4, 5};
    std::cout << "Specific vector size: " << specific_vector.size() << std::endl;
    std::cout << "Specific vector elements: ";
    for (size_t i = 0; i < specific_vector.size(); i++) {
        std::cout << specific_vector[i] << " ";
    }
    std::cout << std::endl;
    
    // Solution: Create a vector of strings and add elements to it
    std::vector<std::string> string_vector;
    string_vector.push_back("Hello");
    string_vector.push_back("World");
    string_vector.push_back("Vector");
    std::cout << "String vector size: " << string_vector.size() << std::endl;
    std::cout << "String vector elements: ";
    for (size_t i = 0; i < string_vector.size(); i++) {
        std::cout << string_vector[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}