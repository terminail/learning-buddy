#include <gtest/gtest.h>
#include <vector>

// Practice test for copy constructor - students need to implement these
TEST(CopyConstructorBasicsPracticeTest, VectorOfObjects) {
    // TODO: Create a class that properly implements copy constructor
    // TODO: Create a vector of these objects
    // TODO: Add objects to the vector
    // TODO: Copy the vector and verify that copy constructors are called
    // TODO: Verify that the copied vector has independent objects
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(CopyConstructorBasicsPracticeTest, CopyConstructorInvocation) {
    // TODO: Create tests that verify when copy constructors are called:
    // - When passing by value to functions
    // - When returning by value from functions
    // - When throwing/catching exceptions by value
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(CopyConstructorBasicsPracticeTest, ShallowVsDeepCopy) {
    // TODO: Create a class that demonstrates the problem with shallow copy
    // - Implement a class with a shallow copy constructor (incorrect)
    // - Show how it leads to problems (double deletion, data corruption)
    // - Implement the same class with a deep copy constructor (correct)
    // - Show how it fixes the problems
    
    SUCCEED(); // Placeholder - replace with actual tests
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
