#include <gtest/gtest.h>
#include <string>

// Practice test for string construction
TEST(StringBasicsPractice, StringConstruction) {
    // Default constructor
    std::string empty;
    EXPECT_TRUE(empty.empty());
    EXPECT_EQ(0, empty.size());
    
    // Constructor with string literal
    std::string hello = "Hello";
    EXPECT_EQ(5, hello.size());
    EXPECT_EQ("Hello", hello);
    
    // Constructor with count and character
    std::string stars(5, '*');
    EXPECT_EQ("*****", stars);
    
    // Copy constructor
    std::string copy(hello);
    EXPECT_EQ(hello, copy);
    
    // Constructor with substring
    std::string sub(hello, 1, 3);  // "ell"
    EXPECT_EQ("ell", sub);
}

// Practice test for string assignment
TEST(StringBasicsPractice, StringAssignment) {
    std::string s1 = "Hello";
    std::string s2;
    
    // Assignment operator
    s2 = s1;
    EXPECT_EQ(s1, s2);
    
    // Assignment with string literal
    s2 = "World";
    EXPECT_EQ("World", s2);
    
    // Assignment with character
    s2 = 'A';
    EXPECT_EQ("A", s2);
}

// Practice test for string access
TEST(StringBasicsPractice, StringAccess) {
    std::string test = "ABC";
    
    // operator[] does not do bounds checking
    // char c = test[10];  // This would be undefined behavior
    
    // at() does bounds checking and throws exception
    EXPECT_THROW({
        try {
            (void)test.at(10);  // Explicitly cast to void to ignore return value
        } catch (const std::out_of_range&) {
            throw;  // Re-throw to be caught by EXPECT_THROW
        }
    }, std::out_of_range);
    
    // Valid access
    EXPECT_NO_THROW({
        char c = test.at(2);
        EXPECT_EQ('C', c);
    });
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}