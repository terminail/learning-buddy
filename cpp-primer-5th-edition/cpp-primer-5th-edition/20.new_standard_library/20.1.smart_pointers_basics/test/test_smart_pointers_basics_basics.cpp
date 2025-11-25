#include <gtest/gtest.h>
#include <memory>
#include <string>

// Simple class for testing
class TestClass {
public:
    TestClass(int value) : value_(value) {}
    int getValue() const { return value_; }
    void setValue(int value) { value_ = value; }
    
private:
    int value_;
};

// Basic test for unique_ptr
TEST(SmartPointersBasicsTest, UniquePtrBasicOperations) {
    // Test creation with make_unique
    auto ptr = std::make_unique<int>(42);
    EXPECT_EQ(*ptr, 42);
    
    // Test modification
    *ptr = 100;
    EXPECT_EQ(*ptr, 100);
    
    // Test ownership transfer
    auto ptr2 = std::move(ptr);
    EXPECT_EQ(*ptr2, 100);
    EXPECT_EQ(ptr, nullptr);
    
    // Test with custom class
    auto obj_ptr = std::make_unique<TestClass>(5);
    EXPECT_EQ(obj_ptr->getValue(), 5);
    
    obj_ptr->setValue(10);
    EXPECT_EQ(obj_ptr->getValue(), 10);
}

// Basic test for shared_ptr
TEST(SmartPointersBasicsTest, SharedPtrBasicOperations) {
    // Test creation with make_shared
    auto shared1 = std::make_shared<std::string>("Hello");
    EXPECT_EQ(*shared1, "Hello");
    EXPECT_EQ(shared1.use_count(), 1);
    
    // Test sharing ownership
    auto shared2 = shared1;
    EXPECT_EQ(shared1.use_count(), 2);
    EXPECT_EQ(shared2.use_count(), 2);
    
    // Test that both pointers point to the same object
    *shared2 = "World";
    EXPECT_EQ(*shared1, "World");
    
    // Test with custom class
    auto obj_shared = std::make_shared<TestClass>(42);
    EXPECT_EQ(obj_shared->getValue(), 42);
    
    {
        auto another_shared = obj_shared;
        EXPECT_EQ(obj_shared.use_count(), 2);
    }
    EXPECT_EQ(obj_shared.use_count(), 1);
}

// Test array support in unique_ptr
TEST(SmartPointersBasicsTest, UniquePtrArraySupport) {
    auto array_ptr = std::make_unique<int[]>(5);
    
    // Initialize array elements
    for (int i = 0; i < 5; ++i) {
        array_ptr[i] = i * 10;
    }
    
    // Test array access
    EXPECT_EQ(array_ptr[0], 0);
    EXPECT_EQ(array_ptr[1], 10);
    EXPECT_EQ(array_ptr[2], 20);
    EXPECT_EQ(array_ptr[3], 30);
    EXPECT_EQ(array_ptr[4], 40);
}

// Test factory functions
TEST(SmartPointersBasicsTest, FactoryFunctions) {
    // Test make_unique
    auto unique_ptr = std::make_unique<int>(42);
    EXPECT_EQ(*unique_ptr, 42);
    
    // Test make_shared
    auto shared_ptr = std::make_shared<int>(42);
    EXPECT_EQ(*shared_ptr, 42);
    EXPECT_EQ(shared_ptr.use_count(), 1);
    
    // Test make_unique with constructor arguments
    auto string_unique = std::make_unique<std::string>("Hello", 3);
    EXPECT_EQ(*string_unique, "Hel");
    
    // Test make_shared with constructor arguments
    auto string_shared = std::make_shared<std::string>(5, 'A');
    EXPECT_EQ(*string_shared, "AAAAA");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}