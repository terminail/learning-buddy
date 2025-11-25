#include <iostream>
#include <set>
#include <utility>
#include <string>

// Solution: Work with std::pair and multiset containers
int main() {
    // Solution: Create and use std::pair objects
    // Create pairs using different methods
    std::pair<std::string, int> p1("apple", 3);
    auto p2 = std::make_pair("banana", 5);
    std::pair<std::string, int> p3{"apple", 3};  // Same as p1
    
    // Access first and second elements of pairs
    std::cout << "Pair 1: " << p1.first << " -> " << p1.second << std::endl;
    std::cout << "Pair 2: " << p2.first << " -> " << p2.second << std::endl;
    
    // Solution: Create a multiset of pairs to store duplicate pairs
    std::multiset<std::pair<std::string, int>> pair_multiset;
    
    // Solution: Insert pairs into the multiset
    pair_multiset.insert(p1);
    pair_multiset.insert(p2);
    pair_multiset.insert(p3);  // Duplicate of p1
    pair_multiset.insert({"orange", 2});
    pair_multiset.insert({"apple", 3});  // Another duplicate
    
    // Solution: Access and iterate through pairs in the multiset
    // Count occurrences of specific pairs
    std::cout << "Count of (apple, 3): " << pair_multiset.count({"apple", 3}) << std::endl;
    std::cout << "Count of (banana, 5): " << pair_multiset.count({"banana", 5}) << std::endl;
    
    // Find pairs in the multiset
    auto it = pair_multiset.find({"orange", 2});
    if (it != pair_multiset.end()) {
        std::cout << "Found pair: " << it->first << " -> " << it->second << std::endl;
    }
    
    // Iterate through all pairs
    std::cout << "\nAll pairs in multiset:" << std::endl;
    for (const auto& pair : pair_multiset) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
    
    return 0;
}