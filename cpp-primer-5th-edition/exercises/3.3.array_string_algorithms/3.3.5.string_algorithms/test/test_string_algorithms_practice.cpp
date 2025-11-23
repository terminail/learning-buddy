#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <random>

// Practice test for advanced string processing
TEST(StringAlgorithmsPractice, AdvancedProcessing) {
    // Test complex text transformation
    std::string text = "Hello, World! Welcome to C++ Programming.";
    
    // Convert to title case (first letter of each word capitalized)
    bool capitalize_next = true;
    std::transform(text.begin(), text.end(), text.begin(),
                   [&capitalize_next](char c) -> char {
                       if (std::isalpha(c)) {
                           if (capitalize_next) {
                               capitalize_next = false;
                               return std::toupper(c);
                           } else {
                               return std::tolower(c);
                           }
                       } else {
                           if (std::isspace(c)) {
                               capitalize_next = true;
                           }
                           return c;
                       }
                   });
    
    // Check that first letters are capitalized
    EXPECT_EQ('H', text[0]);
    EXPECT_EQ('W', text[7]);  // 'W' in "World"
    EXPECT_EQ('W', text[15]); // 'W' in "Welcome"
    
    // Test word filtering
    std::vector<std::string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    
    // Remove words shorter than 5 characters
    auto new_end = std::remove_if(words.begin(), words.end(),
                                  [](const std::string& s) { return s.length() < 5; });
    words.erase(new_end, words.end());
    
    EXPECT_EQ(3, words.size());
    EXPECT_EQ("apple", words[0]);
    EXPECT_EQ("banana", words[1]);
    EXPECT_EQ("elderberry", words[2]);
    
    // Test string sorting by length
    std::sort(words.begin(), words.end(),
              [](const std::string& a, const std::string& b) {
                  return a.length() < b.length();
              });
    
    EXPECT_EQ("apple", words[0]);      // 5 characters
    EXPECT_EQ("banana", words[1]);     // 6 characters
    EXPECT_EQ("elderberry", words[2]); // 10 characters
}

// Practice test for performance with large strings
TEST(StringAlgorithmsPractice, PerformanceWithLargeStrings) {
    // Create a large string
    std::string large_text(10000, 'a');
    
    // Replace every 10th character with 'b'
    auto start = std::chrono::high_resolution_clock::now();
    std::replace_if(large_text.begin(), large_text.end(),
                    [i = 0](char c) mutable { return (++i % 10) == 0; }, 'b');
    auto end = std::chrono::high_resolution_clock::now();
    auto replace_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Verify replacement worked
    int b_count = std::count(large_text.begin(), large_text.end(), 'b');
    EXPECT_EQ(1000, b_count);  // 10000 / 10 = 1000
    
    // Test transformation performance
    start = std::chrono::high_resolution_clock::now();
    std::transform(large_text.begin(), large_text.end(), large_text.begin(), ::toupper);
    end = std::chrono::high_resolution_clock::now();
    auto transform_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Verify transformation worked
    int uppercase_count = std::count(large_text.begin(), large_text.end(), 'B');
    EXPECT_EQ(1000, uppercase_count);
    
    std::cout << "Replace time: " << replace_duration.count() << " microseconds" << std::endl;
    std::cout << "Transform time: " << transform_duration.count() << " microseconds" << std::endl;
}

// Practice test for edge cases and error handling
TEST(StringAlgorithmsPractice, EdgeCases) {
    // Test with empty string
    std::string empty;
    std::replace(empty.begin(), empty.end(), 'a', 'b');
    EXPECT_TRUE(empty.empty());
    
    std::transform(empty.begin(), empty.end(), empty.begin(), ::toupper);
    EXPECT_TRUE(empty.empty());
    
    // Test with single character
    std::string single = "a";
    std::replace(single.begin(), single.end(), 'a', 'b');
    EXPECT_EQ("b", single);
    
    std::transform(single.begin(), single.end(), single.begin(), ::toupper);
    EXPECT_EQ("B", single);
    
    // Test with special characters
    std::string special = "!@#$%^&*()";
    std::replace_if(special.begin(), special.end(),
                    [](char c) { return c == '!'; }, '?');
    EXPECT_EQ("?@#$%^&*()", special);
    
    // Test with unicode-like characters (extended ASCII)
    std::string extended = "café";
    std::transform(extended.begin(), extended.end(), extended.begin(), ::toupper);
    // Note: This may not work perfectly with multi-byte characters, but it's a basic test
    EXPECT_FALSE(extended.empty());
    
    // Test accumulate with empty vector
    std::vector<std::string> empty_vec;
    std::string result = std::accumulate(empty_vec.begin(), empty_vec.end(), std::string("default"));
    EXPECT_EQ("default", result);
    
    // Test accumulate with single element
    std::vector<std::string> single_vec = {"Hello"};
    result = std::accumulate(single_vec.begin(), single_vec.end(), std::string(""));
    EXPECT_EQ("Hello", result);
}