#ifndef OBJECT_ORIENTED_SOLUTIONS_H
#define OBJECT_ORIENTED_SOLUTIONS_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <cmath>

namespace cpp_primer {

/**
 * @brief Base class representing a generic shape
 * 
 * This class provides a foundation for different geometric shapes and demonstrates
 * inheritance and virtual functions.
 */
class ShapeSolutions {
protected:
    std::string name;
    
public:
    // ========== CONSTRUCTORS ==========
    ShapeSolutions();
    explicit ShapeSolutions(const std::string& shape_name);
    
    // ========== VIRTUAL DESTRUCTOR ==========
    virtual ~ShapeSolutions();
    
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
class RectangleSolutions : public ShapeSolutions {
protected:
    double width;
    double height;
    
public:
    // ========== CONSTRUCTORS ==========
    RectangleSolutions();
    RectangleSolutions(double w, double h);
    RectangleSolutions(const std::string& name, double w, double h);
    
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
class CircleSolutions : public ShapeSolutions {
protected:
    double radius;
    
public:
    // ========== CONSTRUCTORS ==========
    CircleSolutions();
    explicit CircleSolutions(double r);
    CircleSolutions(const std::string& name, double r);
    
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
class TriangleSolutions : public ShapeSolutions {
protected:
    double base;
    double height;
    double side1, side2, side3;
    
public:
    // ========== CONSTRUCTORS ==========
    TriangleSolutions();
    TriangleSolutions(double b, double h, double s1, double s2, double s3);
    TriangleSolutions(const std::string& name, double b, double h, double s1, double s2, double s3);
    
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
class DrawingSolutions {
private:
    std::vector<std::unique_ptr<ShapeSolutions>> shapes;
    
public:
    // ========== CONSTRUCTORS ==========
    DrawingSolutions();
    
    // ========== SHAPE MANAGEMENT ==========
    void add_shape(std::unique_ptr<ShapeSolutions> shape);
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
    ShapeSolutions* get_shape(size_t index);
    const ShapeSolutions* get_shape(size_t index) const;
};

/**
 * @brief Interface for objects that can be cloned
 * 
 * This class demonstrates the concept of interfaces in C++ using pure virtual functions.
 */
class CloneableSolutions {
public:
    virtual ~CloneableSolutions() = default;
    virtual std::unique_ptr<CloneableSolutions> clone() const = 0;
};

/**
 * @brief Class that implements the Cloneable interface
 * 
 * This class demonstrates the clone pattern and interface implementation.
 */
class CloneableRectangleSolutions : public RectangleSolutions, public CloneableSolutions {
public:
    // ========== CONSTRUCTORS ==========
    CloneableRectangleSolutions();
    CloneableRectangleSolutions(double w, double h);
    CloneableRectangleSolutions(const std::string& name, double w, double h);
    
    // ========== CLONEABLE INTERFACE ==========
    std::unique_ptr<CloneableSolutions> clone() const override;
    
    // ========== VIRTUAL METHODS ==========
    void draw() const override;
};

} // namespace cpp_primer

#endif // OBJECT_ORIENTED_SOLUTIONS_H