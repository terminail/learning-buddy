// Exercise: Container Adapters - Solution
// This exercise demonstrates container adapters in C++.

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <deque>

int main() {
    // Solution: Work with std::stack operations
    std::stack<int> int_stack;
    
    // Push elements
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    
    std::cout << "Stack size: " << int_stack.size() << std::endl;
    std::cout << "Top element: " << int_stack.top() << std::endl;
    
    // Pop elements (LIFO - Last In, First Out)
    while (!int_stack.empty()) {
        std::cout << "Popping: " << int_stack.top() << std::endl;
        int_stack.pop();
    }
    
    // Stack with different underlying container
    std::stack<int, std::vector<int>> vector_stack;
    vector_stack.push(10);
    vector_stack.push(20);
    std::cout << "Vector stack top: " << vector_stack.top() << std::endl;

    // Solution: Work with std::queue operations
    std::queue<std::string> string_queue;
    
    // Push elements
    string_queue.push("First");
    string_queue.push("Second");
    string_queue.push("Third");
    
    std::cout << "Queue size: " << string_queue.size() << std::endl;
    std::cout << "Front element: " << string_queue.front() << std::endl;
    std::cout << "Back element: " << string_queue.back() << std::endl;
    
    // Pop elements (FIFO - First In, First Out)
    while (!string_queue.empty()) {
        std::cout << "Processing: " << string_queue.front() << std::endl;
        string_queue.pop();
    }

    // Solution: Work with std::priority_queue operations
    std::priority_queue<int> max_heap;
    
    // Push elements
    max_heap.push(10);
    max_heap.push(30);
    max_heap.push(20);
    max_heap.push(5);
    
    std::cout << "Priority queue size: " << max_heap.size() << std::endl;
    
    // Pop elements (highest priority first)
    while (!max_heap.empty()) {
        std::cout << "Highest priority: " << max_heap.top() << std::endl;
        max_heap.pop();
    }
    
    // Min-heap using custom comparator
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    min_heap.push(10);
    min_heap.push(30);
    min_heap.push(20);
    min_heap.push(5);
    
    std::cout << "Min-heap elements: ";
    while (!min_heap.empty()) {
        std::cout << min_heap.top() << " ";
        min_heap.pop();
    }
    std::cout << std::endl;

    // Solution: Compare container adapter characteristics
    // Stack with deque (default)
    std::stack<int, std::deque<int>> deque_stack;
    
    // Queue with deque (default)
    std::queue<int, std::deque<int>> deque_queue;
    
    // Both work similarly but have different underlying container requirements
    deque_stack.push(42);
    deque_queue.push(42);
    
    std::cout << "Stack top: " << deque_stack.top() << std::endl;
    std::cout << "Queue front: " << deque_queue.front() << std::endl;
    
    return 0;
}