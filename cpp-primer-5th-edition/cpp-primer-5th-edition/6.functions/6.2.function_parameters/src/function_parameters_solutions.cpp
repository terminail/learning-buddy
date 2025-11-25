// Exercise 6.1c: Function Parameters - Solution
// This exercise demonstrates different function parameter passing mechanisms in C++.

#include <iostream>
#include <vector>
#include <string>

// Solution: Use pass-by-value parameters
void passByValue(int value) {
    std::cout << "Inside passByValue: " << value << std::endl;
    value = 100;  // Modifies local copy only
    std::cout << "After modification in passByValue: " << value << std::endl;
}

// Solution: Use pass-by-reference parameters
void passByReference(int& ref) {
    std::cout << "Inside passByReference: " << ref << std::endl;
    ref = 200;  // Modifies original variable
    std::cout << "After modification in passByReference: " << ref << std::endl;
}

// Solution: Use pass-by-pointer parameters
void passByPointer(int* ptr) {
    if (ptr != nullptr) {
        std::cout << "Inside passByPointer: " << *ptr << std::endl;
        *ptr = 300;  // Modifies original variable through pointer
        std::cout << "After modification in passByPointer: " << *ptr << std::endl;
    } else {
        std::cout << "Null pointer passed to passByPointer" << std::endl;
    }
}

// Solution: Use const parameters
void constParameter(const std::string& str) {
    std::cout << "Inside constParameter: " << str << std::endl;
    // str = "modified";  // Error! Cannot modify const parameter
    std::cout << "String length: " << str.length() << std::endl;
}

// Solution: Function with array parameter (decays to pointer)
void arrayParameter(int arr[], int size) {
    std::cout << "Inside arrayParameter:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        arr[i] *= 2;  // Modifies original array elements
    }
}

int main() {
    // Solution: Use pass-by-value parameters
    std::cout << "=== Pass by Value ===" << std::endl;
    int value = 42;
    std::cout << "Before passByValue: " << value << std::endl;
    passByValue(value);
    std::cout << "After passByValue: " << value << std::endl;  // Unchanged
    
    // Solution: Use pass-by-reference parameters
    std::cout << "\n=== Pass by Reference ===" << std::endl;
    int ref = 42;
    std::cout << "Before passByReference: " << ref << std::endl;
    passByReference(ref);
    std::cout << "After passByReference: " << ref << std::endl;  // Changed
    
    // Solution: Use pass-by-pointer parameters
    std::cout << "\n=== Pass by Pointer ===" << std::endl;
    int ptr = 42;
    std::cout << "Before passByPointer: " << ptr << std::endl;
    passByPointer(&ptr);
    std::cout << "After passByPointer: " << ptr << std::endl;  // Changed
    
    // Test with null pointer
    passByPointer(nullptr);
    
    // Solution: Use const parameters
    std::cout << "\n=== Const Parameters ===" << std::endl;
    std::string message = "Hello, World!";
    constParameter(message);
    std::cout << "After constParameter: " << message << std::endl;  // Unchanged
    
    // Solution: Array parameter
    std::cout << "\n=== Array Parameter ===" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Before arrayParameter:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    arrayParameter(numbers, size);
    
    std::cout << "After arrayParameter:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    return 0;
}