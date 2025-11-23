#include <gtest/gtest.h>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <string>

// Practice exercises for container adapters

// TODO: Implement a function that uses a stack to reverse a string
// Requirements:
// 1. Take a const std::string& as input
// 2. Return a std::string with characters in reverse order
// 3. Use std::stack<char> to perform the reversal
std::string reverseStringWithStack(const std::string& input) {
    // Student implementation goes here
    return ""; // Placeholder
}

// TODO: Implement a function that checks if a string has balanced parentheses
// Requirements:
// 1. Take a const std::string& as input
// 2. Return true if all parentheses are balanced, false otherwise
// 3. Consider only '(', ')', '[', ']', '{', '}' characters
// 4. Use std::stack<char> to track opening brackets
bool isBalancedParentheses(const std::string& input) {
    // Student implementation goes here
    return false; // Placeholder
}

// TODO: Implement a function that simulates a printer queue
// Requirements:
// 1. Use std::queue<std::string> to store print jobs
// 2. Support adding jobs with different priorities (represented as strings)
// 3. Support processing the next job in queue
class PrinterQueue {
private:
    std::queue<std::string> jobs;

public:
    // Add a new print job to the queue
    void addJob(const std::string& job) {
        // Student implementation goes here
    }

    // Process the next job (remove and return it)
    std::string processNextJob() {
        // Student implementation goes here
        return ""; // Placeholder
    }

    // Check if queue is empty
    bool isEmpty() const {
        // Student implementation goes here
        return true; // Placeholder
    }

    // Get the number of pending jobs
    size_t getJobCount() const {
        // Student implementation goes here
        return 0; // Placeholder
    }
};

// Tests for string reversal with stack
TEST(ContainerAdaptersPractice, ReverseStringWithStack) {
    EXPECT_EQ("", reverseStringWithStack(""));
    EXPECT_EQ("a", reverseStringWithStack("a"));
    EXPECT_EQ("cba", reverseStringWithStack("abc"));
    EXPECT_EQ("olleh", reverseStringWithStack("hello"));
    EXPECT_EQ("!dlrow ,olleh", reverseStringWithStack("hello, world!"));
}

// Tests for balanced parentheses checking
TEST(ContainerAdaptersPractice, BalancedParentheses) {
    EXPECT_TRUE(isBalancedParentheses(""));
    EXPECT_TRUE(isBalancedParentheses("()"));
    EXPECT_TRUE(isBalancedParentheses("[]"));
    EXPECT_TRUE(isBalancedParentheses("{}"));
    EXPECT_TRUE(isBalancedParentheses("()[]{}"));
    EXPECT_TRUE(isBalancedParentheses("([{}])"));
    EXPECT_TRUE(isBalancedParentheses("((()))"));
    
    EXPECT_FALSE(isBalancedParentheses("("));
    EXPECT_FALSE(isBalancedParentheses(")"));
    EXPECT_FALSE(isBalancedParentheses("([)]"));
    EXPECT_FALSE(isBalancedParentheses("((("));
    EXPECT_FALSE(isBalancedParentheses(")))"));
    EXPECT_FALSE(isBalancedParentheses("({)}"));
}

// Tests for printer queue simulation
TEST(ContainerAdaptersPractice, PrinterQueueBasicOperations) {
    PrinterQueue pq;
    
    // Initially empty
    EXPECT_TRUE(pq.isEmpty());
    EXPECT_EQ(0, pq.getJobCount());
    
    // Add jobs
    pq.addJob("Print Document 1");
    pq.addJob("Print Document 2");
    pq.addJob("Print Document 3");
    
    EXPECT_FALSE(pq.isEmpty());
    EXPECT_EQ(3, pq.getJobCount());
    
    // Process jobs
    EXPECT_EQ("Print Document 1", pq.processNextJob());
    EXPECT_EQ(2, pq.getJobCount());
    
    EXPECT_EQ("Print Document 2", pq.processNextJob());
    EXPECT_EQ(1, pq.getJobCount());
    
    pq.addJob("Print Document 4");
    EXPECT_EQ(2, pq.getJobCount());
    
    EXPECT_EQ("Print Document 3", pq.processNextJob());
    EXPECT_EQ(1, pq.getJobCount());
    
    EXPECT_EQ("Print Document 4", pq.processNextJob());
    EXPECT_TRUE(pq.isEmpty());
    EXPECT_EQ(0, pq.getJobCount());
}