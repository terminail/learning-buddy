#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    std::string long_str = "9876543210";
    
    try {
        long converted_long = std::stol(long_str);
        std::cout << "Converted value: " << converted_long << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}