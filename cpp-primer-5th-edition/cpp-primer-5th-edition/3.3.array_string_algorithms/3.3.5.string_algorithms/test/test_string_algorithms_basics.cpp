#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <numeric>

// Test std::replace and std::replace_if
TEST(StringAlgorithmsTest, ReplaceFunctions) {
    std::string text = "Hello, World!";
    
    // Test std::replace
    std::replace(text.begin(), text.end(), 'o', 'O');
    EXPECT_EQ("HellO, WOrld!", text);
    
    // Test std::replace_if
    std::replace_if(text.begin(), text.end(), 
                    [](char c) { return c == 'l'; }, 'L');
    EXPECT_EQ("HeLLO, WOrLd!", text);
    
    // Test with digits
    std::string digits = "abc123def456";
    std::replace_if(digits.begin(), digits.end(),
                    [](char c) { return std::isdigit(c); }, 'X');
    EXPECT_EQ("abcXXXdefXXX", digits);
}

// Test std::transform for string processing
TEST(StringAlgorithmsTest, TransformFunctions) {
    std::string text = "Hello";
    
    // Test uppercase transformation
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    EXPECT_EQ("HELLO", text);
    
    // Test lowercase transformation
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    EXPECT_EQ("hello", text);
    
    // Test custom transformation
    std::transform(text.begin(), text.end(), text.begin(),
                   [](char c) -> char {
                       return c + 1;  // Shift each character by 1
                   });
    EXPECT_EQ("ifmmp", text);
}

// Test text processing algorithms
TEST(StringAlgorithmsTest, TextProcessing) {
    std::string text = "  Hello   World  ";
    
    // Test removing leading whitespace
    text.erase(text.begin(), 
               std::find_if(text.begin(), text.end(), 
                           [](char c) { return !std::isspace(c); }));
    EXPECT_EQ("Hello   World  ", text);
    
    // Test removing trailing whitespace
    text.erase(std::find_if(text.rbegin(), text.rend(),
                           [](char c) { return !std::isspace(c); }).base(),
               text.end());
    EXPECT_EQ("Hello   World", text);
    
    // Test removing consecutive spaces
    std::string::iterator new_end = std::unique(text.begin(), text.end(),
                                               [](char lhs, char rhs) {
                                                   return (lhs == rhs) && (lhs == ' ');
                                               });
    text.erase(new_end, text.end());
    EXPECT_EQ("Hello World", text);
}

// Test accumulate with strings
TEST(StringAlgorithmsTest, AccumulateFunctions) {
    std::vector<std::string> words = {"Hello", " ", "World", "!"};
    
    // Test concatenation
    std::string result = std::accumulate(words.begin(), words.end(), std::string(""));
    EXPECT_EQ("Hello World!", result);
    
    // Test with custom operation
    std::string separated = std::accumulate(words.begin(), words.end(), std::string(""),
                                           [](const std::string& a, const std::string& b) {
                                               return a + (a.empty() ? "" : "|") + b;
                                           });
    EXPECT_EQ("Hello| |World|!", separated);
}