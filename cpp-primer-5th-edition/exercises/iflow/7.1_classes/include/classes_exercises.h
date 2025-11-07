#ifndef CLASSES_EXERCISES_H
#define CLASSES_EXERCISES_H

#include <string>
#include <vector>

namespace cpp_primer {

/**
 * @class Point
 * @brief A simple class representing a 2D point
 * 
 * This class demonstrates basic class structure with constructors,
 * member variables, and member functions.
 */
class Point {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     * Initializes point to (0, 0)
     */
    Point();
    
    /**
     * @brief Parameterized constructor
     * @param x X coordinate
     * @param y Y coordinate
     */
    Point(double x, double y);
    
    // ========== GETTERS ==========
    
    /**
     * @brief Get the x coordinate
     * @return X coordinate
     */
    double get_x() const;
    
    /**
     * @brief Get the y coordinate
     * @return Y coordinate
     */
    double get_y() const;
    
    // ========== SETTERS ==========
    
    /**
     * @brief Set the x coordinate
     * @param x X coordinate
     */
    void set_x(double x);
    
    /**
     * @brief Set the y coordinate
     * @param y Y coordinate
     */
    void set_y(double y);
    
    // ========== OPERATIONS ==========
    
    /**
     * @brief Calculate distance to another point
     * @param other Another point
     * @return Distance to the other point
     */
    double distance_to(const Point& other) const;
    
private:
    double x_;  // X coordinate
    double y_;  // Y coordinate
};

/**
 * @class Student
 * @brief A class representing a student
 * 
 * This class demonstrates more complex class structure with multiple
 * member variables and methods.
 */
class Student {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    Student();
    
    /**
     * @brief Parameterized constructor
     * @param name Student's name
     * @param id Student's ID
     */
    Student(const std::string& name, int id);
    
    // ========== GETTERS ==========
    
    /**
     * @brief Get student's name
     * @return Student's name
     */
    std::string get_name() const;
    
    /**
     * @brief Get student's ID
     * @return Student's ID
     */
    int get_id() const;
    
    // ========== SETTERS ==========
    
    /**
     * @brief Set student's name
     * @param name Student's name
     */
    void set_name(const std::string& name);
    
    /**
     * @brief Set student's ID
     * @param id Student's ID
     */
    void set_id(int id);
    
    // ========== GRADE OPERATIONS ==========
    
    /**
     * @brief Add a grade to the student
     * @param grade Grade to add
     */
    void add_grade(double grade);
    
    /**
     * @brief Calculate average grade
     * @return Average grade
     */
    double calculate_average() const;
    
    /**
     * @brief Get all grades
     * @return Vector of grades
     */
    std::vector<double> get_grades() const;
    
private:
    std::string name_;        // Student's name
    int id_;                  // Student's ID
    std::vector<double> grades_;  // List of grades
};

} // namespace cpp_primer

#endif // CLASSES_EXERCISES_H