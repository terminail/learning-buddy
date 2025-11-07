#include "object_oriented_solutions.h"
#include <cmath>
#include <iostream>

namespace cpp_primer {

const double PI = 3.14159265358979323846;

// ========== SHAPE CLASS SOLUTIONS ==========

// Constructors
ShapeSolutions::ShapeSolutions() : name("Shape") {
    name = "Shape";
}

ShapeSolutions::ShapeSolutions(const std::string& shape_name) : name(shape_name) {
    name = shape_name;
}

// Virtual destructor
ShapeSolutions::~ShapeSolutions() {
    // Empty implementation for base class
}

// Accessors
std::string ShapeSolutions::get_name() const {
    return name;
}

void ShapeSolutions::display_info() const {
    std::cout << "Shape: " << get_name() << std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
}

// Modifiers
void ShapeSolutions::set_name(const std::string& new_name) {
    name = new_name;
}

// ========== RECTANGLE CLASS SOLUTIONS ==========

// Constructors
RectangleSolutions::RectangleSolutions() : ShapeSolutions("Rectangle"), width(0), height(0) {
    name = "Rectangle";
    width = 0;
    height = 0;
}

RectangleSolutions::RectangleSolutions(double w, double h) : ShapeSolutions("Rectangle"), width(w), height(h) {
    name = "Rectangle";
    width = w;
    height = h;
}

RectangleSolutions::RectangleSolutions(const std::string& name, double w, double h) : ShapeSolutions(name), width(w), height(h) {
    this->name = name;
    width = w;
    height = h;
}

// Virtual methods
double RectangleSolutions::area() const {
    return width * height;
}

double RectangleSolutions::perimeter() const {
    return 2 * (width + height);
}

void RectangleSolutions::draw() const {
    std::cout << "Drawing a " << name << " with width " << width 
              << " and height " << height << std::endl;
}

// Accessors
double RectangleSolutions::get_width() const {
    return width;
}

double RectangleSolutions::get_height() const {
    return height;
}

void RectangleSolutions::display_info() const {
    std::cout << "Rectangle: " << get_name() << std::endl;
    std::cout << "Width: " << width << ", Height: " << height << std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
}

// Modifiers
void RectangleSolutions::set_width(double w) {
    width = w;
}

void RectangleSolutions::set_height(double h) {
    height = h;
}

void RectangleSolutions::set_dimensions(double w, double h) {
    width = w;
    height = h;
}

// ========== CIRCLE CLASS SOLUTIONS ==========

// Constructors
CircleSolutions::CircleSolutions() : ShapeSolutions("Circle"), radius(0) {
    name = "Circle";
    radius = 0;
}

CircleSolutions::CircleSolutions(double r) : ShapeSolutions("Circle"), radius(r) {
    name = "Circle";
    radius = r;
}

CircleSolutions::CircleSolutions(const std::string& name, double r) : ShapeSolutions(name), radius(r) {
    this->name = name;
    radius = r;
}

// Virtual methods
double CircleSolutions::area() const {
    return PI * radius * radius;
}

double CircleSolutions::perimeter() const {
    return 2 * PI * radius;
}

void CircleSolutions::draw() const {
    std::cout << "Drawing a " << name << " with radius " << radius << std::endl;
}

// Accessors
double CircleSolutions::get_radius() const {
    return radius;
}

void CircleSolutions::display_info() const {
    std::cout << "Circle: " << get_name() << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
}

// Modifiers
void CircleSolutions::set_radius(double r) {
    radius = r;
}

// ========== TRIANGLE CLASS SOLUTIONS ==========

// Constructors
TriangleSolutions::TriangleSolutions() : ShapeSolutions("Triangle"), base(0), height(0), side1(0), side2(0), side3(0) {
    name = "Triangle";
    base = 0;
    height = 0;
    side1 = 0;
    side2 = 0;
    side3 = 0;
}

TriangleSolutions::TriangleSolutions(double b, double h, double s1, double s2, double s3) : 
    ShapeSolutions("Triangle"), base(b), height(h), side1(s1), side2(s2), side3(s3) {
    name = "Triangle";
    base = b;
    height = h;
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

TriangleSolutions::TriangleSolutions(const std::string& name, double b, double h, double s1, double s2, double s3) : 
    ShapeSolutions(name), base(b), height(h), side1(s1), side2(s2), side3(s3) {
    this->name = name;
    base = b;
    height = h;
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

// Virtual methods
double TriangleSolutions::area() const {
    return 0.5 * base * height;
}

double TriangleSolutions::perimeter() const {
    return side1 + side2 + side3;
}

void TriangleSolutions::draw() const {
    std::cout << "Drawing a " << name << " with base " << base 
              << ", height " << height << ", and sides " << side1 
              << ", " << side2 << ", " << side3 << std::endl;
}

// Accessors
double TriangleSolutions::get_base() const {
    return base;
}

double TriangleSolutions::get_height() const {
    return height;
}

double TriangleSolutions::get_side1() const {
    return side1;
}

double TriangleSolutions::get_side2() const {
    return side2;
}

double TriangleSolutions::get_side3() const {
    return side3;
}

void TriangleSolutions::display_info() const {
    std::cout << "Triangle: " << get_name() << std::endl;
    std::cout << "Base: " << base << ", Height: " << height << std::endl;
    std::cout << "Sides: " << side1 << ", " << side2 << ", " << side3 << std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
}

// Modifiers
void TriangleSolutions::set_base(double b) {
    base = b;
}

void TriangleSolutions::set_height(double h) {
    height = h;
}

void TriangleSolutions::set_sides(double s1, double s2, double s3) {
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

// ========== DRAWING CLASS SOLUTIONS ==========

// Constructor
DrawingSolutions::DrawingSolutions() {
    // Empty implementation - vector initializes automatically
}

// Shape management
void DrawingSolutions::add_shape(std::unique_ptr<ShapeSolutions> shape) {
    shapes.push_back(std::move(shape));
}

void DrawingSolutions::remove_shape(size_t index) {
    if (index < shapes.size()) {
        shapes.erase(shapes.begin() + index);
    }
}

void DrawingSolutions::clear_shapes() {
    shapes.clear();
}

size_t DrawingSolutions::get_shape_count() const {
    return shapes.size();
}

// Drawing operations
void DrawingSolutions::draw_all() const {
    for (const auto& shape : shapes) {
        shape->draw();
    }
}

void DrawingSolutions::display_all_info() const {
    for (const auto& shape : shapes) {
        shape->display_info();
        std::cout << std::endl;
    }
}

std::vector<double> DrawingSolutions::calculate_all_areas() const {
    std::vector<double> areas;
    for (const auto& shape : shapes) {
        areas.push_back(shape->area());
    }
    return areas;
}

std::vector<double> DrawingSolutions::calculate_all_perimeters() const {
    std::vector<double> perimeters;
    for (const auto& shape : shapes) {
        perimeters.push_back(shape->perimeter());
    }
    return perimeters;
}

double DrawingSolutions::total_area() const {
    double total = 0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

double DrawingSolutions::total_perimeter() const {
    double total = 0;
    for (const auto& shape : shapes) {
        total += shape->perimeter();
    }
    return total;
}

// Accessors
ShapeSolutions* DrawingSolutions::get_shape(size_t index) {
    if (index < shapes.size()) {
        return shapes[index].get();
    }
    return nullptr;
}

const ShapeSolutions* DrawingSolutions::get_shape(size_t index) const {
    if (index < shapes.size()) {
        return shapes[index].get();
    }
    return nullptr;
}

// ========== CLONEABLERECTANGLE CLASS SOLUTIONS ==========

// Constructors
CloneableRectangleSolutions::CloneableRectangleSolutions() : RectangleSolutions() {
    // Call base constructor
}

CloneableRectangleSolutions::CloneableRectangleSolutions(double w, double h) : RectangleSolutions(w, h) {
    // Call base constructor
}

CloneableRectangleSolutions::CloneableRectangleSolutions(const std::string& name, double w, double h) : RectangleSolutions(name, w, h) {
    // Call base constructor
}

// Cloneable interface
std::unique_ptr<CloneableSolutions> CloneableRectangleSolutions::clone() const {
    return std::make_unique<CloneableRectangleSolutions>(name, width, height);
}

// Virtual methods
void CloneableRectangleSolutions::draw() const {
    std::cout << "Drawing a Cloneable " << get_name() << " with width " 
              << get_width() << " and height " << get_height() << std::endl;
}

} // namespace cpp_primer