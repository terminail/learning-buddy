#include "strings_vectors_exercises.h"

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

StringsVectors::StringsVectors() {
    // Default constructor implementation
}

// ========== STRING METHODS ==========

std::string StringsVectors::create_string(const std::string& content) {
    // Implement string creation
    return content;
}

std::string StringsVectors::concatenate_strings(const std::string& str1, const std::string& str2) {
    // Implement string concatenation
    return str1 + str2;
}

size_t StringsVectors::get_string_length(const std::string& str) {
    // Implement getting string length
    return str.length();
}

// ========== VECTOR METHODS ==========

std::vector<int> StringsVectors::create_vector(int size, int initial_value) {
    // Implement vector creation with size and initial value
    return std::vector<int>(size, initial_value);
}

size_t StringsVectors::add_to_vector(std::vector<int>& vec, int value) {
    // Implement adding element to vector and return new size
    vec.push_back(value);
    return vec.size();
}

size_t StringsVectors::get_vector_size(const std::vector<int>& vec) {
    // Implement getting vector size
    return vec.size();
}

int StringsVectors::sum_vector_elements(const std::vector<int>& vec) {
    // Implement summing all elements in a vector
    int sum = 0;
    for (int element : vec) {
        sum += element;
    }
    return sum;
}

} // namespace cpp_primer