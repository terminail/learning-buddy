// Exercise: Sorting Algorithms - Solution
// This exercise demonstrates sorting algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>

// Custom comparator for sorting by string length
bool compareByLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

// Custom comparator for sorting pairs by second element
bool comparePairBySecond(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.second < b.second;
}

int main() {
    // Solution: Use std::sort with default ordering
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Sort strings lexicographically
    std::vector<std::string> words = {"banana", "apple", "cherry", "date"};
    std::cout << "Original words: ";
    for (const auto& word : words) std::cout << word << " ";
    std::cout << std::endl;
    
    std::sort(words.begin(), words.end());
    std::cout << "Sorted words: ";
    for (const auto& word : words) std::cout << word << " ";
    std::cout << std::endl;

    // Solution: Use std::sort with custom comparators
    // Sort in descending order
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    std::cout << "Descending numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Sort strings by length using function pointer
    std::sort(words.begin(), words.end(), compareByLength);
    std::cout << "Words sorted by length: ";
    for (const auto& word : words) std::cout << word << " ";
    std::cout << std::endl;
    
    // Sort with lambda comparator (by last character)
    std::sort(words.begin(), words.end(), 
              [](const std::string& a, const std::string& b) {
                  return a.back() < b.back();
              });
    std::cout << "Words sorted by last character: ";
    for (const auto& word : words) std::cout << word << " ";
    std::cout << std::endl;

    // Solution: Use std::stable_sort and related functions
    std::vector<std::pair<int, std::string>> data = {
        {1, "apple"}, {2, "banana"}, {1, "cherry"}, {3, "date"}, {2, "elderberry"}
    };
    
    std::cout << "Original data: ";
    for (const auto& item : data) std::cout << "(" << item.first << "," << item.second << ") ";
    std::cout << std::endl;
    
    // Sort by first element (unstable)
    std::vector<std::pair<int, std::string>> unstable_data = data;
    std::sort(unstable_data.begin(), unstable_data.end());
    std::cout << "Unstable sort by first: ";
    for (const auto& item : unstable_data) std::cout << "(" << item.first << "," << item.second << ") ";
    std::cout << std::endl;
    
    // Sort by first element (stable)
    std::stable_sort(data.begin(), data.end());
    std::cout << "Stable sort by first: ";
    for (const auto& item : data) std::cout << "(" << item.first << "," << item.second << ") ";
    std::cout << std::endl;

    // Solution: Work with partial sorting algorithms
    std::vector<int> large_numbers = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    
    // Partial sort - sort only first 5 elements
    std::partial_sort(large_numbers.begin(), large_numbers.begin() + 5, large_numbers.end());
    std::cout << "Partially sorted (first 5): ";
    for (int n : large_numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // nth_element - find 5th smallest element
    std::vector<int> more_numbers = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    std::nth_element(more_numbers.begin(), more_numbers.begin() + 4, more_numbers.end());
    std::cout << "5th smallest element: " << more_numbers[4] << std::endl;
    std::cout << "Array after nth_element: ";
    for (int n : more_numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    return 0;
}