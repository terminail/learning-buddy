// Solution 3.3a: Algorithms Practice
// This exercise demonstrates common algorithms used with arrays and strings in C++.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    // Solution: Work with character transformation algorithms
    std::string text = "Hello, World! Welcome to C++ Programming!";
    std::cout << "Original text: \"" << text << "\"" << std::endl;
    
    // Use std::transform with ::toupper to convert to uppercase
    std::string upper_text = text;
    std::transform(upper_text.begin(), upper_text.end(), upper_text.begin(), ::toupper);
    std::cout << "Uppercase text: \"" << upper_text << "\"" << std::endl;
    
    // Use std::transform with ::tolower to convert to lowercase
    std::string lower_text = text;
    std::transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
    std::cout << "Lowercase text: \"" << lower_text << "\"" << std::endl;
    
    // Implement custom transformation function
    std::string custom_text = text;
    std::transform(custom_text.begin(), custom_text.end(), custom_text.begin(), 
        [](unsigned char c) -> char {
            if (std::isalpha(c)) {
                return c ^ 32; // Toggle case
            }
            return c;
        });
    std::cout << "Custom transformed text: \"" << custom_text << "\"" << std::endl;
    
    // Solution: Practice searching algorithms with arrays
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
    
    // Use std::binary_search on sorted arrays
    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    bool found = std::binary_search(sorted_numbers.begin(), sorted_numbers.end(), 6);
    std::cout << "Binary search for 6 in sorted array: " << (found ? "found" : "not found") << std::endl;
    
    // Solution: Implement sorting algorithms
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
    
    // Sort by length using custom comparator
    std::vector<std::string> length_sorted = words;
    std::sort(length_sorted.begin(), length_sorted.end(), 
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
    std::cout << "Sorted by length: ";
    for (const auto& word : length_sorted) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    // Solution: Work with array manipulation algorithms
    std::vector<int> data = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    std::cout << "Original data: ";
    for (const auto& num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Use std::reverse to reverse array elements
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
    
    // Use std::remove to remove specific values (erase-remove idiom)
    std::vector<int> filtered_data = data;
    filtered_data.erase(std::remove(filtered_data.begin(), filtered_data.end(), 3), filtered_data.end());
    std::cout << "Data with 3s removed: ";
    for (const auto& num : filtered_data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Solution: Practice string-specific algorithms
    std::string sentence = "The quick brown fox jumps over the lazy dog";
    std::cout << "Original sentence: \"" << sentence << "\"" << std::endl;
    
    // Use std::replace to substitute characters
    std::string replaced_sentence = sentence;
    std::replace(replaced_sentence.begin(), replaced_sentence.end(), 'o', '0');
    std::cout << "With 'o' replaced by '0': \"" << replaced_sentence << "\"" << std::endl;
    
    // Use std::remove_if with predicates
    std::string filtered_sentence = sentence;
    filtered_sentence.erase(
        std::remove_if(filtered_sentence.begin(), filtered_sentence.end(), 
            [](unsigned char c) { return std::ispunct(c); }), 
        filtered_sentence.end());
    std::cout << "Without punctuation: \"" << filtered_sentence << "\"" << std::endl;
    
    // Implement simple text processing function - count vowels
    std::string lowercase_sentence = sentence;
    std::transform(lowercase_sentence.begin(), lowercase_sentence.end(), 
                   lowercase_sentence.begin(), ::tolower);
    
    int vowel_count = std::count_if(lowercase_sentence.begin(), lowercase_sentence.end(),
        [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        });
    std::cout << "Number of vowels: " << vowel_count << std::endl;
    
    return 0;
}