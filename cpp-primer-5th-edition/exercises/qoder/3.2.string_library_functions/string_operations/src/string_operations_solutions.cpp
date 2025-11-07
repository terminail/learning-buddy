// Solution 3.2a: String Operations
// This exercise demonstrates common string library functions in C++.

#include <iostream>
#include <string>

int main() {
    // Solution: Create strings and use search functions
    std::string text = "Hello, World! Welcome to C++ Programming!";
    std::cout << "Original text: \"" << text << "\"" << std::endl;
    
    // Use find() to search for substrings
    size_t pos = text.find("World");
    if (pos != std::string::npos) {
        std::cout << "Found 'World' at position: " << pos << std::endl;
    } else {
        std::cout << "'World' not found" << std::endl;
    }
    
    // Use rfind() to search backwards
    pos = text.rfind("o");
    if (pos != std::string::npos) {
        std::cout << "Last 'o' found at position: " << pos << std::endl;
    }
    
    // Search for non-existent substring
    pos = text.find("Java");
    if (pos == std::string::npos) {
        std::cout << "'Java' not found (pos == npos)" << std::endl;
    }
    
    // Solution: Extract substrings from strings
    std::string substring1 = text.substr(7, 5);  // Extract 5 characters starting at position 7
    std::cout << "Substring from position 7, length 5: \"" << substring1 << "\"" << std::endl;
    
    std::string substring2 = text.substr(13);    // Extract from position 13 to end
    std::cout << "Substring from position 13 to end: \"" << substring2 << "\"" << std::endl;
    
    // Handle out-of-bounds substring operations
    try {
        std::string substring3 = text.substr(100, 5);  // This will throw an exception
        std::cout << "This won't be printed" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range error when extracting substring: " << e.what() << std::endl;
    }
    
    // Solution: Compare strings using different methods
    std::string str1 = "apple";
    std::string str2 = "banana";
    std::string str3 = "apple";
    
    // Use comparison operators
    if (str1 == str3) {
        std::cout << "\"" << str1 << "\" equals \"" << str3 << "\"" << std::endl;
    }
    
    if (str1 < str2) {
        std::cout << "\"" << str1 << "\" comes before \"" << str2 << "\" lexicographically" << std::endl;
    }
    
    // Use compare() method
    int result = str1.compare(str2);
    if (result < 0) {
        std::cout << "\"" << str1 << "\" comes before \"" << str2 << "\" (compare result: " << result << ")" << std::endl;
    } else if (result > 0) {
        std::cout << "\"" << str1 << "\" comes after \"" << str2 << "\" (compare result: " << result << ")" << std::endl;
    } else {
        std::cout << "\"" << str1 << "\" equals \"" << str2 << "\" (compare result: " << result << ")" << std::endl;
    }
    
    // Solution: Modify strings using replacement functions
    std::string modify_text = "Hello, World!";
    std::cout << "Before replacement: \"" << modify_text << "\"" << std::endl;
    
    // Use replace() to substitute parts of strings
    modify_text.replace(7, 5, "C++");  // Replace 5 characters starting at position 7 with "C++"
    std::cout << "After replacing 'World' with 'C++': \"" << modify_text << "\"" << std::endl;
    
    // Use erase() to remove parts of strings
    modify_text.erase(5, 2);  // Remove 2 characters starting at position 5
    std::cout << "After erasing characters at position 5, length 2: \"" << modify_text << "\"" << std::endl;
    
    // Solution: Work with string conversion functions
    // Use std::to_string() to convert numbers to strings
    int num = 42;
    double pi = 3.14159;
    std::string num_str = std::to_string(num);
    std::string pi_str = std::to_string(pi);
    std::cout << "Integer " << num << " as string: \"" << num_str << "\"" << std::endl;
    std::cout << "Double " << pi << " as string: \"" << pi_str << "\"" << std::endl;
    
    // Use std::stoi(), std::stof() to convert strings to numbers
    std::string int_str = "123";
    std::string float_str = "45.67";
    
    try {
        int converted_int = std::stoi(int_str);
        float converted_float = std::stof(float_str);
        std::cout << "String \"" << int_str << "\" as integer: " << converted_int << std::endl;
        std::cout << "String \"" << float_str << "\" as float: " << converted_float << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    }
    
    // Handle conversion errors
    std::string invalid_str = "abc";
    try {
        int invalid_int = std::stoi(invalid_str);
        std::cout << "This won't be printed" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Cannot convert \"" << invalid_str << "\" to integer: " << e.what() << std::endl;
    }
    
    return 0;
}