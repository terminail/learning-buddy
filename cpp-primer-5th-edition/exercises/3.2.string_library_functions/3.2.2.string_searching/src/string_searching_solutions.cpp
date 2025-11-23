// Exercise: String Searching - Solution
// This exercise demonstrates string searching functions in C++.

#include <iostream>
#include <string>

int main() {
    // Solution: Use find() to search for substrings
    std::string text = "Hello, World! Welcome to C++ Programming!";
    
    // Find first occurrence of "World"
    size_t pos = text.find("World");
    if (pos != std::string::npos) {
        std::cout << "Found 'World' at position: " << pos << std::endl;
    } else {
        std::cout << "'World' not found" << std::endl;
    }
    
    // Find "o" starting from position 5
    pos = text.find("o", 5);
    if (pos != std::string::npos) {
        std::cout << "Found 'o' at position: " << pos << std::endl;
    }
    
    // Search for character
    pos = text.find('!');
    if (pos != std::string::npos) {
        std::cout << "Found '!' at position: " << pos << std::endl;
    }

    // Solution: Use rfind() to search backwards
    std::string sentence = "The quick brown fox jumps over the lazy dog. The fox is quick.";
    
    // Find last occurrence of "fox"
    pos = sentence.rfind("fox");
    if (pos != std::string::npos) {
        std::cout << "Last 'fox' found at position: " << pos << std::endl;
    }
    
    // Find last occurrence of "the" (case sensitive)
    pos = sentence.rfind("the");
    if (pos != std::string::npos) {
        std::cout << "Last 'the' found at position: " << pos << std::endl;
    }

    // Solution: Use find_first_of() and find_last_of()
    std::string data = "Hello123World456";
    
    // Find first digit
    pos = data.find_first_of("0123456789");
    if (pos != std::string::npos) {
        std::cout << "First digit at position: " << pos << std::endl;
    }
    
    // Find last letter
    pos = data.find_last_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (pos != std::string::npos) {
        std::cout << "Last letter at position: " << pos << std::endl;
    }

    // Solution: Use find_first_not_of() and find_last_not_of()
    std::string whitespace = "   \t\n  Hello World  \t\n  ";
    
    // Find first non-whitespace character
    pos = whitespace.find_first_not_of(" \t\n");
    if (pos != std::string::npos) {
        std::cout << "First non-whitespace at position: " << pos << std::endl;
    }
    
    // Find last non-whitespace character
    pos = whitespace.find_last_not_of(" \t\n");
    if (pos != std::string::npos) {
        std::cout << "Last non-whitespace at position: " << pos << std::endl;
    }
    
    return 0;
}