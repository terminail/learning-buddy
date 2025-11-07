#ifndef DYNAMIC_MEMORY_EXERCISES_H
#define DYNAMIC_MEMORY_EXERCISES_H

#include <memory>
#include <vector>
#include <string>

namespace cpp_primer {

/**
 * @brief Class containing exercises for dynamic memory management in C++
 * 
 * This class provides methods to practice fundamental concepts of dynamic memory,
 * including new/delete, smart pointers, and memory management best practices.
 */
class DynamicMemory {
public:
    // ========== CONSTRUCTORS ==========
    DynamicMemory();
    
    // ========== RAW POINTER DYNAMIC MEMORY ==========
    int* create_integer(int value);
    std::string* create_string(const std::string& value);
    int* create_array(int size);
    void destroy_integer(int* ptr);
    void destroy_string(std::string* ptr);
    void destroy_array(int* arr);
    
    // ========== SMART POINTERS ==========
    std::unique_ptr<int> create_unique_int(int value);
    std::unique_ptr<std::string> create_unique_string(const std::string& value);
    std::shared_ptr<int> create_shared_int(int value);
    std::shared_ptr<std::string> create_shared_string(const std::string& value);
    std::weak_ptr<int> create_weak_from_shared(std::shared_ptr<int> shared);
    
    // ========== SMART POINTER OPERATIONS ==========
    int get_unique_value(const std::unique_ptr<int>& ptr);
    std::string get_unique_string_value(const std::unique_ptr<std::string>& ptr);
    int get_shared_value(const std::shared_ptr<int>& ptr);
    std::string get_shared_string_value(const std::shared_ptr<std::string>& ptr);
    bool is_weak_expired(const std::weak_ptr<int>& weak_ptr);
    std::shared_ptr<int> lock_weak_ptr(const std::weak_ptr<int>& weak_ptr);
    
    // ========== DYNAMIC ARRAY OPERATIONS ==========
    std::vector<int> fill_dynamic_array(int* arr, int size, int value);
    std::unique_ptr<int[]> create_unique_array(int size);
    std::shared_ptr<int[]> create_shared_array(int size);
    
    // ========== CUSTOM DELETERS ==========
    std::unique_ptr<int, void(*)(int*)> create_unique_with_deleter(int value);
    std::shared_ptr<int> create_shared_with_deleter(int value);
};

} // namespace cpp_primer

#endif // DYNAMIC_MEMORY_EXERCISES_H