#ifndef TEMPLATES_SOLUTIONS_H
#define TEMPLATES_SOLUTIONS_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

namespace cpp_primer {

/**
 * @brief Function template to find the maximum of two values
 * 
 * This function template demonstrates basic template syntax and type deduction.
 */
template<typename T>
T max(const T& a, const T& b);

/**
 * @brief Function template to swap two values
 * 
 * This function template demonstrates reference parameters and type deduction.
 */
template<typename T>
void swap(T& a, T& b);

/**
 * @brief Class template for a simple stack implementation
 * 
 * This class template demonstrates basic class template syntax, member function templates,
 * and template specialization.
 */
template<typename T>
class StackSolutions {
private:
    std::vector<T> elements;
    
public:
    // ========== CONSTRUCTORS ==========
    StackSolutions();
    
    // ========== STACK OPERATIONS ==========
    void push(const T& element);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const;
    size_t size() const;
    
    // ========== UTILITY FUNCTIONS ==========
    void clear();
};

/**
 * @brief Class template for a simple pair implementation
 * 
 * This class template demonstrates multiple template parameters and template methods.
 */
template<typename T1, typename T2>
class PairSolutions {
private:
    T1 first;
    T2 second;
    
public:
    // ========== CONSTRUCTORS ==========
    PairSolutions();
    PairSolutions(const T1& f, const T2& s);
    
    // ========== ACCESSORS ==========
    T1 get_first() const;
    T2 get_second() const;
    
    // ========== MODIFIERS ==========
    void set_first(const T1& f);
    void set_second(const T2& s);
    void set_pair(const T1& f, const T2& s);
    
    // ========== UTILITY FUNCTIONS ==========
    void swap_pair();
};

/**
 * @brief Function template to calculate the sum of elements in a container
 * 
 * This function template demonstrates iterator-based templates and SFINAE.
 */
template<typename Iterator>
auto sum(Iterator begin, Iterator end) -> decltype(*begin + *begin);

/**
 * @brief Function template to find an element in a container
 * 
 * This function template demonstrates predicate-based algorithms.
 */
template<typename Iterator, typename T>
Iterator find(Iterator begin, Iterator end, const T& value);

/**
 * @brief Function template to apply a function to each element in a container
 * 
 * This function template demonstrates higher-order functions and lambda support.
 */
template<typename Iterator, typename Function>
void for_each(Iterator begin, Iterator end, Function f);

/**
 * @brief Class template specialization for Stack<bool>
 * 
 * This class demonstrates template specialization for a specific type.
 */
template<>
class StackSolutions<bool> {
private:
    // Optimized implementation for bool using bitset-like approach
    std::vector<bool> elements;
    
public:
    // ========== CONSTRUCTORS ==========
    StackSolutions();
    
    // ========== STACK OPERATIONS ==========
    void push(bool element);
    void pop();
    bool top() const;
    bool empty() const;
    size_t size() const;
    
    // ========== UTILITY FUNCTIONS ==========
    void clear();
};

/**
 * @brief Variadic template function for printing multiple values
 * 
 * This function demonstrates variadic templates and parameter packs.
 */
template<typename T>
void print(const T& value);

template<typename T, typename... Args>
void print(const T& first, const Args&... args);

/**
 * @brief Class template for a simple wrapper with type traits
 * 
 * This class demonstrates advanced template features including type traits.
 */
template<typename T>
class WrapperSolutions {
private:
    T value;
    
public:
    // ========== CONSTRUCTORS ==========
    WrapperSolutions();
    explicit WrapperSolutions(const T& v);
    
    // ========== ACCESSORS ==========
    T get_value() const;
    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, U>::type
    get_squared() const;
    
    // ========== MODIFIERS ==========
    void set_value(const T& v);
    
    // ========== UTILITY FUNCTIONS ==========
    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, void>::type
    multiply_by(const U& factor);
    
    template<typename U = T>
    typename std::enable_if<std::is_same<U, std::string>::value, void>::type
    append(const std::string& suffix);
};

} // namespace cpp_primer

#include "templates_solutions.tpp"  // Include template implementations

#endif // TEMPLATES_SOLUTIONS_H