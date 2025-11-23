#include <iostream>
#include <vector>
#include <string>
#include <utility>

// Simple class to demonstrate move semantics
class SimpleString {
private:
    char* data;
    size_t len;

public:
    // Solution: Implement constructors
    // Default constructor
    SimpleString() : data(nullptr), len(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    
    // Parameterized constructor
    SimpleString(const char* s) : len(strlen(s)) {
        data = new char[len + 1];
        strcpy(data, s);
        std::cout << "Parameterized constructor called for: " << s << std::endl;
    }
    
    // Copy constructor
    SimpleString(const SimpleString& other) : len(other.len) {
        data = new char[len + 1];
        strcpy(data, other.data);
        std::cout << "Copy constructor called for: " << data << std::endl;
    }
    
    // Move constructor (NEW - this is what we're learning!)
    SimpleString(SimpleString&& other) noexcept : data(other.data), len(other.len) {
        other.data = nullptr;
        other.len = 0;
        std::cout << "Move constructor called" << std::endl;
    }
    
    // Solution: Implement assignment operators
    // Copy assignment operator
    SimpleString& operator=(const SimpleString& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    
    // Move assignment operator (NEW - this is what we're learning!)
    SimpleString& operator=(SimpleString&& other) noexcept {
        std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) {
            delete[] data;
            data = other.data;
            len = other.len;
            other.data = nullptr;
            other.len = 0;
        }
        return *this;
    }
    
    // Solution: Implement destructor
    ~SimpleString() {
        std::cout << "Destructor called for: " << (data ? data : "nullptr") << std::endl;
        delete[] data;
    }
    
    // Solution: Implement utility functions
    size_t length() const { return len; }
    const char* c_str() const { return data; }
    
    // Solution: Implement a print function to show when constructors/destructors are called
    void print() const {
        std::cout << "SimpleString: " << (data ? data : "nullptr") << std::endl;
    }
};

// Solution: Work with std::move to enable move operations
void move_function_exercises() {
    std::cout << "=== Move Function Exercises ===" << std::endl;
    
    // Solution 1: Observe copy operations
    std::cout << "\n1. Copy operations:" << std::endl;
    SimpleString str1("Hello");
    SimpleString str2 = str1;  // Copy constructor called
    str1.print();
    str2.print();
    
    // Solution 2: Use std::move to enable move operations
    std::cout << "\n2. Move operations:" << std::endl;
    SimpleString str3("World");
    SimpleString str4 = std::move(str3);  // Move constructor called
    str3.print();  // Should show nullptr
    str4.print();
    
    // Solution 3: Work with containers and move operations
    std::cout << "\n3. Container move operations:" << std::endl;
    std::vector<SimpleString> vec;
    vec.reserve(3);  // Reserve space to avoid reallocations
    
    SimpleString temp1("First");
    vec.push_back(std::move(temp1));  // Move instead of copy
    
    SimpleString temp2("Second");
    vec.push_back(std::move(temp2));  // Move instead of copy
}

// Solution: Work with std::forward for perfect forwarding
template<typename T>
void process_forwarded(T&& param) {
    std::cout << "Processing forwarded parameter" << std::endl;
    // Just for demonstration - in real code, we'd do something with the parameter
}

template<typename T>
void wrapper_function(T&& param) {
    // Solution: Use std::forward to perfectly forward the parameter
    process_forwarded(std::forward<T>(param));
}

void demonstrate_forwarding(const char* value) {
    std::cout << "Forwarding lvalue: " << value << std::endl;
}

void demonstrate_forwarding(char*&& value) {
    std::cout << "Forwarding rvalue: " << value << std::endl;
}

void perfect_forwarding_exercises() {
    std::cout << "\n=== Perfect Forwarding Exercises ===" << std::endl;
    
    // Solution 1: Understand the difference between std::move and std::forward
    SimpleString lvalue_str("LValue");
    SimpleString rvalue_str("RValue");
    
    std::cout << "\n1. Demonstrating std::move vs std::forward:" << std::endl;
    // std::move always produces an rvalue
    SimpleString moved_str = std::move(lvalue_str);
    
    // For std::forward, we need to see it in a template context
    char lvalue_text[] = "LValue Text";
    wrapper_function(lvalue_text);  // lvalue forwarded as lvalue
    
    char* rvalue_text = new char[15];
    strcpy(rvalue_text, "RValue Text");
    wrapper_function(std::move(rvalue_text));  // rvalue forwarded as rvalue
    delete[] rvalue_text;
    
    // Solution 2: Create a factory function using perfect forwarding
    std::cout << "\n2. Factory function with perfect forwarding:" << std::endl;
    // This would typically be implemented as:
    // template<typename... Args>
    // auto make_simple_string(Args&&... args) {
    //     return SimpleString(std::forward<Args>(args)...);
    // }
    
    // Solution 3: Work with variadic templates and perfect forwarding
    std::cout << "\n3. Variadic templates and perfect forwarding concept:" << std::endl;
    // This would typically be implemented as:
    // template<typename... Args>
    // void emplace_back(Args&&... args) {
    //     // Construct element in place using std::forward
    //     // new(storage_ptr) T(std::forward<Args>(args)...);
    // }
}

// Solution: Practice with move-only types
class MoveOnlyClass {
public:
    MoveOnlyClass() = default;
    
    // Move constructor (no copy constructor)
    MoveOnlyClass(MoveOnlyClass&&) = default;
    MoveOnlyClass& operator=(MoveOnlyClass&&) = default;
    
    // Delete copy operations
    MoveOnlyClass(const MoveOnlyClass&) = delete;
    MoveOnlyClass& operator=(const MoveOnlyClass&) = delete;
    
    void print() const {
        std::cout << "MoveOnlyClass instance" << std::endl;
    }
};

void move_only_exercises() {
    std::cout << "\n=== Move-Only Type Exercises ===" << std::endl;
    
    // Solution 1: Create a move-only class
    std::cout << "\n1. Move-only class:" << std::endl;
    MoveOnlyClass obj1;
    obj1.print();
    
    // Move the object (this works)
    MoveOnlyClass obj2 = std::move(obj1);
    obj2.print();
    
    // Solution 2: Work with std::unique_ptr (which is move-only)
    std::cout << "\n2. Working with unique_ptr (move-only):" << std::endl;
    auto ptr1 = std::make_unique<SimpleString>("Unique");
    std::cout << "Created unique_ptr" << std::endl;
    
    // Move the unique_ptr (this works)
    auto ptr2 = std::move(ptr1);
    std::cout << "Moved unique_ptr" << std::endl;
    std::cout << "ptr1 is " << (ptr1 ? "valid" : "null") << std::endl;
    std::cout << "ptr2 is " << (ptr2 ? "valid" : "null") << std::endl;
    
    // Solution 3: Understand when move-only types are useful
    std::cout << "\n3. Move-only types are useful for:" << std::endl;
    std::cout << "   - Resource management (unique_ptr, unique_lock)" << std::endl;
    std::cout << "   - Thread handles (std::thread)" << std::endl;
    std::cout << "   - File handles" << std::endl;
    std::cout << "   - Any scenario requiring exclusive ownership" << std::endl;
}

int main() {
    std::cout << "Chapter 20.1: Move Semantics Basics Solution" << std::endl;
    std::cout << "===========================================" << std::endl;
    
    move_function_exercises();
    perfect_forwarding_exercises();
    move_only_exercises();
    
    std::cout << "\nSolution completed!" << std::endl;
    return 0;
}