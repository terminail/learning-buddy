// Exercise 12.1a: Dynamic Memory Allocation - Solution
// This exercise demonstrates dynamic memory allocation in C++.

#include <iostream>

int main() {
    // Allocate memory for a single integer using new
    int* single_int = new int(42);
    std::cout << "Single integer value: " << *single_int << std::endl;
    
    // Deallocate the single integer memory using delete
    delete single_int;
    single_int = nullptr; // Good practice to avoid dangling pointers
    
    // Allocate memory for an array of integers using new
    int* int_array = new int[5]{1, 2, 3, 4, 5};
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;
    
    // Deallocate the array memory using delete[]
    delete[] int_array;
    int_array = nullptr; // Good practice to avoid dangling pointers
    
    return 0;
}