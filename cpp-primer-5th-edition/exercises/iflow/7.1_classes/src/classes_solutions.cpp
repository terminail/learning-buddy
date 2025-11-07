#include "classes_solutions.h"
#include <cmath>

namespace cpp_primer {

// ========== POINT CLASS IMPLEMENTATION ==========

// Point constructors
PointSolutions::PointSolutions() : x_(0.0), y_(0.0) {
    // Default constructor implementation
}

PointSolutions::PointSolutions(double x, double y) : x_(x), y_(y) {
    // Parameterized constructor implementation
}

// Point getters
double PointSolutions::get_x() const {
    // Get the x coordinate
    return x_;
}

double PointSolutions::get_y() const {
    // Get the y coordinate
    return y_;
}

// Point setters
void PointSolutions::set_x(double x) {
    // Set the x coordinate
    x_ = x;
}

void PointSolutions::set_y(double y) {
    // Set the y coordinate
    y_ = y;
}

// Point operations
double PointSolutions::distance_to(const PointSolutions& other) const {
    // Calculate distance to another point
    double dx = x_ - other.x_;
    double dy = y_ - other.y_;
    return std::sqrt(dx * dx + dy * dy);
}

// ========== STUDENT CLASS IMPLEMENTATION ==========

// Student constructors
StudentSolutions::StudentSolutions() : name_(""), id_(0) {
    // Default constructor implementation
}

StudentSolutions::StudentSolutions(const std::string& name, int id) : name_(name), id_(id) {
    // Parameterized constructor implementation
}

// Student getters
std::string StudentSolutions::get_name() const {
    // Get student's name
    return name_;
}

int StudentSolutions::get_id() const {
    // Get student's ID
    return id_;
}

// Student setters
void StudentSolutions::set_name(const std::string& name) {
    // Set student's name
    name_ = name;
}

void StudentSolutions::set_id(int id) {
    // Set student's ID
    id_ = id;
}

// Student grade operations
void StudentSolutions::add_grade(double grade) {
    // Add a grade to the student
    grades_.push_back(grade);
}

double StudentSolutions::calculate_average() const {
    // Calculate average grade
    if (grades_.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double grade : grades_) {
        sum += grade;
    }
    return sum / grades_.size();
}

std::vector<double> StudentSolutions::get_grades() const {
    // Get all grades
    return grades_;
}

} // namespace cpp_primer