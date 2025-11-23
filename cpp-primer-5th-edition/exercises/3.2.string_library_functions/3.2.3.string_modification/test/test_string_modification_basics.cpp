#include <gtest/gtest.h>
#include <string>

// Test replace() function
TEST(StringModificationTest, ReplaceFunction) {
    std::string text = "Hello, World!";
    
    // Test replace substring
    text.replace(7, 5, "C++");
    EXPECT_EQ("Hello, C++!", text);
    
    // Test replace with different length
    text.replace(0, 5, "Hi");
    EXPECT_EQ("Hi, C++!", text);
    
    // Test replace single character
    text.replace(2, 1, 1, '!');
    EXPECT_EQ("Hi! C++!", text);
}

// Test erase() function
TEST(StringModificationTest, EraseFunction) {
    std::string text = "The quick brown fox";
    
    // Test erase substring
    text.erase(4, 5);  // Erase "quick"
    EXPECT_EQ("The  brown fox", text);
    
    // Test erase single character
    text.erase(3, 1);  // Erase space
    EXPECT_EQ("The brown fox", text);
    
    // Test erase to end
    text.erase(8);
    EXPECT_EQ("The brown", text);
}

// Test insert() function
TEST(StringModificationTest, InsertFunction) {
    std::string text = "Hello World";
    
    // Test insert string
    text.insert(6, "Beautiful ");
    EXPECT_EQ("Hello Beautiful World", text);
    
    // Test insert characters
    text.insert(0, 2, '>');
    EXPECT_EQ(">>Hello Beautiful World", text);
}

// Test append() and += operations
TEST(StringModificationTest, AppendOperations) {
    std::string text = "Hello";
    
    // Test append string
    text.append(" World");
    EXPECT_EQ("Hello World", text);
    
    // Test += operator
    text += "!";
    EXPECT_EQ("Hello World!", text);
    
    // Test append multiple characters
    text.append(2, '!');
    EXPECT_EQ("Hello World!!!", text);
}