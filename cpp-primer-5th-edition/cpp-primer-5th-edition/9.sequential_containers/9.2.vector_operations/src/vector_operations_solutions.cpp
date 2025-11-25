// Solution 9.1b: Vector Operations
// This exercise demonstrates common vector operations in C++.

#include <iostream>
#include <vector>
#include <string>

int main() {
    // Solution: Create a vector with initial values {1, 2, 3, 4, 5}
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Initial vector: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Add elements to the end of the vector
    numbers.push_back(6);
    numbers.push_back(7);
    std::cout << "After adding elements: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Insert an element at a specific position
    // Insert 10 at the beginning (position 0)
    numbers.insert(numbers.begin(), 10);
    // Insert 20 at position 3
    numbers.insert(numbers.begin() + 3, 20);
    std::cout << "After inserting elements: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Remove elements from the vector
    // Remove the last element
    numbers.pop_back();
    // Remove the element at position 2
    numbers.erase(numbers.begin() + 2);
    // Remove elements from position 1 to 3 (not including 3)
    numbers.erase(numbers.begin() + 1, numbers.begin() + 3);
    std::cout << "After removing elements: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Clear all elements
    numbers.clear();
    std::cout << "After clearing, vector size: " << numbers.size() << std::endl;
    
    // Recreate vector for iteration examples
    std::vector<std::string> words = {"Hello", "Vector", "World"};
    
    // Solution: Iterate through the vector using different methods
    std::cout << "Iteration with index: ";
    for (size_t i = 0; i < words.size(); i++) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Range-based for loop: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Iterator-based loop: ";
    for (auto it = words.begin(); it != words.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}