// Exercise: Constructors Basics - Solution
// This exercise demonstrates different types of constructors in C++.

#include <iostream>
#include <string>

// Solution: Define a class with various constructors
class Student {
private:
    std::string name;
    int age;
    const int studentId;
    
public:
    // Default constructor
    Student() : name("Unknown"), age(0), studentId(0) {
        std::cout << "Default constructor called" << std::endl;
    }
    
    // Parameterized constructor with one parameter
    Student(const std::string& studentName) 
        : name(studentName), age(0), studentId(0) {
        std::cout << "Parameterized constructor (name only) called" << std::endl;
    }
    
    // Parameterized constructor with multiple parameters
    Student(const std::string& studentName, int studentAge) 
        : name(studentName), age(studentAge), studentId(0) {
        std::cout << "Parameterized constructor (name and age) called" << std::endl;
    }
    
    // Constructor with member initializer list for const member
    Student(const std::string& studentName, int studentAge, int id) 
        : name(studentName), age(studentAge), studentId(id) {
        std::cout << "Constructor with const member initialization called" << std::endl;
    }
    
    // Copy constructor
    Student(const Student& other) 
        : name(other.name), age(other.age), studentId(other.studentId) {
        std::cout << "Copy constructor called" << std::endl;
    }
    
    // Getters
    std::string getName() const { return name; }
    int getAge() const { return age; }
    int getStudentId() const { return studentId; }
    
    // Display function
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << ", ID: " << studentId << std::endl;
    }
};

int main() {
    // Solution: Create objects using different constructors
    
    // Using default constructor
    Student student1;
    student1.displayInfo();
    
    std::cout << std::endl;
    
    // Using parameterized constructor with one parameter
    Student student2("Alice");
    student2.displayInfo();
    
    std::cout << std::endl;
    
    // Using parameterized constructor with multiple parameters
    Student student3("Bob", 20);
    student3.displayInfo();
    
    std::cout << std::endl;
    
    // Using constructor with const member
    Student student4("Charlie", 22, 12345);
    student4.displayInfo();
    
    std::cout << std::endl;
    
    // Using copy constructor
    Student student5 = student3;
    student5.displayInfo();
    
    std::cout << std::endl;
    
    // Copy constructor also called in this case
    Student student6(student2);
    student6.displayInfo();
    
    return 0;
}