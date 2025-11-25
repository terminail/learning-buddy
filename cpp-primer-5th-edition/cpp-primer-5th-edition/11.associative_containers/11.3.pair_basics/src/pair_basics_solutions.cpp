#include <utility>
#include <string>
#include <iostream>

int main() {
    // Solution implementation for pair basics
    // 1. Create pairs using different initialization methods
    std::pair<int, double> p1(1, 3.14);
    std::pair<std::string, int> p2{"hello", 42};
    auto p3 = std::make_pair(2.5f, 'A');
    
    // 2. Access first and second elements
    std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;
    std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;
    
    // 3. Compare pairs using relational operators
    std::pair<int, int> p4(1, 2);
    std::pair<int, int> p5(1, 3);
    std::cout << "p4 < p5: " << (p4 < p5) << std::endl;
    
    // 4. Assign values to pair elements
    p1.first = 10;
    p1.second = 2.71;
    std::cout << "Modified p1: " << p1.first << ", " << p1.second << std::endl;
    
    // 5. Use pairs as return values from functions
    // 6. Access key-value pairs from map iterators
    // 7. Use pairs as elements in vector<pair>
    
    return 0;
}