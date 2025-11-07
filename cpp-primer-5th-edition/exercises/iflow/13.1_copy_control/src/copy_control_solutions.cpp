#include "copy_control_solutions.h"
#include <algorithm>
#include <utility>

namespace cpp_primer {

// ========== COPY CONTROL CLASS SOLUTIONS ==========

// Default constructor
CopyControlSolutions::CopyControlSolutions() : data(nullptr), size(0) {
    data = nullptr;
    size = 0;
}

// Constructor with string parameter
CopyControlSolutions::CopyControlSolutions(const std::string& s) : size(s.size()) {
    data = new std::string(s);
    size = s.size();
}

// Copy constructor
CopyControlSolutions::CopyControlSolutions(const CopyControlSolutions& other) : size(other.size) {
    if (other.data) {
        data = new std::string(*(other.data));
    } else {
        data = nullptr;
    }
    size = other.size;
}

// Move constructor
CopyControlSolutions::CopyControlSolutions(CopyControlSolutions&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

// Copy assignment operator
CopyControlSolutions& CopyControlSolutions::operator=(const CopyControlSolutions& other) {
    if (this != &other) {
        delete data;
        if (other.data) {
            data = new std::string(*(other.data));
        } else {
            data = nullptr;
        }
        size = other.size;
    }
    return *this;
}

// Move assignment operator
CopyControlSolutions& CopyControlSolutions::operator=(CopyControlSolutions&& other) noexcept {
    if (this != &other) {
        delete data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

// Destructor
CopyControlSolutions::~CopyControlSolutions() {
    delete data;
}

// Accessors
const std::string& CopyControlSolutions::get_data() const {
    return *data;
}

size_t CopyControlSolutions::get_size() const {
    return size;
}

// Modifiers
void CopyControlSolutions::set_data(const std::string& s) {
    delete data;
    data = new std::string(s);
    size = s.size();
}

void CopyControlSolutions::swap(CopyControlSolutions& other) noexcept {
    std::swap(data, other.data);
    std::swap(size, other.size);
}

// Utility functions
bool CopyControlSolutions::empty() const {
    return data == nullptr;
}

void CopyControlSolutions::clear() {
    delete data;
    data = nullptr;
    size = 0;
}

// ========== DYNAMIC ARRAY CLASS SOLUTIONS ==========

// Default constructor
DynamicArraySolutions::DynamicArraySolutions() : data(nullptr), size(0), capacity(0) {
    data = nullptr;
    size = 0;
    capacity = 0;
}

// Constructor with size parameter
DynamicArraySolutions::DynamicArraySolutions(size_t n) : size(n), capacity(n) {
    if (n > 0) {
        data = new int[n]();
    } else {
        data = nullptr;
    }
    size = n;
    capacity = n;
}

// Constructor with size and initial value
DynamicArraySolutions::DynamicArraySolutions(size_t n, int value) : size(n), capacity(n) {
    if (n > 0) {
        data = new int[n];
        std::fill(data, data + n, value);
    } else {
        data = nullptr;
    }
    size = n;
    capacity = n;
}

// Copy constructor
DynamicArraySolutions::DynamicArraySolutions(const DynamicArraySolutions& other) : size(other.size), capacity(other.capacity) {
    if (other.capacity > 0) {
        data = new int[other.capacity];
        std::copy(other.data, other.data + other.size, data);
    } else {
        data = nullptr;
    }
    size = other.size;
    capacity = other.capacity;
}

// Move constructor
DynamicArraySolutions::DynamicArraySolutions(DynamicArraySolutions&& other) noexcept 
    : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

// Copy assignment operator
DynamicArraySolutions& DynamicArraySolutions::operator=(const DynamicArraySolutions& other) {
    if (this != &other) {
        delete[] data;
        if (other.capacity > 0) {
            data = new int[other.capacity];
            std::copy(other.data, other.data + other.size, data);
        } else {
            data = nullptr;
        }
        size = other.size;
        capacity = other.capacity;
    }
    return *this;
}

// Move assignment operator
DynamicArraySolutions& DynamicArraySolutions::operator=(DynamicArraySolutions&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

// Destructor
DynamicArraySolutions::~DynamicArraySolutions() {
    delete[] data;
}

// Accessors
size_t DynamicArraySolutions::get_size() const {
    return size;
}

size_t DynamicArraySolutions::get_capacity() const {
    return capacity;
}

int DynamicArraySolutions::at(size_t index) const {
    if (index < size) {
        return data[index];
    }
    throw std::out_of_range("Index out of range");
}

bool DynamicArraySolutions::empty() const {
    return size == 0;
}

// Modifiers
void DynamicArraySolutions::push_back(int value) {
    if (size >= capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

void DynamicArraySolutions::pop_back() {
    if (size > 0) {
        --size;
    }
}

void DynamicArraySolutions::resize(size_t new_size) {
    if (new_size > capacity) {
        reserve(new_size);
    }
    size = new_size;
}

void DynamicArraySolutions::reserve(size_t new_capacity) {
    if (new_capacity > capacity) {
        int* new_data = new int[new_capacity]();
        if (data) {
            std::copy(data, data + size, new_data);
            delete[] data;
        }
        data = new_data;
        capacity = new_capacity;
    }
}

void DynamicArraySolutions::clear() {
    size = 0;
}

// Operators
int& DynamicArraySolutions::operator[](size_t index) {
    return data[index];
}

const int& DynamicArraySolutions::operator[](size_t index) const {
    return data[index];
}

// Utility functions
void DynamicArraySolutions::swap(DynamicArraySolutions& other) noexcept {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

// ========== SMART CONTAINER CLASS SOLUTIONS ==========

// Default constructor
SmartContainerSolutions::SmartContainerSolutions() : data(nullptr), numbers(std::make_shared<std::vector<int>>()) {
    data = nullptr;
    numbers = std::make_shared<std::vector<int>>();
}

// Constructor with string parameter
SmartContainerSolutions::SmartContainerSolutions(const std::string& s) : numbers(std::make_shared<std::vector<int>>()) {
    data = std::make_unique<std::string>(s);
    numbers = std::make_shared<std::vector<int>>();
}

// Constructor with string and vector parameters
SmartContainerSolutions::SmartContainerSolutions(const std::string& s, const std::vector<int>& nums) {
    data = std::make_unique<std::string>(s);
    numbers = std::make_shared<std::vector<int>>(nums);
}

// Copy constructor
SmartContainerSolutions::SmartContainerSolutions(const SmartContainerSolutions& other) {
    if (other.data) {
        data = std::make_unique<std::string>(*(other.data));
    } else {
        data = nullptr;
    }
    numbers = other.numbers;  // Shallow copy (shared ownership)
}

// Move constructor
SmartContainerSolutions::SmartContainerSolutions(SmartContainerSolutions&& other) noexcept 
    : data(std::move(other.data)), numbers(std::move(other.numbers)) {
    // Already implemented with move semantics
}

// Copy assignment operator
SmartContainerSolutions& SmartContainerSolutions::operator=(const SmartContainerSolutions& other) {
    if (this != &other) {
        if (other.data) {
            data = std::make_unique<std::string>(*(other.data));
        } else {
            data = nullptr;
        }
        numbers = other.numbers;  // Shallow copy (shared ownership)
    }
    return *this;
}

// Move assignment operator
SmartContainerSolutions& SmartContainerSolutions::operator=(SmartContainerSolutions&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        numbers = std::move(other.numbers);
    }
    return *this;
}

// Accessors
const std::string& SmartContainerSolutions::get_string() const {
    return *data;
}

const std::vector<int>& SmartContainerSolutions::get_numbers() const {
    return *numbers;
}

size_t SmartContainerSolutions::get_numbers_size() const {
    return numbers->size();
}

// Modifiers
void SmartContainerSolutions::set_string(const std::string& s) {
    if (!data) {
        data = std::make_unique<std::string>(s);
    } else {
        *data = s;
    }
}

void SmartContainerSolutions::add_number(int num) {
    numbers->push_back(num);
}

void SmartContainerSolutions::clear_numbers() {
    numbers->clear();
}

// Utility functions
bool SmartContainerSolutions::has_data() const {
    return data != nullptr;
}

void SmartContainerSolutions::swap(SmartContainerSolutions& other) noexcept {
    std::swap(data, other.data);
    std::swap(numbers, other.numbers);
}

} // namespace cpp_primer