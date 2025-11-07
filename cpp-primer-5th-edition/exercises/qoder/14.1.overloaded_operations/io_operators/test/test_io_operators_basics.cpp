#include <gtest/gtest.h>
#include <sstream>
#include <string>

// Simple implementation for testing
class TestPerson {
private:
    std::string name;
    int age;

public:
    TestPerson() : name(""), age(0) {}
    TestPerson(const std::string& n, int a) : name(n), age(a) {}
    
    friend std::ostream& operator<<(std::ostream& os, const TestPerson& person);
    friend std::istream& operator>>(std::istream& is, TestPerson& person);
    
    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = a; }
};

std::ostream& operator<<(std::ostream& os, const TestPerson& person) {
    os << person.name << " " << person.age;
    return os;
}

std::istream& operator>>(std::istream& is, TestPerson& person) {
    is >> person.name >> person.age;
    return is;
}

// Basic test for output operator
TEST(IOOperatorsTest, OutputOperator) {
    TestPerson person("Alice", 25);
    std::ostringstream oss;
    oss << person;
    
    EXPECT_EQ(oss.str(), "Alice 25");
}

// Basic test for input operator
TEST(IOOperatorsTest, InputOperator) {
    std::istringstream iss("Bob 30");
    TestPerson person;
    iss >> person;
    
    EXPECT_EQ(person.getName(), "Bob");
    EXPECT_EQ(person.getAge(), 30);
}

// Test chaining of output operators
TEST(IOOperatorsTest, Chaining) {
    TestPerson person1("Alice", 25);
    TestPerson person2("Bob", 30);
    std::ostringstream oss;
    oss << person1 << " and " << person2;
    
    EXPECT_EQ(oss.str(), "Alice 25 and Bob 30");
}