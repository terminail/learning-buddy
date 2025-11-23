#include <gtest/gtest.h>
#include <memory>

// Test for unique_ptr
TEST(SmartPointersTest, UniquePtr) {
    // Test unique_ptr creation and automatic deallocation
    {
        std::unique_ptr<int> unique_int = std::make_unique<int>(55);
        EXPECT_EQ(*unique_int, 55);
        // Automatic deallocation when unique_int goes out of scope
    }
    SUCCEED() << "Unique pointer automatically deallocated";
}

// Test for shared_ptr
TEST(SmartPointersTest, SharedPtr) {
    // Test shared_ptr creation and reference counting
    std::shared_ptr<int> shared_int1 = std::make_shared<int>(77);
    EXPECT_EQ(*shared_int1, 77);
    EXPECT_EQ(shared_int1.use_count(), 1);
    
    {
        std::shared_ptr<int> shared_int2 = shared_int1; // Shared ownership
        EXPECT_EQ(shared_int1.use_count(), 2);
        EXPECT_EQ(*shared_int2, 77);
    } // shared_int2 goes out of scope here
    
    EXPECT_EQ(shared_int1.use_count(), 1);
}

// Test for unique_ptr array
TEST(SmartPointersTest, UniquePtrArray) {
    // Test unique_ptr array creation and automatic deallocation
    {
        std::unique_ptr<int[]> unique_array = std::make_unique<int[]>(3);
        unique_array[0] = 10;
        unique_array[1] = 20;
        unique_array[2] = 30;
        
        EXPECT_EQ(unique_array[0], 10);
        EXPECT_EQ(unique_array[1], 20);
        EXPECT_EQ(unique_array[2], 30);
        // Automatic deallocation when unique_array goes out of scope
    }
    SUCCEED() << "Unique pointer array automatically deallocated";
}