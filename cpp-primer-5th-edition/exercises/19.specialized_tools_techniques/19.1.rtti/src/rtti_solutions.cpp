// Exercise 19.1a: Run-Time Type Identification (RTTI) - Solution
// This exercise demonstrates RTTI in C++.

#include <iostream>
#include <typeinfo>
#include <string>
#include <memory>
#include <vector>

// Base class with virtual function
class Base {
public:
    virtual ~Base() = default;
    virtual void display() const {
        std::cout << "Base class" << std::endl;
    }
};

// Derived classes
class Derived1 : public Base {
public:
    void display() const override {
        std::cout << "Derived1 class" << std::endl;
    }
    
    void derived1Specific() const {
        std::cout << "Derived1 specific function" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void display() const override {
        std::cout << "Derived2 class" << std::endl;
    }
    
    void derived2Specific() const {
        std::cout << "Derived2 specific function" << std::endl;
    }
};

int main() {
    // Use typeid operator for type identification
    Base* base_ptr = new Derived1();
    std::cout << "Type of base_ptr: " << typeid(*base_ptr).name() << std::endl;
    std::cout << "Type of Base: " << typeid(Base).name() << std::endl;
    std::cout << "Type of Derived1: " << typeid(Derived1).name() << std::endl;
    
    // Compare type information
    if (typeid(*base_ptr) == typeid(Derived1)) {
        std::cout << "base_ptr points to Derived1 object" << std::endl;
    }
    
    if (typeid(*base_ptr) != typeid(Derived2)) {
        std::cout << "base_ptr does not point to Derived2 object" << std::endl;
    }
    
    // Use dynamic_cast for safe downcasting
    Derived1* derived1_ptr = dynamic_cast<Derived1*>(base_ptr);
    if (derived1_ptr) {
        std::cout << "Successfully cast to Derived1*" << std::endl;
        derived1_ptr->derived1Specific();
    }
    
    // Try to cast to Derived2* (should fail)
    Derived2* derived2_ptr = dynamic_cast<Derived2*>(base_ptr);
    if (!derived2_ptr) {
        std::cout << "Failed to cast to Derived2* (as expected)" << std::endl;
    }
    
    // Implement type-safe container
    std::vector<std::unique_ptr<Base>> container;
    container.push_back(std::make_unique<Derived1>());
    container.push_back(std::make_unique<Derived2>());
    container.push_back(std::make_unique<Derived1>());
    
    std::cout << "Container contents:" << std::endl;
    for (const auto& obj : container) {
        // Use typeid to determine actual type
        if (typeid(*obj) == typeid(Derived1)) {
            std::cout << "  Derived1 object" << std::endl;
            // Safe downcast
            Derived1* d1 = dynamic_cast<Derived1*>(obj.get());
            if (d1) d1->derived1Specific();
        } else if (typeid(*obj) == typeid(Derived2)) {
            std::cout << "  Derived2 object" << std::endl;
            // Safe downcast
            Derived2* d2 = dynamic_cast<Derived2*>(obj.get());
            if (d2) d2->derived2Specific();
        } else {
            std::cout << "  Base object" << std::endl;
        }
    }
    
    delete base_ptr;
    return 0;
}