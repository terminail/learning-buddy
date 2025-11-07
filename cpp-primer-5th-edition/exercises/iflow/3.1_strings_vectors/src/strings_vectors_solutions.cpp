#include "strings_vectors_solutions.h"

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

StringsVectorsSolutions::StringsVectorsSolutions() {
    // Default constructor implementation
}

// ========== STRING METHODS ==========

std::string StringsVectorsSolutions::create_string(const std::string& content) {
    // Create and return a string with the given content
    return std::string(content);
}

std::string StringsVectorsSolutions::concatenate_strings(const std::string& str1, const std::string& str2) {
    // Concatenate two strings and return the result
    return str1 + str2;
}

size_t StringsVectorsSolutions::get_string_length(const std::string& str) {
    // Return the length of the input string
    return str.length();
}

// ========== VECTOR METHODS ==========

std::vector<int> StringsVectorsSolutions::create_vector(int size, int initial_value) {
    // Create and return a vector with the specified size and initial value
    return std::vector<int>(size, initial_value);
}

size_t StringsVectorsSolutions::add_to_vector(std::vector<int>& vec, int value) {
    // Add the value to the vector and return the updated size
    vec.push_back(value);
    return vec.size();
}

size_t StringsVectorsSolutions::get_vector_size(const std::vector<int>& vec) {
    // Return the size of the input vector
    return vec.size();
}

int StringsVectorsSolutions::sum_vector_elements(const std::vector<int>& vec) {
    // Calculate and return the sum of all elements in the vector
    int sum = 0;
    for (const int& element : vec) {
        sum += element;
    }
    return sum;
}

} // namespace cpp_primer