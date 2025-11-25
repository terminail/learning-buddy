// Exercise 16.1b: Class Templates - Solution
// This exercise demonstrates class templates in C++.

#include <iostream>
#include <vector>
#include <string>

// Class template for a simple container
template<typename T>
class SimpleContainer {
private:
    std::vector<T> elements;

public:
    void add(const T& element) {
        elements.push_back(element);
    }
    
    void remove(size_t index) {
        if (index < elements.size()) {
            elements.erase(elements.begin() + index);
        }
    }
    
    T& operator[](size_t index) {
        return elements.at(index);
    }
    
    const T& operator[](size_t index) const {
        return elements.at(index);
    }
    
    size_t size() const {
        return elements.size();
    }
    
    bool empty() const {
        return elements.empty();
    }
};

// Class template with multiple template parameters
template<typename Key, typename Value>
class KeyValuePair {
private:
    Key key;
    Value value;

public:
    KeyValuePair(const Key& k, const Value& v) : key(k), value(v) {}
    
    const Key& getKey() const { return key; }
    const Value& getValue() const { return value; }
    
    void setValue(const Value& v) { value = v; }
};

// Class template with default template parameters
template<typename T = int, typename Container = std::vector<T>>
class Stack {
private:
    Container container;

public:
    void push(const T& item) {
        container.push_back(item);
    }
    
    T pop() {
        if (container.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        T item = container.back();
        container.pop_back();
        return item;
    }
    
    bool empty() const {
        return container.empty();
    }
    
    size_t size() const {
        return container.size();
    }
};

int main() {
    // Test class template with different types
    SimpleContainer<int> int_container;
    int_container.add(1);
    int_container.add(2);
    int_container.add(3);
    
    SimpleContainer<std::string> string_container;
    string_container.add("hello");
    string_container.add("world");
    
    std::cout << "Integer container size: " << int_container.size() << std::endl;
    std::cout << "String container size: " << string_container.size() << std::endl;
    
    // Test class template with multiple template parameters
    KeyValuePair<std::string, int> pair("age", 25);
    std::cout << "Key: " << pair.getKey() << ", Value: " << pair.getValue() << std::endl;
    
    // Test class template with default template parameters
    Stack<> default_stack; // Uses default int and vector<int>
    default_stack.push(10);
    default_stack.push(20);
    std::cout << "Default stack size: " << default_stack.size() << std::endl;
    std::cout << "Popped value: " << default_stack.pop() << std::endl;
    
    Stack<std::string, std::vector<std::string>> string_stack;
    string_stack.push("first");
    string_stack.push("second");
    std::cout << "String stack size: " << string_stack.size() << std::endl;
    std::cout << "Popped value: " << string_stack.pop() << std::endl;
    
    return 0;
}