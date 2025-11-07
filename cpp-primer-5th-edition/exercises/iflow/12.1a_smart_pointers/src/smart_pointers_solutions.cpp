#include "smart_pointers_solutions.h"
#include "smart_pointers_exercises.h"
#include <memory>

// Exercise 1: Create and return a unique_ptr to a SimpleClass object
std::unique_ptr<SimpleClass> SmartPointersSolutions::createUniquePtr(int value, const std::string& name) {
    return std::make_unique<SimpleClass>(value, name);
}

// Exercise 2: Create and return a shared_ptr to a SimpleClass object
std::shared_ptr<SimpleClass> SmartPointersSolutions::createSharedPtr(int value, const std::string& name) {
    return std::make_shared<SimpleClass>(value, name);
}

// Exercise 3: Get the value from a unique_ptr to SimpleClass
int SmartPointersSolutions::getValueFromUniquePtr(const std::unique_ptr<SimpleClass>& ptr) {
    return ptr->getValue();
}

// Exercise 4: Get the value from a shared_ptr to SimpleClass
int SmartPointersSolutions::getValueFromSharedPtr(const std::shared_ptr<SimpleClass>& ptr) {
    return ptr->getValue();
}

// Exercise 5: Reset a unique_ptr to point to a new SimpleClass object
void SmartPointersSolutions::resetUniquePtr(std::unique_ptr<SimpleClass>& ptr, int value, const std::string& name) {
    ptr.reset(new SimpleClass(value, name));
}

// Exercise 6: Reset a shared_ptr to point to a new SimpleClass object
void SmartPointersSolutions::resetSharedPtr(std::shared_ptr<SimpleClass>& ptr, int value, const std::string& name) {
    ptr = std::make_shared<SimpleClass>(value, name);
}

// Exercise 7: Get the reference count of a shared_ptr
long SmartPointersSolutions::getSharedRefCount(const std::shared_ptr<SimpleClass>& ptr) {
    return ptr.use_count();
}

// Exercise 8: Create a weak_ptr from a shared_ptr
std::weak_ptr<SimpleClass> SmartPointersSolutions::createWeakPtr(const std::shared_ptr<SimpleClass>& sharedPtr) {
    return std::weak_ptr<SimpleClass>(sharedPtr);
}

// Exercise 9: Check if a weak_ptr is still valid (not expired)
bool SmartPointersSolutions::isWeakPtrValid(const std::weak_ptr<SimpleClass>& weakPtr) {
    return !weakPtr.expired();
}

// Exercise 10: Lock a weak_ptr to get a shared_ptr (or nullptr if expired)
std::shared_ptr<SimpleClass> SmartPointersSolutions::lockWeakPtr(const std::weak_ptr<SimpleClass>& weakPtr) {
    return weakPtr.lock();
}

// Exercise 11: Create and return a SimpleClass object using make_unique
std::unique_ptr<SimpleClass> SmartPointersSolutions::createWithMakeUnique(int value, const std::string& name) {
    return std::make_unique<SimpleClass>(value, name);
}

// Exercise 12: Create and return a SimpleClass object using make_shared
std::shared_ptr<SimpleClass> SmartPointersSolutions::createWithMakeShared(int value, const std::string& name) {
    return std::make_shared<SimpleClass>(value, name);
}