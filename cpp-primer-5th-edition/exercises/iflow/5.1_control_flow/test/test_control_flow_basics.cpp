#include <gtest/gtest.h>
#include "control_flow_exercises.h"

using namespace cpp_primer;

class ControlFlowTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(ControlFlowTest, DefaultConstructor) {
    ControlFlow exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== CONDITIONAL STATEMENT TESTS ==========

TEST_F(ControlFlowTest, CheckNumberSign) {
    ControlFlow exercise;
    
    // Test positive number
    EXPECT_EQ(exercise.check_number_sign(5), "positive") << "Expected 'positive' for positive number";
    
    // Test negative number
    EXPECT_EQ(exercise.check_number_sign(-3), "negative") << "Expected 'negative' for negative number";
    
    // Test zero
    EXPECT_EQ(exercise.check_number_sign(0), "zero") << "Expected 'zero' for zero";
}

TEST_F(ControlFlowTest, FindMaximum) {
    ControlFlow exercise;
    
    // Test when first number is maximum
    EXPECT_EQ(exercise.find_maximum(10, 5, 3), 10) << "Expected 10 as maximum";
    
    // Test when second number is maximum
    EXPECT_EQ(exercise.find_maximum(2, 15, 8), 15) << "Expected 15 as maximum";
    
    // Test when third number is maximum
    EXPECT_EQ(exercise.find_maximum(1, 7, 12), 12) << "Expected 12 as maximum";
    
    // Test when all numbers are equal
    EXPECT_EQ(exercise.find_maximum(5, 5, 5), 5) << "Expected 5 as maximum when all are equal";
}

// ========== LOOP STATEMENT TESTS ==========

TEST_F(ControlFlowTest, SumWithForLoop) {
    ControlFlow exercise;
    
    // Test sum of 1 to 5
    EXPECT_EQ(exercise.sum_with_for_loop(5), 15) << "Expected sum of 1+2+3+4+5=15";
    
    // Test sum of 1 to 1
    EXPECT_EQ(exercise.sum_with_for_loop(1), 1) << "Expected sum of 1=1";
    
    // Test sum of 1 to 0 (edge case)
    EXPECT_EQ(exercise.sum_with_for_loop(0), 0) << "Expected sum of 0=0";
}

TEST_F(ControlFlowTest, SumWithWhileLoop) {
    ControlFlow exercise;
    
    // Test sum of 1 to 5
    EXPECT_EQ(exercise.sum_with_while_loop(5), 15) << "Expected sum of 1+2+3+4+5=15";
    
    // Test sum of 1 to 1
    EXPECT_EQ(exercise.sum_with_while_loop(1), 1) << "Expected sum of 1=1";
    
    // Test sum of 1 to 0 (edge case)
    EXPECT_EQ(exercise.sum_with_while_loop(0), 0) << "Expected sum of 0=0";
}

TEST_F(ControlFlowTest, SumEvenNumbers) {
    ControlFlow exercise;
    
    // Test vector with mixed numbers
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(exercise.sum_even_numbers(numbers), 12) << "Expected sum of 2+4+6=12";
    
    // Test vector with only odd numbers
    std::vector<int> odd_numbers = {1, 3, 5};
    EXPECT_EQ(exercise.sum_even_numbers(odd_numbers), 0) << "Expected sum of no even numbers=0";
    
    // Test vector with only even numbers
    std::vector<int> even_numbers = {2, 4, 6, 8};
    EXPECT_EQ(exercise.sum_even_numbers(even_numbers), 20) << "Expected sum of 2+4+6+8=20";
    
    // Test empty vector
    std::vector<int> empty_numbers = {};
    EXPECT_EQ(exercise.sum_even_numbers(empty_numbers), 0) << "Expected sum of empty vector=0";
}

// ========== SWITCH STATEMENT TESTS ==========

TEST_F(ControlFlowTest, ConvertToLetterGrade) {
    ControlFlow exercise;
    
    // Test A grade
    EXPECT_EQ(exercise.convert_to_letter_grade(95), 'A') << "Expected 'A' for grade 95";
    EXPECT_EQ(exercise.convert_to_letter_grade(90), 'A') << "Expected 'A' for grade 90";
    
    // Test B grade
    EXPECT_EQ(exercise.convert_to_letter_grade(85), 'B') << "Expected 'B' for grade 85";
    EXPECT_EQ(exercise.convert_to_letter_grade(80), 'B') << "Expected 'B' for grade 80";
    
    // Test C grade
    EXPECT_EQ(exercise.convert_to_letter_grade(75), 'C') << "Expected 'C' for grade 75";
    EXPECT_EQ(exercise.convert_to_letter_grade(70), 'C') << "Expected 'C' for grade 70";
    
    // Test D grade
    EXPECT_EQ(exercise.convert_to_letter_grade(65), 'D') << "Expected 'D' for grade 65";
    EXPECT_EQ(exercise.convert_to_letter_grade(60), 'D') << "Expected 'D' for grade 60";
    
    // Test F grade
    EXPECT_EQ(exercise.convert_to_letter_grade(55), 'F') << "Expected 'F' for grade 55";
    EXPECT_EQ(exercise.convert_to_letter_grade(0), 'F') << "Expected 'F' for grade 0";
}

// ========== BREAK AND CONTINUE TESTS ==========

TEST_F(ControlFlowTest, FindFirstEven) {
    ControlFlow exercise;
    
    // Test vector with even number at beginning
    std::vector<int> numbers1 = {2, 3, 5, 7};
    EXPECT_EQ(exercise.find_first_even(numbers1), 2) << "Expected first even number to be 2";
    
    // Test vector with even number in middle
    std::vector<int> numbers2 = {1, 3, 4, 5, 7};
    EXPECT_EQ(exercise.find_first_even(numbers2), 4) << "Expected first even number to be 4";
    
    // Test vector with even number at end
    std::vector<int> numbers3 = {1, 3, 5, 6};
    EXPECT_EQ(exercise.find_first_even(numbers3), 6) << "Expected first even number to be 6";
    
    // Test vector with no even numbers
    std::vector<int> numbers4 = {1, 3, 5, 7};
    EXPECT_EQ(exercise.find_first_even(numbers4), -1) << "Expected -1 for no even numbers";
    
    // Test empty vector
    std::vector<int> numbers5 = {};
    EXPECT_EQ(exercise.find_first_even(numbers5), -1) << "Expected -1 for empty vector";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}