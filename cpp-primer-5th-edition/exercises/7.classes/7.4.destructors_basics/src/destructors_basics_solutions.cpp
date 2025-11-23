// Exercise: Destructors Basics - Solution
// This exercise demonstrates destructors in C++.

#include <iostream>
#include <string>

// Solution: Define a class with a basic destructor
class SimpleClass {
private:
    std::string name;
    
public:
    // Constructor
    SimpleClass(const std::string& n) : name(n) {
        std::cout << "Constructor called for " << name << std::endl;
    }
    
    // Destructor
    ~SimpleClass() {
        std::cout << "Destructor called for " << name << std::endl;
    }
    
    std::string getName() const { return name; }
};

// Solution: Class with resource management
class ResourceManager {
private:
    std::string* data;
    size_t size;
    
public:
    // Constructor
    ResourceManager(size_t s) : size(s) {
        data = new std::string[size];
        std::cout << "ResourceManager constructor: Allocated memory for " << size << " strings" << std::endl;
    }
    
    // Destructor - properly clean up resources
    ~ResourceManager() {
        delete[] data;
        std::cout << "ResourceManager destructor: Freed memory for " << size << " strings" << std::endl;
    }
    
    // Copy constructor (Rule of Three)
    ResourceManager(const ResourceManager& other) : size(other.size) {
        data = new std::string[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        std::cout << "ResourceManager copy constructor called" << std::endl;
    }
    
    // Copy assignment operator (Rule of Three)
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new std::string[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
            std::cout << "ResourceManager copy assignment operator called" << std::endl;
        }
        return *this;
    }
    
    size_t getSize() const { return size; }
};

// Solution: Base and derived classes with destructors
class Base {
public:
    Base() { std::cout << "Base constructor called" << std::endl; }
    virtual ~Base() { std::cout << "Base destructor called" << std::endl; }
};

class Derived : public Base {
private:
    std::string* resource;
    
public:
    Derived() : resource(new std::string("derived resource")) {
        std::cout << "Derived constructor called" << std::endl;
    }
    
    // Virtual destructor ensures proper cleanup
    virtual ~Derived() {
        delete resource;
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main() {
    // Solution: Create objects and observe destructor behavior
    {
        std::cout << "Creating SimpleClass objects:" << std::endl;
        SimpleClass obj1("Object1");
        SimpleClass obj2("Object2");
        std::cout << "End of scope block" << std::endl;
        // Destructors called here in reverse order
    }
    
    std::cout << std::endl;
    
    // Solution: Test resource management
    std::cout << "Testing ResourceManager:" << std::endl;
    ResourceManager rm(5);
    {
        ResourceManager rm2 = rm; // Copy constructor called
        std::cout << "ResourceManager objects created" << std::endl;
    } // rm2 destructor called here
    std::cout << "ResourceManager rm still exists" << std::endl;
    // rm destructor called at end of main
    
    std::cout << std::endl;
    
    // Solution: Test destructor order with inheritance
    std::cout << "Testing inheritance destructors:" << std::endl;
    {
        Derived derivedObj;
        std::cout << "Derived object created" << std::endl;
    } // Destructors called in reverse order: Derived then Base
    std::cout << "Derived object destroyed" << std::endl;
    
    return 0;
}