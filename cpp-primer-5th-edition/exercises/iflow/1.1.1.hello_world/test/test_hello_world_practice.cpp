#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <streambuf>

class HelloWorldPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: MODIFY MESSAGES ==========

/**
 * Practice Problem 1: Modify the output message
 * 
 * In the exercise file, modify the main function to output a different message.
 * For example: "Welcome to C++!" or "Hello, C++ World!"
 */
TEST_F(HelloWorldPracticeTest, Practice1_ModifyMessage) {
    SUCCEED() << "Practice: Try changing the output message in the exercise file";
}

// ========== PRACTICE PROBLEM 2: ADD ADDITIONAL OUTPUT ==========

/**
 * Practice Problem 2: Add additional output
 * 
 * In the exercise file, modify the main function to add extra output lines.
 * For example: Output your name or the current date
 */
TEST_F(HelloWorldPracticeTest, Practice2_AdditionalOutput) {
    SUCCEED() << "Practice: Try adding more output lines to the exercise";
}

// ========== PRACTICE PROBLEM 3: USE DIFFERENT OUTPUT METHODS ==========

/**
 * Practice Problem 3: Use different output methods
 * 
 * Try using different ways to output "Hello, World!" 
 * For example: Using std::printf or std::cerr
 */
TEST_F(HelloWorldPracticeTest, Practice3_DifferentOutputMethods) {
    SUCCEED() << "Practice: Try using different output methods like printf";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(HelloWorldPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own variations of Hello World";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}