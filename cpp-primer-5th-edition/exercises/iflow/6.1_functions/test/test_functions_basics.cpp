#include <gtest/gtest.h>
#include "functions_exercises.h"
#include <vector>

using namespace cpp_primer;

class FunctionsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(FunctionsTest, DefaultConstructor) {
    Functions exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== BASIC FUNCTION TESTS ==========

TEST_F(FunctionsTest, Square) {
    Functions exercise;
    
    // Test positive number
    EXPECT_EQ(exercise.square(5), 25) << "Expected square of 5 to be 25";
    
    // Test negative number
    EXPECT_EQ(exercise.square(-3), 9) << "Expected square of -3 to be 9";
    
    // Test zero
    EXPECT_EQ(exercise.square(0), 0) << "Expected square of 0 to be 0";
}

TEST_F(FunctionsTest, RectangleArea) {
    Functions exercise;
    
    // Test normal rectangle
    EXPECT_NEAR(exercise.rectangle_area(5.0, 3.0), 15.0, 0.001) << "Expected area of 5x3 rectangle to be 15";
    
    // Test square
    EXPECT_NEAR(exercise.rectangle_area(4.0, 4.0), 16.0, 0.001) << "Expected area of 4x4 square to be 16";
    
    // Test with decimal values
    EXPECT_NEAR(exercise.rectangle_area(2.5, 4.0), 10.0, 0.001) << "Expected area of 2.5x4 rectangle to be 10";
}

// ========== FUNCTION OVERLOADING TESTS ==========

TEST_F(FunctionsTest, AddIntegers) {
    Functions exercise;
    
    // Test positive integers
    EXPECT_EQ(exercise.add(5, 3), 8) << "Expected 5 + 3 = 8";
    
    // Test negative integers
    EXPECT_EQ(exercise.add(-2, 7), 5) << "Expected -2 + 7 = 5";
    
    // Test zero
    EXPECT_EQ(exercise.add(0, 0), 0) << "Expected 0 + 0 = 0";
}

TEST_F(FunctionsTest, AddDoubles) {
    Functions exercise;
    
    // Test positive doubles
    EXPECT_NEAR(exercise.add(3.5, 2.1), 5.6, 0.001) << "Expected 3.5 + 2.1 = 5.6";
    
    // Test negative doubles
    EXPECT_NEAR(exercise.add(-1.5, 4.2), 2.7, 0.001) << "Expected -1.5 + 4.2 = 2.7";
    
    // Test zero
    EXPECT_NEAR(exercise.add(0.0, 0.0), 0.0, 0.001) << "Expected 0.0 + 0.0 = 0.0";
}

TEST_F(FunctionsTest, AddStrings) {
    Functions exercise;
    
    // Test normal strings
    EXPECT_EQ(exercise.add("Hello", "World"), "HelloWorld") << "Expected 'Hello' + 'World' = 'HelloWorld'";
    
    // Test empty strings
    EXPECT_EQ(exercise.add("", ""), "") << "Expected '' + '' = ''";
    
    // Test one empty string
    EXPECT_EQ(exercise.add("Hello", ""), "Hello") << "Expected 'Hello' + '' = 'Hello'";
}

// ========== PASS BY REFERENCE TESTS ==========

TEST_F(FunctionsTest, Swap) {
    Functions exercise;
    
    // Test normal swap
    int a = 5, b = 10;
    exercise.swap(a, b);
    EXPECT_EQ(a, 10) << "Expected a to be 10 after swap";
    EXPECT_EQ(b, 5) << "Expected b to be 5 after swap";
    
    // Test same values
    int x = 7, y = 7;
    exercise.swap(x, y);
    EXPECT_EQ(x, 7) << "Expected x to be 7 after swap";
    EXPECT_EQ(y, 7) << "Expected y to be 7 after swap";
}

TEST_F(FunctionsTest, FindMaximum) {
    Functions exercise;
    
    // Test normal vector
    std::vector<int> numbers = {3, 7, 2, 9, 1};
    int& max_ref = exercise.find_maximum(numbers);
    EXPECT_EQ(max_ref, 9) << "Expected maximum to be 9";
    
    // Test single element
    std::vector<int> single = {42};
    int& single_ref = exercise.find_maximum(single);
    EXPECT_EQ(single_ref, 42) << "Expected maximum of single element to be 42";
}

// ========== DEFAULT PARAMETERS TESTS ==========

TEST_F(FunctionsTest, Power) {
    Functions exercise;
    
    // Test with default parameter
    EXPECT_EQ(exercise.power(5), 25) << "Expected 5^2 = 25";
    
    // Test with explicit parameter
    EXPECT_EQ(exercise.power(3, 3), 27) << "Expected 3^3 = 27";
    
    // Test with exponent 0
    EXPECT_EQ(exercise.power(10, 0), 1) << "Expected 10^0 = 1";
}

// ========== ARRAY PARAMETER TESTS ==========

TEST_F(FunctionsTest, SumArray) {
    Functions exercise;
    
    // Test normal array
    int arr1[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(exercise.sum_array(arr1, 5), 15) << "Expected sum of {1,2,3,4,5} = 15";
    
    // Test empty array
    int arr2[] = {};
    EXPECT_EQ(exercise.sum_array(arr2, 0), 0) << "Expected sum of empty array = 0";
    
    // Test array with negative numbers
    int arr3[] = {-1, 2, -3, 4};
    EXPECT_EQ(exercise.sum_array(arr3, 4), 2) << "Expected sum of {-1,2,-3,4} = 2";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}