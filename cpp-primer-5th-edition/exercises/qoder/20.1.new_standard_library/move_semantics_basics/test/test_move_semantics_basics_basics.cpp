#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <string>
#include <utility>

// Simple class for testing move semantics
class TestString {
private:
    char* data;
    size_t len;

public:
    TestString() : data(nullptr), len(0) {}
    
    TestString(const char* s) : len(strlen(s)) {
        data = new char[len + 1];
        strcpy(data, s);
    }
    
    // Copy constructor
    TestString(const TestString& other) : len(other.len) {
        data = new char[len + 1];
        strcpy(data, other.data);
    }
    
    // Move constructor
    TestString(TestString&& other) noexcept : data(other.data), len(other.len) {
        other.data = nullptr;
        other.len = 0;
    }
    
    // Copy assignment
    TestString& operator=(const TestString& other) {
        if (this != &other) {
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    
    // Move assignment
    TestString& operator=(TestString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            len = other.len;
            other.data = nullptr;
            other.len = 0;
        }
        return *this;
    }
    
    ~TestString() {
        delete[] data;
    }
    
    size_t length() const { return len; }
    const char* c_str() const { return data; }
};

// Basic test for move constructor
TEST(MoveSemanticsBasicsTest, MoveConstructor) {
    TestString original("Hello");
    EXPECT_EQ(original.length(), 5);
    
    // Test move constructor
    TestString moved = std::move(original);
    EXPECT_EQ(moved.length(), 5);
    EXPECT_STREQ(moved.c_str(), "Hello");
    
    // Original should be in a valid but unspecified state
    // Typically, it should be empty or null
    // The exact state depends on our implementation
}

// Basic test for move assignment
TEST(MoveSemanticsBasicsTest, MoveAssignment) {
    TestString original("World");
    TestString target;
    
    // Test move assignment
    target = std::move(original);
    EXPECT_EQ(target.length(), 5);
    EXPECT_STREQ(target.c_str(), "World");
}

// Test with containers
TEST(MoveSemanticsBasicsTest, ContainerMoveOperations) {
    std::vector<TestString> vec;
    vec.reserve(2);
    
    TestString str1("First");
    TestString str2("Second");
    
    // Test move operations with containers
    vec.push_back(std::move(str1));
    vec.push_back(std::move(str2));
    
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0].length(), 5);
    EXPECT_EQ(vec[1].length(), 6);
}

// Test std::move function
TEST(MoveSemanticsBasicsTest, StdMoveFunction) {
    TestString original("Test");
    
    // Verify that std::move converts lvalue to rvalue reference
    TestString moved = std::move(original);
    
    // After move, original should be in moved-from state
    // Our implementation sets data to nullptr
    // This test depends on the specific implementation
}

// Test with standard library types
TEST(MoveSemanticsBasicsTest, StandardLibraryMove) {
    // Test with std::string
    std::string original("Hello World");
    std::string moved = std::move(original);
    
    EXPECT_EQ(moved, "Hello World");
    // original is in valid but unspecified state
    
    // Test with std::vector
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = std::move(vec1);
    
    EXPECT_EQ(vec2.size(), 5);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[4], 5);
    // vec1 is now empty
    EXPECT_TRUE(vec1.empty());
}