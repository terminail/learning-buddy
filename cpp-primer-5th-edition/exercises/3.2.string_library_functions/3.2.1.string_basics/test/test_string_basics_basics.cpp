#include <gtest/gtest.h>
#include <string>

// Test string creation methods
TEST(StringBasicsTest, StringCreation) {
    // Test empty string creation
    std::string empty;
    EXPECT_TRUE(empty.empty());
    EXPECT_EQ(0, empty.size());
    
    // Test string literal initialization
    std::string literal = "Hello";
    EXPECT_FALSE(literal.empty());
    EXPECT_EQ(5, literal.size());
    EXPECT_EQ("Hello", literal);
    
    // Test copy initialization
    std::string copy = literal;
    EXPECT_EQ(literal, copy);
    
    // Test fill initialization
    std::string fill(5, 'A');
    EXPECT_EQ("AAAAA", fill);
}

// Test string size and capacity functions
TEST(StringBasicsTest, SizeAndCapacity) {
    std::string test = "Hello World";
    
    EXPECT_EQ(11, test.size());
    EXPECT_EQ(11, test.length());
    EXPECT_FALSE(test.empty());
    
    // max_size() should be a large number
    EXPECT_GT(test.max_size(), 1000000);
}

// Test character access
TEST(StringBasicsTest, CharacterAccess) {
    std::string test = "Example";
    
    // Test operator[]
    EXPECT_EQ('E', test[0]);
    EXPECT_EQ('e', test[6]);
    
    // Test at() method
    EXPECT_EQ('E', test.at(0));
    EXPECT_EQ('e', test.at(6));
    
    // Test front() and back()
    EXPECT_EQ('E', test.front());
    EXPECT_EQ('e', test.back());
}

// Test assignment operations
TEST(StringBasicsTest, AssignmentOperations) {
    std::string s1, s2;
    
    s1 = "Hello";
    EXPECT_EQ("Hello", s1);
    
    s2 = s1;
    EXPECT_EQ("Hello", s2);
    EXPECT_EQ(s1, s2);
}