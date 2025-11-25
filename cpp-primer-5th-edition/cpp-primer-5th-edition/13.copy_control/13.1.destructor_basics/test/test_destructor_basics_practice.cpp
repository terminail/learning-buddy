#include <gtest/gtest.h>
#include <vector>
#include <memory>

// Practice test for destructors - students need to implement these
TEST(DestructorBasicsPracticeTest, HeapObjects) {
    // TODO: Create a class with proper destructor
    // TODO: Create objects on the heap using new
    // TODO: Verify that destructors are NOT called until delete is used
    // TODO: Verify that destructors ARE called when delete is used
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(DestructorBasicsPracticeTest, ContainerDestruction) {
    // TODO: Create a class with proper destructor
    // TODO: Create containers (vector, array, etc.) of these objects
    // TODO: Verify that destructors are called for all contained objects
    //   when the container is destroyed
    // TODO: Test with different container types
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(DestructorBasicsPracticeTest, ExceptionSafety) {
    // TODO: Create tests that demonstrate exception safety with destructors
    // - Create a class that might throw in constructors
    // - Verify that destructors are still called properly for
    //   partially constructed objects
    // - Test the behavior with stack unwinding during exceptions
    
    SUCCEED(); // Placeholder - replace with actual tests
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
