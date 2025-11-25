// Exercise 17.1a: Bitset Operations - Solution
// This exercise demonstrates bitset operations in C++.

#include <iostream>
#include <bitset>

int main() {
    // Create bitsets of different sizes
    std::bitset<8> bits1(std::string("10101010"));
    std::bitset<8> bits2(std::string("11110000"));
    std::bitset<16> bits3(0xFFFF); // All bits set to 1
    
    std::cout << "Bitset 1: " << bits1 << std::endl;
    std::cout << "Bitset 2: " << bits2 << std::endl;
    std::cout << "Bitset 3: " << bits3 << std::endl;
    
    // Perform bitwise operations on bitsets
    std::cout << "AND: " << (bits1 & bits2) << std::endl;
    std::cout << "OR:  " << (bits1 | bits2) << std::endl;
    std::cout << "XOR: " << (bits1 ^ bits2) << std::endl;
    std::cout << "NOT: " << (~bits1) << std::endl;
    
    // Compare bitsets
    std::cout << "bits1 == bits2: " << (bits1 == bits2) << std::endl;
    std::cout << "bits1 != bits2: " << (bits1 != bits2) << std::endl;
    
    // Use bitset member functions
    bits1.set(0);  // Set bit 0 to 1
    bits1.reset(1);  // Set bit 1 to 0
    bits1.flip(2);  // Flip bit 2
    std::cout << "Modified bits1: " << bits1 << std::endl;
    
    std::cout << "Bit 3 is " << (bits1.test(3) ? "set" : "not set") << std::endl;
    std::cout << "Any bits set: " << (bits1.any() ? "yes" : "no") << std::endl;
    std::cout << "All bits set: " << (bits1.all() ? "yes" : "no") << std::endl;
    std::cout << "No bits set: " << (bits1.none() ? "yes" : "no") << std::endl;
    std::cout << "Number of bits set: " << bits1.count() << std::endl;
    std::cout << "Size of bitset: " << bits1.size() << std::endl;
    
    return 0;
}