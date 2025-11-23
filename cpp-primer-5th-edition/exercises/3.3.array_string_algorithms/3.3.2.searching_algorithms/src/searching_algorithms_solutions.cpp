// Exercise: Searching Algorithms - Solution
// This exercise demonstrates searching algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    // Solution: Use std::find and std::find_if
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    
    // Find specific value
    auto it = std::find(numbers.begin(), numbers.end(), 30);
    if (it != numbers.end()) {
        std::cout << "Found 30 at position: " << (it - numbers.begin()) << std::endl;
    } else {
        std::cout << "30 not found" << std::endl;
    }
    
    // Find with predicate (find first even number)
    auto even_it = std::find_if(numbers.begin(), numbers.end(), 
                                [](int n) { return n % 2 == 0; });
    if (even_it != numbers.end()) {
        std::cout << "First even number: " << *even_it << std::endl;
    }
    
    // Find with predicate (find number > 35)
    auto greater_it = std::find_if(numbers.begin(), numbers.end(),
                                   [](int n) { return n > 35; });
    if (greater_it != numbers.end()) {
        std::cout << "First number > 35: " << *greater_it << std::endl;
    }

    // Solution: Use std::count and std::count_if
    std::vector<int> repeated = {1, 2, 2, 3, 2, 4, 2, 5};
    
    // Count occurrences of 2
    int count = std::count(repeated.begin(), repeated.end(), 2);
    std::cout << "Count of 2: " << count << std::endl;
    
    // Count even numbers
    int even_count = std::count_if(repeated.begin(), repeated.end(),
                                   [](int n) { return n % 2 == 0; });
    std::cout << "Count of even numbers: " << even_count << std::endl;
    
    // Count numbers greater than 3
    int greater_count = std::count_if(repeated.begin(), repeated.end(),
                                      [](int n) { return n > 3; });
    std::cout << "Count of numbers > 3: " << greater_count << std::endl;

    // Solution: Use std::binary_search and related functions
    std::vector<int> sorted = {10, 20, 30, 40, 50, 60, 70};
    
    // Binary search for existing value
    bool found = std::binary_search(sorted.begin(), sorted.end(), 40);
    std::cout << "Binary search for 40: " << (found ? "Found" : "Not found") << std::endl;
    
    // Binary search for non-existing value
    found = std::binary_search(sorted.begin(), sorted.end(), 35);
    std::cout << "Binary search for 35: " << (found ? "Found" : "Not found") << std::endl;
    
    // Lower bound (first element >= 35)
    auto lower = std::lower_bound(sorted.begin(), sorted.end(), 35);
    if (lower != sorted.end()) {
        std::cout << "Lower bound of 35: " << *lower << std::endl;
    }
    
    // Upper bound (first element > 35)
    auto upper = std::upper_bound(sorted.begin(), sorted.end(), 35);
    if (upper != sorted.end()) {
        std::cout << "Upper bound of 35: " << *upper << std::endl;
    }

    // Solution: Work with string searching algorithms
    std::string text = "Hello, World! Welcome to C++ Programming!";
    
    // Search for substring
    auto str_it = std::search(text.begin(), text.end(), 
                              std::boyer_moore_searcher(std::string("World")));
    if (str_it != text.end()) {
        std::cout << "Found 'World' at position: " << (str_it - text.begin()) << std::endl;
    }
    
    // Find end (last occurrence)
    auto end_it = std::find_end(text.begin(), text.end(), 
                                std::string("o").begin(), std::string("o").end());
    if (end_it != text.end()) {
        std::cout << "Last 'o' at position: " << (end_it - text.begin()) << std::endl;
    }
    
    return 0;
}