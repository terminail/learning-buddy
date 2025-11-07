#include <gtest/gtest.h>
#include <iostream>
#include <string>

// Practice problems for class basics

class ClassBasicsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: MULTIPLE CONSTRUCTORS ==========

/**
 * Practice Problem 1: Implement multiple constructors
 * 
 * Practice creating classes with multiple constructors.
 */
TEST_F(ClassBasicsPracticeTest, Practice1_MultipleConstructors) {
    // TODO: Practice implementing multiple constructors:
    // - Create a class with a default constructor
    // - Create a class with a parameterized constructor
    // - Create a class with a copy constructor
    // Example approach: Try defining different ways to create objects
    
    SUCCEED() << "Implement multiple constructors practice problem";
}

// ========== PRACTICE PROBLEM 2: CONST MEMBER FUNCTIONS ==========

/**
 * Practice Problem 2: Use const member functions
 * 
 * Practice using const correctness in member functions.
 */
TEST_F(ClassBasicsPracticeTest, Practice2_ConstMemberFunctions) {
    // TODO: Practice using const member functions:
    // - Create const member functions that don't modify data
    // - Create non-const member functions that do modify data
    // - Understand when to use const objects
    // Example approach: Try using const objects and functions
    
    SUCCEED() << "Implement const member functions practice problem";
}

// ========== PRACTICE PROBLEM 3: CLASS WITH CONTAINER MEMBERS ==========

/**
 * Practice Problem 3: Create classes with container members
 * 
 * Practice creating classes that contain STL containers.
 */
TEST_F(ClassBasicsPracticeTest, Practice3_ClassWithContainers) {
    // TODO: Practice creating classes with container members:
    // - Create a class with std::vector as a member
    // - Create a class with std::string as a member
    // - Implement functions to manipulate container members
    // Example approach: Try creating classes with complex data members
    
    SUCCEED() << "Implement class with container members practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}