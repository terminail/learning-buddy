#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <sstream>
#include "object_oriented_exercises.h"
#include "object_oriented_solutions.h"

namespace cpp_primer {

// Test fixture for ObjectOriented practice exercises
class ObjectOrientedPracticeTest : public ::testing::Test {
protected:
    // No specific setup needed for this test fixture
};

// Test comprehensive shape functionality
TEST_F(ObjectOrientedPracticeTest, TestComprehensiveShapeFunctionality) {
    // Test rectangle with various operations
    Rectangle ex_rect("MyRectangle", 6.0, 8.0);
    RectangleSolutions sol_rect("MyRectangle", 6.0, 8.0);
    
    // Test initial values
    EXPECT_EQ(ex_rect.get_name(), "MyRectangle");
    EXPECT_EQ(sol_rect.get_name(), "MyRectangle");
    
    EXPECT_DOUBLE_EQ(ex_rect.get_width(), 6.0);
    EXPECT_DOUBLE_EQ(sol_rect.get_width(), 6.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.get_height(), 8.0);
    EXPECT_DOUBLE_EQ(sol_rect.get_height(), 8.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.area(), 48.0);
    EXPECT_DOUBLE_EQ(sol_rect.area(), 48.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.perimeter(), 28.0);
    EXPECT_DOUBLE_EQ(sol_rect.perimeter(), 28.0);
    
    // Test modifying dimensions
    ex_rect.set_width(10.0);
    sol_rect.set_width(10.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.area(), 80.0);
    EXPECT_DOUBLE_EQ(sol_rect.area(), 80.0);
    
    ex_rect.set_height(5.0);
    sol_rect.set_height(5.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.area(), 50.0);
    EXPECT_DOUBLE_EQ(sol_rect.area(), 50.0);
    
    EXPECT_DOUBLE_EQ(ex_rect.perimeter(), 30.0);
    EXPECT_DOUBLE_EQ(sol_rect.perimeter(), 30.0);
    
    // Test circle with various operations
    Circle ex_circle("MyCircle", 7.0);
    CircleSolutions sol_circle("MyCircle", 7.0);
    
    EXPECT_EQ(ex_circle.get_name(), "MyCircle");
    EXPECT_EQ(sol_circle.get_name(), "MyCircle");
    
    EXPECT_DOUBLE_EQ(ex_circle.get_radius(), 7.0);
    EXPECT_DOUBLE_EQ(sol_circle.get_radius(), 7.0);
    
    // Area = π * r^2 = π * 49
    EXPECT_NEAR(ex_circle.area(), 3.14159265358979323846 * 49, 1e-9);
    EXPECT_NEAR(sol_circle.area(), 3.14159265358979323846 * 49, 1e-9);
    
    // Perimeter = 2 * π * r = 2 * π * 7
    EXPECT_NEAR(ex_circle.perimeter(), 2 * 3.14159265358979323846 * 7, 1e-9);
    EXPECT_NEAR(sol_circle.perimeter(), 2 * 3.14159265358979323846 * 7, 1e-9);
    
    // Test modifying radius
    ex_circle.set_radius(3.0);
    sol_circle.set_radius(3.0);
    
    // Area = π * r^2 = π * 9
    EXPECT_NEAR(ex_circle.area(), 3.14159265358979323846 * 9, 1e-9);
    EXPECT_NEAR(sol_circle.area(), 3.14159265358979323846 * 9, 1e-9);
    
    // Perimeter = 2 * π * r = 2 * π * 3
    EXPECT_NEAR(ex_circle.perimeter(), 2 * 3.14159265358979323846 * 3, 1e-9);
    EXPECT_NEAR(sol_circle.perimeter(), 2 * 3.14159265358979323846 * 3, 1e-9);
    
    // Test triangle with various operations
    Triangle ex_triangle("MyTriangle", 10.0, 12.0, 10.0, 12.0, 15.0);
    TriangleSolutions sol_triangle("MyTriangle", 10.0, 12.0, 10.0, 12.0, 15.0);
    
    EXPECT_EQ(ex_triangle.get_name(), "MyTriangle");
    EXPECT_EQ(sol_triangle.get_name(), "MyTriangle");
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_base(), 10.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_base(), 10.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_height(), 12.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_height(), 12.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_side1(), 10.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_side1(), 10.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_side2(), 12.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_side2(), 12.0);
    
    EXPECT_DOUBLE_EQ(ex_triangle.get_side3(), 15.0);
    EXPECT_DOUBLE_EQ(sol_triangle.get_side3(), 15.0);
    
    // Area = 0.5 * base * height = 0.5 * 10 * 12 = 60
    EXPECT_DOUBLE_EQ(ex_triangle.area(), 60.0);
    EXPECT_DOUBLE_EQ(sol_triangle.area(), 60.0);
    
    // Perimeter = side1 + side2 + side3 = 10 + 12 + 15 = 37
    EXPECT_DOUBLE_EQ(ex_triangle.perimeter(), 37.0);
    EXPECT_DOUBLE_EQ(sol_triangle.perimeter(), 37.0);
    
    // Test modifying triangle dimensions
    ex_triangle.set_base(8.0);
    ex_triangle.set_height(6.0);
    ex_triangle.set_sides(5.0, 5.0, 8.0);
    
    sol_triangle.set_base(8.0);
    sol_triangle.set_height(6.0);
    sol_triangle.set_sides(5.0, 5.0, 8.0);
    
    // Area = 0.5 * base * height = 0.5 * 8 * 6 = 24
    EXPECT_DOUBLE_EQ(ex_triangle.area(), 24.0);
    EXPECT_DOUBLE_EQ(sol_triangle.area(), 24.0);
    
    // Perimeter = side1 + side2 + side3 = 5 + 5 + 8 = 18
    EXPECT_DOUBLE_EQ(ex_triangle.perimeter(), 18.0);
    EXPECT_DOUBLE_EQ(sol_triangle.perimeter(), 18.0);
}

// Test Drawing class comprehensive functionality
TEST_F(ObjectOrientedPracticeTest, TestDrawingComprehensiveFunctionality) {
    Drawing ex_drawing;
    DrawingSolutions sol_drawing;
    
    // Test adding various shapes
    ex_drawing.add_shape(std::make_unique<Rectangle>("Rect1", 3.0, 4.0));
    ex_drawing.add_shape(std::make_unique<Circle>("Circle1", 2.0));
    ex_drawing.add_shape(std::make_unique<Triangle>("Triangle1", 6.0, 8.0, 6.0, 8.0, 10.0));
    
    sol_drawing.add_shape(std::make_unique<RectangleSolutions>("Rect1", 3.0, 4.0));
    sol_drawing.add_shape(std::make_unique<CircleSolutions>("Circle1", 2.0));
    sol_drawing.add_shape(std::make_unique<TriangleSolutions>("Triangle1", 6.0, 8.0, 6.0, 8.0, 10.0));
    
    EXPECT_EQ(ex_drawing.get_shape_count(), 3);
    EXPECT_EQ(sol_drawing.get_shape_count(), 3);
    
    // Test accessing shapes
    Shape* ex_shape0 = ex_drawing.get_shape(0);
    Shape* ex_shape1 = ex_drawing.get_shape(1);
    Shape* ex_shape2 = ex_drawing.get_shape(2);
    
    ShapeSolutions* sol_shape0 = sol_drawing.get_shape(0);
    ShapeSolutions* sol_shape1 = sol_drawing.get_shape(1);
    ShapeSolutions* sol_shape2 = sol_drawing.get_shape(2);
    
    EXPECT_NE(ex_shape0, nullptr);
    EXPECT_NE(ex_shape1, nullptr);
    EXPECT_NE(ex_shape2, nullptr);
    
    EXPECT_NE(sol_shape0, nullptr);
    EXPECT_NE(sol_shape1, nullptr);
    EXPECT_NE(sol_shape2, nullptr);
    
    // Test shape names
    EXPECT_EQ(ex_shape0->get_name(), "Rect1");
    EXPECT_EQ(ex_shape1->get_name(), "Circle1");
    EXPECT_EQ(ex_shape2->get_name(), "Triangle1");
    
    EXPECT_EQ(sol_shape0->get_name(), "Rect1");
    EXPECT_EQ(sol_shape1->get_name(), "Circle1");
    EXPECT_EQ(sol_shape2->get_name(), "Triangle1");
    
    // Test area calculations
    std::vector<double> ex_areas = ex_drawing.calculate_all_areas();
    std::vector<double> sol_areas = sol_drawing.calculate_all_areas();
    
    EXPECT_EQ(ex_areas.size(), 3);
    EXPECT_EQ(sol_areas.size(), 3);
    
    // Rectangle area = 3 * 4 = 12
    EXPECT_DOUBLE_EQ(ex_areas[0], 12.0);
    EXPECT_DOUBLE_EQ(sol_areas[0], 12.0);
    
    // Circle area = π * 4
    EXPECT_NEAR(ex_areas[1], 3.14159265358979323846 * 4, 1e-9);
    EXPECT_NEAR(sol_areas[1], 3.14159265358979323846 * 4, 1e-9);
    
    // Triangle area = 0.5 * 6 * 8 = 24
    EXPECT_DOUBLE_EQ(ex_areas[2], 24.0);
    EXPECT_DOUBLE_EQ(sol_areas[2], 24.0);
    
    // Test perimeter calculations
    std::vector<double> ex_perimeters = ex_drawing.calculate_all_perimeters();
    std::vector<double> sol_perimeters = sol_drawing.calculate_all_perimeters();
    
    EXPECT_EQ(ex_perimeters.size(), 3);
    EXPECT_EQ(sol_perimeters.size(), 3);
    
    // Rectangle perimeter = 2 * (3 + 4) = 14
    EXPECT_DOUBLE_EQ(ex_perimeters[0], 14.0);
    EXPECT_DOUBLE_EQ(sol_perimeters[0], 14.0);
    
    // Circle perimeter = 2 * π * 2 = 4 * π
    EXPECT_NEAR(ex_perimeters[1], 4 * 3.14159265358979323846, 1e-9);
    EXPECT_NEAR(sol_perimeters[1], 4 * 3.14159265358979323846, 1e-9);
    
    // Triangle perimeter = 6 + 8 + 10 = 24
    EXPECT_DOUBLE_EQ(ex_perimeters[2], 24.0);
    EXPECT_DOUBLE_EQ(sol_perimeters[2], 24.0);
    
    // Test total calculations
    EXPECT_DOUBLE_EQ(ex_drawing.total_area(), 12.0 + 3.14159265358979323846 * 4 + 24.0);
    EXPECT_DOUBLE_EQ(sol_drawing.total_area(), 12.0 + 3.14159265358979323846 * 4 + 24.0);
    
    EXPECT_DOUBLE_EQ(ex_drawing.total_perimeter(), 14.0 + 4 * 3.14159265358979323846 + 24.0);
    EXPECT_DOUBLE_EQ(sol_drawing.total_perimeter(), 14.0 + 4 * 3.14159265358979323846 + 24.0);
    
    // Test removing shapes
    ex_drawing.remove_shape(1);  // Remove circle
    sol_drawing.remove_shape(1);  // Remove circle
    
    EXPECT_EQ(ex_drawing.get_shape_count(), 2);
    EXPECT_EQ(sol_drawing.get_shape_count(), 2);
    
    // Test that remaining shapes are correct
    Shape* ex_remaining0 = ex_drawing.get_shape(0);
    Shape* ex_remaining1 = ex_drawing.get_shape(1);
    
    ShapeSolutions* sol_remaining0 = sol_drawing.get_shape(0);
    ShapeSolutions* sol_remaining1 = sol_drawing.get_shape(1);
    
    EXPECT_EQ(ex_remaining0->get_name(), "Rect1");
    EXPECT_EQ(ex_remaining1->get_name(), "Triangle1");
    
    EXPECT_EQ(sol_remaining0->get_name(), "Rect1");
    EXPECT_EQ(sol_remaining1->get_name(), "Triangle1");
    
    // Test clearing all shapes
    ex_drawing.clear_shapes();
    sol_drawing.clear_shapes();
    
    EXPECT_EQ(ex_drawing.get_shape_count(), 0);
    EXPECT_EQ(sol_drawing.get_shape_count(), 0);
    
    // Test accessing shape at invalid index
    EXPECT_EQ(ex_drawing.get_shape(0), nullptr);
    EXPECT_EQ(sol_drawing.get_shape(0), nullptr);
}

// Test polymorphism with complex scenarios
TEST_F(ObjectOrientedPracticeTest, TestPolymorphismComplexScenarios) {
    // Create a vector of shape pointers to test polymorphism
    std::vector<std::unique_ptr<Shape>> ex_shapes;
    std::vector<std::unique_ptr<ShapeSolutions>> sol_shapes;
    
    // Add various shapes
    ex_shapes.push_back(std::make_unique<Rectangle>("PolyRect", 5.0, 3.0));
    ex_shapes.push_back(std::make_unique<Circle>("PolyCircle", 4.0));
    ex_shapes.push_back(std::make_unique<Triangle>("PolyTriangle", 8.0, 6.0, 6.0, 8.0, 10.0));
    
    sol_shapes.push_back(std::make_unique<RectangleSolutions>("PolyRect", 5.0, 3.0));
    sol_shapes.push_back(std::make_unique<CircleSolutions>("PolyCircle", 4.0));
    sol_shapes.push_back(std::make_unique<TriangleSolutions>("PolyTriangle", 8.0, 6.0, 6.0, 8.0, 10.0));
    
    // Test that all shapes can be treated polymorphically
    std::vector<double> ex_areas, sol_areas;
    std::vector<double> ex_perimeters, sol_perimeters;
    
    for (size_t i = 0; i < ex_shapes.size(); ++i) {
        ex_areas.push_back(ex_shapes[i]->area());
        ex_perimeters.push_back(ex_shapes[i]->perimeter());
        
        sol_areas.push_back(sol_shapes[i]->area());
        sol_perimeters.push_back(sol_shapes[i]->perimeter());
    }
    
    // Verify results
    EXPECT_EQ(ex_areas.size(), 3);
    EXPECT_EQ(sol_areas.size(), 3);
    
    EXPECT_EQ(ex_perimeters.size(), 3);
    EXPECT_EQ(sol_perimeters.size(), 3);
    
    // Rectangle: area = 15, perimeter = 16
    EXPECT_DOUBLE_EQ(ex_areas[0], 15.0);
    EXPECT_DOUBLE_EQ(sol_areas[0], 15.0);
    
    EXPECT_DOUBLE_EQ(ex_perimeters[0], 16.0);
    EXPECT_DOUBLE_EQ(sol_perimeters[0], 16.0);
    
    // Circle: area = π * 16, perimeter = 2 * π * 4
    EXPECT_NEAR(ex_areas[1], 3.14159265358979323846 * 16, 1e-9);
    EXPECT_NEAR(sol_areas[1], 3.14159265358979323846 * 16, 1e-9);
    
    EXPECT_NEAR(ex_perimeters[1], 2 * 3.14159265358979323846 * 4, 1e-9);
    EXPECT_NEAR(sol_perimeters[1], 2 * 3.14159265358979323846 * 4, 1e-9);
    
    // Triangle: area = 24, perimeter = 24
    EXPECT_DOUBLE_EQ(ex_areas[2], 24.0);
    EXPECT_DOUBLE_EQ(sol_areas[2], 24.0);
    
    EXPECT_DOUBLE_EQ(ex_perimeters[2], 24.0);
    EXPECT_DOUBLE_EQ(sol_perimeters[2], 24.0);
}

// Test CloneableRectangle comprehensive functionality
TEST_F(ObjectOrientedPracticeTest, TestCloneableRectangleComprehensive) {
    // Test default constructor
    CloneableRectangle ex_default;
    CloneableRectangleSolutions sol_default;
    
    EXPECT_EQ(ex_default.get_name(), "Rectangle");
    EXPECT_EQ(sol_default.get_name(), "Rectangle");
    
    EXPECT_DOUBLE_EQ(ex_default.get_width(), 0.0);
    EXPECT_DOUBLE_EQ(sol_default.get_width(), 0.0);
    
    EXPECT_DOUBLE_EQ(ex_default.get_height(), 0.0);
    EXPECT_DOUBLE_EQ(sol_default.get_height(), 0.0);
    
    // Test constructor with dimensions
    CloneableRectangle ex_with_dims(7.0, 9.0);
    CloneableRectangleSolutions sol_with_dims(7.0, 9.0);
    
    EXPECT_EQ(ex_with_dims.get_name(), "Rectangle");
    EXPECT_EQ(sol_with_dims.get_name(), "Rectangle");
    
    EXPECT_DOUBLE_EQ(ex_with_dims.get_width(), 7.0);
    EXPECT_DOUBLE_EQ(sol_with_dims.get_width(), 7.0);
    
    EXPECT_DOUBLE_EQ(ex_with_dims.get_height(), 9.0);
    EXPECT_DOUBLE_EQ(sol_with_dims.get_height(), 9.0);
    
    EXPECT_DOUBLE_EQ(ex_with_dims.area(), 63.0);
    EXPECT_DOUBLE_EQ(sol_with_dims.area(), 63.0);
    
    EXPECT_DOUBLE_EQ(ex_with_dims.perimeter(), 32.0);
    EXPECT_DOUBLE_EQ(sol_with_dims.perimeter(), 32.0);
    
    // Test constructor with name and dimensions
    CloneableRectangle ex_with_name("CustomRect", 4.0, 6.0);
    CloneableRectangleSolutions sol_with_name("CustomRect", 4.0, 6.0);
    
    EXPECT_EQ(ex_with_name.get_name(), "CustomRect");
    EXPECT_EQ(sol_with_name.get_name(), "CustomRect");
    
    EXPECT_DOUBLE_EQ(ex_with_name.get_width(), 4.0);
    EXPECT_DOUBLE_EQ(sol_with_name.get_width(), 4.0);
    
    EXPECT_DOUBLE_EQ(ex_with_name.get_height(), 6.0);
    EXPECT_DOUBLE_EQ(sol_with_name.get_height(), 6.0);
    
    EXPECT_DOUBLE_EQ(ex_with_name.area(), 24.0);
    EXPECT_DOUBLE_EQ(sol_with_name.area(), 24.0);
    
    EXPECT_DOUBLE_EQ(ex_with_name.perimeter(), 20.0);
    EXPECT_DOUBLE_EQ(sol_with_name.perimeter(), 20.0);
    
    // Test clone functionality with different types
    std::unique_ptr<Cloneable> ex_clone1 = ex_with_name.clone();
    std::unique_ptr<CloneableSolutions> sol_clone1 = sol_with_name.clone();
    
    EXPECT_NE(ex_clone1, nullptr);
    EXPECT_NE(sol_clone1, nullptr);
    
    // Cast to CloneableRectangle to test values
    CloneableRectangle* ex_cloned_rect1 = dynamic_cast<CloneableRectangle*>(ex_clone1.get());
    CloneableRectangleSolutions* sol_cloned_rect1 = dynamic_cast<CloneableRectangleSolutions*>(sol_clone1.get());
    
    EXPECT_NE(ex_cloned_rect1, nullptr);
    EXPECT_NE(sol_cloned_rect1, nullptr);
    
    if (ex_cloned_rect1 && sol_cloned_rect1) {
        EXPECT_EQ(ex_cloned_rect1->get_name(), "CustomRect");
        EXPECT_EQ(sol_cloned_rect1->get_name(), "CustomRect");
        
        EXPECT_DOUBLE_EQ(ex_cloned_rect1->get_width(), 4.0);
        EXPECT_DOUBLE_EQ(sol_cloned_rect1->get_width(), 4.0);
        
        EXPECT_DOUBLE_EQ(ex_cloned_rect1->get_height(), 6.0);
        EXPECT_DOUBLE_EQ(sol_cloned_rect1->get_height(), 6.0);
        
        EXPECT_DOUBLE_EQ(ex_cloned_rect1->area(), 24.0);
        EXPECT_DOUBLE_EQ(sol_cloned_rect1->area(), 24.0);
    }
    
    // Test modifying cloned object doesn't affect original
    if (ex_cloned_rect1 && sol_cloned_rect1) {
        ex_cloned_rect1->set_width(10.0);
        sol_cloned_rect1->set_width(10.0);
        
        // Original should be unchanged
        EXPECT_DOUBLE_EQ(ex_with_name.get_width(), 4.0);
        EXPECT_DOUBLE_EQ(sol_with_name.get_width(), 4.0);
        
        // Clone should be changed
        EXPECT_DOUBLE_EQ(ex_cloned_rect1->get_width(), 10.0);
        EXPECT_DOUBLE_EQ(sol_cloned_rect1->get_width(), 10.0);
    }
    
    // Test multiple clones
    std::unique_ptr<Cloneable> ex_clone2 = ex_with_name.clone();
    std::unique_ptr<CloneableSolutions> sol_clone2 = sol_with_name.clone();
    
    CloneableRectangle* ex_cloned_rect2 = dynamic_cast<CloneableRectangle*>(ex_clone2.get());
    CloneableRectangleSolutions* sol_cloned_rect2 = dynamic_cast<CloneableRectangleSolutions*>(sol_clone2.get());
    
    EXPECT_NE(ex_cloned_rect2, nullptr);
    EXPECT_NE(sol_cloned_rect2, nullptr);
    
    if (ex_cloned_rect2 && sol_cloned_rect2) {
        // Both should have the same values as the original
        EXPECT_EQ(ex_cloned_rect2->get_name(), "CustomRect");
        EXPECT_EQ(sol_cloned_rect2->get_name(), "CustomRect");
        
        EXPECT_DOUBLE_EQ(ex_cloned_rect2->get_width(), 4.0);
        EXPECT_DOUBLE_EQ(sol_cloned_rect2->get_width(), 4.0);
        
        EXPECT_DOUBLE_EQ(ex_cloned_rect2->get_height(), 6.0);
        EXPECT_DOUBLE_EQ(sol_cloned_rect2->get_height(), 6.0);
    }
}

// Test complex scenario combining multiple OOP concepts
TEST_F(ObjectOrientedPracticeTest, TestComplexOOPScenario) {
    // Create a drawing with various shapes including CloneableRectangle
    Drawing ex_drawing;
    DrawingSolutions sol_drawing;
    
    // Add regular shapes
    ex_drawing.add_shape(std::make_unique<Rectangle>("StandardRect", 3.0, 4.0));
    ex_drawing.add_shape(std::make_unique<Circle>("StandardCircle", 5.0));
    
    sol_drawing.add_shape(std::make_unique<RectangleSolutions>("StandardRect", 3.0, 4.0));
    sol_drawing.add_shape(std::make_unique<CircleSolutions>("StandardCircle", 5.0));
    
    // Add CloneableRectangle
    ex_drawing.add_shape(std::make_unique<CloneableRectangle>("CloneableRect", 6.0, 8.0));
    sol_drawing.add_shape(std::make_unique<CloneableRectangleSolutions>("CloneableRect", 6.0, 8.0));
    
    // Add another triangle
    ex_drawing.add_shape(std::make_unique<Triangle>("StandardTriangle", 10.0, 12.0, 10.0, 12.0, 15.0));
    sol_drawing.add_shape(std::make_unique<TriangleSolutions>("StandardTriangle", 10.0, 12.0, 10.0, 12.0, 15.0));
    
    // Verify all shapes were added
    EXPECT_EQ(ex_drawing.get_shape_count(), 4);
    EXPECT_EQ(sol_drawing.get_shape_count(), 4);
    
    // Test that all shapes can be accessed
    for (size_t i = 0; i < ex_drawing.get_shape_count(); ++i) {
        Shape* ex_shape = ex_drawing.get_shape(i);
        ShapeSolutions* sol_shape = sol_drawing.get_shape(i);
        
        EXPECT_NE(ex_shape, nullptr);
        EXPECT_NE(sol_shape, nullptr);
        
        // Verify names
        if (i == 0) {
            EXPECT_EQ(ex_shape->get_name(), "StandardRect");
            EXPECT_EQ(sol_shape->get_name(), "StandardRect");
        } else if (i == 1) {
            EXPECT_EQ(ex_shape->get_name(), "StandardCircle");
            EXPECT_EQ(sol_shape->get_name(), "StandardCircle");
        } else if (i == 2) {
            EXPECT_EQ(ex_shape->get_name(), "CloneableRect");
            EXPECT_EQ(sol_shape->get_name(), "CloneableRect");
        } else if (i == 3) {
            EXPECT_EQ(ex_shape->get_name(), "StandardTriangle");
            EXPECT_EQ(sol_shape->get_name(), "StandardTriangle");
        }
    }
    
    // Test area calculations for all shapes
    std::vector<double> ex_areas = ex_drawing.calculate_all_areas();
    std::vector<double> sol_areas = sol_drawing.calculate_all_areas();
    
    EXPECT_EQ(ex_areas.size(), 4);
    EXPECT_EQ(sol_areas.size(), 4);
    
    // StandardRect: 3 * 4 = 12
    EXPECT_DOUBLE_EQ(ex_areas[0], 12.0);
    EXPECT_DOUBLE_EQ(sol_areas[0], 12.0);
    
    // StandardCircle: π * 25
    EXPECT_NEAR(ex_areas[1], 3.14159265358979323846 * 25, 1e-9);
    EXPECT_NEAR(sol_areas[1], 3.14159265358979323846 * 25, 1e-9);
    
    // CloneableRect: 6 * 8 = 48
    EXPECT_DOUBLE_EQ(ex_areas[2], 48.0);
    EXPECT_DOUBLE_EQ(sol_areas[2], 48.0);
    
    // StandardTriangle: 0.5 * 10 * 12 = 60
    EXPECT_DOUBLE_EQ(ex_areas[3], 60.0);
    EXPECT_DOUBLE_EQ(sol_areas[3], 60.0);
    
    // Test total area
    double expected_total_area = 12.0 + 3.14159265358979323846 * 25 + 48.0 + 60.0;
    EXPECT_NEAR(ex_drawing.total_area(), expected_total_area, 1e-9);
    EXPECT_NEAR(sol_drawing.total_area(), expected_total_area, 1e-9);
    
    // Test perimeter calculations for all shapes
    std::vector<double> ex_perimeters = ex_drawing.calculate_all_perimeters();
    std::vector<double> sol_perimeters = sol_drawing.calculate_all_perimeters();
    
    EXPECT_EQ(ex_perimeters.size(), 4);
    EXPECT_EQ(sol_perimeters.size(), 4);
    
    // StandardRect: 2 * (3 + 4) = 14
    EXPECT_DOUBLE_EQ(ex_perimeters[0], 14.0);
    EXPECT_DOUBLE_EQ(sol_perimeters[0], 14.0);
    
    // StandardCircle: 2 * π * 5 = 10 * π
    EXPECT_NEAR(ex_perimeters[1], 10 * 3.14159265358979323846, 1e-9);
    EXPECT_NEAR(sol_perimeters[1], 10 * 3.14159265358979323846, 1e-9);
    
    // CloneableRect: 2 * (6 + 8) = 28
    EXPECT_DOUBLE_EQ(ex_perimeters[2], 28.0);
    EXPECT_DOUBLE_EQ(sol_perimeters[2], 28.0);
    
    // StandardTriangle: 10 + 12 + 15 = 37
    EXPECT_DOUBLE_EQ(ex_perimeters[3], 37.0);
    EXPECT_DOUBLE_EQ(sol_perimeters[3], 37.0);
    
    // Test total perimeter
    double expected_total_perimeter = 14.0 + 10 * 3.14159265358979323846 + 28.0 + 37.0;
    EXPECT_NEAR(ex_drawing.total_perimeter(), expected_total_perimeter, 1e-9);
    EXPECT_NEAR(sol_drawing.total_perimeter(), expected_total_perimeter, 1e-9);
}

} // namespace cpp_primer