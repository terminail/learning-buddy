// Exercise: String Conversion - Solution
// This exercise demonstrates string conversion functions in C++.

#include <iostream>
#include <string>
#include <sstream>

int main() {
    // Solution: Use std::to_string() to convert numbers to strings
    int int_val = 42;
    double double_val = 3.14159;
    long long_val = 1234567890L;
    
    std::string int_str = std::to_string(int_val);
    std::string double_str = std::to_string(double_val);
    std::string long_str = std::to_string(long_val);
    
    std::cout << "Integer to string: " << int_str << std::endl;
    std::cout << "Double to string: " << double_str << std::endl;
    std::cout << "Long to string: " << long_str << std::endl;

    // Solution: Use std::stoi(), std::stol(), std::stoll() to convert strings to integers
    std::string int_string = "123";
    std::string long_string = "9876543210";
    std::string hex_string = "FF";
    
    try {
        int converted_int = std::stoi(int_string);
        long converted_long = std::stol(long_string);
        int hex_int = std::stoi(hex_string, nullptr, 16);  // Base 16
        
        std::cout << "String to int: " << converted_int << std::endl;
        std::cout << "String to long: " << converted_long << std::endl;
        std::cout << "Hex string to int: " << hex_int << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    }

    // Solution: Use std::stof(), std::stod(), std::stold() to convert strings to floating-point
    std::string float_string = "3.14";
    std::string double_string = "2.718281828";
    
    try {
        float converted_float = std::stof(float_string);
        double converted_double = std::stod(double_string);
        
        std::cout << "String to float: " << converted_float << std::endl;
        std::cout << "String to double: " << converted_double << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    }

    // Solution: Work with std::stringstream for complex conversions
    std::string complex_string = "42 3.14 Hello 123";
    std::stringstream ss(complex_string);
    
    int num1;
    double num2;
    std::string word;
    int num3;
    
    ss >> num1 >> num2 >> word >> num3;
    
    std::cout << "Parsed values: " << num1 << ", " << num2 << ", " << word << ", " << num3 << std::endl;
    
    return 0;
}