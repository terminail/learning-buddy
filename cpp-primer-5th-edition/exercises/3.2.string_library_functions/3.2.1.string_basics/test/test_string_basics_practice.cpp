#include <gtest/gtest.h>
#include <string>

// Practice test for string initialization with different constructors
TEST(StringBasicsPractice, InitializationConstructors) {
    // Test initialization with substring
    std::string source = "Hello World";
    std::string substr(source, 6, 5);  // "World"
    EXPECT_EQ("World", substr);
    
    // Test initialization with character array and count
    char char_array[] = "Character Array";
    std::string from_array(char_array, 9);  // "Character"
    EXPECT_EQ("Character", from_array);
    
    // Test move constructor (C++11)
    std::string original = "Move me";
    std::string moved = std::move(original);
    EXPECT_EQ("Move me", moved);
    // original is in valid but unspecified state after move
}

// Practice test for bounds checking
TEST(StringBasicsPractice, BoundsChecking) {
    std::string test = "ABC";
    
    // operator[] does not do bounds checking
    // test[10];  // This would be undefined behavior
    
    // at() does bounds checking and throws exception
    EXPECT_THROW(test.at(10), std::out_of_range);
    
    // Valid access
    EXPECT_NO_THROW(test.at(2));
    EXPECT_EQ('C', test.at(2));
}

// Practice test for string comparison
TEST(StringBasicsPractice, StringComparison) {
    std::string s1 = "Apple";
    std::string s2 = "Banana";
    std::string s3 = "Apple";
    
    // Lexicographical comparison
    EXPECT_TRUE(s1 < s2);
    EXPECT_TRUE(s2 > s1);
    EXPECT_FALSE(s1 > s2);
    
    // Equality
    EXPECT_TRUE(s1 == s3);
    EXPECT_FALSE(s1 == s2);
    
    // Using compare method
    EXPECT_EQ(0, s1.compare(s3));      // Equal
    EXPECT_LT(s1.compare(s2), 0);      // s1 < s2
    EXPECT_GT(s2.compare(s1), 0);      // s2 > s1
}

// Practice test for string limits
TEST(StringBasicsPractice, StringLimits) {
    std::string test = "Test";
    
    // max_size() should be consistent
    auto max1 = test.max_size();
    std::string another = "Another";
    auto max2 = another.max_size();
    
    EXPECT_EQ(max1, max2);
}