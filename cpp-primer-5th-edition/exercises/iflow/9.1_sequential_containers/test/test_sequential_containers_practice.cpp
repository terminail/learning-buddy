#include <gtest/gtest.h>
#include "sequential_containers_exercises.h"
#include <stack>
#include <queue>

using namespace cpp_primer;

class SequentialContainersPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: CONTAINER ADAPTERS ==========

/**
 * Practice Problem 1: Use container adapters (stack, queue)
 * 
 * Practice using stack and queue container adapters
 */
TEST_F(SequentialContainersPracticeTest, Practice1_ContainerAdapters) {
    SUCCEED() << "Practice: Try implementing functions that use stack and queue";
}

// ========== PRACTICE PROBLEM 2: ITERATOR OPERATIONS ==========

/**
 * Practice Problem 2: Use iterator operations
 * 
 * Practice using iterator operations like std::advance, std::distance, etc.
 */
TEST_F(SequentialContainersPracticeTest, Practice2_IteratorOperations) {
    SUCCEED() << "Practice: Try implementing functions that use various iterator operations";
}

// ========== PRACTICE PROBLEM 3: CONTAINER COMPARISONS ==========

/**
 * Practice Problem 3: Compare different containers
 * 
 * Practice comparing performance and characteristics of different containers
 */
TEST_F(SequentialContainersPracticeTest, Practice3_ContainerComparisons) {
    SUCCEED() << "Practice: Try implementing timing functions to compare container performance";
}

// ========== PRACTICE PROBLEM 4: CUSTOM CONTAINER OPERATIONS ==========

/**
 * Practice Problem 4: Implement custom container operations
 * 
 * Practice implementing custom algorithms for container operations
 */
TEST_F(SequentialContainersPracticeTest, Practice4_CustomOperations) {
    SUCCEED() << "Practice: Try implementing custom algorithms like reverse or unique";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(SequentialContainersPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own sequential container exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Implement more complex container operations
 * 
 * Try implementing operations like merging sorted containers or finding intersections
 */
TEST_F(SequentialContainersPracticeTest, BonusChallenge_ComplexOperations) {
    SUCCEED() << "Bonus: Try implementing functions to merge sorted containers";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}