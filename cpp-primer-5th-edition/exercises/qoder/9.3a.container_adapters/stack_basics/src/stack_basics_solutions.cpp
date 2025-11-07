// Solution 9.3a: Stack Basics
// This exercise demonstrates the std::stack container adapter in C++.

#include <iostream>
#include <stack>
#include <vector>

int main() {
    // Solution: Create an empty stack of integers
    std::stack<int> int_stack;
    std::cout << "Empty stack size: " << int_stack.size() << std::endl;
    
    // Solution: Push several elements onto the stack
    int_stack.push(10);
    int_stack.push(20);
    int_stack.push(30);
    int_stack.push(40);
    int_stack.push(50);
    std::cout << "Stack size after pushing 5 elements: " << int_stack.size() << std::endl;
    
    // Solution: Check the top element of the stack without removing it
    std::cout << "Top element: " << int_stack.top() << std::endl;
    
    // Solution: Remove elements from the stack
    std::cout << "Removing elements from stack:" << std::endl;
    while (!int_stack.empty()) {
        std::cout << "Popping: " << int_stack.top() << std::endl;
        int_stack.pop();
    }
    
    // Solution: Check if the stack is empty
    if (int_stack.empty()) {
        std::cout << "Stack is now empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }
    
    // Solution: Get the size of the stack
    std::cout << "Final stack size: " << int_stack.size() << std::endl;
    
    return 0;
}