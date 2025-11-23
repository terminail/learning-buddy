#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <vector>

// Practice test for smart pointers - students need to implement these
TEST(SmartPointersBasicsPracticeTest, CustomDeleters) {
    // TODO: Create a unique_ptr with a custom deleter
    // - Define a custom deleter function or lambda
    // - Create a unique_ptr that uses this custom deleter
    // - Verify that the custom deleter is called when the pointer is destroyed
    
    // Example custom deleter:
    // auto custom_deleter = [](int* ptr) {
    //     std::cout << "Custom deleter called for ptr: " << ptr << std::endl;
    //     delete ptr;
    // };
    // std::unique_ptr<int, decltype(custom_deleter)> ptr(new int(42), custom_deleter);
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(SmartPointersBasicsPracticeTest, SharedPtrCyclicReferences) {
    // TODO: Create a scenario that demonstrates cyclic references with shared_ptr
    // - Create two classes that reference each other with shared_ptr
    // - Show how this creates a memory leak
    // - Demonstrate how to fix it using weak_ptr
    
    // Example structure:
    // class Node {
    // public:
    //     std::shared_ptr<Node> next;
    //     std::weak_ptr<Node> parent;  // Use weak_ptr to break cycles
    // };
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(SmartPointersBasicsPracticeTest, ExceptionSafety) {
    // TODO: Create tests that demonstrate exception safety with smart pointers
    // - Create a function that might throw an exception
    // - Show how make_unique provides exception safety
    // - Compare with manual memory management
    
    // Example:
    // auto ptr = std::make_unique<int>(throwing_function());  // Safe - no leak if exception thrown
    // vs
    // int* raw_ptr = new int(throwing_function());  // Potential leak if exception thrown
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(SmartPointersBasicsPracticeTest, PerformanceComparison) {
    // TODO: Create tests that compare performance of different smart pointer approaches
    // - Compare make_shared vs shared_ptr constructor
    // - Compare unique_ptr vs raw pointers (for educational purposes)
    // - Measure construction/destruction times
    
    SUCCEED(); // Placeholder - replace with actual tests
}