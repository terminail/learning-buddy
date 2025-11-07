#include <gtest/gtest.h>
#include "map_operations_exercises.h"
#include <map>
#include <unordered_map>

using namespace cpp_primer;

class MapOperationsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: MAP ITERATION ==========

/**
 * Practice Problem 1: Iterate through map elements
 * 
 * Practice different ways to iterate through map elements
 */
TEST_F(MapOperationsPracticeTest, Practice1_MapIteration) {
    SUCCEED() << "Practice: Try implementing functions that iterate through maps in different ways";
}

// ========== PRACTICE PROBLEM 2: MAP COMPARISONS ==========

/**
 * Practice Problem 2: Compare maps
 * 
 * Practice comparing maps for equality and other operations
 */
TEST_F(MapOperationsPracticeTest, Practice2_MapComparisons) {
    SUCCEED() << "Practice: Try implementing functions that compare maps";
}

// ========== PRACTICE PROBLEM 3: MAP PERFORMANCE ==========

/**
 * Practice Problem 3: Analyze map performance
 * 
 * Practice analyzing performance characteristics of map operations
 */
TEST_F(MapOperationsPracticeTest, Practice3_MapPerformance) {
    SUCCEED() << "Practice: Try implementing timing functions to compare map operation performance";
}

// ========== PRACTICE PROBLEM 4: NESTED MAPS ==========

/**
 * Practice Problem 4: Work with nested maps
 * 
 * Practice creating and using maps of maps
 */
TEST_F(MapOperationsPracticeTest, Practice4_NestedMaps) {
    SUCCEED() << "Practice: Try implementing functions that work with nested maps";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(MapOperationsPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own map operation exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Implement more complex map operations
 * 
 * Try implementing operations like merging maps or finding intersections
 */
TEST_F(MapOperationsPracticeTest, BonusChallenge_ComplexOperations) {
    SUCCEED() << "Bonus: Try implementing functions that merge two maps";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}