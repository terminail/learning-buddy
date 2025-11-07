#include <gtest/gtest.h>
#include "generic_algorithms_exercises.h"
#include <set>
#include <map>

using namespace cpp_primer;

class GenericAlgorithmsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: LAMBDA EXPRESSIONS ==========

/**
 * Practice Problem 1: Use lambda expressions with algorithms
 * 
 * Practice using lambda expressions as predicates and functions with STL algorithms
 */
TEST_F(GenericAlgorithmsPracticeTest, Practice1_LambdaExpressions) {
    SUCCEED() << "Practice: Try implementing functions that use lambda expressions with various algorithms";
}

// ========== PRACTICE PROBLEM 2: FUNCTION OBJECTS ==========

/**
 * Practice Problem 2: Use function objects (functors)
 * 
 * Practice creating and using function objects with algorithms
 */
TEST_F(GenericAlgorithmsPracticeTest, Practice2_FunctionObjects) {
    SUCCEED() << "Practice: Try implementing custom function objects for use with algorithms";
}

// ========== PRACTICE PROBLEM 3: CUSTOM ALGORITHMS ==========

/**
 * Practice Problem 3: Implement custom algorithms
 * 
 * Practice implementing custom algorithms similar to STL algorithms
 */
TEST_F(GenericAlgorithmsPracticeTest, Practice3_CustomAlgorithms) {
    SUCCEED() << "Practice: Try implementing your own version of common STL algorithms";
}

// ========== PRACTICE PROBLEM 4: ALGORITHM COMPLEXITY ==========

/**
 * Practice Problem 4: Analyze algorithm complexity
 * 
 * Practice analyzing and comparing the complexity of different algorithms
 */
TEST_F(GenericAlgorithmsPracticeTest, Practice4_AlgorithmComplexity) {
    SUCCEED() << "Practice: Try implementing timing functions to compare algorithm performance";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(GenericAlgorithmsPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own generic algorithm exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Implement more complex algorithms
 * 
 * Try implementing operations like set operations or custom sorting algorithms
 */
TEST_F(GenericAlgorithmsPracticeTest, BonusChallenge_ComplexAlgorithms) {
    SUCCEED() << "Bonus: Try implementing functions that use set operations like union or intersection";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}