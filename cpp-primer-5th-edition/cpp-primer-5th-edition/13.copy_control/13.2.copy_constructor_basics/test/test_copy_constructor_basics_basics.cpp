#include <gtest/gtest.h>
#include <cstring>

// Simple implementation for testing
class TestString {
private:
    char* data;
    size_t len;

public:
    TestString() : data(new char[1]), len(0) {
        data[0] = '\0';
    }
    
    TestString(const char* s) : len(strlen(s)) {
        data = new char[len + 1];
        strcpy(data, s);
    }
    
    TestString(const TestString& other) : len(other.len) {
        data = new char[len + 1];
        strcpy(data, other.data);
    }
    
    ~TestString() {
        delete[] data;
    }
    
    size_t getLength() const { return len; }
    const char* getData() const { return data; }
};

// Basic test for copy constructor
TEST(CopyConstructorBasicsTest, BasicCopy) {
    TestString original("Hello");
    TestString copy = original;
    
    // Test that copy has same content
    EXPECT_EQ(copy.getLength(), 5);
    EXPECT_STREQ(copy.getData(), "Hello");
    
    // Test that they are independent (deep copy)
    EXPECT_NE(original.getData(), copy.getData());
}

// Test copy constructor with empty string
TEST(CopyConstructorBasicsTest, EmptyStringCopy) {
    TestString original("");
    TestString copy = original;
    
    // Test that copy has same content
    EXPECT_EQ(copy.getLength(), 0);
    EXPECT_STREQ(copy.getData(), "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
