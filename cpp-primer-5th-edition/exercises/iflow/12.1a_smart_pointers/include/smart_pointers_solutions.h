#ifndef SMART_POINTERS_SOLUTIONS_H
#define SMART_POINTERS_SOLUTIONS_H

#include <memory>
#include <string>

// Forward declaration of SimpleClass
class SimpleClass;

class SmartPointersSolutions {
public:
    // Exercise 1: Create and return a unique_ptr to a SimpleClass object
    static std::unique_ptr<SimpleClass> createUniquePtr(int value, const std::string& name);

    // Exercise 2: Create and return a shared_ptr to a SimpleClass object
    static std::shared_ptr<SimpleClass> createSharedPtr(int value, const std::string& name);

    // Exercise 3: Get the value from a unique_ptr to SimpleClass
    static int getValueFromUniquePtr(const std::unique_ptr<SimpleClass>& ptr);

    // Exercise 4: Get the value from a shared_ptr to SimpleClass
    static int getValueFromSharedPtr(const std::shared_ptr<SimpleClass>& ptr);

    // Exercise 5: Reset a unique_ptr to point to a new SimpleClass object
    static void resetUniquePtr(std::unique_ptr<SimpleClass>& ptr, int value, const std::string& name);

    // Exercise 6: Reset a shared_ptr to point to a new SimpleClass object
    static void resetSharedPtr(std::shared_ptr<SimpleClass>& ptr, int value, const std::string& name);

    // Exercise 7: Get the reference count of a shared_ptr
    static long getSharedRefCount(const std::shared_ptr<SimpleClass>& ptr);

    // Exercise 8: Create a weak_ptr from a shared_ptr
    static std::weak_ptr<SimpleClass> createWeakPtr(const std::shared_ptr<SimpleClass>& sharedPtr);

    // Exercise 9: Check if a weak_ptr is still valid (not expired)
    static bool isWeakPtrValid(const std::weak_ptr<SimpleClass>& weakPtr);

    // Exercise 10: Lock a weak_ptr to get a shared_ptr (or nullptr if expired)
    static std::shared_ptr<SimpleClass> lockWeakPtr(const std::weak_ptr<SimpleClass>& weakPtr);

    // Exercise 11: Create and return a SimpleClass object using make_unique
    static std::unique_ptr<SimpleClass> createWithMakeUnique(int value, const std::string& name);

    // Exercise 12: Create and return a SimpleClass object using make_shared
    static std::shared_ptr<SimpleClass> createWithMakeShared(int value, const std::string& name);
};

#endif // SMART_POINTERS_SOLUTIONS_H