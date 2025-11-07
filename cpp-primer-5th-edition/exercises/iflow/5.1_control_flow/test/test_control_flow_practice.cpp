#include <gtest/gtest.h>
#include "control_flow_exercises.h"
#include <algorithm>

using namespace cpp_primer;

class ControlFlowPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: NESTED LOOPS ==========

/**
 * Practice Problem 1: Implement nested loops
 * 
 * Practice implementing nested loops to create patterns or work with 2D structures
 */
TEST_F(ControlFlowPracticeTest, Practice1_NestedLoops) {
    SUCCEED() << "Practice: Try implementing nested loops to print multiplication table or calculate factorial";
}

// ========== PRACTICE PROBLEM 2: DO-WHILE LOOPS ==========

/**
 * Practice Problem 2: Use do-while loops
 * 
 * Practice implementing do-while loops for scenarios where the loop body must execute at least once
 */
TEST_F(ControlFlowPracticeTest, Practice2_DoWhileLoops) {
    SUCCEED() << "Practice: Try implementing a do-while loop version of the sum function";
}

// ========== PRACTICE PROBLEM 3: SWITCH WITH ENUMS ==========

/**
 * Practice Problem 3: Use switch statements with enums
 * 
 * Practice implementing switch statements with enum types
 */
TEST_F(ControlFlowPracticeTest, Practice3_SwitchWithEnums) {
    SUCCEED() << "Practice: Try creating an enum for days of the week and using in a switch statement";
}

// ========== PRACTICE PROBLEM 4: COMPLEX CONDITIONS ==========

/**
 * Practice Problem 4: Use complex conditional expressions
 * 
 * Practice using logical operators (&&, ||, !) in complex conditions
 */
TEST_F(ControlFlowPracticeTest, Practice4_ComplexConditions) {
    SUCCEED() << "Practice: Try implementing a function that checks if a year is a leap year";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(ControlFlowPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own control flow exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Implement more complex control flow
 * 
 * Try implementing algorithms like bubble sort or binary search using control flow
 */
TEST_F(ControlFlowPracticeTest, BonusChallenge_ComplexAlgorithms) {
    SUCCEED() << "Bonus: Implement a simple sorting algorithm using control flow statements";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}