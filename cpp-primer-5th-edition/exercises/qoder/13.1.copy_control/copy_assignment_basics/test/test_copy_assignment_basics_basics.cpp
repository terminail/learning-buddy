#include <gtest/gtest.h>
#include <cstring>

// Simple implementation for testing
class TestArray {
private:
    int* data;
    size_t size;

public:
    TestArray() : data(nullptr), size(0) {}
    
    TestArray(size_t s) : size(s) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = static_cast<int>(i);
        }
    }
    
    TestArray(const TestArray& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    
    TestArray& operator=(const TestArray& rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        delete[] data;
        
        size = rhs.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = rhs.data[i];
        }
        
        return *this;
    }
    
    ~TestArray() {
        delete[] data;
    }
    
    size_t getSize() const { return size; }
    int* getData() const { return data; }
    
    int& operator[](size_t index) { return data[index]; }
    const int& operator[](size_t index) const { return data[index]; }
};

// Basic test for copy assignment operator
TEST(CopyAssignmentBasicsTest, BasicAssignment) {
    TestArray arr1(5);
    TestArray arr2;
    
    // Test assignment
    arr2 = arr1;
    
    // Test that copy has same content
    EXPECT_EQ(arr2.getSize(), 5);
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(arr2[i], static_cast<int>(i));
    }
    
    // Test that they are independent (deep copy)
    EXPECT_NE(arr1.getData(), arr2.getData());
    
    // Modify one and check the other is unaffected
    arr1[0] = 99;
    EXPECT_EQ(arr2[0], 0);
}

// Test self-assignment
TEST(CopyAssignmentBasicsTest, SelfAssignment) {
    TestArray arr(5);
    
    // Store original values
    int* originalData = arr.getData();
    
    // Test self-assignment
    arr = arr;
    
    // Should still be valid and unchanged
    EXPECT_EQ(arr.getSize(), 5);
    EXPECT_EQ(arr.getData(), originalData);
}