// Solution 3.1.1a: Array Basics
// This exercise demonstrates C-style arrays in C++.

#include <iostream>

int main() {
    // Solution: Declare and initialize an array of 5 integers with values {1, 2, 3, 4, 5}
    int numbers[5] = {1, 2, 3, 4, 5};
    
    // Solution: Access and print individual elements of the array
    std::cout << "Array elements:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    // Solution: Calculate and print the sum of all elements in the array
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    std::cout << "Sum of elements: " << sum << std::endl;
    
    // Solution: Find and print the largest element in the array
    int largest = numbers[0];
    for (int i = 1; i < 5; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    std::cout << "Largest element: " << largest << std::endl;
    
    // Solution: Modify elements in the array
    std::cout << "Array elements after multiplying by 2:" << std::endl;
    for (int i = 0; i < 5; i++) {
        numbers[i] *= 2;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    return 0;
}