#include <gtest/gtest.h>

// Test for dynamic memory allocation
TEST(DynamicAllocationTest, SingleIntegerAllocation) {
    // Test single integer allocation and deallocation
    int* single_int = new int(42);
    EXPECT_EQ(*single_int, 42);
    delete single_int;
}

// Test for array allocation
TEST(DynamicAllocationTest, ArrayAllocation) {
    // Test array allocation and deallocation
    int* int_array = new int[3]{10, 20, 30};
    EXPECT_EQ(int_array[0], 10);
    EXPECT_EQ(int_array[1], 20);
    EXPECT_EQ(int_array[2], 30);
    delete[] int_array;
}

// Test for memory leak prevention
TEST(DynamicAllocationTest, MemoryLeakPrevention) {
    // Test that memory is properly deallocated
    int* ptr = new int(100);
    delete ptr;
    // Setting pointer to nullptr after deletion is good practice
    ptr = nullptr;
    SUCCEED() << "Memory properly deallocated";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
