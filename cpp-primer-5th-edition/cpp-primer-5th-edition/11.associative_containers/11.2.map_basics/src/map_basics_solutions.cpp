#include <iostream>
#include <map>
#include <string>

// Solution: Work with map container basics
int main() {
    // Solution: Create a map to store word counts (string -> int)
    std::map<std::string, int> word_count;
    
    // Solution: Add some words to the map using different insertion methods
    // Using subscript operator []
    word_count["apple"] = 3;
    word_count["banana"] = 5;
    
    // Using insert() method
    word_count.insert({"orange", 2});
    word_count.insert(std::make_pair("grape", 7));
    
    // Solution: Access and display values for specific keys
    std::cout << "Apple count: " << word_count["apple"] << std::endl;
    std::cout << "Banana count: " << word_count.at("banana") << std::endl;
    
    // Solution: Iterate through the map and print all key-value pairs
    std::cout << "All word counts:" << std::endl;
    for (const auto& pair : word_count) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    return 0;
}