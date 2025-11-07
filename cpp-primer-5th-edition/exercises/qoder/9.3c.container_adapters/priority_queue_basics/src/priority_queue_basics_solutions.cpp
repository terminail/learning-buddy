// Solution 9.3c: Priority Queue Basics
// This exercise demonstrates the std::priority_queue container adapter in C++.

#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Solution: Create an empty priority queue of integers (max-heap by default)
    std::priority_queue<int> int_pq;
    std::cout << "Empty priority queue size: " << int_pq.size() << std::endl;
    
    // Solution: Push several elements into the priority queue
    int_pq.push(10);
    int_pq.push(50);
    int_pq.push(30);
    int_pq.push(20);
    int_pq.push(40);
    std::cout << "Priority queue size after pushing 5 elements: " << int_pq.size() << std::endl;
    
    // Solution: Access the top element of the priority queue without removing it
    std::cout << "Top element (highest priority): " << int_pq.top() << std::endl;
    
    // Solution: Remove elements from the priority queue
    std::cout << "Removing elements from priority queue (highest priority first):" << std::endl;
    while (!int_pq.empty()) {
        std::cout << "Top element: " << int_pq.top() << std::endl;
        int_pq.pop();
    }
    
    // Solution: Check if the priority queue is empty
    if (int_pq.empty()) {
        std::cout << "Priority queue is now empty" << std::endl;
    } else {
        std::cout << "Priority queue is not empty" << std::endl;
    }
    
    // Solution: Get the size of the priority queue
    std::cout << "Final priority queue size: " << int_pq.size() << std::endl;
    
    return 0;
}