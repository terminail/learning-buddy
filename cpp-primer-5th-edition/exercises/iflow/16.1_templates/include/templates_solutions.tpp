#ifndef TEMPLATES_SOLUTIONS_TPP
#define TEMPLATES_SOLUTIONS_TPP

#include "templates_solutions.h"
#include <type_traits>

namespace cpp_primer {

// ========== FUNCTION TEMPLATES ==========

template<typename T>
T max(const T& a, const T& b) {
    return a > b ? a : b;
}

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// ========== STACK CLASS TEMPLATE ==========

template<typename T>
StackSolutions<T>::StackSolutions() {
    // Vector initializes automatically
}

template<typename T>
void StackSolutions<T>::push(const T& element) {
    elements.push_back(element);
}

template<typename T>
void StackSolutions<T>::pop() {
    if (!elements.empty()) {
        elements.pop_back();
    }
}

template<typename T>
T& StackSolutions<T>::top() {
    return elements.back();
}

template<typename T>
const T& StackSolutions<T>::top() const {
    return elements.back();
}

template<typename T>
bool StackSolutions<T>::empty() const {
    return elements.empty();
}

template<typename T>
size_t StackSolutions<T>::size() const {
    return elements.size();
}

template<typename T>
void StackSolutions<T>::clear() {
    elements.clear();
}

// ========== PAIR CLASS TEMPLATE ==========

template<typename T1, typename T2>
PairSolutions<T1, T2>::PairSolutions() : first(T1{}), second(T2{}) {
    first = T1{};
    second = T2{};
}

template<typename T1, typename T2>
PairSolutions<T1, T2>::PairSolutions(const T1& f, const T2& s) : first(f), second(s) {
    first = f;
    second = s;
}

template<typename T1, typename T2>
T1 PairSolutions<T1, T2>::get_first() const {
    return first;
}

template<typename T1, typename T2>
T2 PairSolutions<T1, T2>::get_second() const {
    return second;
}

template<typename T1, typename T2>
void PairSolutions<T1, T2>::set_first(const T1& f) {
    first = f;
}

template<typename T1, typename T2>
void PairSolutions<T1, T2>::set_second(const T2& s) {
    second = s;
}

template<typename T1, typename T2>
void PairSolutions<T1, T2>::set_pair(const T1& f, const T2& s) {
    first = f;
    second = s;
}

template<typename T1, typename T2>
void PairSolutions<T1, T2>::swap_pair() {
    if constexpr (std::is_same_v<T1, T2>) {
        T1 temp = first;
        first = second;
        second = temp;
    }
}

// ========== ALGORITHM FUNCTION TEMPLATES ==========

template<typename Iterator>
auto sum(Iterator begin, Iterator end) -> decltype(*begin + *begin) {
    using ValueType = decltype(*begin + *begin);
    ValueType total = ValueType{};
    for (auto it = begin; it != end; ++it) {
        total += *it;
    }
    return total;
}

template<typename Iterator, typename T>
Iterator find(Iterator begin, Iterator end, const T& value) {
    for (auto it = begin; it != end; ++it) {
        if (*it == value) {
            return it;
        }
    }
    return end;
}

template<typename Iterator, typename Function>
void for_each(Iterator begin, Iterator end, Function f) {
    for (auto it = begin; it != end; ++it) {
        f(*it);
    }
}

// ========== STACK<bool> SPECIALIZATION ==========

template<>
StackSolutions<bool>::StackSolutions() {
    // Vector initializes automatically
}

template<>
void StackSolutions<bool>::push(bool element) {
    elements.push_back(element);
}

template<>
void StackSolutions<bool>::pop() {
    if (!elements.empty()) {
        elements.pop_back();
    }
}

template<>
bool StackSolutions<bool>::top() const {
    return elements.back();
}

template<>
bool StackSolutions<bool>::empty() const {
    return elements.empty();
}

template<>
size_t StackSolutions<bool>::size() const {
    return elements.size();
}

template<>
void StackSolutions<bool>::clear() {
    elements.clear();
}

// ========== VARIADIC TEMPLATE FUNCTIONS ==========

template<typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    std::cout << first << " ";
    print(args...);
}

// ========== WRAPPER CLASS TEMPLATE ==========

template<typename T>
WrapperSolutions<T>::WrapperSolutions() : value(T{}) {
    value = T{};
}

template<typename T>
WrapperSolutions<T>::WrapperSolutions(const T& v) : value(v) {
    value = v;
}

template<typename T>
T WrapperSolutions<T>::get_value() const {
    return value;
}

template<typename T>
template<typename U>
typename std::enable_if<std::is_arithmetic<U>::value, U>::type
WrapperSolutions<T>::get_squared() const {
    return value * value;
}

template<typename T>
void WrapperSolutions<T>::set_value(const T& v) {
    value = v;
}

template<typename T>
template<typename U>
typename std::enable_if<std::is_arithmetic<U>::value, void>::type
WrapperSolutions<T>::multiply_by(const U& factor) {
    value *= factor;
}

template<typename T>
template<typename U>
typename std::enable_if<std::is_same<U, std::string>::value, void>::type
WrapperSolutions<T>::append(const std::string& suffix) {
    value += suffix;
}

} // namespace cpp_primer

#endif // TEMPLATES_SOLUTIONS_TPP