#include <gtest/gtest.h>
#include <string>
#include <vector>

// Practice test for reference vs pointer
TEST(FunctionParametersPractice, ReferenceVsPointer) {
    int value = 42;
    
    // Reference version
    auto modifyByReference = [](int& ref) {
        ref += 10;
    };
    
    // Pointer version
    auto modifyByPointer = [](int* ptr) {
        if (ptr) {
            *ptr += 20;
        }
    };
    
    int originalValue = value;
    
    modifyByReference(value);
    EXPECT_EQ(originalValue + 10, value);
    
    modifyByPointer(&value);
    EXPECT_EQ(originalValue + 10 + 20, value);
    
    // References cannot be null, so they're safer
    // Pointers can be null, so they require null checking
    modifyByPointer(nullptr);  // Safe due to null check
}

// Practice test for const correctness
TEST(FunctionParametersPractice, ConstCorrectness) {
    std::string message = "Hello";
    
    // Function that should not modify its parameter
    auto getStringLength = [](const std::string& str) {
        // str += " World";  // Compilation error - good!
        return str.length();
    };
    
    size_t length = getStringLength(message);
    EXPECT_EQ(5, length);
    EXPECT_EQ("Hello", message);  // Unchanged
    
    // Function that does modify its parameter (should not use const)
    auto appendString = [](std::string& str) {
        str += " World";
    };
    
    std::string mutableMessage = message;
    appendString(mutableMessage);
    EXPECT_EQ("Hello World", mutableMessage);
}

// Practice test for array parameters
TEST(FunctionParametersPractice, ArrayParameters) {
    int array[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    // Function that modifies array elements
    auto doubleArray = [](int arr[], int sz) {
        for (int i = 0; i < sz; i++) {
            arr[i] *= 2;
        }
    };
    
    doubleArray(array, size);
    
    EXPECT_EQ(2, array[0]);
    EXPECT_EQ(4, array[1]);
    EXPECT_EQ(6, array[2]);
    EXPECT_EQ(8, array[3]);
    EXPECT_EQ(10, array[4]);
    
    // Demonstrate that arrays decay to pointers
    auto arraySize = [](int arr[]) {
        // sizeof(arr) would give pointer size, not array size
        // This is why we need to pass size explicitly
        return sizeof(arr);  // This returns pointer size
    };
    
    // This demonstrates the pointer decay
    EXPECT_EQ(sizeof(int*), arraySize(array));
}

// Practice test for efficient parameter passing
TEST(FunctionParametersPractice, EfficientParameterPassing) {
    // Large object - should use const reference for efficiency
    std::vector<int> largeVector(1000, 42);
    
    auto processLargeVector = [](const std::vector<int>& vec) {
        return vec.size();
    };
    
    size_t size = processLargeVector(largeVector);
    EXPECT_EQ(1000, size);
    
    // Small object - pass by value might be acceptable
    auto processSmallValue = [](int value) {
        return value * 2;
    };
    
    int result = processSmallValue(21);
    EXPECT_EQ(42, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}