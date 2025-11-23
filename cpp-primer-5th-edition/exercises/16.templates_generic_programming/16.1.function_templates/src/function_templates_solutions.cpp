// Exercise 16.1a: Function Templates - Solution
// This exercise demonstrates function templates in C++.

#include <iostream>
#include <string>

// Function template for finding the maximum of two values
template<typename T>
T max_value(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Function template with multiple template parameters
template<typename T1, typename T2>
void print_two_values(const T1& first, const T2& second) {
    std::cout << "First: " << first << ", Second: " << second << std::endl;
}

// Template specialization for const char*
template<>
const char* max_value<const char*>(const char* const& a, const char* const& b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}

int main() {
    // Test function template with different types
    std::cout << "Max of 5 and 10: " << max_value(5, 10) << std::endl;
    std::cout << "Max of 3.14 and 2.71: " << max_value(3.14, 2.71) << std::endl;
    std::cout << "Max of 'apple' and 'banana': " << max_value(std::string("apple"), std::string("banana")) << std::endl;
    
    // Test function template with multiple template parameters
    print_two_values(42, "Hello");
    print_two_values(3.14, 100);
    
    // Test template specialization
    const char* result = max_value("xyz", "abc");
    std::cout << "Max of 'xyz' and 'abc': " << result << std::endl;
    
    return 0;
}