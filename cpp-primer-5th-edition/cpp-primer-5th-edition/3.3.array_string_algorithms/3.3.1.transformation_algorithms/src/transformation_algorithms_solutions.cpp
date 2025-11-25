// Exercise: Transformation Algorithms - Solution
// This exercise demonstrates transformation algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

// Custom transformation function
int square(int x) {
    return x * x;
}

// Function object (functor)
struct MultiplyBy {
    int factor;
    MultiplyBy(int f) : factor(f) {}
    int operator()(int x) const {
        return x * factor;
    }
};

int main() {
    // Solution: Use std::transform with function pointers
    std::vector<char> chars = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> upper_chars(chars.size());
    
    // Convert to uppercase
    std::transform(chars.begin(), chars.end(), upper_chars.begin(), ::toupper);
    
    std::cout << "Original: ";
    for (char c : chars) std::cout << c;
    std::cout << std::endl;
    
    std::cout << "Uppercase: ";
    for (char c : upper_chars) std::cout << c;
    std::cout << std::endl;

    // Solution: Use std::transform with lambda functions
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> squares(numbers.size());
    
    // Square each element using lambda
    std::transform(numbers.begin(), numbers.end(), squares.begin(), 
                   [](int n) { return n * n; });
    
    std::cout << "Numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "Squares: ";
    for (int n : squares) std::cout << n << " ";
    std::cout << std::endl;

    // Solution: Use std::transform with custom functions
    std::vector<int> values = {10, 20, 30, 40, 50};
    std::vector<int> doubled(values.size());
    
    // Use custom function
    std::transform(values.begin(), values.end(), doubled.begin(), square);
    
    std::cout << "Values: ";
    for (int n : values) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "Squared: ";
    for (int n : doubled) std::cout << n << " ";
    std::cout << std::endl;
    
    // Use function object
    std::vector<int> multiplied(values.size());
    std::transform(values.begin(), values.end(), multiplied.begin(), MultiplyBy(3));
    
    std::cout << "Multiplied by 3: ";
    for (int n : multiplied) std::cout << n << " ";
    std::cout << std::endl;

    // Solution: Work with string transformations
    std::string text = "Hello World";
    
    // Convert to lowercase
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    std::cout << "Lowercase: " << text << std::endl;
    
    // Capitalize first letter of each word
    text[0] = std::toupper(text[0]);
    for (size_t i = 1; i < text.length(); ++i) {
        if (text[i-1] == ' ') {
            text[i] = std::toupper(text[i]);
        }
    }
    std::cout << "Capitalized: " << text << std::endl;
    
    return 0;
}