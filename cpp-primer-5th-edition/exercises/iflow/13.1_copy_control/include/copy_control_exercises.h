#ifndef COPY_CONTROL_EXERCISES_H
#define COPY_CONTROL_EXERCISES_H

#include <string>
#include <vector>
#include <memory>

namespace cpp_primer {

/**
 * @brief Class containing exercises for copy control in C++
 * 
 * This class provides methods to practice implementing copy constructors,
 * copy assignment operators, move constructors, and move assignment operators.
 */
class CopyControl {
private:
    std::string* data;
    size_t size;
    
public:
    // ========== CONSTRUCTORS AND DESTRUCTOR ==========
    CopyControl();
    explicit CopyControl(const std::string& s);
    CopyControl(const CopyControl& other);  // Copy constructor
    CopyControl(CopyControl&& other) noexcept;  // Move constructor
    CopyControl& operator=(const CopyControl& other);  // Copy assignment
    CopyControl& operator=(CopyControl&& other) noexcept;  // Move assignment
    ~CopyControl();  // Destructor
    
    // ========== ACCESSORS ==========
    const std::string& get_data() const;
    size_t get_size() const;
    
    // ========== MODIFIERS ==========
    void set_data(const std::string& s);
    void swap(CopyControl& other) noexcept;
    
    // ========== UTILITY FUNCTIONS ==========
    bool empty() const;
    void clear();
};

/**
 * @brief Class containing exercises for copy control with dynamic arrays
 * 
 * This class provides methods to practice implementing copy control for
 * classes that manage dynamic arrays.
 */
class DynamicArray {
private:
    int* data;
    size_t size;
    size_t capacity;
    
public:
    // ========== CONSTRUCTORS AND DESTRUCTOR ==========
    DynamicArray();
    explicit DynamicArray(size_t n);
    DynamicArray(size_t n, int value);
    DynamicArray(const DynamicArray& other);  // Copy constructor
    DynamicArray(DynamicArray&& other) noexcept;  // Move constructor
    DynamicArray& operator=(const DynamicArray& other);  // Copy assignment
    DynamicArray& operator=(DynamicArray&& other) noexcept;  // Move assignment
    ~DynamicArray();  // Destructor
    
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
    void swap(DynamicArray& other) noexcept;
};

/**
 * @brief Class containing exercises for copy control with smart pointers
 * 
 * This class provides methods to practice implementing copy control for
 * classes that use smart pointers.
 */
class SmartContainer {
private:
    std::unique_ptr<std::string> data;
    std::shared_ptr<std::vector<int>> numbers;
    
public:
    // ========== CONSTRUCTORS ==========
    SmartContainer();
    explicit SmartContainer(const std::string& s);
    SmartContainer(const std::string& s, const std::vector<int>& nums);
    SmartContainer(const SmartContainer& other);  // Copy constructor
    SmartContainer(SmartContainer&& other) noexcept;  // Move constructor
    SmartContainer& operator=(const SmartContainer& other);  // Copy assignment
    SmartContainer& operator=(SmartContainer&& other) noexcept;  // Move assignment
    
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
    void swap(SmartContainer& other) noexcept;
};

} // namespace cpp_primer

#endif // COPY_CONTROL_EXERCISES_H