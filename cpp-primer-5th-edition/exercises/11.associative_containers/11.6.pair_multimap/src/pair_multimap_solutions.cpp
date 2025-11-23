#include <iostream>
#include <map>
#include <string>
#include <vector>

// Solution: Work with std::pair and multimap containers
int main() {
    // Solution: Create and use std::pair objects
    // Create pairs using different methods
    std::pair<std::string, int> p1("apple", 3);
    auto p2 = std::make_pair("banana", 5);
    std::pair<std::string, int> p3{"orange", 2};
    
    // Access first and second elements of pairs
    std::cout << "Pair 1: " << p1.first << " -> " << p1.second << std::endl;
    std::cout << "Pair 2: " << p2.first << " -> " << p2.second << std::endl;
    
    // Solution: Create a multimap to store multiple values for the same key
    std::multimap<std::string, int> family_children;
    
    // Solution: Insert elements into the multimap using pairs
    family_children.insert(p1);
    family_children.insert(p2);
    family_children.insert(p3);
    family_children.insert({"Smith", 2});
    family_children.insert({"Smith", 4});
    family_children.insert({"Smith", 1});
    
    // Solution: Access and iterate through elements in the multimap
    // Find all values for a specific key
    std::string search_key = "Smith";
    auto range = family_children.equal_range(search_key);
    
    std::cout << "Children in " << search_key << " family:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "  " << it->second << " children" << std::endl;
    }
    
    // Iterate through all elements
    std::cout << "\nAll families:" << std::endl;
    for (const auto& entry : family_children) {
        std::cout << entry.first << ": " << entry.second << " children" << std::endl;
    }
    
    return 0;
}