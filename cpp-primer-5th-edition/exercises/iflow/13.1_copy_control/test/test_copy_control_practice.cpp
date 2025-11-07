#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "copy_control_exercises.h"
#include "copy_control_solutions.h"

namespace cpp_primer {

// Test fixture for CopyControl practice exercises
class CopyControlPracticeTest : public ::testing::Test {
protected:
    CopyControl exercises;
    CopyControlSolutions solutions;
};

// Test dynamic array functionality
TEST_F(CopyControlPracticeTest, TestDynamicArrayBasics) {
    DynamicArray arr(5, 10);  // Array of 5 elements, all 10
    DynamicArraySolutions sol(5, 10);
    
    EXPECT_EQ(arr.get_size(), 5);
    EXPECT_EQ(sol.get_size(), 5);
    
    for (size_t i = 0; i < arr.get_size(); ++i) {
        EXPECT_EQ(arr[i], 10);
        EXPECT_EQ(sol[i], 10);
    }
}

TEST_F(CopyControlPracticeTest, TestDynamicArrayCopyConstructor) {
    DynamicArray original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    
    DynamicArraySolutions sol_original(3);
    sol_original[0] = 1;
    sol_original[1] = 2;
    sol_original[2] = 3;
    
    // Copy the arrays
    DynamicArray copy(original);
    DynamicArraySolutions sol_copy(sol_original);
    
    // Verify the copy has the same values
    EXPECT_EQ(copy.get_size(), original.get_size());
    EXPECT_EQ(sol_copy.get_size(), sol_original.get_size());
    
    for (size_t i = 0; i < copy.get_size(); ++i) {
        EXPECT_EQ(copy[i], original[i]);
        EXPECT_EQ(sol_copy[i], sol_original[i]);
    }
    
    // Modify original, ensure copy is independent
    original[0] = 99;
    sol_original[0] = 99;
    
    EXPECT_EQ(copy[0], 1);  // Copy should still have original value
    EXPECT_EQ(sol_copy[0], 1);  // Solution copy should still have original value
}

TEST_F(CopyControlPracticeTest, TestDynamicArrayMoveConstructor) {
    DynamicArray original(3);
    original[0] = 100;
    original[1] = 200;
    original[2] = 300;
    
    DynamicArraySolutions sol_original(3);
    sol_original[0] = 100;
    sol_original[1] = 200;
    sol_original[2] = 300;
    
    // Move the arrays
    DynamicArray moved(std::move(original));
    DynamicArraySolutions sol_moved(std::move(sol_original));
    
    // Verify moved array has the values
    EXPECT_EQ(moved.get_size(), 3);
    EXPECT_EQ(sol_moved.get_size(), 3);
    
    EXPECT_EQ(moved[0], 100);
    EXPECT_EQ(moved[1], 200);
    EXPECT_EQ(moved[2], 300);
    
    EXPECT_EQ(sol_moved[0], 100);
    EXPECT_EQ(sol_moved[1], 200);
    EXPECT_EQ(sol_moved[2], 300);
}

TEST_F(CopyControlPracticeTest, TestDynamicArrayCopyAssignment) {
    DynamicArray source(2);
    source[0] = 50;
    source[1] = 75;
    
    DynamicArraySolutions sol_source(2);
    sol_source[0] = 50;
    sol_source[1] = 75;
    
    // Create destination arrays with different initial values
    DynamicArray dest(4, 0);
    DynamicArraySolutions sol_dest(4, 0);
    
    // Perform copy assignment
    dest = source;
    sol_dest = sol_source;
    
    // Verify destination has source's values
    EXPECT_EQ(dest.get_size(), source.get_size());
    EXPECT_EQ(sol_dest.get_size(), sol_source.get_size());
    
    for (size_t i = 0; i < dest.get_size(); ++i) {
        EXPECT_EQ(dest[i], source[i]);
        EXPECT_EQ(sol_dest[i], sol_source[i]);
    }
}

TEST_F(CopyControlPracticeTest, TestDynamicArrayMoveAssignment) {
    DynamicArray source(3);
    source[0] = 111;
    source[1] = 222;
    source[2] = 333;
    
    DynamicArraySolutions sol_source(3);
    sol_source[0] = 111;
    sol_source[1] = 222;
    sol_source[2] = 333;
    
    // Create destination arrays
    DynamicArray dest(2, 0);
    DynamicArraySolutions sol_dest(2, 0);
    
    // Perform move assignment
    dest = std::move(source);
    sol_dest = std::move(sol_source);
    
    // Verify destination has source's values
    EXPECT_EQ(dest.get_size(), 3);
    EXPECT_EQ(sol_dest.get_size(), 3);
    
    EXPECT_EQ(dest[0], 111);
    EXPECT_EQ(dest[1], 222);
    EXPECT_EQ(dest[2], 333);
    
    EXPECT_EQ(sol_dest[0], 111);
    EXPECT_EQ(sol_dest[1], 222);
    EXPECT_EQ(sol_dest[2], 333);
}

// Test smart container functionality
TEST_F(CopyControlPracticeTest, TestSmartContainerBasics) {
    SmartContainer smart("Hello", {1, 2, 3, 4, 5});
    SmartContainerSolutions sol_smart("Hello", {1, 2, 3, 4, 5});
    
    EXPECT_EQ(smart.get_string(), "Hello");
    EXPECT_EQ(sol_smart.get_string(), "Hello");
    
    EXPECT_EQ(smart.get_numbers_size(), 5);
    EXPECT_EQ(sol_smart.get_numbers_size(), 5);
    
    std::vector<int> expected = {1, 2, 3, 4, 5};
    auto numbers = smart.get_numbers();
    auto sol_numbers = sol_smart.get_numbers();
    
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(numbers[i], expected[i]);
        EXPECT_EQ(sol_numbers[i], expected[i]);
    }
}

TEST_F(CopyControlPracticeTest, TestSmartContainerCopyConstructor) {
    SmartContainer original("Original", {10, 20, 30});
    SmartContainerSolutions sol_original("Original", {10, 20, 30});
    
    // Copy the containers
    SmartContainer copy(original);
    SmartContainerSolutions sol_copy(sol_original);
    
    // Verify the copy has the same values
    EXPECT_EQ(copy.get_string(), original.get_string());
    EXPECT_EQ(sol_copy.get_string(), sol_original.get_string());
    
    EXPECT_EQ(copy.get_numbers_size(), original.get_numbers_size());
    EXPECT_EQ(sol_copy.get_numbers_size(), sol_original.get_numbers_size());
    
    // Add a number to original's vector - since it uses shared_ptr, both should see the change in the vector
    original.add_number(40);
    sol_original.add_number(40);
    
    // Verify both original and copy have the same vector (shared ownership)
    EXPECT_EQ(original.get_numbers_size(), 4);
    EXPECT_EQ(copy.get_numbers_size(), 4);
    EXPECT_EQ(sol_original.get_numbers_size(), 4);
    EXPECT_EQ(sol_copy.get_numbers_size(), 4);
}

TEST_F(CopyControlPracticeTest, TestSmartContainerMoveConstructor) {
    SmartContainer original("MoveMe", {5, 10, 15});
    SmartContainerSolutions sol_original("MoveMe", {5, 10, 15});
    
    // Move the containers
    SmartContainer moved(std::move(original));
    SmartContainerSolutions sol_moved(std::move(sol_original));
    
    // Verify moved container has the values
    EXPECT_EQ(moved.get_string(), "MoveMe");
    EXPECT_EQ(sol_moved.get_string(), "MoveMe");
    
    EXPECT_EQ(moved.get_numbers_size(), 3);
    EXPECT_EQ(sol_moved.get_numbers_size(), 3);
    
    // Verify original is in a valid state
    EXPECT_FALSE(original.has_data());  // Original should be empty after move
    EXPECT_FALSE(sol_original.has_data());  // Solution original should be empty after move
}

TEST_F(CopyControlPracticeTest, TestSmartContainerCopyAssignment) {
    SmartContainer source("Source", {100, 200});
    SmartContainerSolutions sol_source("Source", {100, 200});
    
    // Create destination containers
    SmartContainer dest("Dest", {0, 0, 0});
    SmartContainerSolutions sol_dest("Dest", {0, 0, 0});
    
    // Perform copy assignment
    dest = source;
    sol_dest = sol_source;
    
    // Verify destination has source's values
    EXPECT_EQ(dest.get_string(), source.get_string());
    EXPECT_EQ(sol_dest.get_string(), sol_source.get_string());
    
    EXPECT_EQ(dest.get_numbers_size(), source.get_numbers_size());
    EXPECT_EQ(sol_dest.get_numbers_size(), sol_source.get_numbers_size());
}

TEST_F(CopyControlPracticeTest, TestSmartContainerMoveAssignment) {
    SmartContainer source("MoveSource", {777, 888, 999});
    SmartContainerSolutions sol_source("MoveSource", {777, 888, 999});
    
    // Create destination containers
    SmartContainer dest("Dest", {0});
    SmartContainerSolutions sol_dest("Dest", {0});
    
    // Perform move assignment
    dest = std::move(source);
    sol_dest = std::move(sol_source);
    
    // Verify destination has source's values
    EXPECT_EQ(dest.get_string(), "MoveSource");
    EXPECT_EQ(sol_dest.get_string(), "MoveSource");
    
    EXPECT_EQ(dest.get_numbers_size(), 3);
    EXPECT_EQ(sol_dest.get_numbers_size(), 3);
    
    // Verify source is in a valid state after move
    EXPECT_FALSE(source.has_data());  // Source should be empty after move
    EXPECT_FALSE(sol_source.has_data());  // Solution source should be empty after move
}

// Test memory management correctness with a more complex scenario
TEST_F(CopyControlPracticeTest, TestComplexScenario) {
    // Create a dynamic array and perform multiple operations
    DynamicArray arr(5, 42);  // All elements are 42
    DynamicArraySolutions sol_arr(5, 42);
    
    // Copy it
    DynamicArray copy1(arr);
    DynamicArraySolutions sol_copy1(sol_arr);
    
    // Modify original
    for (size_t i = 0; i < arr.get_size(); ++i) {
        arr[i] = i * 10;
        sol_arr[i] = i * 10;
    }
    
    // Verify copy is independent
    for (size_t i = 0; i < copy1.get_size(); ++i) {
        EXPECT_EQ(copy1[i], 42);  // Copy should still have original values
        EXPECT_EQ(sol_copy1[i], 42);  // Solution copy should still have original values
    }
    
    // Move original to another array
    DynamicArray moved(std::move(arr));
    DynamicArraySolutions sol_moved(std::move(sol_arr));
    
    // Verify moved array has the modified values
    for (size_t i = 0; i < moved.get_size(); ++i) {
        EXPECT_EQ(moved[i], i * 10);  // Moved should have modified values
        EXPECT_EQ(sol_moved[i], i * 10);  // Solution moved should have modified values
    }
    
    // Verify original is in a valid state after move
    EXPECT_EQ(arr.get_size(), 0);  // Original should be empty after move
    EXPECT_EQ(sol_arr.get_size(), 0);  // Solution original should be empty after move
}

} // namespace cpp_primer