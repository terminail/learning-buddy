#include <gtest/gtest.h>
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
    
    // Getter functions for testing
    std::string getBrand() const { return brand; }
    std::string getModel() const { return model; }
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
    
    // Getter function for testing
    int getNumberOfDoors() const { return numberOfDoors; }
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
    
    // Getter function for testing
    int getEngineSize() const { return engineSize; }
};

// Test for Vehicle base class
TEST(InheritanceBasicsTest, VehicleBaseClass) {
    Vehicle vehicle("Generic", "Model");
    EXPECT_EQ(vehicle.getBrand(), "Generic");
    EXPECT_EQ(vehicle.getModel(), "Model");
}

// Test for Car derived class
TEST(InheritanceBasicsTest, CarDerivedClass) {
    Car car("Toyota", "Camry", 4);
    EXPECT_EQ(car.getBrand(), "Toyota");
    EXPECT_EQ(car.getModel(), "Camry");
    EXPECT_EQ(car.getNumberOfDoors(), 4);
}

// Test for Motorcycle derived class
TEST(InheritanceBasicsTest, MotorcycleDerivedClass) {
    Motorcycle motorcycle("Harley-Davidson", "Street 750", 750);
    EXPECT_EQ(motorcycle.getBrand(), "Harley-Davidson");
    EXPECT_EQ(motorcycle.getModel(), "Street 750");
    EXPECT_EQ(motorcycle.getEngineSize(), 750);
}

// Test for polymorphism
TEST(InheritanceBasicsTest, Polymorphism) {
    Vehicle* car = new Car("Honda", "Civic", 4);
    Vehicle* motorcycle = new Motorcycle("Yamaha", "YZF-R3", 321);
    
    // Test that the objects were created correctly
    EXPECT_EQ(car->getBrand(), "Honda");
    EXPECT_EQ(motorcycle->getBrand(), "Yamaha");
    
    delete car;
    delete motorcycle;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
