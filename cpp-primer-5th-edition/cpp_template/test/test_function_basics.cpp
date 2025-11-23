#include "function_exercises.h"
#include <gtest/gtest.h>

TEST(FunctionExercisesTest, BasicOperations) {
    EXPECT_EQ(cpp_primer::add_integers(2, 3), 5);
    EXPECT_TRUE(cpp_primer::is_even(4));
    EXPECT_FALSE(cpp_primer::is_even(3));
    EXPECT_DOUBLE_EQ(cpp_primer::fahrenheit_to_celsius(32), 0.0);
    EXPECT_EQ(cpp_primer::factorial(5), 120);
}

TEST(FunctionExercisesTest, StringAndArrayOperations) {
    EXPECT_EQ(cpp_primer::reverse_string("hello"), "olleh");
    EXPECT_EQ(cpp_primer::count_vowels("Hello World"), 3);
    
    int arr[] = {1, 5, 3, 9, 2};
    EXPECT_EQ(cpp_primer::find_max(arr, 5), 9);
    EXPECT_DOUBLE_EQ(cpp_primer::calculate_average(arr, 5), 4.0);
}

TEST(FunctionExercisesTest, ControlFlow) {
    EXPECT_TRUE(cpp_primer::is_leap_year(2020));
    EXPECT_FALSE(cpp_primer::is_leap_year(1900));
    EXPECT_TRUE(cpp_primer::is_prime(7));
    EXPECT_FALSE(cpp_primer::is_prime(9));
    EXPECT_EQ(cpp_primer::fibonacci(6), 8);
}

TEST(FunctionExercisesTest, FunctionOverloading) {
    EXPECT_EQ(cpp_primer::max_value(3, 7), 7);
    EXPECT_DOUBLE_EQ(cpp_primer::max_value(3.5, 2.1), 3.5);
    EXPECT_EQ(cpp_primer::max_value(1, 5, 3), 5);
}