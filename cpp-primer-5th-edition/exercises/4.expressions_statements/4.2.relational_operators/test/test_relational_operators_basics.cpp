#include <gtest/gtest.h>
#include <string>

// Test equality operators
TEST(RelationalOperatorsTest, EqualityOperators) {
    int a = 10;
    int b = 20;
    int c = 10;
    
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a == c);
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a != c);
}

// Test relational operators
TEST(RelationalOperatorsTest, RelationalOperators) {
    int x = 5;
    int y = 10;
    
    EXPECT_TRUE(x < y);
    EXPECT_FALSE(x > y);
    EXPECT_TRUE(x <= y);
    EXPECT_FALSE(x >= y);
    EXPECT_TRUE(y >= x);
    EXPECT_TRUE(y > x);
}

// Test character comparisons
TEST(RelationalOperatorsTest, CharacterComparisons) {
    char c1 = 'A';
    char c2 = 'Z';
    
    EXPECT_TRUE(c1 < c2);
    EXPECT_FALSE(c1 > c2);
    EXPECT_TRUE(c1 != c2);
    EXPECT_FALSE(c1 == c2);
}

// Test string comparisons
TEST(RelationalOperatorsTest, StringComparisons) {
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::string s3 = "apple";
    
    EXPECT_TRUE(s1 < s2);
    EXPECT_FALSE(s1 > s2);
    EXPECT_TRUE(s1 == s3);
    EXPECT_FALSE(s1 != s3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}