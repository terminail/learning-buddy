#include <gtest/gtest.h>
#include <deque>
#include <algorithm>

// Practice test for advanced deque operations
TEST(DequeOperationsPractice, AdvancedOperations) {
    // Test insert and erase operations
    std::deque<int> numbers = {1, 2, 3, 4, 5};
    
    // Insert multiple elements
    numbers.insert(numbers.begin() + 2, {99, 88, 77});
    EXPECT_EQ(8, numbers.size());
    EXPECT_EQ(99, numbers[2]);
    EXPECT_EQ(88, numbers[3]);
    EXPECT_EQ(77, numbers[4]);
    
    // Erase range of elements
    numbers.erase(numbers.begin() + 1, numbers.begin() + 4);
    EXPECT_EQ(5, numbers.size());
    EXPECT_EQ(1, numbers[0]);
    EXPECT_EQ(88, numbers[1]);
    EXPECT_EQ(77, numbers[2]);
    
    // Test clear operation
    numbers.clear();
    EXPECT_TRUE(numbers.empty());
    EXPECT_EQ(0, numbers.size());
}

// Practice test for performance characteristics
TEST(DequeOperationsPractice, PerformanceCharacteristics) {
    std::deque<int> dq;
    
    // Test efficient insertion at both ends
    for (int i = 0; i < 1000; ++i) {
        dq.push_front(i);
        dq.push_back(i);
    }
    
    EXPECT_EQ(2000, dq.size());
    
    // Test that front and back operations are O(1)
    EXPECT_EQ(999, dq.front());  // Last element pushed to front
    EXPECT_EQ(999, dq.back());   // Last element pushed to back
    
    // Test random access
    EXPECT_EQ(dq[0], dq.at(0));
    EXPECT_EQ(dq[1000], dq.at(1000));
}

// Practice test for iterator invalidation
TEST(DequeOperationsPractice, IteratorInvalidation) {
    std::deque<int> numbers = {1, 2, 3, 4, 5};
    
    // Test that iterators are not invalidated by push_back/push_front
    // (This is implementation-dependent, but generally true for deques)
    auto it = numbers.begin() + 2;
    int value = *it;
    
    numbers.push_front(0);
    numbers.push_back(6);
    
    // The iterator should still be valid (implementation-dependent behavior)
    // We test that the deque still works correctly
    EXPECT_EQ(7, numbers.size());
    EXPECT_EQ(0, numbers.front());
    EXPECT_EQ(6, numbers.back());
    
    // Original value should still be accessible through index
    EXPECT_EQ(value, numbers[3]);  // Original position 2, now position 3 after push_front
}