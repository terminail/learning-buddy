#include <gtest/gtest.h>
#include "exercise_name_exercises.h"

using namespace cpp_primer;

class ExerciseNamePracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: BASIC FUNCTIONALITY ==========

/**
 * Practice Problem 1: Implement a basic function for your exercise
 * 
 * Add this function to the ExerciseName class:
 * return_type method_name(parameter_type parameter);
 */
TEST_F(ExerciseNamePracticeTest, Practice1_BasicFunctionality) {
    ExerciseName exercise;
    
    // TODO: Add test cases for your specific function
    // Example:
    // EXPECT_EQ(exercise.method_name("test_input"), "expected_output");
    // EXPECT_EQ(exercise.method_name(""), "empty_result");
}

// ========== PRACTICE PROBLEM 2: INTERMEDIATE CONCEPTS ==========

/**
 * Practice Problem 2: Implement an intermediate function for your exercise
 * 
 * Add this function to the ExerciseName class:
 * return_type method_name(parameter_type parameter);
 */
TEST_F(ExerciseNamePracticeTest, Practice2_IntermediateConcepts) {
    ExerciseName exercise;
    
    // TODO: Add test cases for your intermediate function
    // Example:
    // EXPECT_EQ(exercise.intermediate_method("input"), "expected_output");
}

// ========== PRACTICE PROBLEM 3: ADVANCED CONCEPTS ==========

/**
 * Practice Problem 3: Implement an advanced function for your exercise
 * 
 * Add this function to the ExerciseName class:
 * return_type method_name(parameter_type parameter);
 */
TEST_F(ExerciseNamePracticeTest, Practice3_AdvancedConcepts) {
    ExerciseName exercise;
    
    // TODO: Add test cases for your advanced function
    // Example:
    // EXPECT_TRUE(exercise.advanced_method("valid_input"));
    // EXPECT_FALSE(exercise.advanced_method("invalid_input"));
}

// ========== PRACTICE PROBLEM 4: ERROR HANDLING ==========

/**
 * Practice Problem 4: Implement error handling for your exercise
 * 
 * Add this function to the ExerciseName class:
 * return_type method_name(parameter_type parameter);
 */
TEST_F(ExerciseNamePracticeTest, Practice4_ErrorHandling) {
    ExerciseName exercise;
    
    // TODO: Add test cases for error handling
    // Example:
    // EXPECT_THROW(exercise.method_name("invalid_input"), std::invalid_argument);
}

// ========== PRACTICE PROBLEM 5: EDGE CASES ==========

/**
 * Practice Problem 5: Handle edge cases in your exercise
 * 
 * Add this function to the ExerciseName class:
 * return_type method_name(parameter_type parameter);
 */
TEST_F(ExerciseNamePracticeTest, Practice5_EdgeCases) {
    ExerciseName exercise;
    
    // TODO: Add test cases for edge cases
    // Example:
    // EXPECT_EQ(exercise.method_name(""), "empty_result");
    // EXPECT_EQ(exercise.method_name("boundary_case"), "boundary_result");
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(ExerciseNamePracticeTest, CustomPracticeProblems) {
    ExerciseName exercise;
    
    // TODO: Add your custom practice problems
    // This is where you test your own implementations
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}