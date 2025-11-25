#include <gtest/gtest.h>
#include <string>

// Test find() and rfind()
TEST(StringSearchingTest, FindFunction) {
    std::string text = "Hello World Hello";
    
    // Test finding existing substring
    size_t pos = text.find("World");
    EXPECT_EQ(6, pos);  // "World" starts at position 6
    
    // Test finding with start position
    pos = text.find("Hello", 1);
    EXPECT_EQ(12, pos);  // Second "Hello" starts at position 12
    
    // Test finding non-existing substring
    pos = text.find("Python");
    EXPECT_EQ(std::string::npos, pos);
}

TEST(StringSearchingTest, RFindFunction) {
    std::string text = "Hello World Hello";
    
    // Test finding existing substring from end
    size_t pos = text.rfind("Hello");
    EXPECT_EQ(12, pos);  // Last "Hello" starts at position 12
    
    // Test finding with end position
    pos = text.rfind("World", 10);
    EXPECT_EQ(6, pos);  // "World" starts at position 6
    
    // Test finding non-existing substring
    pos = text.rfind("Python");
    EXPECT_EQ(std::string::npos, pos);
}

// Test find_first_of() and find_last_of()
TEST(StringSearchingTest, FindOfFunctions) {
    std::string text = "Hello123World";
    
    // Test find_first_of
    size_t pos = text.find_first_of("0123456789");
    EXPECT_EQ(5, pos);  // First digit is at position 5
    
    // Test find_last_of
    pos = text.find_last_of("abcdefghijklmnopqrstuvwxyz");
    EXPECT_EQ(12, pos);  // Last letter is at position 12 ('d')
    
    // Test when none found
    pos = text.find_first_of("XYZ");
    EXPECT_EQ(std::string::npos, pos);
}

// Test find_first_not_of() and find_last_not_of()
TEST(StringSearchingTest, FindNotOfFunctions) {
    std::string text = "   Hello World   ";
    
    // Test find_first_not_of
    size_t pos = text.find_first_not_of(" ");
    EXPECT_EQ(3, pos);  // First non-space is at position 3
    
    // Test find_last_not_of
    pos = text.find_last_not_of(" ");
    EXPECT_EQ(13, pos);  // Last non-space is at position 13
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}