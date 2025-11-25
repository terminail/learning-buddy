#include <gtest/gtest.h>
#include <sstream>
#include <string>

// Practice test for IO operators - students need to implement these
TEST(IOOperatorsPracticeTest, ErrorHandling) {
    // TODO: Create a class with proper IO operators
    // TODO: Test error handling in input operators:
    // - What happens with invalid input (e.g., string for integer)
    // - How to check and handle stream state
    // - Ensuring object state is valid even when input fails
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(IOOperatorsPracticeTest, ComplexObjectIO) {
    // TODO: Create a class with nested objects that also have IO operators
    // TODO: Implement IO operators that correctly handle nested objects
    // TODO: Test that the entire object graph is properly serialized/deserialized
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(IOOperatorsPracticeTest, FormattingOptions) {
    // TODO: Create tests for different formatting options:
    // - Implement flags to control output format
    // - Test with different stream manipulators (setw, setprecision, etc.)
    // - Implement custom manipulators for your class
    
    SUCCEED(); // Placeholder - replace with actual tests
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
