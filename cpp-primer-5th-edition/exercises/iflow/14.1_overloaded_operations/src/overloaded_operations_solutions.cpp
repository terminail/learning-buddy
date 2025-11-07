#include "overloaded_operations_solutions.h"
#include <cmath>
#include <stdexcept>

namespace cpp_primer {

// ========== COMPLEX NUMBER CLASS SOLUTIONS ==========

// Constructors
ComplexNumberSolutions::ComplexNumberSolutions() : real(0), imaginary(0) {
    real = 0;
    imaginary = 0;
}

ComplexNumberSolutions::ComplexNumberSolutions(double r) : real(r), imaginary(0) {
    real = r;
    imaginary = 0;
}

ComplexNumberSolutions::ComplexNumberSolutions(double r, double i) : real(r), imaginary(i) {
    real = r;
    imaginary = i;
}

// Arithmetic operators
ComplexNumberSolutions ComplexNumberSolutions::operator+(const ComplexNumberSolutions& other) const {
    return ComplexNumberSolutions(real + other.real, imaginary + other.imaginary);
}

ComplexNumberSolutions ComplexNumberSolutions::operator-(const ComplexNumberSolutions& other) const {
    return ComplexNumberSolutions(real - other.real, imaginary - other.imaginary);
}

ComplexNumberSolutions ComplexNumberSolutions::operator*(const ComplexNumberSolutions& other) const {
    // Formula: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    double new_real = real * other.real - imaginary * other.imaginary;
    double new_imaginary = real * other.imaginary + imaginary * other.real;
    return ComplexNumberSolutions(new_real, new_imaginary);
}

ComplexNumberSolutions ComplexNumberSolutions::operator/(const ComplexNumberSolutions& other) const {
    // Formula: (a + bi) / (c + di) = ((ac + bd) + (bc - ad)i) / (c^2 + d^2)
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    double new_real = (real * other.real + imaginary * other.imaginary) / denominator;
    double new_imaginary = (imaginary * other.real - real * other.imaginary) / denominator;
    return ComplexNumberSolutions(new_real, new_imaginary);
}

// Compound assignment operators
ComplexNumberSolutions& ComplexNumberSolutions::operator+=(const ComplexNumberSolutions& other) {
    real += other.real;
    imaginary += other.imaginary;
    return *this;
}

ComplexNumberSolutions& ComplexNumberSolutions::operator-=(const ComplexNumberSolutions& other) {
    real -= other.real;
    imaginary -= other.imaginary;
    return *this;
}

ComplexNumberSolutions& ComplexNumberSolutions::operator*=(const ComplexNumberSolutions& other) {
    double new_real = real * other.real - imaginary * other.imaginary;
    double new_imaginary = real * other.imaginary + imaginary * other.real;
    real = new_real;
    imaginary = new_imaginary;
    return *this;
}

ComplexNumberSolutions& ComplexNumberSolutions::operator/=(const ComplexNumberSolutions& other) {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    double new_real = (real * other.real + imaginary * other.imaginary) / denominator;
    double new_imaginary = (imaginary * other.real - real * other.imaginary) / denominator;
    real = new_real;
    imaginary = new_imaginary;
    return *this;
}

// Unary operators
ComplexNumberSolutions ComplexNumberSolutions::operator+() const {
    return ComplexNumberSolutions(real, imaginary);
}

ComplexNumberSolutions ComplexNumberSolutions::operator-() const {
    return ComplexNumberSolutions(-real, -imaginary);
}

ComplexNumberSolutions& ComplexNumberSolutions::operator++() {
    ++real;
    return *this;
}

ComplexNumberSolutions ComplexNumberSolutions::operator++(int) {
    ComplexNumberSolutions temp(real, imaginary);
    ++real;
    return temp;
}

ComplexNumberSolutions& ComplexNumberSolutions::operator--() {
    --real;
    return *this;
}

ComplexNumberSolutions ComplexNumberSolutions::operator--(int) {
    ComplexNumberSolutions temp(real, imaginary);
    --real;
    return temp;
}

// Comparison operators
bool ComplexNumberSolutions::operator==(const ComplexNumberSolutions& other) const {
    // Compare magnitudes with small tolerance for floating point comparison
    const double tolerance = 1e-9;
    return std::abs(magnitude() - other.magnitude()) < tolerance;
}

bool ComplexNumberSolutions::operator!=(const ComplexNumberSolutions& other) const {
    return !(*this == other);
}

bool ComplexNumberSolutions::operator<(const ComplexNumberSolutions& other) const {
    return magnitude() < other.magnitude();
}

bool ComplexNumberSolutions::operator>(const ComplexNumberSolutions& other) const {
    return magnitude() > other.magnitude();
}

bool ComplexNumberSolutions::operator<=(const ComplexNumberSolutions& other) const {
    return magnitude() <= other.magnitude();
}

bool ComplexNumberSolutions::operator>=(const ComplexNumberSolutions& other) const {
    return magnitude() >= other.magnitude();
}

// Accessors
double ComplexNumberSolutions::get_real() const {
    return real;
}

double ComplexNumberSolutions::get_imaginary() const {
    return imaginary;
}

// Modifiers
void ComplexNumberSolutions::set_real(double r) {
    real = r;
}

void ComplexNumberSolutions::set_imaginary(double i) {
    imaginary = i;
}

// Utility functions
double ComplexNumberSolutions::magnitude() const {
    return std::sqrt(real * real + imaginary * imaginary);
}

ComplexNumberSolutions ComplexNumberSolutions::conjugate() const {
    return ComplexNumberSolutions(real, -imaginary);
}

// ========== NON-MEMBER OPERATORS ==========
std::ostream& operator<<(std::ostream& os, const ComplexNumberSolutions& cn) {
    os << cn.get_real() << " + " << cn.get_imaginary() << "i";
    return os;
}

std::istream& operator>>(std::istream& is, ComplexNumberSolutions& cn) {
    double r, i;
    is >> r >> i;
    cn.set_real(r);
    cn.set_imaginary(i);
    return is;
}

// ========== SAFE ARRAY CLASS SOLUTIONS ==========

// Constructors
SafeArraySolutions::SafeArraySolutions() : size_(0) {
    data = nullptr;
    size_ = 0;
}

SafeArraySolutions::SafeArraySolutions(size_t size) : size_(size) {
    if (size > 0) {
        data = std::make_unique<int[]>(size);
    } else {
        data = nullptr;
    }
    size_ = size;
}

SafeArraySolutions::SafeArraySolutions(size_t size, int initial_value) : size_(size) {
    if (size > 0) {
        data = std::make_unique<int[]>(size);
        for (size_t i = 0; i < size; ++i) {
            data[i] = initial_value;
        }
    } else {
        data = nullptr;
    }
    size_ = size;
}

SafeArraySolutions::SafeArraySolutions(const SafeArraySolutions& other) : size_(other.size_) {
    if (other.size_ > 0) {
        data = std::make_unique<int[]>(other.size_);
        for (size_t i = 0; i < other.size_; ++i) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
    size_ = other.size_;
}

SafeArraySolutions::SafeArraySolutions(SafeArraySolutions&& other) noexcept : data(std::move(other.data)), size_(other.size_) {
    other.size_ = 0;
}

SafeArraySolutions& SafeArraySolutions::operator=(const SafeArraySolutions& other) {
    if (this != &other) {
        size_ = other.size_;
        if (other.size_ > 0) {
            data = std::make_unique<int[]>(other.size_);
            for (size_t i = 0; i < other.size_; ++i) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    return *this;
}

SafeArraySolutions& SafeArraySolutions::operator=(SafeArraySolutions&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        size_ = other.size_;
        other.size_ = 0;
    }
    return *this;
}

SafeArraySolutions::~SafeArraySolutions() {
    // Handled by unique_ptr automatically
}

// Subscript operators
int& SafeArraySolutions::operator[](size_t index) {
    return data[index];
}

const int& SafeArraySolutions::operator[](size_t index) const {
    return data[index];
}

// Function call operators
int SafeArraySolutions::operator()(size_t index) const {
    return data[index];
}

void SafeArraySolutions::operator()(size_t index, int value) {
    data[index] = value;
}

// Accessors
size_t SafeArraySolutions::size() const {
    return size_;
}

bool SafeArraySolutions::empty() const {
    return size_ == 0;
}

// Modifiers
void SafeArraySolutions::resize(size_t new_size) {
    if (new_size != size_) {
        auto new_data = std::make_unique<int[]>(new_size);
        size_t copy_size = std::min(size_, new_size);
        for (size_t i = 0; i < copy_size; ++i) {
            new_data[i] = data[i];
        }
        data = std::move(new_data);
        size_ = new_size;
    }
}

void SafeArraySolutions::fill(int value) {
    for (size_t i = 0; i < size_; ++i) {
        data[i] = value;
    }
}

// Utility functions
int SafeArraySolutions::sum() const {
    int total = 0;
    for (size_t i = 0; i < size_; ++i) {
        total += data[i];
    }
    return total;
}

double SafeArraySolutions::average() const {
    if (size_ == 0) return 0.0;
    return static_cast<double>(sum()) / size_;
}

// ========== SIMPLE PTR TEMPLATE SOLUTIONS ==========

// Constructors
template<typename T>
SimplePtrSolutions<T>::SimplePtrSolutions() : ptr(nullptr) {
    ptr = nullptr;
}

template<typename T>
SimplePtrSolutions<T>::SimplePtrSolutions(T* p) : ptr(p) {
    ptr = p;
}

template<typename T>
SimplePtrSolutions<T>::SimplePtrSolutions(const SimplePtrSolutions& other) : ptr(nullptr) {
    if (other.ptr != nullptr) {
        ptr = new T(*other.ptr);
    } else {
        ptr = nullptr;
    }
}

template<typename T>
SimplePtrSolutions<T>::SimplePtrSolutions(SimplePtrSolutions&& other) noexcept : ptr(other.ptr) {
    ptr = other.ptr;
    other.ptr = nullptr;
}

template<typename T>
SimplePtrSolutions<T>& SimplePtrSolutions<T>::operator=(const SimplePtrSolutions& other) {
    if (this != &other) {
        delete ptr;
        if (other.ptr != nullptr) {
            ptr = new T(*other.ptr);
        } else {
            ptr = nullptr;
        }
    }
    return *this;
}

template<typename T>
SimplePtrSolutions<T>& SimplePtrSolutions<T>::operator=(SimplePtrSolutions&& other) noexcept {
    if (this != &other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

template<typename T>
SimplePtrSolutions<T>::~SimplePtrSolutions() {
    delete ptr;
}

// Dereference operators
template<typename T>
T& SimplePtrSolutions<T>::operator*() {
    return *ptr;
}

template<typename T>
const T& SimplePtrSolutions<T>::operator*() const {
    return *ptr;
}

template<typename T>
T* SimplePtrSolutions<T>::operator->() {
    return ptr;
}

template<typename T>
const T* SimplePtrSolutions<T>::operator->() const {
    return ptr;
}

// Conversion operator
template<typename T>
SimplePtrSolutions<T>::operator bool() const {
    return ptr != nullptr;
}

// Comparison operators
template<typename T>
bool SimplePtrSolutions<T>::operator==(const SimplePtrSolutions& other) const {
    return ptr == other.ptr;
}

template<typename T>
bool SimplePtrSolutions<T>::operator!=(const SimplePtrSolutions& other) const {
    return ptr != other.ptr;
}

template<typename T>
bool SimplePtrSolutions<T>::operator<(const SimplePtrSolutions& other) const {
    return ptr < other.ptr;
}

template<typename T>
bool SimplePtrSolutions<T>::operator>(const SimplePtrSolutions& other) const {
    return ptr > other.ptr;
}

// Accessors
template<typename T>
T* SimplePtrSolutions<T>::get() const {
    return ptr;
}

// Modifiers
template<typename T>
T* SimplePtrSolutions<T>::release() {
    T* old_ptr = ptr;
    ptr = nullptr;
    return old_ptr;
}

template<typename T>
void SimplePtrSolutions<T>::reset() {
    delete ptr;
    ptr = nullptr;
}

template<typename T>
void SimplePtrSolutions<T>::reset(T* p) {
    delete ptr;
    ptr = p;
}

// Explicit instantiation of commonly used SimplePtrSolutions types
template class SimplePtrSolutions<int>;
template class SimplePtrSolutions<double>;
template class SimplePtrSolutions<std::string>;

} // namespace cpp_primer