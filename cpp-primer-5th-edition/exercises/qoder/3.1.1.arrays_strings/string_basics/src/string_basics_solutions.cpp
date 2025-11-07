// Solution 3.1.1b: String Basics
// This exercise demonstrates std::string in C++.

#include <iostream>
#include <string>

int main() {
    // Solution: Declare and initialize strings in different ways
    std::string empty_str;                           // Empty string
    std::string hello_str = "Hello";                 // Initialize with literal
    std::string world_str("World");                  // Initialize with constructor
    std::string copy_str = hello_str;                // Initialize with another string
    
    std::cout << "Empty string: '" << empty_str << "'" << std::endl;
    std::cout << "Hello string: '" << hello_str << "'" << std::endl;
    std::cout << "World string: '" << world_str << "'" << std::endl;
    std::cout << "Copy string: '" << copy_str << "'" << std::endl;
    
    // Solution: Access and print individual characters of a string
    std::string sample = "C++ Programming";
    std::cout << "Characters in '" << sample << "':" << std::endl;
    for (size_t i = 0; i < sample.length(); i++) {
        std::cout << "sample[" << i << "] = '" << sample[i] << "'" << std::endl;
    }
    
    // Using at() method with bounds checking
    try {
        std::cout << "First character using at(): '" << sample.at(0) << "'" << std::endl;
        std::cout << "Last character using at(): '" << sample.at(sample.length() - 1) << "'" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    }
    
    // Solution: Concatenate strings using different methods
    std::string result1 = hello_str + " " + world_str;  // Using + operator
    std::cout << "Concatenated with +: '" << result1 << "'" << std::endl;
    
    std::string result2 = hello_str;
    result2 += " C++";                                  // Using += operator
    std::cout << "Appended with +=: '" << result2 << "'" << std::endl;
    
    std::string result3 = hello_str;
    result3.append(" Students");                        // Using append() method
    std::cout << "Appended with append(): '" << result3 << "'" << std::endl;
    
    // Solution: Get and print string information
    std::cout << "Length of '" << result1 << "': " << result1.length() << std::endl;
    std::cout << "Size of '" << result1 << "': " << result1.size() << std::endl;
    std::cout << "Is empty string empty? " << (empty_str.empty() ? "Yes" : "No") << std::endl;
    if (!result1.empty()) {
        std::cout << "First character: '" << result1.front() << "'" << std::endl;
        std::cout << "Last character: '" << result1.back() << "'" << std::endl;
    }
    
    // Solution: Modify strings
    std::string modify_str = "Original";
    std::cout << "Before modification: '" << modify_str << "'" << std::endl;
    
    modify_str.assign("New Content");                   // Replace entire content
    std::cout << "After assign(): '" << modify_str << "'" << std::endl;
    
    modify_str.insert(4, " Great");                     // Insert at position 4
    std::cout << "After insert(): '" << modify_str << "'" << std::endl;
    
    modify_str.erase(4, 6);                             // Remove 6 characters from position 4
    std::cout << "After erase(): '" << modify_str << "'" << std::endl;
    
    return 0;
}