// Exercise 15.1b: Virtual Functions - Solution
// This exercise demonstrates virtual functions and polymorphism in C++.

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

// Base class Shape
class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& c) : color(c) {}
    virtual ~Shape() = default;
    
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const {
        std::cout << "Shape color: " << color << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(const std::string& c, double w, double h) 
        : Shape(c), width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    
    double perimeter() const override {
        return 2 * (width + height);
    }
    
    void display() const override {
        Shape::display();
        std::cout << "Type: Rectangle, Width: " << width << ", Height: " << height << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(const std::string& c, double r) 
        : Shape(c), radius(r) {}
    
    double area() const override {
        return M_PI * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
    
    void display() const override {
        Shape::display();
        std::cout << "Type: Circle, Radius: " << radius << std::endl;
    }
};

int main() {
    // Create instances of Rectangle and Circle
    Rectangle rectangle("Red", 5.0, 3.0);
    Circle circle("Blue", 4.0);
    
    // Store them in a vector of Shape pointers
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>("Green", 4.0, 6.0));
    shapes.push_back(std::make_unique<Circle>("Yellow", 3.0));
    
    // Add the stack objects to the vector
    shapes.push_back(std::make_unique<Rectangle>(rectangle));
    shapes.push_back(std::make_unique<Circle>(circle));
    
    // Iterate through the vector and call virtual functions
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "Area: " << shape->area() << std::endl;
        std::cout << "Perimeter: " << shape->perimeter() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    
    return 0;
}