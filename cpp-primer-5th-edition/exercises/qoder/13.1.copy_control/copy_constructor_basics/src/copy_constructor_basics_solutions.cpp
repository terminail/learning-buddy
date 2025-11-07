#include <iostream>
#include <string>
#include <cstring>

// Solution: Implement a class with proper copy constructor
class MyString {
private:
    char* data;
    size_t len;

public:
    // Solution: Implement default constructor
    MyString() : data(new char[1]), len(0) {
        data[0] = '\0';
    }
    
    // Solution: Implement parameterized constructor
    MyString(const char* s) : len(strlen(s)) {
        data = new char[len + 1];
        strcpy(data, s);
    }
    
    // Solution: Implement copy constructor
    MyString(const MyString& other) : len(other.len) {
        data = new char[len + 1];
        strcpy(data, other.data);
        std::cout << "Copy constructor called" << std::endl;
    }
    
    // Solution: Implement destructor
    ~MyString() {
        delete[] data;
        std::cout << "Destructor called" << std::endl;
    }
    
    // Solution: Implement a display method to print the string
    void display() const {
        std::cout << "String: " << data << ", Length: " << len << std::endl;
    }
    
    // Solution: Implement getters for len and data (for testing)
    size_t getLength() const { return len; }
    const char* getData() const { return data; }
};

int main() {
    // Solution: Create objects using different constructors
    // Create an object using the parameterized constructor
    MyString str1("Hello World");
    std::cout << "Original string: ";
    str1.display();
    
    // Create a copy using the copy constructor
    MyString str2 = str1;
    std::cout << "Copied string: ";
    str2.display();
    
    // Display both objects to verify they are independent
    std::cout << "Both strings after creation:" << std::endl;
    str1.display();
    str2.display();
    
    return 0;
}