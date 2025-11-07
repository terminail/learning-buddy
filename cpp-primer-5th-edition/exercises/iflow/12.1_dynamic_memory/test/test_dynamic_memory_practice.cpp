#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "dynamic_memory_exercises.h"
#include "dynamic_memory_solutions.h"

namespace cpp_primer {

// Test fixture for DynamicMemory practice exercises
class DynamicMemoryPracticeTest : public ::testing::Test {
protected:
    DynamicMemory exercises;
    DynamicMemorySolutions solutions;
};

// Test smart pointer operations in more complex scenarios
TEST_F(DynamicMemoryPracticeTest, TestSharedPtrOperations) {
    auto ptr1 = exercises.create_shared_int(100);
    auto ptr2 = ptr1;  // Copy the shared_ptr
    EXPECT_EQ(ptr1.use_count(), 2);
    EXPECT_EQ(ptr2.use_count(), 2);
    EXPECT_EQ(*ptr1, *ptr2);
    
    // Test shared value retrieval
    EXPECT_EQ(exercises.get_shared_value(ptr1), 100);
    EXPECT_EQ(exercises.get_shared_value(ptr2), 100);
}

TEST_F(DynamicMemoryPracticeTest, TestWeakPtrOperations) {
    auto shared = exercises.create_shared_int(200);
    auto weak = exercises.create_weak_from_shared(shared);
    
    // Test locking weak pointer
    auto locked = exercises.lock_weak_ptr(weak);
    ASSERT_NE(locked, nullptr);
    EXPECT_EQ(*locked, 200);
    EXPECT_EQ(locked.use_count(), 2);  // Original + locked
    
    // Test weak pointer expiration
    shared.reset();
    EXPECT_TRUE(exercises.is_weak_expired(weak));
    auto expired_locked = exercises.lock_weak_ptr(weak);
    EXPECT_EQ(expired_locked, nullptr);
}

// Test dynamic array operations
TEST_F(DynamicMemoryPracticeTest, TestFillDynamicArray) {
    int size = 4;
    int* arr = new int[size];
    
    int fill_value = 5;
    std::vector<int> result = exercises.fill_dynamic_array(arr, size, fill_value);
    
    // Verify the array was filled correctly
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(arr[i], fill_value);
    }
    
    // Verify the returned vector has the same values
    EXPECT_EQ(result.size(), static_cast<size_t>(size));
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_EQ(result[i], fill_value);
    }
    
    delete[] arr;
}

TEST_F(DynamicMemoryPracticeTest, TestSharedArray) {
    int size = 5;
    auto arr = exercises.create_shared_array(size);
    ASSERT_NE(arr, nullptr);
    
    // Initialize array elements
    for (int i = 0; i < size; ++i) {
        arr.get()[i] = i * 3;
    }
    
    // Verify elements
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(arr.get()[i], i * 3);
    }
}

// Test custom deleters
TEST_F(DynamicMemoryPracticeTest, TestCustomDeleters) {
    // Test unique_ptr with custom deleter
    auto unique_with_deleter = exercises.create_unique_with_deleter(42);
    ASSERT_NE(unique_with_deleter, nullptr);
    EXPECT_EQ(*unique_with_deleter, 42);
    
    // Test shared_ptr with custom deleter
    auto shared_with_deleter = exercises.create_shared_with_deleter(99);
    ASSERT_NE(shared_with_deleter, nullptr);
    EXPECT_EQ(*shared_with_deleter, 99);
}

// Test complete workflow with raw pointers
TEST_F(DynamicMemoryPracticeTest, TestRawPointerWorkflow) {
    // Create a dynamic integer
    int* int_ptr = exercises.create_integer(777);
    ASSERT_NE(int_ptr, nullptr);
    EXPECT_EQ(*int_ptr, 777);
    
    // Create a dynamic string
    std::string* str_ptr = exercises.create_string("Test String");
    ASSERT_NE(str_ptr, nullptr);
    EXPECT_EQ(*str_ptr, "Test String");
    
    // Create a dynamic array
    int* arr_ptr = exercises.create_array(3);
    ASSERT_NE(arr_ptr, nullptr);
    
    // Clean up
    exercises.destroy_integer(int_ptr);
    exercises.destroy_string(str_ptr);
    exercises.destroy_array(arr_ptr);
}

// Test solution implementation matches exercise implementation
TEST_F(DynamicMemoryPracticeTest, TestExerciseSolutionEquivalence) {
    // Test integer creation
    int value = 1234;
    auto exercise_ptr = exercises.create_unique_int(value);
    auto solution_ptr = solutions.create_unique_int(value);
    EXPECT_EQ(exercises.get_unique_value(exercise_ptr), solutions.get_unique_value(solution_ptr));
    
    // Test string creation
    std::string str_val = "Test equivalence";
    auto exercise_str_ptr = exercises.create_unique_string(str_val);
    auto solution_str_ptr = solutions.create_unique_string(str_val);
    EXPECT_EQ(exercises.get_unique_string_value(exercise_str_ptr), 
              solutions.get_unique_string_value(solution_str_ptr));
    
    // Test shared pointer operations
    auto shared_ex = exercises.create_shared_int(5678);
    auto shared_sol = solutions.create_shared_int(5678);
    EXPECT_EQ(exercises.get_shared_value(shared_ex), solutions.get_shared_value(shared_sol));
    
    // Test weak pointer operations
    auto weak_ex = exercises.create_weak_from_shared(shared_ex);
    auto weak_sol = solutions.create_weak_from_shared(shared_sol);
    EXPECT_EQ(exercises.is_weak_expired(weak_ex), solutions.is_weak_expired(weak_sol));
    
    if (!exercises.is_weak_expired(weak_ex)) {
        auto locked_ex = exercises.lock_weak_ptr(weak_ex);
        auto locked_sol = solutions.lock_weak_ptr(weak_sol);
        if (locked_ex && locked_sol) {
            EXPECT_EQ(*locked_ex, *locked_sol);
        }
    }
}

} // namespace cpp_primer