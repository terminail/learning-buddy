// Exercise: Array Manipulation Algorithms - Solution
// This exercise demonstrates array manipulation algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>

int main() {
    // Solution: Use std::reverse and std::reverse_copy
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Original numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Reverse in place
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Reversed numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Reverse copy
    std::vector<int> original = {1, 2, 3, 4, 5};
    std::vector<int> reversed(original.size());
    std::reverse_copy(original.begin(), original.end(), reversed.begin());
    std::cout << "Original: ";
    for (int n : original) std::cout << n << " ";
    std::cout << std::endl;
    std::cout << "Reversed copy: ";
    for (int n : reversed) std::cout << n << " ";
    std::cout << std::endl;
    
    // Solution: Use std::unique and std::unique_copy
    std::vector<int> duplicates = {1, 1, 2, 2, 2, 3, 3, 4, 5, 5};
    std::cout << "With duplicates: ";
    for (int n : duplicates) std::cout << n << " ";
    std::cout << std::endl;
    
    // Unique - moves duplicates to end, returns new end iterator
    auto new_end = std::unique(duplicates.begin(), duplicates.end());
    std::cout << "Unique result: ";
    for (auto it = duplicates.begin(); it != new_end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Erase-remove idiom to actually remove duplicates
    duplicates.erase(new_end, duplicates.end());
    std::cout << "After erase: ";
    for (int n : duplicates) std::cout << n << " ";
    std::cout << std::endl;
    
    // Unique copy
    std::vector<int> with_duplicates = {1, 1, 2, 2, 3, 3, 4};
    std::vector<int> unique_copy(with_duplicates.size());
    auto copy_end = std::unique_copy(with_duplicates.begin(), with_duplicates.end(), unique_copy.begin());
    unique_copy.erase(copy_end, unique_copy.end());
    std::cout << "Unique copy: ";
    for (int n : unique_copy) std::cout << n << " ";
    std::cout << std::endl;

    // Solution: Use std::remove and std::remove_if
    std::vector<int> to_remove = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Original: ";
    for (int n : to_remove) std::cout << n << " ";
    std::cout << std::endl;
    
    // Remove specific value (remove all even numbers)
    auto remove_end = std::remove_if(to_remove.begin(), to_remove.end(),
                                     [](int n) { return n % 2 == 0; });
    to_remove.erase(remove_end, to_remove.end());
    std::cout << "After removing even numbers: ";
    for (int n : to_remove) std::cout << n << " ";
    std::cout << std::endl;
    
    // Remove specific value
    std::vector<int> remove_specific = {1, 2, 3, 2, 4, 2, 5};
    auto specific_end = std::remove(remove_specific.begin(), remove_specific.end(), 2);
    remove_specific.erase(specific_end, remove_specific.end());
    std::cout << "After removing 2s: ";
    for (int n : remove_specific) std::cout << n << " ";
    std::cout << std::endl;

    // Solution: Work with rotation and shuffling algorithms
    std::vector<int> rotate_data = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "Original: ";
    for (int n : rotate_data) std::cout << n << " ";
    std::cout << std::endl;
    
    // Rotate - move elements so that element at position 3 becomes first
    std::rotate(rotate_data.begin(), rotate_data.begin() + 3, rotate_data.end());
    std::cout << "After rotating at position 3: ";
    for (int n : rotate_data) std::cout << n << " ";
    std::cout << std::endl;
    
    // Shuffle
    std::vector<int> shuffle_data = {1, 2, 3, 4, 5};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffle_data.begin(), shuffle_data.end(), g);
    std::cout << "After shuffling: ";
    for (int n : shuffle_data) std::cout << n << " ";
    std::cout << std::endl;
    
    return 0;
}