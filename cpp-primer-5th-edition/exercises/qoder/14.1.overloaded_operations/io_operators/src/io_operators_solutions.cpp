#include <iostream>
#include <string>

// Solution: Implement a class with overloaded IO operators
class Person {
private:
    std::string name;
    int age;

public:
    // Solution: Implement constructors
    Person() : name(""), age(0) {}
    
    Person(const std::string& n, int a) : name(n), age(a) {}
    
    // Solution: Declare overloaded IO operators as friend functions
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    friend std::istream& operator>>(std::istream& is, Person& person);
    
    // Solution: Implement getters for name and age
    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    
    // Solution: Implement setters for name and age (needed for extraction operator)
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = a; }
    
    // Solution: Implement a display method to print person information
    void display() const {
        std::cout << "Person: " << name << ", Age: " << age << std::endl;
    }
};

// Solution: Implement non-member operator<< function
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Person(Name: " << person.name << ", Age: " << person.age << ")";
    return os;
}

// Solution: Implement non-member operator>> function
std::istream& operator>>(std::istream& is, Person& person) {
    is >> person.name >> person.age;
    return is;
}

int main() {
    // Solution: Create Person objects and demonstrate IO operators
    Person p1("Alice", 25);
    Person p2;
    
    std::cout << "Output using operator<<:" << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    
    std::cout << "\nChaining output operators:" << std::endl;
    std::cout << p1 << " and " << p2 << std::endl;
    
    std::cout << "\nEnter name and age for second person: ";
    std::cin >> p2;
    
    std::cout << "Updated person information:" << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    
    return 0;
}