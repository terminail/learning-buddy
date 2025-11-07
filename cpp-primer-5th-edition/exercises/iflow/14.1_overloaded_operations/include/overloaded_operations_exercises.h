#ifndef OVERLOADED_OPERATIONS_EXERCISES_H
#define OVERLOADED_OPERATIONS_EXERCISES_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

namespace cpp_primer {

/**
 * @brief Class containing exercises for overloaded operators in C++
 * 
 * This class provides methods to practice implementing various overloaded operators
 * including arithmetic, comparison, increment/decrement, subscript, and stream operators.
 */
class ComplexNumber {
private:
    double real;
    double imaginary;
    
public:
    // ========== CONSTRUCTORS ==========
    ComplexNumber();
    ComplexNumber(double r);
    ComplexNumber(double r, double i);
    
    // ========== ARITHMETIC OPERATORS ==========
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;
    
    // ========== COMPOUND ASSIGNMENT OPERATORS ==========
    ComplexNumber& operator+=(const ComplexNumber& other);
    ComplexNumber& operator-=(const ComplexNumber& other);
    ComplexNumber& operator*=(const ComplexNumber& other);
    ComplexNumber& operator/=(const ComplexNumber& other);
    
    // ========== UNARY OPERATORS ==========
    ComplexNumber operator+() const;  // Unary plus
    ComplexNumber operator-() const;  // Unary minus
    ComplexNumber& operator++();      // Prefix increment
    ComplexNumber operator++(int);    // Postfix increment
    ComplexNumber& operator--();      // Prefix decrement
    ComplexNumber operator--(int);    // Postfix decrement
    
    // ========== COMPARISON OPERATORS ==========
    bool operator==(const ComplexNumber& other) const;
    bool operator!=(const ComplexNumber& other) const;
    bool operator<(const ComplexNumber& other) const;
    bool operator>(const ComplexNumber& other) const;
    bool operator<=(const ComplexNumber& other) const;
    bool operator>=(const ComplexNumber& other) const;
    
    // ========== ACCESSORS ==========
    double get_real() const;
    double get_imaginary() const;
    
    // ========== MODIFIERS ==========
    void set_real(double r);
    void set_imaginary(double i);
    
    // ========== UTILITY FUNCTIONS ==========
    double magnitude() const;
    ComplexNumber conjugate() const;
};

// ========== NON-MEMBER OPERATORS ==========
std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);
std::istream& operator>>(std::istream& is, ComplexNumber& cn);

/**
 * @brief Class containing exercises for subscript and function call operators
 * 
 * This class provides methods to practice implementing subscript and function call operators.
 */
class SafeArray {
private:
    std::unique_ptr<int[]> data;
    size_t size_;
    
public:
    // ========== CONSTRUCTORS ==========
    SafeArray();
    explicit SafeArray(size_t size);
    SafeArray(size_t size, int initial_value);
    SafeArray(const SafeArray& other);
    SafeArray(SafeArray&& other) noexcept;
    SafeArray& operator=(const SafeArray& other);
    SafeArray& operator=(SafeArray&& other) noexcept;
    ~SafeArray();
    
    // ========== SUBSCRIPT OPERATORS ==========
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    // ========== FUNCTION CALL OPERATORS ==========
    int operator()(size_t index) const;
    void operator()(size_t index, int value);
    
    // ========== ACCESSORS ==========
    size_t size() const;
    bool empty() const;
    
    // ========== MODIFIERS ==========
    void resize(size_t new_size);
    void fill(int value);
    
    // ========== UTILITY FUNCTIONS ==========
    int sum() const;
    double average() const;
};

/**
 * @brief Class containing exercises for smart pointer-like operators
 * 
 * This class provides methods to practice implementing operators for a smart pointer-like class.
 */
template<typename T>
class SimplePtr {
private:
    T* ptr;
    
public:
    // ========== CONSTRUCTORS ==========
    SimplePtr();
    explicit SimplePtr(T* p);
    SimplePtr(const SimplePtr& other);
    SimplePtr(SimplePtr&& other) noexcept;
    SimplePtr& operator=(const SimplePtr& other);
    SimplePtr& operator=(SimplePtr&& other) noexcept;
    ~SimplePtr();
    
    // ========== DEREFERENCE OPERATORS ==========
    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;
    
    // ========== CONVERSION OPERATORS ==========
    operator bool() const;
    
    // ========== COMPARISON OPERATORS ==========
    bool operator==(const SimplePtr& other) const;
    bool operator!=(const SimplePtr& other) const;
    bool operator<(const SimplePtr& other) const;
    bool operator>(const SimplePtr& other) const;
    
    // ========== ACCESSORS ==========
    T* get() const;
    
    // ========== MODIFIERS ==========
    T* release();
    void reset();
    void reset(T* p);
};

} // namespace cpp_primer

#endif // OVERLOADED_OPERATIONS_EXERCISES_H