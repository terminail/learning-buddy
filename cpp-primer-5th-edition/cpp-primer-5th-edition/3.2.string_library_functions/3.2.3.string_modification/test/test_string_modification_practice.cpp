#include <gtest/gtest.h>
#include <string>

// Practice test for advanced modification scenarios
TEST(StringModificationPractice, AdvancedScenarios) {
    // Test replace with iterators
    std::string text = "Hello World";
    text.replace(text.begin() + 6, text.begin() + 11, "C++");
    EXPECT_EQ("Hello C++", text);
    
    // Test erase with iterators
    text.erase(text.begin() + 5, text.end());
    EXPECT_EQ("Hello", text);
    
    // Test insert with iterators
    std::string insert_text = "Hi";
    insert_text.insert(insert_text.end(), {' ', 't', 'h', 'e', 'r', 'e'});
    EXPECT_EQ("Hi there", insert_text);
}

// Practice test for exception handling
TEST(StringModificationPractice, ExceptionHandling) {
    std::string text = "Test";
    
    // Test out of range for replace
    EXPECT_THROW(text.replace(10, 5, "Error"), std::out_of_range);
    
    // Test out of range for erase
    EXPECT_THROW(text.erase(10, 5), std::out_of_range);
    
    // Test out of range for insert
    EXPECT_THROW(text.insert(10, "Error"), std::out_of_range);
}

// Practice test for performance considerations
TEST(StringModificationPractice, PerformanceConsiderations) {
    std::string text = "Hello";
    
    // Reserve space to avoid multiple reallocations
    text.reserve(100);
    
    // Multiple modifications
    for (int i = 0; i < 10; i++) {
        text += " World";
    }
    
    EXPECT_EQ("Hello World World World World World World World World World World", text);
    
    // Test capacity management
    EXPECT_GE(text.capacity(), 100);
}