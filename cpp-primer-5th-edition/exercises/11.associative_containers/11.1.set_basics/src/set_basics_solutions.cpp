#include <iostream>
#include <set>
#include <string>

// Solution: Work with set container basics
int main() {
    // Solution: Create a set to store unique strings
    std::set<std::string> unique_words;
    
    // Solution: Add some words to the set using different insertion methods
    unique_words.insert("apple");
    unique_words.insert("banana");
    unique_words.insert("orange");
    unique_words.insert("apple");  // Duplicate, will be ignored
    
    // Solution: Check if specific elements exist in the set
    if (unique_words.count("apple")) {
        std::cout << "Found apple in the set" << std::endl;
    }
    
    if (unique_words.find("grape") != unique_words.end()) {
        std::cout << "Found grape in the set" << std::endl;
    } else {
        std::cout << "Grape not found in the set" << std::endl;
    }
    
    // Solution: Iterate through the set and print all elements
    std::cout << "Unique words in the set:" << std::endl;
    for (const auto& word : unique_words) {
        std::cout << word << std::endl;
    }
    
    std::cout << "Total unique words: " << unique_words.size() << std::endl;
    
    return 0;
}