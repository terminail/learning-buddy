#include <gtest/gtest.h>
#include "copy_constructor_exercises.h"
#include <cstring>
#include <vector>

// Test suite for basic copy constructor operations
class CopyConstructorBasicsTest : public ::testing::Test {
protected:
    void SetUp() override {
        SimpleString::resetCounts();
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test SimpleString default constructor
TEST_F(CopyConstructorBasicsTest, TestSimpleStringDefaultConstructor) {
    SimpleString str;
    EXPECT_EQ(str.size(), 0);
    EXPECT_EQ(str.c_str(), nullptr);
    EXPECT_EQ(SimpleString::getConstructorCount(), 1);
}

// Test SimpleString constructor with C-string
TEST_F(CopyConstructorBasicsTest, TestSimpleStringCstringConstructor) {
    const char* testStr = "Hello, World!";
    SimpleString str(testStr);
    EXPECT_EQ(str.size(), std::strlen(testStr));
    EXPECT_STREQ(str.c_str(), testStr);
    EXPECT_EQ(SimpleString::getConstructorCount(), 1);
}

// Test SimpleString copy constructor
TEST_F(CopyConstructorBasicsTest, TestSimpleStringCopyConstructor) {
    const char* testStr = "Copy Test";
    SimpleString original(testStr);
    SimpleString copy(original);  // This should invoke the copy constructor
    
    EXPECT_EQ(copy.size(), original.size());
    EXPECT_STREQ(copy.c_str(), original.c_str());
    // Note: We can't directly test the copy constructor implementation here
    // because it's a TODO in the exercise file
}

// Test SimpleString destructor
TEST_F(CopyConstructorBasicsTest, TestSimpleStringDestructor) {
    {
        SimpleString str("Test");
        EXPECT_EQ(SimpleString::getConstructorCount(), 1);
    }  // str goes out of scope here, destructor should be called
    
    EXPECT_EQ(SimpleString::getDestructorCount(), 1);
}

// Test Container constructor
TEST_F(CopyConstructorBasicsTest, TestContainerConstructor) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::string name = "TestContainer";
    
    Container container(data, name);
    EXPECT_EQ(container.size(), 5);
    EXPECT_EQ(container.getName(), name);
    EXPECT_EQ(container.getData(), data);
}

// Test Container copy constructor
TEST_F(CopyConstructorBasicsTest, TestContainerCopyConstructor) {
    std::vector<int> data = {10, 20, 30};
    std::string name = "CopyTest";
    
    Container original(data, name);
    Container copy(original);  // This should invoke the copy constructor
    
    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.getName(), original.getName());
    EXPECT_EQ(copy.getData(), original.getData());
}

// Test PointerWrapper constructor and destructor
TEST_F(CopyConstructorBasicsTest, TestPointerWrapperConstructorDestructor) {
    {
        PointerWrapper ptrWrapper(42);
        EXPECT_EQ(ptrWrapper.getValue(), 42);
        EXPECT_EQ(ptrWrapper.getPtrValue(), 42);
    }  // Destructor should be called when ptrWrapper goes out of scope
}

// Test PointerWrapper copy constructor
TEST_F(CopyConstructorBasicsTest, TestPointerWrapperCopyConstructor) {
    PointerWrapper original(100);
    PointerWrapper copy(original);  // This should invoke the copy constructor
    
    EXPECT_EQ(copy.getValue(), original.getValue());
    EXPECT_EQ(copy.getPtrValue(), original.getPtrValue());
    
    // Test that they have different memory addresses (deep copy)
    // Note: We can't directly test the memory addresses without access to ptr_
}