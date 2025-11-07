#include <gtest/gtest.h>
#include "classes_exercises.h"

using namespace cpp_primer;

class ClassesPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: COPY CONSTRUCTOR ==========

/**
 * Practice Problem 1: Implement copy constructor and assignment operator
 * 
 * Practice implementing copy constructor and assignment operator for classes
 */
TEST_F(ClassesPracticeTest, Practice1_CopyConstructor) {
    SUCCEED() << "Practice: Try implementing copy constructor and assignment operator for Point and Student classes";
}

// ========== PRACTICE PROBLEM 2: OPERATOR OVERLOADING ==========

/**
 * Practice Problem 2: Overload operators for classes
 * 
 * Practice overloading operators like ==, <, + for classes
 */
TEST_F(ClassesPracticeTest, Practice2_OperatorOverloading) {
    SUCCEED() << "Practice: Try overloading operators for Point class (e.g., ==, <, +)";
}

// ========== PRACTICE PROBLEM 3: CONST MEMBER FUNCTIONS ==========

/**
 * Practice Problem 3: Use const member functions
 * 
 * Practice marking member functions as const when they don't modify object state
 */
TEST_F(ClassesPracticeTest, Practice3_ConstMemberFunctions) {
    SUCCEED() << "Practice: Review which member functions should be marked as const";
}

// ========== PRACTICE PROBLEM 4: STATIC MEMBERS ==========

/**
 * Practice Problem 4: Use static members
 * 
 * Practice adding static members to classes for shared data
 */
TEST_F(ClassesPracticeTest, Practice4_StaticMembers) {
    SUCCEED() << "Practice: Try adding a static member to Student class to track total number of students";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(ClassesPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own class exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Implement inheritance
 * 
 * Try implementing inheritance by creating a derived class from Point or Student
 */
TEST_F(ClassesPracticeTest, BonusChallenge_Inheritance) {
    SUCCEED() << "Bonus: Try creating a derived class like GraduateStudent from Student";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}