// Solution 9.1c: Vector Algorithms
// This exercise demonstrates common algorithms used with std::vector containers.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    // Solution: Create a vector with initial values {5, 2, 8, 1, 9, 3}
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};
    std::cout << "Original vector: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted vector: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Find a specific element in the vector (e.g., value 8)
    auto it = std::find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        std::cout << "Found element 8 at position: " << (it - numbers.begin()) << std::endl;
    } else {
        std::cout << "Element 8 not found" << std::endl;
    }
    
    // Solution: Calculate the sum of all elements in the vector
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of elements: " << sum << std::endl;
    
    // Solution: Reverse the order of elements in the vector
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Reversed vector: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Remove all occurrences of a specific value (e.g., value 1)
    // Since 1 is not in our current vector, let's add it first for demonstration
    numbers.push_back(1);
    numbers.push_back(1);
    std::cout << "Vector before removing 1s: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Now remove all occurrences of 1
    numbers.erase(std::remove(numbers.begin(), numbers.end(), 1), numbers.end());
    std::cout << "Vector after removing 1s: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}