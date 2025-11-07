#ifndef COPY_CONSTRUCTOR_EXERCISES_H
#define COPY_CONSTRUCTOR_EXERCISES_H

#include <cstddef>
#include <string>
#include <vector>

// A class with dynamically allocated memory to demonstrate copy constructor concepts
class SimpleString {
private:
    char* data_;
    size_t size_;
    static int constructor_count_;
    static int destructor_count_;
    static int copy_constructor_count_;

public:
    // Exercise 1: Default constructor
    SimpleString();
    
    // Exercise 2: Constructor with C-string
    SimpleString(const char* str);
    
    // Exercise 3: Copy constructor (TODO: Implement this)
    SimpleString(const SimpleString& other);
    
    // Exercise 4: Destructor
    ~SimpleString();
    
    // Exercise 5: Assignment operator (TODO: Implement this)
    SimpleString& operator=(const SimpleString& other);
    
    // Getters
    size_t size() const;
    const char* c_str() const;
    
    // Utility functions for testing
    static void resetCounts();
    static int getConstructorCount();
    static int getDestructorCount();
    static int getCopyConstructorCount();
};

// A class with a vector member to demonstrate copy constructor behavior with standard containers
class Container {
private:
    std::vector<int> data_;
    std::string name_;

public:
    // Exercise 6: Constructor with vector and name
    Container(const std::vector<int>& data, const std::string& name);
    
    // Exercise 7: Copy constructor (TODO: Implement this)
    Container(const Container& other);
    
    // Exercise 8: Assignment operator (TODO: Implement this)
    Container& operator=(const Container& other);
    
    // Getters
    size_t size() const;
    const std::vector<int>& getData() const;
    const std::string& getName() const;
    
    // Utility functions
    void addElement(int element);
};

// A class with pointer members to demonstrate deep vs shallow copy
class PointerWrapper {
private:
    int* ptr_;
    int value_;

public:
    // Exercise 9: Constructor
    PointerWrapper(int value);
    
    // Exercise 10: Copy constructor (TODO: Implement this for deep copy)
    PointerWrapper(const PointerWrapper& other);
    
    // Exercise 11: Assignment operator (TODO: Implement this for deep copy)
    PointerWrapper& operator=(const PointerWrapper& other);
    
    // Exercise 12: Destructor
    ~PointerWrapper();
    
    // Getters
    int getValue() const;
    int getPtrValue() const;
    
    // Setter
    void setPtrValue(int value);
};

#endif // COPY_CONSTRUCTOR_EXERCISES_H