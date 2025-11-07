#include <gtest/gtest.h>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

// Practice problems for priority queue basics

class PriorityQueueBasicsPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: MIN-HEAP PRIORITY QUEUE ==========

/**
 * Practice Problem 1: Create a min-heap priority queue
 * 
 * Practice using priority queues with custom ordering.
 */
TEST_F(PriorityQueueBasicsPracticeTest, Practice1_MinHeap) {
    // TODO: Practice creating a min-heap priority queue:
    // - Use std::priority_queue with std::greater comparator
    // - Create: std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    // - Verify that smallest elements have highest priority
    // Example approach: Push elements and verify they're removed smallest first
    
    SUCCEED() << "Implement min-heap priority queue practice problem";
}

// ========== PRACTICE PROBLEM 2: CUSTOM OBJECT PRIORITY QUEUE ==========

/**
 * Practice Problem 2: Use priority queues with custom objects
 * 
 * Practice using priority queues with custom comparators for objects.
 */
TEST_F(PriorityQueueBasicsPracticeTest, Practice2_CustomObjects) {
    // TODO: Practice using priority queues with custom objects:
    // - Create a simple struct or class (e.g., Task with priority field)
    // - Implement a custom comparator for the struct/class
    // - Use the priority queue with custom objects
    // Example approach: Create tasks with different priorities and process them
    
    SUCCEED() << "Implement custom object priority queue practice problem";
}

// ========== PRACTICE PROBLEM 3: PRIORITY QUEUE ALGORITHM APPLICATIONS ==========

/**
 * Practice Problem 3: Apply priority queues to algorithmic problems
 * 
 * Practice using priority queues to solve common algorithmic problems.
 */
TEST_F(PriorityQueueBasicsPracticeTest, Practice3_AlgorithmApplications) {
    // TODO: Practice applying priority queues to algorithmic problems:
    // - Implement a simple task scheduler with priorities
    // - Find the kth largest element in an array
    // - Merge k sorted lists
    // Example approach: Implement each algorithm using priority queue operations
    
    SUCCEED() << "Implement priority queue algorithm applications practice problem";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}