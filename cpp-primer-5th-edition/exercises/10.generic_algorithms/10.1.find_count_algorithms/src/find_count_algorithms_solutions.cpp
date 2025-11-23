// Exercise 10.1a: Find and Count Algorithms - Solution
// This exercise demonstrates non-modifying sequence algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

int main() {
    // Use std::find to locate elements in containers
    std::vector<int> numbers = {10, 20, 30, 40, 50, 30, 60};
    
    // Find a specific value
    auto it = std::find(numbers.begin(), numbers.end(), 30);
    if (it != numbers.end()) {
        std::cout << "Found 30 at position: " << (it - numbers.begin()) << std::endl;
    } else {
        std::cout << "30 not found in the vector" << std::endl;
    }
    
    // Find a value that doesn't exist
    auto it2 = std::find(numbers.begin(), numbers.end(), 100);
    if (it2 != numbers.end()) {
        std::cout << "Found 100 at position: " << (it2 - numbers.begin()) << std::endl;
    } else {
        std::cout << "100 not found in the vector" << std::endl;
    }
    
    // Use std::count to count occurrences of elements
    int count_30 = std::count(numbers.begin(), numbers.end(), 30);
    std::cout << "Number of occurrences of 30: " << count_30 << std::endl;
    
    // Use std::count_if with a predicate
    int count_even = std::count_if(numbers.begin(), numbers.end(), 
                                  [](int n) { return n % 2 == 0; });
    std::cout << "Number of even numbers: " << count_even << std::endl;
    
    // Use std::find_if and related algorithms
    std::vector<std::string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    
    // Find the first word with more than 5 characters
    auto word_it = std::find_if(words.begin(), words.end(), 
                               [](const std::string& s) { return s.length() > 5; });
    if (word_it != words.end()) {
        std::cout << "First word with more than 5 characters: " << *word_it << std::endl;
    }
    
    // Find the first word that doesn't start with 'a'
    auto word_it2 = std::find_if_not(words.begin(), words.end(), 
                                    [](const std::string& s) { return s[0] == 'a'; });
    if (word_it2 != words.end()) {
        std::cout << "First word not starting with 'a': " << *word_it2 << std::endl;
    }
    
    // Work with list container
    std::list<char> letters = {'a', 'b', 'c', 'd', 'e', 'c', 'f'};
    
    auto list_it = std::find(letters.begin(), letters.end(), 'c');
    if (list_it != letters.end()) {
        std::cout << "Found 'c' in the list" << std::endl;
    }
    
    int count_c = std::count(letters.begin(), letters.end(), 'c');
    std::cout << "Number of 'c' characters: " << count_c << std::endl;
    
    return 0;
}