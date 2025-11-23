#include "function_exercises.h"
#include <stdexcept>
#include <algorithm>
#include <cmath>

namespace cpp_primer {

// ========== 基础类型和变量练习 ==========

int add_integers(int a, int b) {
    return a + b;
}

bool is_even(int num) {
    return num % 2 == 0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// ========== 字符串和数组练习 ==========

std::string reverse_string(const std::string& str) {
    std::string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

int count_vowels(const std::string& str) {
    int count = 0;
    std::string vowels = "aeiouAEIOU";
    for (char c : str) {
        if (vowels.find(c) != std::string::npos) {
            count++;
        }
    }
    return count;
}

int find_max(const int arr[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive");
    }
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

double calculate_average(const int arr[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive");
    }
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// ========== 控制流练习 ==========

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void print_multiplication_table(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }
}

int fibonacci(int n) {
    if (n < 0) {
        throw std::invalid_argument("Fibonacci is not defined for negative numbers");
    }
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// ========== 函数重载练习 ==========

int max_value(int a, int b) {
    return (a > b) ? a : b;
}

double max_value(double a, double b) {
    return (a > b) ? a : b;
}

int max_value(int a, int b, int c) {
    return max_value(max_value(a, b), c);
}

} // namespace cpp_primer