#include <iostream>
#include <string>

// Solution: Implement a class with overloaded comparison operators
class Student {
private:
    std::string name;
    double gpa;

public:
    // Solution: Implement constructors
    Student() : name(""), gpa(0.0) {}
    
    Student(const std::string& n, double g) : name(n), gpa(g) {}
    
    // Solution: Implement overloaded comparison operators
    // Best practice: Implement only < and ==, then derive others
    
    bool operator==(const Student& other) const {
        return name == other.name && gpa == other.gpa;
    }
    
    bool operator!=(const Student& other) const {
        return !(*this == other);
    }
    
    bool operator<(const Student& other) const {
        if (gpa != other.gpa) {
            return gpa < other.gpa;
        }
        return name < other.name;
    }
    
    bool operator>(const Student& other) const {
        return other < *this;
    }
    
    bool operator<=(const Student& other) const {
        return !(*this > other);
    }
    
    bool operator>=(const Student& other) const {
        return !(*this < other);
    }
    
    // Solution: Implement getters for name and gpa
    const std::string& getName() const { return name; }
    double getGpa() const { return gpa; }
    
    // Solution: Implement a display method to print student information
    void display() const {
        std::cout << "Student: " << name << ", GPA: " << gpa << std::endl;
    }
};

int main() {
    // Solution: Create Student objects and demonstrate comparison operators
    Student s1("Alice", 3.8);
    Student s2("Bob", 3.9);
    Student s3("Charlie", 3.8);
    Student s4("Alice", 3.8);
    
    std::cout << "Comparing students:" << std::endl;
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    
    std::cout << "\nComparison results:" << std::endl;
    std::cout << "s1 == s2: " << (s1 == s2 ? "true" : "false") << std::endl;
    std::cout << "s1 == s4: " << (s1 == s4 ? "true" : "false") << std::endl;
    std::cout << "s1 != s2: " << (s1 != s2 ? "true" : "false") << std::endl;
    std::cout << "s1 < s2: " << (s1 < s2 ? "true" : "false") << std::endl;
    std::cout << "s1 > s2: " << (s1 > s2 ? "true" : "false") << std::endl;
    std::cout << "s1 <= s3: " << (s1 <= s3 ? "true" : "false") << std::endl;
    std::cout << "s2 >= s1: " << (s2 >= s1 ? "true" : "false") << std::endl;
    
    return 0;
}