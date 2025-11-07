#include <gtest/gtest.h>
#include "strings_vectors_exercises.h"
#include <algorithm>

using namespace cpp_primer;

class StringsVectorsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: STRING MANIPULATION ==========

/**
 * Practice Problem 1: String manipulation functions
 * 
 * In the exercise file, implement additional string manipulation functions
 * such as reversing a string, counting characters, or finding substrings
 */
TEST_F(StringsVectorsPracticeTest, Practice1_StringManipulation) {
    SUCCEED() << "Practice: Try implementing additional string manipulation functions";
}

// ========== PRACTICE PROBLEM 2: VECTOR ALGORITHMS ==========

/**
 * Practice Problem 2: Use STL algorithms with vectors
 * 
 * Practice using algorithms like std::find, std::sort, std::reverse with vectors
 */
TEST_F(StringsVectorsPracticeTest, Practice2_VectorAlgorithms) {
    SUCCEED() << "Practice: Try using STL algorithms with vectors";
}

// ========== PRACTICE PROBLEM 3: STRING AND VECTOR COMBINATIONS ==========

/**
 * Practice Problem 3: Work with vectors of strings
 * 
 * Create functions that work with std::vector<std::string>
 */
TEST_F(StringsVectorsPracticeTest, Practice3_VectorOfString) {
    SUCCEED() << "Practice: Try working with vectors of strings";
}

// ========== PRACTICE PROBLEM 4: RANGE-BASED LOOPS ==========

/**
 * Practice Problem 4: Use range-based for loops
 * 
 * Practice iterating through strings and vectors using range-based for loops
 */
TEST_F(StringsVectorsPracticeTest, Practice4_RangeBasedLoops) {
    SUCCEED() << "Practice: Use range-based for loops with containers";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(StringsVectorsPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own string and vector exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Implement more complex operations
 * 
 * Try implementing operations like string tokenization or vector filtering
 */
TEST_F(StringsVectorsPracticeTest, BonusChallenge_ComplexOperations) {
    SUCCEED() << "Bonus: Implement complex string and vector operations";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}