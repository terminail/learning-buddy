// Exercise: String-Specific Algorithms - Solution
// This exercise demonstrates string-specific algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <numeric>

int main() {
    // Solution: Use std::replace and std::replace_if
    std::string text = "Hello, World! Welcome to C++ Programming!";
    std::cout << "Original text: " << text << std::endl;
    
    // Replace all 'o' characters with 'O'
    std::replace(text.begin(), text.end(), 'o', 'O');
    std::cout << "After replacing 'o' with 'O': " << text << std::endl;
    
    // Replace spaces with underscores using replace_if
    std::replace_if(text.begin(), text.end(), 
                    [](char c) { return c == ' '; }, '_');
    std::cout << "After replacing spaces with '_': " << text << std::endl;
    
    // Replace digits with 'X' using replace_if
    std::string with_digits = "Price: $123.45";
    std::replace_if(with_digits.begin(), with_digits.end(),
                    [](char c) { return std::isdigit(c); }, 'X');
    std::cout << "After replacing digits with 'X': " << with_digits << std::endl;

    // Solution: Use std::transform for string processing
    std::string message = "Hello World";
    std::cout << "Original message: " << message << std::endl;
    
    // Convert to uppercase
    std::transform(message.begin(), message.end(), message.begin(), ::toupper);
    std::cout << "Uppercase: " << message << std::endl;
    
    // Convert to lowercase
    std::transform(message.begin(), message.end(), message.begin(), ::tolower);
    std::cout << "Lowercase: " << message << std::endl;
    
    // Custom transformation - swap case
    std::transform(message.begin(), message.end(), message.begin(),
                   [](char c) -> char {
                       if (std::islower(c)) return std::toupper(c);
                       if (std::isupper(c)) return std::tolower(c);
                       return c;
                   });
    std::cout << "Swapped case: " << message << std::endl;

    // Solution: Work with text processing algorithms
    std::string sentence = "  Hello,   World!  Welcome   to   C++!  ";
    std::cout << "Original sentence: '" << sentence << "'" << std::endl;
    
    // Remove leading whitespace
    sentence.erase(sentence.begin(), 
                   std::find_if(sentence.begin(), sentence.end(), 
                               [](char c) { return !std::isspace(c); }));
    std::cout << "After removing leading whitespace: '" << sentence << "'" << std::endl;
    
    // Remove trailing whitespace
    sentence.erase(std::find_if(sentence.rbegin(), sentence.rend(),
                               [](char c) { return !std::isspace(c); }).base(),
                   sentence.end());
    std::cout << "After removing trailing whitespace: '" << sentence << "'" << std::endl;
    
    // Remove extra spaces between words
    std::string::iterator new_end = std::unique(sentence.begin(), sentence.end(),
                                               [](char lhs, char rhs) {
                                                   return (lhs == rhs) && (lhs == ' ');
                                               });
    sentence.erase(new_end, sentence.end());
    std::cout << "After removing extra spaces: '" << sentence << "'" << std::endl;

    // Solution: Use std::accumulate and related algorithms with strings
    std::vector<std::string> words = {"Hello", " ", "World", "!", " ", "Welcome", " ", "to", " ", "C++", "!"};
    
    // Concatenate all strings
    std::string result = std::accumulate(words.begin(), words.end(), std::string(""));
    std::cout << "Concatenated result: " << result << std::endl;
    
    // Concatenate with separator
    std::string separated = std::accumulate(words.begin(), words.end(), std::string(""),
                                           [](const std::string& a, const std::string& b) {
                                               return a + (a.empty() ? "" : " ") + b;
                                           });
    std::cout << "Separated result: " << separated << std::endl;
    
    // Count total characters
    size_t total_chars = std::accumulate(words.begin(), words.end(), 0,
                                        [](size_t sum, const std::string& s) {
                                            return sum + s.length();
                                        });
    std::cout << "Total characters: " << total_chars << std::endl;
    
    return 0;
}