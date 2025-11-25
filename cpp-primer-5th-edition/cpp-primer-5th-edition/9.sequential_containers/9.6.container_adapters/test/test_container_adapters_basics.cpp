#include <gtest/gtest.h>
#include <stack>
#include <queue>
#include <vector>

// Test stack operations
TEST(ContainerAdaptersTest, StackOperations) {
    std::stack<int> int_stack;
    
    // Test empty stack
    EXPECT_TRUE(int_stack.empty());
    EXPECT_EQ(0, int_stack.size());
    
    // Test push operations
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    
    EXPECT_FALSE(int_stack.empty());
    EXPECT_EQ(3, int_stack.size());
    EXPECT_EQ(3, int_stack.top());
    
    // Test pop operations
    int_stack.pop();
    EXPECT_EQ(2, int_stack.top());
    EXPECT_EQ(2, int_stack.size());
    
    int_stack.pop();
    int_stack.pop();
    EXPECT_TRUE(int_stack.empty());
}

// Test queue operations
TEST(ContainerAdaptersTest, QueueOperations) {
    std::queue<std::string> string_queue;
    
    // Test empty queue
    EXPECT_TRUE(string_queue.empty());
    EXPECT_EQ(0, string_queue.size());
    
    // Test push operations
    string_queue.push("First");
    string_queue.push("Second");
    
    EXPECT_FALSE(string_queue.empty());
    EXPECT_EQ(2, string_queue.size());
    EXPECT_EQ("First", string_queue.front());
    EXPECT_EQ("Second", string_queue.back());
    
    // Test pop operations
    string_queue.pop();
    EXPECT_EQ("Second", string_queue.front());
    EXPECT_EQ(1, string_queue.size());
    
    string_queue.pop();
    EXPECT_TRUE(string_queue.empty());
}

// Test priority_queue operations
TEST(ContainerAdaptersTest, PriorityQueueOperations) {
    std::priority_queue<int> max_heap;
    
    // Test empty priority queue
    EXPECT_TRUE(max_heap.empty());
    
    // Test push operations
    max_heap.push(10);
    max_heap.push(30);
    max_heap.push(20);
    
    EXPECT_FALSE(max_heap.empty());
    EXPECT_EQ(30, max_heap.top());  // Max element should be on top
    
    // Test pop operations
    max_heap.pop();
    EXPECT_EQ(20, max_heap.top());  // Next max element
    
    max_heap.pop();
    EXPECT_EQ(10, max_heap.top());
}

// Test different underlying containers
TEST(ContainerAdaptersTest, UnderlyingContainers) {
    // Stack with vector
    std::stack<int, std::vector<int>> vector_stack;
    vector_stack.push(1);
    vector_stack.push(2);
    EXPECT_EQ(2, vector_stack.top());
    
    // Stack with deque
    std::stack<int, std::deque<int>> deque_stack;
    deque_stack.push(1);
    deque_stack.push(2);
    EXPECT_EQ(2, deque_stack.top());
    
    // Queue with deque
    std::queue<int, std::deque<int>> deque_queue;
    deque_queue.push(1);
    deque_queue.push(2);
    EXPECT_EQ(1, deque_queue.front());
    EXPECT_EQ(2, deque_queue.back());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}