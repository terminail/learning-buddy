#include "copy_constructor_exercises.h"
#include <cstring>
#include <algorithm>

// Static member definitions
int SimpleString::constructor_count_ = 0;
int SimpleString::destructor_count_ = 0;
int SimpleString::copy_constructor_count_ = 0;

// SimpleString implementations

// Exercise 1: Default constructor
SimpleString::SimpleString() : data_(nullptr), size_(0) {
    constructor_count_++;
}

// Exercise 2: Constructor with C-string
SimpleString::SimpleString(const char* str) : data_(nullptr), size_(0) {
    constructor_count_++;
    if (str) {
        size_ = std::strlen(str);
        data_ = new char[size_ + 1];
        std::strcpy(data_, str);
    }
}

// Exercise 3: Copy constructor (TODO: Implement this)
SimpleString::SimpleString(const SimpleString& other) {
    // TODO: Implement the copy constructor
    // Hint: Allocate new memory and copy the data from other
    copy_constructor_count_++;
    // Your implementation here
}

// Exercise 4: Destructor
SimpleString::~SimpleString() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    destructor_count_++;
}

// Exercise 5: Assignment operator (TODO: Implement this)
SimpleString& SimpleString::operator=(const SimpleString& other) {
    // TODO: Implement the assignment operator
    // Hint: Check for self-assignment, deallocate current memory, 
    // allocate new memory, and copy data from other
    // Your implementation here
    return *this;
}

// Getters
size_t SimpleString::size() const {
    return size_;
}

const char* SimpleString::c_str() const {
    return data_;
}

// Utility functions for testing
void SimpleString::resetCounts() {
    constructor_count_ = 0;
    destructor_count_ = 0;
    copy_constructor_count_ = 0;
}

int SimpleString::getConstructorCount() {
    return constructor_count_;
}

int SimpleString::getDestructorCount() {
    return destructor_count_;
}

int SimpleString::getCopyConstructorCount() {
    return copy_constructor_count_;
}

// Container implementations

// Exercise 6: Constructor with vector and name
Container::Container(const std::vector<int>& data, const std::string& name) 
    : data_(data), name_(name) {
}

// Exercise 7: Copy constructor (TODO: Implement this)
Container::Container(const Container& other) {
    // TODO: Implement the copy constructor
    // Hint: Member-wise copy is sufficient for std::vector and std::string
    // Your implementation here
}

// Exercise 8: Assignment operator (TODO: Implement this)
Container& Container::operator=(const Container& other) {
    // TODO: Implement the assignment operator
    // Hint: Check for self-assignment and copy data from other
    // Your implementation here
    return *this;
}

// Getters
size_t Container::size() const {
    return data_.size();
}

const std::vector<int>& Container::getData() const {
    return data_;
}

const std::string& Container::getName() const {
    return name_;
}

// Utility functions
void Container::addElement(int element) {
    data_.push_back(element);
}

// PointerWrapper implementations

// Exercise 9: Constructor
PointerWrapper::PointerWrapper(int value) : value_(value) {
    ptr_ = new int(value);
}

// Exercise 10: Copy constructor (TODO: Implement this for deep copy)
PointerWrapper::PointerWrapper(const PointerWrapper& other) {
    // TODO: Implement the copy constructor for deep copy
    // Hint: Allocate new memory for ptr_ and copy the value from other
    // Your implementation here
}

// Exercise 11: Assignment operator (TODO: Implement this for deep copy)
PointerWrapper& PointerWrapper::operator=(const PointerWrapper& other) {
    // TODO: Implement the assignment operator for deep copy
    // Hint: Check for self-assignment, deallocate current memory,
    // allocate new memory, and copy data from other
    // Your implementation here
    return *this;
}

// Exercise 12: Destructor
PointerWrapper::~PointerWrapper() {
    delete ptr_;
    ptr_ = nullptr;
}

// Getters
int PointerWrapper::getValue() const {
    return value_;
}

int PointerWrapper::getPtrValue() const {
    return ptr_ ? *ptr_ : 0;
}

// Setter
void PointerWrapper::setPtrValue(int value) {
    if (ptr_) {
        *ptr_ = value;
    }
}