// Exercise 18.1b: Exception Handling - Solution
// This exercise demonstrates exception handling in C++.

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

// Implement basic exception handling
double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

// Create custom exception classes
class CustomException : public std::exception {
private:
    std::string message;
    
public:
    CustomException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class IndexOutOfBoundsException : public std::exception {
private:
    std::string message;
    
public:
    IndexOutOfBoundsException(size_t index, size_t size) {
        message = "Index " + std::to_string(index) + " out of bounds for size " + std::to_string(size);
    }
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Implement exception specifications
void noThrowFunction() noexcept {
    // This function guarantees it won't throw exceptions
    std::cout << "This function doesn't throw exceptions" << std::endl;
}

int main() {
    // Implement basic exception handling
    try {
        double result = divide(10.0, 0.0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Caught runtime error: " << e.what() << std::endl;
    }
    
    // Create and use custom exceptions
    try {
        throw CustomException("This is a custom exception");
    } catch (const CustomException& e) {
        std::cout << "Caught custom exception: " << e.what() << std::endl;
    }
    
    // Test index out of bounds exception
    try {
        std::vector<int> vec = {1, 2, 3};
        if (5 >= vec.size()) {
            throw IndexOutOfBoundsException(5, vec.size());
        }
    } catch (const IndexOutOfBoundsException& e) {
        std::cout << "Caught index out of bounds exception: " << e.what() << std::endl;
    }
    
    // Work with exception specifications
    noThrowFunction();
    
    // Multiple catch blocks
    try {
        throw std::invalid_argument("Invalid argument");
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid argument: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught generic exception: " << e.what() << std::endl;
    }
    
    return 0;
}