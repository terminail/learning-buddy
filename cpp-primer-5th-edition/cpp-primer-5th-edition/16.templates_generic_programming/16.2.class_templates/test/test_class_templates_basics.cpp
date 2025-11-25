#include <gtest/gtest.h>
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

// Test for class template with integers
TEST(ClassTemplatesTest, IntegerContainer) {
    SimpleContainer<int> container;
    EXPECT_TRUE(container.empty());
    EXPECT_EQ(container.size(), 0);
    
    container.add(42);
    container.add(100);
    EXPECT_FALSE(container.empty());
    EXPECT_EQ(container.size(), 2);
    EXPECT_EQ(container[0], 42);
    EXPECT_EQ(container[1], 100);
    
    container.remove(0);
    EXPECT_EQ(container.size(), 1);
    EXPECT_EQ(container[0], 100);
}

// Test for class template with strings
TEST(ClassTemplatesTest, StringContainer) {
    SimpleContainer<std::string> container;
    EXPECT_TRUE(container.empty());
    EXPECT_EQ(container.size(), 0);
    
    container.add("hello");
    container.add("world");
    EXPECT_FALSE(container.empty());
    EXPECT_EQ(container.size(), 2);
    EXPECT_EQ(container[0], "hello");
    EXPECT_EQ(container[1], "world");
}

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

// Test for class template with default parameters
TEST(ClassTemplatesTest, StackWithDefaults) {
    Stack<> int_stack; // Uses default parameters
    EXPECT_TRUE(int_stack.empty());
    EXPECT_EQ(int_stack.size(), 0);
    
    int_stack.push(10);
    int_stack.push(20);
    EXPECT_FALSE(int_stack.empty());
    EXPECT_EQ(int_stack.size(), 2);
    EXPECT_EQ(int_stack.pop(), 20);
    EXPECT_EQ(int_stack.pop(), 10);
    EXPECT_TRUE(int_stack.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}