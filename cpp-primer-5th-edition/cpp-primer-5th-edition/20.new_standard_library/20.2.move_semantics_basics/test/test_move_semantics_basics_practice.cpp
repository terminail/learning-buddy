#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <utility>

// Practice test for move semantics - students need to implement these
TEST(MoveSemanticsBasicsPracticeTest, PerfectForwarding) {
    // TODO: Create tests that demonstrate perfect forwarding
    // - Create a template function that uses std::forward
    // - Show how it preserves value categories
    // - Demonstrate with both lvalue and rvalue arguments
    
    // Example:
    // template<typename T>
    // void wrapper(T&& param) {
    //     some_function(std::forward<T>(param));
    // }
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(MoveSemanticsBasicsPracticeTest, MoveOnlyTypes) {
    // TODO: Create tests for move-only types
    // - Define a class that is move-only (no copy operations)
    // - Test that copy operations are disabled (compilation should fail)
    // - Test that move operations work correctly
    // - Verify resource management with move-only types
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(MoveSemanticsBasicsPracticeTest, ExceptionSafety) {
    // TODO: Create tests that demonstrate exception safety with move operations
    // - Create a class with throwing constructors
    // - Show how move operations can provide strong exception safety
    // - Test noexcept specifications on move constructors/assignment operators
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(MoveSemanticsBasicsPracticeTest, PerformanceComparison) {
    // TODO: Create tests that measure performance difference between
    // copy and move operations
    // - Create a class with expensive copy operations
    // - Measure time for copying vs moving objects
    // - Test with containers (vector push_back, etc.)
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(MoveSemanticsBasicsPracticeTest, ReturnValueOptimization) {
    // TODO: Create tests that demonstrate return value optimization
    // - Create functions that return objects by value
    // - Show when RVO and NRVO apply
    // - Compare with explicit std::move (which can be harmful)
    
    SUCCEED(); // Placeholder - replace with actual tests
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}