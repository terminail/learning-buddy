#include <set>
#include <string>
#include <iostream>

int main() {
    // Solution implementation for multiset basics
    
    // 1. Create empty multisets
    std::multiset<int> ms1;
    
    // 2. Initialize multisets with values
    std::multiset<int> ms2 = {1, 2, 2, 3, 3, 3, 4};
    
    // 3. Use different insertion methods
    ms1.insert(5);
    ms1.insert(5);  // Duplicate allowed
    ms1.insert(1);
    ms1.insert(3);
    ms1.insert(3);  // Another duplicate
    
    // 4. Use iterators to traverse multisets
    std::cout << "Multiset contents:" << std::endl;
    for (const auto& element : ms1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    // 5. Count occurrences of elements
    std::cout << "Count of 3 in ms1: " << ms1.count(3) << std::endl;
    std::cout << "Count of 5 in ms1: " << ms1.count(5) << std::endl;
    
    // 6. Find elements in multisets
    auto it = ms1.find(3);
    if (it != ms1.end()) {
        std::cout << "Found element 3" << std::endl;
    }
    
    // 7. Erase elements by value
    size_t erased = ms1.erase(3);
    std::cout << "Erased " << erased << " occurrences of 3" << std::endl;
    std::cout << "Count of 3 after erase: " << ms1.count(3) << std::endl;
    
    return 0;
}