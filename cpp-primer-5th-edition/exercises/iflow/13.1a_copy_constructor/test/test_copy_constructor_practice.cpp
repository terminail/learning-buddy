#include <gtest/gtest.h>
#include "copy_constructor_exercises.h"
#include <vector>
#include <cstring>

// Test suite for advanced copy constructor operations
class CopyConstructorPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        SimpleString::resetCounts();
    }
    
    void TearDown() override {
        // Cleanup code if needed
    }
};

// Test SimpleString assignment operator
TEST_F(CopyConstructorPracticeTest, TestSimpleStringAssignmentOperator) {
    SimpleString str1("Hello");
    SimpleString str2("World");
    
    str2 = str1;  // This should invoke the assignment operator
    
    EXPECT_EQ(str2.size(), str1.size());
    EXPECT_STREQ(str2.c_str(), str1.c_str());
    
    // Test self-assignment
    str1 = str1;
    EXPECT_EQ(str1.size(), 5);
    EXPECT_STREQ(str1.c_str(), "Hello");
}

// Test Container assignment operator
TEST_F(CopyConstructorPracticeTest, TestContainerAssignmentOperator) {
    std::vector<int> data1 = {1, 2, 3};
    std::vector<int> data2 = {4, 5, 6, 7};
    
    Container container1(data1, "First");
    Container container2(data2, "Second");
    
    container2 = container1;  // This should invoke the assignment operator
    
    EXPECT_EQ(container2.size(), container1.size());
    EXPECT_EQ(container2.getName(), container1.getName());
    EXPECT_EQ(container2.getData(), container1.getData());
    
    // Test self-assignment
    container1 = container1;
    EXPECT_EQ(container1.size(), 3);
    EXPECT_EQ(container1.getName(), "First");
}

// Test PointerWrapper assignment operator
TEST_F(CopyConstructorPracticeTest, TestPointerWrapperAssignmentOperator) {
    PointerWrapper ptr1(100);
    PointerWrapper ptr2(200);
    
    ptr2 = ptr1;  // This should invoke the assignment operator
    
    EXPECT_EQ(ptr2.getValue(), ptr1.getValue());
    EXPECT_EQ(ptr2.getPtrValue(), ptr1.getPtrValue());
    
    // Test self-assignment
    ptr1 = ptr1;
    EXPECT_EQ(ptr1.getValue(), 100);
    EXPECT_EQ(ptr1.getPtrValue(), 100);
}

// Test copy constructor with modification
TEST_F(CopyConstructorPracticeTest, TestCopyConstructorWithModification) {
    SimpleString original("Original");
    SimpleString copy(original);
    
    // Modify the copy
    // Note: We can't directly modify the internal data without additional methods
    
    // Verify that original is unchanged
    EXPECT_EQ(original.size(), 8);
    EXPECT_STREQ(original.c_str(), "Original");
}

// Test deep copy behavior
TEST_F(CopyConstructorPracticeTest, TestDeepCopyBehavior) {
    PointerWrapper original(50);
    PointerWrapper copy(original);
    
    // Modify the original
    original.setPtrValue(75);
    
    // Verify that copy is unchanged (deep copy)
    EXPECT_EQ(copy.getPtrValue(), 50);
    EXPECT_EQ(original.getPtrValue(), 75);
}

// Test comprehensive copy constructor workflow
TEST_F(CopyConstructorPracticeTest, TestComprehensiveWorkflow) {
    // Test SimpleString workflow
    SimpleString str1("Test String");
    EXPECT_EQ(SimpleString::getConstructorCount(), 1);
    
    SimpleString str2(str1);  // Copy constructor
    EXPECT_EQ(SimpleString::getCopyConstructorCount(), 1);
    EXPECT_EQ(SimpleString::getConstructorCount(), 1);  // No new constructor call
    
    SimpleString str3("Another String");
    str3 = str1;  // Assignment operator
    EXPECT_EQ(str3.size(), str1.size());
    EXPECT_STREQ(str3.c_str(), str1.c_str());
    
    // Test Container workflow
    std::vector<int> data = {1, 2, 3, 4, 5};
    Container container1(data, "TestContainer");
    Container container2(container1);  // Copy constructor
    
    EXPECT_EQ(container2.size(), container1.size());
    EXPECT_EQ(container2.getName(), container1.getName());
    EXPECT_EQ(container2.getData(), container1.getData());
    
    // Test PointerWrapper workflow
    PointerWrapper ptr1(123);
    PointerWrapper ptr2(ptr1);  // Copy constructor (should be deep copy)
    
    EXPECT_EQ(ptr2.getValue(), ptr1.getValue());
    EXPECT_EQ(ptr2.getPtrValue(), ptr1.getPtrValue());
    
    // Modify ptr1 and verify ptr2 is unchanged
    ptr1.setPtrValue(456);
    EXPECT_EQ(ptr1.getPtrValue(), 456);
    EXPECT_EQ(ptr2.getPtrValue(), 123);  // Should be unchanged due to deep copy
    
    // Count destructors when objects go out of scope
    int initialDestructorCount = SimpleString::getDestructorCount();
}