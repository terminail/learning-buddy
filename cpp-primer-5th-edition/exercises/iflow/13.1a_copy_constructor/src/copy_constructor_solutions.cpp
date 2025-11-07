#include "copy_constructor_solutions.h"
#include "copy_constructor_exercises.h"
#include <cstring>
#include <algorithm>

// Solutions for SimpleString
SimpleString::SimpleString(const SimpleString& other) : data_(nullptr), size_(0) {
    copy_constructor_count_++;
    if (other.data_) {
        size_ = other.size_;
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
    }
}

SimpleString& SimpleString::operator=(const SimpleString& other) {
    if (this != &other) {  // Self-assignment check
        delete[] data_;  // Deallocate existing memory
        
        if (other.data_) {
            size_ = other.size_;
            data_ = new char[size_ + 1];
            std::strcpy(data_, other.data_);
        } else {
            data_ = nullptr;
            size_ = 0;
        }
    }
    return *this;
}

// Solutions for Container
Container::Container(const Container& other) : data_(other.data_), name_(other.name_) {
    // Member-wise copy is sufficient for std::vector and std::string
}

Container& Container::operator=(const Container& other) {
    if (this != &other) {  // Self-assignment check
        data_ = other.data_;
        name_ = other.name_;
    }
    return *this;
}

// Solutions for PointerWrapper
PointerWrapper::PointerWrapper(const PointerWrapper& other) : value_(other.value_) {
    // Deep copy: allocate new memory for ptr_
    ptr_ = new int(*other.ptr_);
}

PointerWrapper& PointerWrapper::operator=(const PointerWrapper& other) {
    if (this != &other) {  // Self-assignment check
        value_ = other.value_;
        // Deallocate current memory
        delete ptr_;
        // Allocate new memory and copy the value
        ptr_ = new int(*other.ptr_);
    }
    return *this;
}