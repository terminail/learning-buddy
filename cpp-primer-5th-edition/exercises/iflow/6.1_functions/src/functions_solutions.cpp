#include "functions_solutions.h"
#include <algorithm>
#include <stdexcept>

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

FunctionsSolutions::FunctionsSolutions() {
    // Default constructor implementation
}

// ========== BASIC FUNCTIONS ==========

int FunctionsSolutions::square(int number) {
    // Calculate the square of a number
    return number * number;
}

double FunctionsSolutions::rectangle_area(double length, double width) {
    // Calculate the area of a rectangle
    return length * width;
}

// ========== FUNCTION OVERLOADING ==========

int FunctionsSolutions::add(int a, int b) {
    // Add two integers
    return a + b;
}

double FunctionsSolutions::add(double a, double b) {
    // Add two doubles
    return a + b;
}

std::string FunctionsSolutions::add(const std::string& str1, const std::string& str2) {
    // Concatenate two strings
    return str1 + str2;
}

// ========== PASS BY REFERENCE ==========

void FunctionsSolutions::swap(int& a, int& b) {
    // Swap two integers using pass by reference
    int temp = a;
    a = b;
    b = temp;
}

int& FunctionsSolutions::find_maximum(std::vector<int>& numbers) {
    // Find the maximum element in a vector and return it by reference
    if (numbers.empty()) {
        throw std::invalid_argument("Vector is empty");
    }
    return *std::max_element(numbers.begin(), numbers.end());
}

// ========== DEFAULT PARAMETERS ==========

int FunctionsSolutions::power(int base, int exponent) {
    // Calculate the power of a number
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// ========== FUNCTION WITH ARRAY PARAMETER ==========

int FunctionsSolutions::sum_array(const int arr[], int size) {
    // Calculate the sum of array elements
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

} // namespace cpp_primer