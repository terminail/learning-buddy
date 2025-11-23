#include <gtest/gtest.h>
#include <string>

// Practice test for advanced searching scenarios
TEST(StringSearchingPractice, AdvancedScenarios) {
    // Test case sensitivity
    std::string text = "Hello World";
    size_t pos = text.find("hello");  // Case sensitive search
    EXPECT_EQ(std::string::npos, pos);
    
    pos = text.find("Hello");
    EXPECT_EQ(0, pos);
    
    // Test searching with empty strings
    std::string data = "Test";
    pos = data.find("");  // Finding empty string
    EXPECT_EQ(0, pos);  // Always found at position 0
    
    // Test searching beyond string length
    pos = data.find("Test", 10);  // Start position beyond string
    EXPECT_EQ(std::string::npos, pos);
}

// Practice test for character set searching
TEST(StringSearchingPractice, CharacterSetSearching) {
    std::string text = "abc123def456";
    
    // Find first vowel
    size_t pos = text.find_first_of("aeiouAEIOU");
    EXPECT_EQ(0, pos);  // 'a' is first vowel
    
    // Find last vowel
    pos = text.find_last_of("aeiouAEIOU");
    EXPECT_EQ(7, pos);  // 'e' is last vowel
    
    // Find first consonant
    pos = text.find_first_not_of("aeiouAEIOU0123456789");
    EXPECT_EQ(1, pos);  // 'b' is first consonant
    
    // Find last consonant
    pos = text.find_last_not_of("aeiouAEIOU0123456789");
    EXPECT_EQ(8, pos);  // 'f' is last consonant
}

// Practice test for error handling
TEST(StringSearchingPractice, ErrorHandling) {
    std::string empty;
    
    // Searching in empty string
    size_t pos = empty.find("test");
    EXPECT_EQ(std::string::npos, pos);
    
    // Searching for empty string in empty string
    pos = empty.find("");
    EXPECT_EQ(0, pos);
    
    // All find functions should return npos for empty string when searching for non-empty
    pos = empty.find_first_of("abc");
    EXPECT_EQ(std::string::npos, pos);
    
    pos = empty.find_last_of("abc");
    EXPECT_EQ(std::string::npos, pos);
}