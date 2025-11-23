// Exercise: String Basics - Solution
// This exercise demonstrates string creation, initialization, and basic operations in C++.

#include <iostream>
#include <string>

int main() {
    // Solution: Create strings using different initialization methods
    std::string empty_string;                           // Empty string
    std::string literal_string = "Hello";              // Initialize with string literal
    std::string copy_string = literal_string;          // Copy initialization
    std::string substr_string("Hello World", 5);       // Initialize with part of character array
    std::string fill_string(10, 'A');                  // Fill with 10 'A' characters
    std::string char_array_string("C-Style String");   // Initialize with character array

    std::cout << "Empty string: '" << empty_string << "'" << std::endl;
    std::cout << "Literal string: '" << literal_string << "'" << std::endl;
    std::cout << "Copy string: '" << copy_string << "'" << std::endl;
    std::cout << "Substring string: '" << substr_string << "'" << std::endl;
    std::cout << "Fill string: '" << fill_string << "'" << std::endl;
    std::cout << "Char array string: '" << char_array_string << "'" << std::endl;

    // Solution: Work with string capacity and size functions
    std::cout << "\nString sizes:" << std::endl;
    std::cout << "literal_string.size(): " << literal_string.size() << std::endl;
    std::cout << "literal_string.length(): " << literal_string.length() << std::endl;
    std::cout << "empty_string.empty(): " << (empty_string.empty() ? "true" : "false") << std::endl;
    std::cout << "literal_string.empty(): " << (literal_string.empty() ? "true" : "false") << std::endl;
    std::cout << "literal_string.max_size(): " << literal_string.max_size() << std::endl;

    // Solution: Access individual characters in strings
    std::string sample = "Example";
    std::cout << "\nCharacter access:" << std::endl;
    std::cout << "sample[0]: " << sample[0] << std::endl;
    std::cout << "sample.at(1): " << sample.at(1) << std::endl;
    std::cout << "sample.front(): " << sample.front() << std::endl;
    std::cout << "sample.back(): " << sample.back() << std::endl;

    // Solution: Perform basic string operations
    std::string assign_string;
    assign_string = "Assigned value";
    std::string assign_string2("Another value");
    
    std::cout << "\nAssignment operations:" << std::endl;
    std::cout << "assign_string: " << assign_string << std::endl;
    std::cout << "assign_string2: " << assign_string2 << std::endl;
    
    // String equality and basic comparison
    std::cout << "\nString comparisons:" << std::endl;
    std::cout << "literal_string == copy_string: " << (literal_string == copy_string ? "true" : "false") << std::endl;
    std::cout << "literal_string == \"Hello\": " << (literal_string == "Hello" ? "true" : "false") << std::endl;

    return 0;
}