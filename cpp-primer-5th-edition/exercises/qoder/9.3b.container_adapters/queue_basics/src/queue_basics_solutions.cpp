// Solution 9.3b: Queue Basics
// This exercise demonstrates the std::queue container adapter in C++.

#include <iostream>
#include <queue>
#include <deque>

int main() {
    // Solution: Create an empty queue of integers
    std::queue<int> int_queue;
    std::cout << "Empty queue size: " << int_queue.size() << std::endl;
    
    // Solution: Push several elements into the queue
    int_queue.push(10);
    int_queue.push(20);
    int_queue.push(30);
    int_queue.push(40);
    int_queue.push(50);
    std::cout << "Queue size after pushing 5 elements: " << int_queue.size() << std::endl;
    
    // Solution: Access the front and back elements of the queue without removing them
    std::cout << "Front element: " << int_queue.front() << std::endl;
    std::cout << "Back element: " << int_queue.back() << std::endl;
    
    // Solution: Remove elements from the queue
    std::cout << "Removing elements from queue:" << std::endl;
    while (!int_queue.empty()) {
        std::cout << "Front element: " << int_queue.front() << std::endl;
        int_queue.pop();
    }
    
    // Solution: Check if the queue is empty
    if (int_queue.empty()) {
        std::cout << "Queue is now empty" << std::endl;
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }
    
    // Solution: Get the size of the queue
    std::cout << "Final queue size: " << int_queue.size() << std::endl;
    
    return 0;
}