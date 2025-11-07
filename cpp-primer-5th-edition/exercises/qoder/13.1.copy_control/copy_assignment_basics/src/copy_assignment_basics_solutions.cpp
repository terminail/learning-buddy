#include <iostream>
#include <string>
#include <cstring>

// Solution: Implement a class with proper copy assignment operator
class MyArray {
private:
    int* data;
    size_t size;

public:
    // Solution: Implement default constructor
    MyArray() : data(nullptr), size(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    
    // Solution: Implement parameterized constructor
    MyArray(size_t s) : size(s) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = static_cast<int>(i);
        }
        std::cout << "Parameterized constructor called (size: " << size << ")" << std::endl;
    }
    
    // Solution: Implement copy constructor
    MyArray(const MyArray& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        std::cout << "Copy constructor called" << std::endl;
    }
    
    // Solution: Implement copy assignment operator
    MyArray& operator=(const MyArray& rhs) {
        std::cout << "Copy assignment operator called" << std::endl;
        
        // Check for self-assignment
        if (this == &rhs) {
            return *this;
        }
        
        // Deallocate existing memory
        delete[] data;
        
        // Allocate new memory and copy data
        size = rhs.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = rhs.data[i];
        }
        
        return *this;
    }
    
    // Solution: Implement destructor
    ~MyArray() {
        delete[] data;
        std::cout << "Destructor called" << std::endl;
    }
    
    // Solution: Implement a display method to print the array
    void display() const {
        std::cout << "Array (size " << size << "): ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    
    // Solution: Implement getters for size and data (for testing)
    size_t getSize() const { return size; }
    int* getData() const { return data; }
};

int main() {
    // Solution: Create objects and demonstrate copy assignment
    // Create objects using different constructors
    MyArray arr1(5);
    MyArray arr2;
    
    std::cout << "Before assignment:" << std::endl;
    arr1.display();
    arr2.display();
    
    // Use copy assignment operator to assign one object to another
    arr2 = arr1;
    
    std::cout << "After assignment:" << std::endl;
    arr1.display();
    arr2.display();
    
    // Demonstrate self-assignment
    std::cout << "Testing self-assignment:" << std::endl;
    arr1 = arr1;
    
    return 0;
}