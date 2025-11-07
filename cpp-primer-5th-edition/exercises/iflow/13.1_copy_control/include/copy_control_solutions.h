#ifndef COPY_CONTROL_SOLUTIONS_H
#define COPY_CONTROL_SOLUTIONS_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>

namespace cpp_primer {

/**
 * @brief Class containing solutions for copy control exercises in C++
 * 
 * This class provides complete implementations for all copy control exercises,
 * demonstrating proper implementation of copy constructors, copy assignment operators,
 * move constructors, and move assignment operators.
 */
class CopyControlSolutions {
private:
    std::string* data;
    size_t size;
    
public:
    // ========== CONSTRUCTORS AND DESTRUCTOR ==========
    CopyControlSolutions();
    explicit CopyControlSolutions(const std::string& s);
    CopyControlSolutions(const CopyControlSolutions& other);  // Copy constructor
    CopyControlSolutions(CopyControlSolutions&& other) noexcept;  // Move constructor
    CopyControlSolutions& operator=(const CopyControlSolutions& other);  // Copy assignment
    CopyControlSolutions& operator=(CopyControlSolutions&& other) noexcept;  // Move assignment
    ~CopyControlSolutions();  // Destructor
    
    // ========== ACCESSORS ==========
    const std::string& get_data() const;
    size_t get_size() const;
    
    // ========== MODIFIERS ==========
    void set_data(const std::string& s);
    void swap(CopyControlSolutions& other) noexcept;
    
    // ========== UTILITY FUNCTIONS ==========
    bool empty() const;
    void clear();
};

/**
 * @brief Class containing solutions for copy control with dynamic arrays
 * 
 * This class provides complete implementations for copy control exercises with dynamic arrays.
 */
class DynamicArraySolutions {
private:
    int* data;
    size_t size;
    size_t capacity;
    
public:
    // ========== CONSTRUCTORS AND DESTRUCTOR ==========
    DynamicArraySolutions();
    explicit DynamicArraySolutions(size_t n);
    DynamicArraySolutions(size_t n, int value);
    DynamicArraySolutions(const DynamicArraySolutions& other);  // Copy constructor
    DynamicArraySolutions(DynamicArraySolutions&& other) noexcept;  // Move constructor
    DynamicArraySolutions& operator=(const DynamicArraySolutions& other);  // Copy assignment
    DynamicArraySolutions& operator=(DynamicArraySolutions&& other) noexcept;  // Move assignment
    ~DynamicArraySolutions();  // Destructor
    
    // ========== ACCESSORS ==========
    size_t get_size() const;
    size_t get_capacity() const;
    int at(size_t index) const;
    bool empty() const;
    
    // ========== MODIFIERS ==========
    void push_back(int value);
    void pop_back();
    void resize(size_t new_size);
    void reserve(size_t new_capacity);
    void clear();
    
    // ========== OPERATORS ==========
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    // ========== UTILITY FUNCTIONS ==========
    void swap(DynamicArraySolutions& other) noexcept;
};

/**
 * @brief Class containing solutions for copy control with smart pointers
 * 
 * This class provides complete implementations for copy control exercises with smart pointers.
 */
class SmartContainerSolutions {
private:
    std::unique_ptr<std::string> data;
    std::shared_ptr<std::vector<int>> numbers;
    
public:
    // ========== CONSTRUCTORS ==========
    SmartContainerSolutions();
    explicit SmartContainerSolutions(const std::string& s);
    SmartContainerSolutions(const std::string& s, const std::vector<int>& nums);
    SmartContainerSolutions(const SmartContainerSolutions& other);  // Copy constructor
    SmartContainerSolutions(SmartContainerSolutions&& other) noexcept;  // Move constructor
    SmartContainerSolutions& operator=(const SmartContainerSolutions& other);  // Copy assignment
    SmartContainerSolutions& operator=(SmartContainerSolutions&& other) noexcept;  // Move assignment
    
    // ========== ACCESSORS ==========
    const std::string& get_string() const;
    const std::vector<int>& get_numbers() const;
    size_t get_numbers_size() const;
    
    // ========== MODIFIERS ==========
    void set_string(const std::string& s);
    void add_number(int num);
    void clear_numbers();
    
    // ========== UTILITY FUNCTIONS ==========
    bool has_data() const;
    void swap(SmartContainerSolutions& other) noexcept;
};

} // namespace cpp_primer

#endif // COPY_CONTROL_SOLUTIONS_H