// Exercise: Deque Operations - Solution
// This exercise demonstrates deque container operations in C++.

#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    // Solution: Create and initialize deques
    std::deque<int> empty_deque;
    std::deque<int> init_deque = {1, 2, 3, 4, 5};
    std::deque<int> fill_deque(5, 10);  // 5 elements, all value 10
    
    std::cout << "Empty deque size: " << empty_deque.size() << std::endl;
    std::cout << "Initialized deque: ";
    for (int n : init_deque) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "Filled deque: ";
    for (int n : fill_deque) std::cout << n << " ";
    std::cout << std::endl;

    // Solution: Work with deque element access
    std::deque<std::string> words = {"first", "second", "third"};
    
    // Access elements
    std::cout << "First element: " << words.front() << std::endl;
    std::cout << "Last element: " << words.back() << std::endl;
    std::cout << "Middle element: " << words.at(1) << std::endl;
    
    // Modify elements
    words[0] = "FIRST";
    words.at(2) = "THIRD";
    std::cout << "Modified deque: ";
    for (const auto& word : words) std::cout << word << " ";
    std::cout << std::endl;

    // Solution: Perform deque modification operations
    std::deque<int> numbers;
    
    // Add elements at both ends
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_front(0);
    numbers.push_front(-1);
    
    std::cout << "After push operations: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Remove elements from both ends
    numbers.pop_back();
    numbers.pop_front();
    
    std::cout << "After pop operations: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Insert and erase in middle
    numbers.insert(numbers.begin() + 1, 99);
    std::cout << "After insert: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    numbers.erase(numbers.begin() + 1);
    std::cout << "After erase: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // Solution: Work with deque iterators and algorithms
    std::deque<int> data = {5, 2, 8, 1, 9, 3};
    
    // Sort the deque
    std::sort(data.begin(), data.end());
    std::cout << "Sorted deque: ";
    for (int n : data) std::cout << n << " ";
    std::cout << std::endl;
    
    // Find an element
    auto it = std::find(data.begin(), data.end(), 8);
    if (it != data.end()) {
        std::cout << "Found 8 at position: " << (it - data.begin()) << std::endl;
    }
    
    // Reverse the deque
    std::reverse(data.begin(), data.end());
    std::cout << "Reversed deque: ";
    for (int n : data) std::cout << n << " ";
    std::cout << std::endl;
    
    return 0;
}