#include "smart_pointers_exercises.h"
#include <string>
#include <memory>

// Implementation of SimpleClass
SimpleClass::SimpleClass(int value, const std::string& name) 
    : value_(value), name_(name) {
}

SimpleClass::~SimpleClass() {
    // Destructor intentionally left empty
}

int SimpleClass::getValue() const {
    return value_;
}

std::string SimpleClass::getName() const {
    return name_;
}

void SimpleClass::setValue(int value) {
    value_ = value;
}

void SimpleClass::setName(const std::string& name) {
    name_ = name;
}

// Exercise 1: Create and return a unique_ptr to a SimpleClass object
std::unique_ptr<SimpleClass> SmartPointers::createUniquePtr(int value, const std::string& name) {
    // TODO: Implement this function to create and return a unique_ptr to a SimpleClass object
    // Hint: Use std::make_unique or new with std::unique_ptr constructor
    return std::unique_ptr<SimpleClass>(); // Replace this with your implementation
}

// Exercise 2: Create and return a shared_ptr to a SimpleClass object
std::shared_ptr<SimpleClass> SmartPointers::createSharedPtr(int value, const std::string& name) {
    // TODO: Implement this function to create and return a shared_ptr to a SimpleClass object
    // Hint: Use std::make_shared or new with std::shared_ptr constructor
    return std::shared_ptr<SimpleClass>(); // Replace this with your implementation
}

// Exercise 3: Get the value from a unique_ptr to SimpleClass
int SmartPointers::getValueFromUniquePtr(const std::unique_ptr<SimpleClass>& ptr) {
    // TODO: Implement this function to get the value from a unique_ptr to SimpleClass
    // Hint: Use the -> operator or .get() method
    return 0; // Replace this with your implementation
}

// Exercise 4: Get the value from a shared_ptr to SimpleClass
int SmartPointers::getValueFromSharedPtr(const std::shared_ptr<SimpleClass>& ptr) {
    // TODO: Implement this function to get the value from a shared_ptr to SimpleClass
    // Hint: Use the -> operator
    return 0; // Replace this with your implementation
}

// Exercise 5: Reset a unique_ptr to point to a new SimpleClass object
void SmartPointers::resetUniquePtr(std::unique_ptr<SimpleClass>& ptr, int value, const std::string& name) {
    // TODO: Implement this function to reset the unique_ptr to point to a new SimpleClass object
    // Hint: Use the reset() method
}

// Exercise 6: Reset a shared_ptr to point to a new SimpleClass object
void SmartPointers::resetSharedPtr(std::shared_ptr<SimpleClass>& ptr, int value, const std::string& name) {
    // TODO: Implement this function to reset the shared_ptr to point to a new SimpleClass object
    // Hint: Use assignment or reset() method
}

// Exercise 7: Get the reference count of a shared_ptr
long SmartPointers::getSharedRefCount(const std::shared_ptr<SimpleClass>& ptr) {
    // TODO: Implement this function to get the reference count of a shared_ptr
    // Hint: Use the use_count() method
    return 0; // Replace this with your implementation
}

// Exercise 8: Create a weak_ptr from a shared_ptr
std::weak_ptr<SimpleClass> SmartPointers::createWeakPtr(const std::shared_ptr<SimpleClass>& sharedPtr) {
    // TODO: Implement this function to create a weak_ptr from a shared_ptr
    // Hint: Simply assign the shared_ptr to a weak_ptr
    return std::weak_ptr<SimpleClass>(); // Replace this with your implementation
}

// Exercise 9: Check if a weak_ptr is still valid (not expired)
bool SmartPointers::isWeakPtrValid(const std::weak_ptr<SimpleClass>& weakPtr) {
    // TODO: Implement this function to check if a weak_ptr is still valid
    // Hint: Use the expired() method (note: it returns true if expired)
    return false; // Replace this with your implementation
}

// Exercise 10: Lock a weak_ptr to get a shared_ptr (or nullptr if expired)
std::shared_ptr<SimpleClass> SmartPointers::lockWeakPtr(const std::weak_ptr<SimpleClass>& weakPtr) {
    // TODO: Implement this function to lock a weak_ptr and get a shared_ptr
    // Hint: Use the lock() method
    return std::shared_ptr<SimpleClass>(); // Replace this with your implementation
}

// Exercise 11: Create and return a SimpleClass object using make_unique
std::unique_ptr<SimpleClass> SmartPointers::createWithMakeUnique(int value, const std::string& name) {
    // TODO: Implement this function to create a SimpleClass object using make_unique
    // Hint: Use std::make_unique
    return std::unique_ptr<SimpleClass>(); // Replace this with your implementation
}

// Exercise 12: Create and return a SimpleClass object using make_shared
std::shared_ptr<SimpleClass> SmartPointers::createWithMakeShared(int value, const std::string& name) {
    // TODO: Implement this function to create a SimpleClass object using make_shared
    // Hint: Use std::make_shared
    return std::shared_ptr<SimpleClass>(); // Replace this with your implementation
}