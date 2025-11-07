#include <gtest/gtest.h>
#include "classes_exercises.h"

using namespace cpp_primer;

class ClassesTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== POINT CLASS TESTS ==========

TEST_F(ClassesTest, PointDefaultConstructor) {
    Point point;
    
    // Test default constructor initializes to (0, 0)
    EXPECT_EQ(point.get_x(), 0.0) << "Expected x coordinate to be 0";
    EXPECT_EQ(point.get_y(), 0.0) << "Expected y coordinate to be 0";
}

TEST_F(ClassesTest, PointParameterizedConstructor) {
    Point point(3.0, 4.0);
    
    // Test parameterized constructor
    EXPECT_EQ(point.get_x(), 3.0) << "Expected x coordinate to be 3.0";
    EXPECT_EQ(point.get_y(), 4.0) << "Expected y coordinate to be 4.0";
}

TEST_F(ClassesTest, PointGettersAndSetters) {
    Point point;
    
    // Test setters
    point.set_x(5.0);
    point.set_y(-2.0);
    
    // Test getters
    EXPECT_EQ(point.get_x(), 5.0) << "Expected x coordinate to be 5.0";
    EXPECT_EQ(point.get_y(), -2.0) << "Expected y coordinate to be -2.0";
}

TEST_F(ClassesTest, PointDistanceTo) {
    Point point1(0.0, 0.0);
    Point point2(3.0, 4.0);
    
    // Test distance calculation (should be 5.0 for a 3-4-5 right triangle)
    double distance = point1.distance_to(point2);
    EXPECT_NEAR(distance, 5.0, 0.001) << "Expected distance to be 5.0";
    
    // Test distance to same point (should be 0.0)
    Point point3(2.0, 3.0);
    double same_distance = point3.distance_to(point3);
    EXPECT_NEAR(same_distance, 0.0, 0.001) << "Expected distance to same point to be 0.0";
}

// ========== STUDENT CLASS TESTS ==========

TEST_F(ClassesTest, StudentDefaultConstructor) {
    Student student;
    
    // Test default constructor
    EXPECT_EQ(student.get_name(), "") << "Expected empty name for default constructor";
    EXPECT_EQ(student.get_id(), 0) << "Expected ID 0 for default constructor";
    EXPECT_EQ(student.get_grades().size(), 0) << "Expected no grades for default constructor";
}

TEST_F(ClassesTest, StudentParameterizedConstructor) {
    Student student("Alice", 12345);
    
    // Test parameterized constructor
    EXPECT_EQ(student.get_name(), "Alice") << "Expected name to be 'Alice'";
    EXPECT_EQ(student.get_id(), 12345) << "Expected ID to be 12345";
    EXPECT_EQ(student.get_grades().size(), 0) << "Expected no grades initially";
}

TEST_F(ClassesTest, StudentGettersAndSetters) {
    Student student;
    
    // Test setters
    student.set_name("Bob");
    student.set_id(67890);
    
    // Test getters
    EXPECT_EQ(student.get_name(), "Bob") << "Expected name to be 'Bob'";
    EXPECT_EQ(student.get_id(), 67890) << "Expected ID to be 67890";
}

TEST_F(ClassesTest, StudentGradeOperations) {
    Student student("Charlie", 11111);
    
    // Test adding grades
    student.add_grade(85.0);
    student.add_grade(92.0);
    student.add_grade(78.0);
    
    // Test getting grades
    std::vector<double> grades = student.get_grades();
    EXPECT_EQ(grades.size(), 3) << "Expected 3 grades";
    EXPECT_EQ(grades[0], 85.0) << "Expected first grade to be 85.0";
    EXPECT_EQ(grades[1], 92.0) << "Expected second grade to be 92.0";
    EXPECT_EQ(grades[2], 78.0) << "Expected third grade to be 78.0";
    
    // Test calculating average
    double average = student.calculate_average();
    EXPECT_NEAR(average, 85.0, 0.001) << "Expected average to be 85.0";
}

TEST_F(ClassesTest, StudentCalculateAverage) {
    Student student("Diana", 22222);
    
    // Test average of empty grades
    double empty_average = student.calculate_average();
    EXPECT_NEAR(empty_average, 0.0, 0.001) << "Expected average of empty grades to be 0.0";
    
    // Add some grades and test average
    student.add_grade(100.0);
    student.add_grade(90.0);
    student.add_grade(80.0);
    student.add_grade(70.0);
    
    double average = student.calculate_average();
    EXPECT_NEAR(average, 85.0, 0.001) << "Expected average to be 85.0";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}