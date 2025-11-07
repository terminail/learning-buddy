// Solution 10.1a: Algorithm Basics
// This exercise demonstrates generic algorithms in C++.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
    // Solution: Work with searching algorithms
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::cout << "Original numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Use std::find to search for specific values
    auto it = std::find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        std::cout << "Found 5 at position: " << (it - numbers.begin()) << std::endl;
    }
    
    // Use std::count to count occurrences of values
    int count = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "Count of 5s: " << count << std::endl;
    
    // Use std::binary_search on sorted containers
    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    bool found = std::binary_search(sorted_numbers.begin(), sorted_numbers.end(), 6);
    std::cout << "Binary search for 6 in sorted array: " << (found ? "found" : "not found") << std::endl;
    
    // Solution: Work with sorting algorithms
    std::vector<std::string> words = {"banana", "apple", "cherry", "date", "elderberry"};
    std::cout << "Original words: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    // Use std::sort to sort in ascending order
    std::vector<std::string> sorted_words = words;
    std::sort(sorted_words.begin(), sorted_words.end());
    std::cout << "Sorted words (ascending): ";
    for (const auto& word : sorted_words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    // Use std::sort with custom comparator for descending order
    std::vector<std::string> desc_words = words;
    std::sort(desc_words.begin(), desc_words.end(), std::greater<std::string>());
    std::cout << "Sorted words (descending): ";
    for (const auto& word : desc_words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    // Solution: Work with rearranging algorithms
    std::vector<int> data = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    std::cout << "Original data: ";
    for (const auto& num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Use std::reverse to reverse container elements
    std::vector<int> reversed_data = data;
    std::reverse(reversed_data.begin(), reversed_data.end());
    std::cout << "Reversed data: ";
    for (const auto& num : reversed_data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Use std::unique to remove consecutive duplicates
    std::vector<int> unique_data = data;
    auto unique_end = std::unique(unique_data.begin(), unique_data.end());
    unique_data.erase(unique_end, unique_data.end());
    std::cout << "Unique data: ";
    for (const auto& num : unique_data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Use std::remove to mark elements for removal (erase-remove idiom)
    std::vector<int> filtered_data = data;
    filtered_data.erase(std::remove(filtered_data.begin(), filtered_data.end(), 3), filtered_data.end());
    std::cout << "Data with 3s removed: ";
    for (const auto& num : filtered_data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Work with predicate algorithms
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Original values: ";
    for (const auto& val : values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    // Use std::find_if with custom predicates
    auto even_it = std::find_if(values.begin(), values.end(), [](int n) { return n % 2 == 0; });
    if (even_it != values.end()) {
        std::cout << "First even number: " << *even_it << std::endl;
    }
    
    // Use std::count_if with custom predicates
    int even_count = std::count_if(values.begin(), values.end(), [](int n) { return n % 2 == 0; });
    std::cout << "Count of even numbers: " << even_count << std::endl;
    
    // Use std::remove_if with custom predicates
    std::vector<int> odd_values = values;
    odd_values.erase(std::remove_if(odd_values.begin(), odd_values.end(), [](int n) { return n % 2 == 0; }), odd_values.end());
    std::cout << "Odd numbers only: ";
    for (const auto& val : odd_values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    // Solution: Work with numeric algorithms
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "Numbers: ";
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Use std::accumulate to sum container elements
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << "Sum of numbers: " << sum << std::endl;
    
    // Use std::accumulate with custom operations
    int product = std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
    std::cout << "Product of numbers: " << product << std::endl;
    
    // Use std::inner_product for dot products
    std::vector<int> nums2 = {2, 3, 4, 5, 6};
    int dot_product = std::inner_product(nums.begin(), nums.end(), nums2.begin(), 0);
    std::cout << "Dot product: " << dot_product << std::endl;
    
    return 0;
}