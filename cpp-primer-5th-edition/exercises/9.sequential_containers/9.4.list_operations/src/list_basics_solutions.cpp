// Solution 9.2a: List Basics
// This exercise demonstrates the std::list container in C++.

#include <iostream>
#include <list>
#include <string>

int main() {
    // Solution: Create an empty list of integers
    std::list<int> empty_list;
    std::cout << "Empty list size: " << empty_list.size() << std::endl;
    
    // Solution: Create a list with initial values {1, 2, 3, 4, 5}
    std::list<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Initial list: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Add elements to the front and back of the list
    numbers.push_front(0);
    numbers.push_back(6);
    std::cout << "List after adding front and back: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Insert an element at a specific position in the list
    auto it = numbers.begin();
    std::advance(it, 3);  // Move iterator to position 3
    numbers.insert(it, 99);
    std::cout << "List after inserting 99 at position 3: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Iterate through the list and print all elements
    std::cout << "List elements using iterators: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Solution: Remove elements from the front and back of the list
    numbers.pop_front();
    numbers.pop_back();
    std::cout << "List after removing front and back: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}