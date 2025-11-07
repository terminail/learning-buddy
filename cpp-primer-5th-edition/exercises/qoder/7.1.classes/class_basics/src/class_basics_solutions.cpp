// Solution 7.1a: Class Basics
// This exercise demonstrates classes in C++.

#include <iostream>
#include <string>

// Solution: Define a simple class called Student
class Student {
private:
    // Private data members
    std::string name;
    int age;

public:
    // Solution: Add member functions to the Student class
    
    // Constructor that takes name and age parameters
    Student(const std::string& studentName, int studentAge) 
        : name(studentName), age(studentAge) {
    }
    
    // Getter functions to access private data members
    std::string getName() const {
        return name;
    }
    
    int getAge() const {
        return age;
    }
    
    // Setter functions to modify private data members
    void setName(const std::string& studentName) {
        name = studentName;
    }
    
    void setAge(int studentAge) {
        if (studentAge >= 0) {
            age = studentAge;
        }
    }
    
    // Function to display student information
    void displayInfo() const {
        std::cout << "Student Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Solution: Create Student objects and test their functionality
    
    // Create a Student object with initial values
    Student student1("Alice", 20);
    std::cout << "Initial student information:" << std::endl;
    student1.displayInfo();
    
    // Display the student's information using getter functions
    std::cout << "Using getter functions:" << std::endl;
    std::cout << "Name: " << student1.getName() << std::endl;
    std::cout << "Age: " << student1.getAge() << std::endl;
    
    // Modify the student's data using setter functions
    student1.setName("Alice Smith");
    student1.setAge(21);
    
    // Display the updated information
    std::cout << "Updated student information:" << std::endl;
    student1.displayInfo();
    
    // Create another Student object
    Student student2("Bob", 19);
    std::cout << "Second student information:" << std::endl;
    student2.displayInfo();
    
    return 0;
}