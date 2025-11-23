// Exercise 15.1a: Inheritance Basics - Solution
// This exercise demonstrates inheritance in C++.

#include <iostream>
#include <string>

// Base class Vehicle
class Vehicle {
protected:
    std::string brand;
    std::string model;

public:
    Vehicle(const std::string& b, const std::string& m) : brand(b), model(m) {}
    
    virtual void displayInfo() const {
        std::cout << "Vehicle: " << brand << " " << model << std::endl;
    }
    
    virtual ~Vehicle() = default;
};

// Derived class Car
class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(const std::string& brand, const std::string& model, int doors) 
        : Vehicle(brand, model), numberOfDoors(doors) {}
    
    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Type: Car, Doors: " << numberOfDoors << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    int engineSize; // in cc

public:
    Motorcycle(const std::string& brand, const std::string& model, int engine) 
        : Vehicle(brand, model), engineSize(engine) {}
    
    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Type: Motorcycle, Engine: " << engineSize << "cc" << std::endl;
    }
};

int main() {
    // Create instances of Car and Motorcycle
    Car car("Toyota", "Camry", 4);
    Motorcycle motorcycle("Harley-Davidson", "Street 750", 750);
    
    // Call their displayInfo() functions
    car.displayInfo();
    std::cout << std::endl;
    motorcycle.displayInfo();
    
    return 0;
}