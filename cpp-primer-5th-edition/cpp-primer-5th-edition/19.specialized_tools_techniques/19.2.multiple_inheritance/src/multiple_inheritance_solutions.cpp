// Exercise 19.1b: Multiple Inheritance - Solution
// This exercise demonstrates multiple inheritance in C++.

#include <iostream>
#include <string>

// Implement basic multiple inheritance
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

// Handle diamond problem with virtual inheritance
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
    
    // Inherits eat() from Animal through virtual inheritance
    // No ambiguity because of virtual inheritance
};

// Implement mixins using multiple inheritance
class TimestampMixin {
protected:
    std::string timestamp = "2023-01-01 12:00:00";
    
public:
    const std::string& getTimestamp() const {
        return timestamp;
    }
};

class LoggableMixin {
public:
    void log(const std::string& message) const {
        std::cout << "[LOG] " << message << std::endl;
    }
};

class Event : public TimestampMixin, public LoggableMixin {
private:
    std::string description;
    
public:
    Event(const std::string& desc) : description(desc) {}
    
    void process() const {
        log("Processing event: " + description + " at " + getTimestamp());
    }
};

int main() {
    // Implement basic multiple inheritance
    Duck duck;
    duck.fly();
    duck.swim();
    duck.quack();
    
    // Handle diamond problem with virtual inheritance
    Bat bat;
    bat.eat();    // No ambiguity due to virtual inheritance
    bat.breathe();
    bat.flap();
    bat.fly();
    
    // Implement mixins using multiple inheritance
    Event event("System startup");
    event.process();
    
    return 0;
}