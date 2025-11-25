#include <gtest/gtest.h>
#include <string>
#include <iostream>

// Basic multiple inheritance
class Flyable {
public:
    virtual void fly() const {
        std::cout << "Flying" << std::endl;
    }
    virtual ~Flyable() = default;
};

class Swimmable {
public:
    virtual void swim() const {
        std::cout << "Swimming" << std::endl;
    }
    virtual ~Swimmable() = default;
};

class Duck : public Flyable, public Swimmable {
public:
    void quack() const {
        std::cout << "Quacking" << std::endl;
    }
    
    void fly() const override {
        std::cout << "Duck flying" << std::endl;
    }
    
    void swim() const override {
        std::cout << "Duck swimming" << std::endl;
    }
};

// Test for basic multiple inheritance
TEST(MultipleInheritanceTest, BasicMultipleInheritance) {
    Duck duck;
    
    // Test that duck has all the capabilities
    duck.fly();
    duck.swim();
    duck.quack();
    
    // Test polymorphism
    Flyable* flyable = &duck;
    Swimmable* swimmable = &duck;
    
    flyable->fly();
    swimmable->swim();
    
    SUCCEED() << "Basic multiple inheritance working correctly";
}

// Virtual inheritance to solve diamond problem
class Animal {
public:
    virtual void eat() const {
        std::cout << "Eating" << std::endl;
    }
    virtual ~Animal() = default;
};

class Mammal : virtual public Animal {
public:
    void breathe() const {
        std::cout << "Breathing air" << std::endl;
    }
};

class WingedAnimal : virtual public Animal {
public:
    void flap() const {
        std::cout << "Flapping wings" << std::endl;
    }
};

class Bat : public Mammal, public WingedAnimal {
public:
    void fly() const {
        std::cout << "Bat flying" << std::endl;
    }
};

// Test for virtual inheritance
TEST(MultipleInheritanceTest, VirtualInheritance) {
    Bat bat;
    
    // Test that bat can access all inherited functions without ambiguity
    bat.eat();     // From Animal (through virtual inheritance)
    bat.breathe(); // From Mammal
    bat.flap();    // From WingedAnimal
    bat.fly();     // From Bat
    
    SUCCEED() << "Virtual inheritance resolving diamond problem correctly";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}