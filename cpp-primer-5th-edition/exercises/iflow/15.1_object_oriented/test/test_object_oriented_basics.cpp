#include <gtest/gtest.h>
#include "object_oriented_exercises.h"
#include "object_oriented_solutions.h"

namespace cpp_primer {

// Test fixture for ObjectOriented exercises
class ObjectOrientedBasicsTest : public ::testing::Test {
protected:
    Shape* exercises_shape;
    ShapeSolutions* solutions_shape;
};

// Test Shape base class
TEST_F(ObjectOrientedBasicsTest, TestShapeBaseClass) {
    // Test Rectangle
    Rectangle ex_rect(5.0, 3.0);
    RectangleSolutions sol_rect(5.0, 3.0);
    
    EXPECT_EQ(ex_rect.get_name(), "Rectangle");
    EXPECT_EQ(sol_rect.get_name(), "Rectangle");
    
    EXPECT_EQ(ex_rect.get_width(), 5.0);
    EXPECT_EQ(sol_rect.get_width(), 5.0);
    
    EXPECT_EQ(ex_rect.get_height(), 3.0);
    EXPECT_EQ(sol_rect.get_height(), 3.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.area(), 15.0);
    EXPECT_DOUBLE_EQ(sol_rect.area(), 15.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.perimeter(), 16.0);
    EXPECT_DOUBLE_EQ(sol_rect.perimeter(), 16.0);
    
    // Test Circle
    Circle ex_circle(4.0);
    CircleSolutions sol_circle(4.0);
    
    EXPECT_EQ(ex_circle.get_name(), "Circle");
    EXPECT_EQ(sol_circle.get_name(), "Circle");
    
    EXPECT_DOUBLE_EQ(ex_circle.get_radius(), 4.0);
    EXPECT_DOUBLE_EQ(sol_circle.get_radius(), 4.0);
    
    // Area = π * r^2 = π * 16
    EXPECT_NEAR(ex_circle.area(), 3.14159265358979323846 * 16, 1e-9);
    EXPECT_NEAR(sol_circle.area(), 3.14159265358979323846 * 16, 1e-9);
    
    // Perimeter = 2 * π * r = 2 * π * 4
    EXPECT_NEAR(ex_circle.perimeter(), 2 * 3.14159265358979323846 * 4, 1e-9);
    EXPECT_NEAR(sol_circle.perimeter(), 2 * 3.14159265358979323846 * 4, 1e-9);
    
    // Test Triangle
    Triangle ex_triangle(6.0, 4.0, 3.0, 4.0, 5.0);
    TriangleSolutions sol_triangle(6.0, 4.0, 3.0, 4.0, 5.0);
    
    EXPECT_EQ(ex_triangle.get_name(), "Triangle");
    EXPECT_EQ(sol_triangle.get_name(), "Triangle");
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_base(), 6.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_base(), 6.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_height(), 4.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_height(), 4.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_side1(), 3.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_side1(), 3.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_side2(), 4.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_side2(), 4.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_side3(), 5.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_side3(), 5.0);
    
    // Area = 0.5 * base * height = 0.5 * 6 * 4 = 12
    EXPECT_DOUBLE_EQ(ex_triangle.area(), 12.0);
    EXPECT_DOUBLE_EQ(sol_triangle.area(), 12.0);
    
    // Perimeter = side1 + side2 + side3 = 3 + 4 + 5 = 12
    EXPECT_DOUBLE_EQ(ex_triangle.perimeter(), 12.0);
    EXPECT_DOUBLE_EQ(sol_triangle.perimeter(), 12.0);
}

// Test polymorphism with Shape pointers
TEST_F(ObjectOrientedBasicsTest, TestShapePolymorphism) {
    // Create shapes using base class pointers
    std::unique_ptr<Shape> ex_rect = std::make_unique<Rectangle>(3.0, 4.0);
    std::unique_ptr<Shape> ex_circle = std::make_unique<Circle>(5.0);
    std::unique_ptr<Shape> ex_triangle = std::make_unique<Triangle>(6.0, 8.0, 6.0, 8.0, 10.0);
    
    std::unique_ptr<ShapeSolutions> sol_rect = std::make_unique<RectangleSolutions>(3.0, 4.0);
    std::unique_ptr<ShapeSolutions> sol_circle = std::make_unique<CircleSolutions>(5.0);
    std::unique_ptr<ShapeSolutions> sol_triangle = std::make_unique<TriangleSolutions>(6.0, 8.0, 6.0, 8.0, 10.0);
    
    // Test rectangle polymorphism
    EXPECT_DOUBLE_EQ(ex_rect->area(), 12.0);
    EXPECT_DOUBLE_EQ(sol_rect->area(), 12.0);
    
    EXPECT_DOUBLE_EQ(ex_rect->perimeter(), 14.0);
    EXPECT_DOUBLE_EQ(sol_rect->perimeter(), 14.0);
    
    // Test circle polymorphism
    EXPECT_NEAR(ex_circle->area(), 3.14159265358979323846 * 25, 1e-9);
    EXPECT_NEAR(sol_circle->area(), 3.14159265358979323846 * 25, 1e-9);
    
    EXPECT_NEAR(ex_circle->perimeter(), 2 * 3.14159265358979323846 * 5, 1e-9);
    EXPECT_NEAR(sol_circle->perimeter(), 2 * 3.14159265358979323846 * 5, 1e-9);
    
    // Test triangle polymorphism
    EXPECT_DOUBLE_EQ(ex_triangle->area(), 24.0);
    EXPECT_DOUBLE_EQ(sol_triangle->area(), 24.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle->perimeter(), 24.0);
    EXPECT_DOUBLE_EQ(sol_triangle->perimeter(), 24.0);
}

// Test shape modifiers
TEST_F(ObjectOrientedBasicsTest, TestShapeModifiers) {
    Rectangle ex_rect;
    RectangleSolutions sol_rect;
    
    ex_rect.set_dimensions(7.0, 2.0);
    sol_rect.set_dimensions(7.0, 2.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.area(), 14.0);
    EXPECT_DOUBLE_EQ(sol_rect.area(), 14.0);
    
    Circle ex_circle;
    CircleSolutions sol_circle;
    
    ex_circle.set_radius(3.0);
    sol_circle.set_radius(3.0);
    
    EXPECT_NEAR(ex_circle.area(), 3.14159265358979323846 * 9, 1e-9);
    EXPECT_NEAR(sol_circle.area(), 3.14159265358979323846 * 9, 1e-9);
    
    Triangle ex_triangle;
    TriangleSolutions sol_triangle;
    
    ex_triangle.set_base(5.0);
    ex_triangle.set_height(4.0);
    ex_triangle.set_sides(3.0, 4.0, 5.0);
    
    sol_triangle.set_base(5.0);
    sol_triangle.set_height(4.0);
    sol_triangle.set_sides(3.0, 4.0, 5.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.area(), 10.0);
    EXPECT_DOUBLE_EQ(sol_triangle.area(), 10.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.perimeter(), 12.0);
    EXPECT_DOUBLE_EQ(sol_triangle.perimeter(), 12.0);
}

// Test Drawing class basic functionality
TEST_F(ObjectOrientedBasicsTest, TestDrawingBasics) {
    Drawing ex_drawing;
    DrawingSolutions sol_drawing;
    
    EXPECT_EQ(ex_drawing.get_shape_count(), 0);
    EXPECT_EQ(sol_drawing.get_shape_count(), 0);
    
    // Add shapes
    ex_drawing.add_shape(std::make_unique<Rectangle>(2.0, 3.0));
    ex_drawing.add_shape(std::make_unique<Circle>(4.0));
    ex_drawing.add_shape(std::make_unique<Triangle>(5.0, 6.0, 5.0, 5.0, 6.0));
    
    sol_drawing.add_shape(std::make_unique<RectangleSolutions>(2.0, 3.0));
    sol_drawing.add_shape(std::make_unique<CircleSolutions>(4.0));
    sol_drawing.add_shape(std::make_unique<TriangleSolutions>(5.0, 6.0, 5.0, 5.0, 6.0));
    
    EXPECT_EQ(ex_drawing.get_shape_count(), 3);
    EXPECT_EQ(sol_drawing.get_shape_count(), 3);
    
    // Test accessors
    Shape* ex_shape = ex_drawing.get_shape(0);
    ShapeSolutions* sol_shape = sol_drawing.get_shape(0);
    
    EXPECT_NE(ex_shape, nullptr);
    EXPECT_NE(sol_shape, nullptr);
    
    // Test calculations
    std::vector<double> ex_areas = ex_drawing.calculate_all_areas();
    std::vector<double> sol_areas = sol_drawing.calculate_all_areas();
    
    EXPECT_EQ(ex_areas.size(), 3);
    EXPECT_EQ(sol_areas.size(), 3);
    
    // Rectangle area = 2 * 3 = 6
    EXPECT_DOUBLE_EQ(ex_areas[0], 6.0);
    EXPECT_DOUBLE_EQ(sol_areas[0], 6.0);
    
    // Circle area = π * 16
    EXPECT_NEAR(ex_areas[1], 3.14159265358979323846 * 16, 1e-9);
    EXPECT_NEAR(sol_areas[1], 3.14159265358979323846 * 16, 1e-9);
    
    // Triangle area = 0.5 * 5 * 6 = 15
    EXPECT_DOUBLE_EQ(ex_areas[2], 15.0);
    EXPECT_DOUBLE_EQ(sol_areas[2], 15.0);
}

// Test CloneableRectangle
TEST_F(ObjectOrientedBasicsTest, TestCloneableRectangle) {
    CloneableRectangle ex_cloneable("CloneableRect", 4.0, 5.0);
    CloneableRectangleSolutions sol_cloneable("CloneableRect", 4.0, 5.0);
    
    EXPECT_EQ(ex_cloneable.get_name(), "CloneableRect");
    EXPECT_EQ(sol_cloneable.get_name(), "CloneableRect");
    
    EXPECT_DOUBLE_EQ(ex_cloneable.get_width(), 4.0);
    EXPECT_DOUBLE_EQ(sol_cloneable.get_width(), 4.0);
    
    EXPECT_DOUBLE_EQ(ex_cloneable.get_height(), 5.0);
    EXPECT_DOUBLE_EQ(sol_cloneable.get_height(), 5.0);
    
    EXPECT_DOUBLE_EQ(ex_cloneable.area(), 20.0);
    EXPECT_DOUBLE_EQ(sol_cloneable.area(), 20.0);
    
    EXPECT_DOUBLE_EQ(ex_cloneable.perimeter(), 18.0);
    EXPECT_DOUBLE_EQ(sol_cloneable.perimeter(), 18.0);
    
    // Test clone functionality
    std::unique_ptr<Cloneable> ex_clone = ex_cloneable.clone();
    std::unique_ptr<CloneableSolutions> sol_clone = sol_cloneable.clone();
    
    EXPECT_NE(ex_clone, nullptr);
    EXPECT_NE(sol_clone, nullptr);
    
    // Cast to CloneableRectangle to test values
    CloneableRectangle* ex_cloned_rect = dynamic_cast<CloneableRectangle*>(ex_clone.get());
    CloneableRectangleSolutions* sol_cloned_rect = dynamic_cast<CloneableRectangleSolutions*>(sol_clone.get());
    
    EXPECT_NE(ex_cloned_rect, nullptr);
    EXPECT_NE(sol_cloned_rect, nullptr);
    
    if (ex_cloned_rect && sol_cloned_rect) {
        EXPECT_EQ(ex_cloned_rect->get_name(), "CloneableRect");
        EXPECT_EQ(sol_cloned_rect->get_name(), "CloneableRect");
        
        EXPECT_DOUBLE_EQ(ex_cloned_rect->get_width(), 4.0);
        EXPECT_DOUBLE_EQ(sol_cloned_rect->get_width(), 4.0);
        
        EXPECT_DOUBLE_EQ(ex_cloned_rect->get_height(), 5.0);
        EXPECT_DOUBLE_EQ(sol_cloned_rect->get_height(), 5.0);
    }
}

} // namespace cpp_primer