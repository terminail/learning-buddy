#include <iostream>
#include <climits>
#include <string>

int main() {
    std::cout << "LONG_MAX: " << LONG_MAX << std::endl;
    std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;
    
    // Check if our test value is within range
    std::string test_value = "9876543210";
    std::cout << "Test value: " << test_value << std::endl;
    
    if (std::stoll(test_value) <= LONG_MAX) {
        std::cout << "Test value is within LONG_MAX range" << std::endl;
    } else {
        std::cout << "Test value exceeds LONG_MAX range" << std::endl;
    }
    
    return 0;
}