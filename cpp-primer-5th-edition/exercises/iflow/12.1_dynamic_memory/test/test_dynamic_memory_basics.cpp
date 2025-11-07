#include <gtest/gtest.h>
#include "dynamic_memory_exercises.h"
#include "dynamic_memory_solutions.h"

namespace cpp_primer {

// Test fixture for DynamicMemory exercises
class DynamicMemoryBasicsTest : public ::testing::Test {
protected:
    DynamicMemory exercises;
    DynamicMemorySolutions solutions;
};

// Test raw pointer dynamic memory creation
TEST_F(DynamicMemoryBasicsTest, TestCreateInteger) {
    int value = 42;
    int* ptr = exercises.create_integer(value);
    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, value);
    delete ptr;
}

TEST_F(DynamicMemoryBasicsTest, TestCreateString) {
    std::string value = "Hello, World!";
    std::string* ptr = exercises.create_string(value);
    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, value);
    delete ptr;
}

TEST_F(DynamicMemoryBasicsTest, TestCreateArray) {
    int size = 5;
    int* arr = exercises.create_array(size);
    ASSERT_NE(arr, nullptr);
    // Initialize array elements
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
    // Verify array elements
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(arr[i], i);
    }
    delete[] arr;
}

// Test smart pointer creation
TEST_F(DynamicMemoryBasicsTest, TestCreateUniqueInt) {
    int value = 123;
    auto ptr = exercises.create_unique_int(value);
    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, value);
}

TEST_F(DynamicMemoryBasicsTest, TestCreateUniqueString) {
    std::string value = "Smart Pointer";
    auto ptr = exercises.create_unique_string(value);
    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, value);
}

TEST_F(DynamicMemoryBasicsTest, TestCreateSharedInt) {
    int value = 456;
    auto ptr = exercises.create_shared_int(value);
    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, value);
    EXPECT_EQ(ptr.use_count(), 1);
}

TEST_F(DynamicMemoryBasicsTest, TestCreateWeakFromShared) {
    auto shared = std::make_shared<int>(789);
    auto weak = exercises.create_weak_from_shared(shared);
    EXPECT_FALSE(weak.expired());
    
    // Verify the weak ptr can be locked
    auto locked = weak.lock();
    ASSERT_NE(locked, nullptr);
    EXPECT_EQ(*locked, 789);
}

// Test smart pointer operations
TEST_F(DynamicMemoryBasicsTest, TestGetUniqueValue) {
    auto ptr = exercises.create_unique_int(999);
    int value = exercises.get_unique_value(ptr);
    EXPECT_EQ(value, 999);
}

TEST_F(DynamicMemoryBasicsTest, TestGetSharedValue) {
    auto ptr = exercises.create_shared_int(888);
    int value = exercises.get_shared_value(ptr);
    EXPECT_EQ(value, 888);
}

TEST_F(DynamicMemoryBasicsTest, TestIsWeakExpired) {
    auto shared = std::make_shared<int>(777);
    auto weak = exercises.create_weak_from_shared(shared);
    EXPECT_FALSE(exercises.is_weak_expired(weak));
    
    shared.reset();  // Release the shared pointer
    EXPECT_TRUE(exercises.is_weak_expired(weak));
}

// Test dynamic array operations
TEST_F(DynamicMemoryBasicsTest, TestCreateUniqueArray) {
    int size = 3;
    auto arr = exercises.create_unique_array(size);
    ASSERT_NE(arr, nullptr);
    
    // Initialize and test array elements
    for (int i = 0; i < size; ++i) {
        arr[i] = i * 2;
    }
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(arr[i], i * 2);
    }
}

} // namespace cpp_primer