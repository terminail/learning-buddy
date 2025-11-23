#include <map>
#include <string>
#include <iostream>

int main() {
    // Solution implementation for multimap basics
    
    // 1. Create empty multimaps
    std::multimap<int, std::string> mm1;
    
    // 2. Initialize multimaps with values
    std::multimap<int, std::string> mm2 = {
        {1, "one"},
        {2, "two"},
        {1, "another one"},
        {3, "three"}
    };
    
    // 3. Use different insertion methods
    mm1.insert({1, "first"});
    mm1.insert(std::make_pair(2, "second"));
    mm1.insert({1, "duplicate"});
    
    // 4. Use iterators to traverse multimaps
    std::cout << "Multimap contents:" << std::endl;
    for (const auto& pair : mm1) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // 5. Find elements with specific keys
    auto range = mm2.equal_range(1);
    std::cout << "Elements with key 1:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    
    // 6. Count occurrences of keys
    std::cout << "Count of key 1: " << mm2.count(1) << std::endl;
    
    // 7. Erase elements by key
    mm1.erase(1);
    std::cout << "After erasing key 1, size: " << mm1.size() << std::endl;
    
    return 0;
}