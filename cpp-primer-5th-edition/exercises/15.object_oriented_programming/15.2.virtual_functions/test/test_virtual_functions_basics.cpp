#include <gtest/gtest.h>
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
    
    // Getter for testing
    std::string getColor() const { return color; }
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
    
    // Getters for testing
    double getWidth() const { return width; }
    double getHeight() const { return height; }
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
    
    // Getter for testing
    double getRadius() const { return radius; }
};

// Test for Shape base class (abstract)
TEST(VirtualFunctionsTest, ShapeBaseClass) {
    // Shape is abstract, so we can't instantiate it directly
    SUCCEED() << "Shape is an abstract base class";
}

// Test for Rectangle derived class
TEST(VirtualFunctionsTest, RectangleDerivedClass) {
    Rectangle rectangle("Red", 5.0, 3.0);
    EXPECT_EQ(rectangle.getColor(), "Red");
    EXPECT_DOUBLE_EQ(rectangle.area(), 15.0);
    EXPECT_DOUBLE_EQ(rectangle.perimeter(), 16.0);
    EXPECT_DOUBLE_EQ(rectangle.getWidth(), 5.0);
    EXPECT_DOUBLE_EQ(rectangle.getHeight(), 3.0);
}

// Test for Circle derived class
TEST(VirtualFunctionsTest, CircleDerivedClass) {
    Circle circle("Blue", 4.0);
    EXPECT_EQ(circle.getColor(), "Blue");
    EXPECT_NEAR(circle.area(), M_PI * 16.0, 0.001);
    EXPECT_NEAR(circle.perimeter(), 2 * M_PI * 4.0, 0.001);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 4.0);
}

// Test for polymorphism
TEST(VirtualFunctionsTest, Polymorphism) {
    std::unique_ptr<Shape> rect = std::make_unique<Rectangle>("Green", 3.0, 4.0);
    std::unique_ptr<Shape> circle = std::make_unique<Circle>("Yellow", 2.0);
    
    // Test that virtual functions work correctly
    EXPECT_DOUBLE_EQ(rect->area(), 12.0);
    EXPECT_NEAR(circle->area(), M_PI * 4.0, 0.001);
    
    // Test perimeter
    EXPECT_DOUBLE_EQ(rect->perimeter(), 14.0);
    EXPECT_NEAR(circle->perimeter(), 2 * M_PI * 2.0, 0.001);
}