#include "dynamic_memory_solutions.h"

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

DynamicMemorySolutions::DynamicMemorySolutions() {
    // Default constructor implementation
}

// ========== RAW POINTER DYNAMIC MEMORY ==========

int* DynamicMemorySolutions::create_integer(int value) {
    // Create a new integer on the heap with the given value
    return new int(value);
}

std::string* DynamicMemorySolutions::create_string(const std::string& value) {
    // Create a new string on the heap with the given value
    return new std::string(value);
}

int* DynamicMemorySolutions::create_array(int size) {
    // Create a new integer array on the heap with the given size
    return new int[size];
}

void DynamicMemorySolutions::destroy_integer(int* ptr) {
    // Delete the integer pointer
    delete ptr;
}

void DynamicMemorySolutions::destroy_string(std::string* ptr) {
    // Delete the string pointer
    delete ptr;
}

void DynamicMemorySolutions::destroy_array(int* arr) {
    // Delete the integer array
    delete[] arr;
}

// ========== SMART POINTERS ==========

std::unique_ptr<int> DynamicMemorySolutions::create_unique_int(int value) {
    // Create a unique_ptr to an integer with the given value
    return std::make_unique<int>(value);
}

std::unique_ptr<std::string> DynamicMemorySolutions::create_unique_string(const std::string& value) {
    // Create a unique_ptr to a string with the given value
    return std::make_unique<std::string>(value);
}

std::shared_ptr<int> DynamicMemorySolutions::create_shared_int(int value) {
    // Create a shared_ptr to an integer with the given value
    return std::make_shared<int>(value);
}

std::shared_ptr<std::string> DynamicMemorySolutions::create_shared_string(const std::string& value) {
    // Create a shared_ptr to a string with the given value
    return std::make_shared<std::string>(value);
}

std::weak_ptr<int> DynamicMemorySolutions::create_weak_from_shared(std::shared_ptr<int> shared) {
    // Create a weak_ptr from a shared_ptr
    return std::weak_ptr<int>(shared);
}

// ========== SMART POINTER OPERATIONS ==========

int DynamicMemorySolutions::get_unique_value(const std::unique_ptr<int>& ptr) {
    // Get the value from a unique_ptr
    return *ptr;
}

std::string DynamicMemorySolutions::get_unique_string_value(const std::unique_ptr<std::string>& ptr) {
    // Get the string value from a unique_ptr
    return *ptr;
}

int DynamicMemorySolutions::get_shared_value(const std::shared_ptr<int>& ptr) {
    // Get the value from a shared_ptr
    return *ptr;
}

std::string DynamicMemorySolutions::get_shared_string_value(const std::shared_ptr<std::string>& ptr) {
    // Get the string value from a shared_ptr
    return *ptr;
}

bool DynamicMemorySolutions::is_weak_expired(const std::weak_ptr<int>& weak_ptr) {
    // Check if a weak_ptr has expired
    return weak_ptr.expired();
}

std::shared_ptr<int> DynamicMemorySolutions::lock_weak_ptr(const std::weak_ptr<int>& weak_ptr) {
    // Lock a weak_ptr and return a shared_ptr
    return weak_ptr.lock();
}

// ========== DYNAMIC ARRAY OPERATIONS ==========

std::vector<int> DynamicMemorySolutions::fill_dynamic_array(int* arr, int size, int value) {
    // Fill the dynamic array with the given value and return a vector with the same values
    std::vector<int> result;
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
        result.push_back(value);
    }
    return result;
}

std::unique_ptr<int[]> DynamicMemorySolutions::create_unique_array(int size) {
    // Create a unique_ptr to an integer array of given size
    return std::make_unique<int[]>(size);
}

std::shared_ptr<int[]> DynamicMemorySolutions::create_shared_array(int size) {
    // Create a shared_ptr to an integer array of given size
    return std::shared_ptr<int[]>(new int[size], std::default_delete<int[]>());
}

// ========== CUSTOM DELETERS ==========

std::unique_ptr<int, void(*)(int*)> DynamicMemorySolutions::create_unique_with_deleter(int value) {
    // Create a unique_ptr with a custom deleter
    auto deleter = [](int* ptr) { 
        delete ptr; 
    };
    return std::unique_ptr<int, void(*)(int*)>(new int(value), deleter);
}

std::shared_ptr<int> DynamicMemorySolutions::create_shared_with_deleter(int value) {
    // Create a shared_ptr with a custom deleter
    auto deleter = [](int* ptr) { 
        delete ptr; 
    };
    return std::shared_ptr<int>(new int(value), deleter);
}

} // namespace cpp_primer