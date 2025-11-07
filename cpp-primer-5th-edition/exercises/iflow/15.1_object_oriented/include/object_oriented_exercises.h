#ifndef OBJECT_ORIENTED_EXERCISES_H
#define OBJECT_ORIENTED_EXERCISES_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace cpp_primer {

/**
 * @brief Base class representing a generic shape
 * 
 * This class provides a foundation for different geometric shapes and demonstrates
 * inheritance and virtual functions.
 */
class Shape {
protected:
    std::string name;
    
public:
    // ========== CONSTRUCTORS ==========
    Shape();
    explicit Shape(const std::string& shape_name);
    
    // ========== VIRTUAL DESTRUCTOR ==========
    virtual ~Shape();
    
    // ========== VIRTUAL METHODS ==========
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;
    
    // ========== ACCESSORS ==========
    std::string get_name() const;
    virtual void display_info() const;
    
    // ========== MODIFIERS ==========
    void set_name(const std::string& new_name);
};

/**
 * @brief Derived class representing a rectangle
 * 
 * This class demonstrates inheritance and polymorphism by implementing
 * the virtual methods from the Shape base class.
 */
class Rectangle : public Shape {
protected:
    double width;
    double height;
    
public:
    // ========== CONSTRUCTORS ==========
    Rectangle();
    Rectangle(double w, double h);
    Rectangle(const std::string& name, double w, double h);
    
    // ========== VIRTUAL METHODS ==========
    double area() const override;
    double perimeter() const override;
    void draw() const override;
    
    // ========== ACCESSORS ==========
    double get_width() const;
    double get_height() const;
    void display_info() const override;
    
    // ========== MODIFIERS ==========
    void set_width(double w);
    void set_height(double h);
    void set_dimensions(double w, double h);
};

/**
 * @brief Derived class representing a circle
 * 
 * This class demonstrates inheritance and polymorphism by implementing
 * the virtual methods from the Shape base class.
 */
class Circle : public Shape {
protected:
    double radius;
    
public:
    // ========== CONSTRUCTORS ==========
    Circle();
    explicit Circle(double r);
    Circle(const std::string& name, double r);
    
    // ========== VIRTUAL METHODS ==========
    double area() const override;
    double perimeter() const override;
    void draw() const override;
    
    // ========== ACCESSORS ==========
    double get_radius() const;
    void display_info() const override;
    
    // ========== MODIFIERS ==========
    void set_radius(double r);
};

/**
 * @brief Derived class representing a triangle
 * 
 * This class demonstrates inheritance and polymorphism by implementing
 * the virtual methods from the Shape base class.
 */
class Triangle : public Shape {
protected:
    double base;
    double height;
    double side1, side2, side3;
    
public:
    // ========== CONSTRUCTORS ==========
    Triangle();
    Triangle(double b, double h, double s1, double s2, double s3);
    Triangle(const std::string& name, double b, double h, double s1, double s2, double s3);
    
    // ========== VIRTUAL METHODS ==========
    double area() const override;
    double perimeter() const override;
    void draw() const override;
    
    // ========== ACCESSORS ==========
    double get_base() const;
    double get_height() const;
    double get_side1() const;
    double get_side2() const;
    double get_side3() const;
    void display_info() const override;
    
    // ========== MODIFIERS ==========
    void set_base(double b);
    void set_height(double h);
    void set_sides(double s1, double s2, double s3);
};

/**
 * @brief Class demonstrating multiple inheritance and advanced OOP concepts
 * 
 * This class shows how to work with polymorphism, virtual functions,
 * and abstract base classes in more complex scenarios.
 */
class Drawing {
private:
    std::vector<std::unique_ptr<Shape>> shapes;
    
public:
    // ========== CONSTRUCTORS ==========
    Drawing();
    
    // ========== SHAPE MANAGEMENT ==========
    void add_shape(std::unique_ptr<Shape> shape);
    void remove_shape(size_t index);
    void clear_shapes();
    size_t get_shape_count() const;
    
    // ========== DRAWING OPERATIONS ==========
    void draw_all() const;
    void display_all_info() const;
    std::vector<double> calculate_all_areas() const;
    std::vector<double> calculate_all_perimeters() const;
    double total_area() const;
    double total_perimeter() const;
    
    // ========== ACCESSORS ==========
    Shape* get_shape(size_t index);
    const Shape* get_shape(size_t index) const;
};

/**
 * @brief Interface for objects that can be cloned
 * 
 * This class demonstrates the concept of interfaces in C++ using pure virtual functions.
 */
class Cloneable {
public:
    virtual ~Cloneable() = default;
    virtual std::unique_ptr<Cloneable> clone() const = 0;
};

/**
 * @brief Class that implements the Cloneable interface
 * 
 * This class demonstrates the clone pattern and interface implementation.
 */
class CloneableRectangle : public Rectangle, public Cloneable {
public:
    // ========== CONSTRUCTORS ==========
    CloneableRectangle();
    CloneableRectangle(double w, double h);
    CloneableRectangle(const std::string& name, double w, double h);
    
    // ========== CLONEABLE INTERFACE ==========
    std::unique_ptr<Cloneable> clone() const override;
    
    // ========== VIRTUAL METHODS ==========
    void draw() const override;
};

} // namespace cpp_primer

#endif // OBJECT_ORIENTED_EXERCISES_H