#include <gtest/gtest.h>
#include <string>

// Class with const member for practice
class PracticeClass {
private:
    std::string name;
    int value;
    const int id;
    
public:
    // Constructor with member initializer list for const member
    PracticeClass(const std::string& n, int v, int i) : name(n), value(v), id(i) {}
    
    // Copy constructor
    PracticeClass(const PracticeClass& other) : name(other.name), value(other.value), id(other.id) {}
    
    // Getters
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getId() const { return id; }
};

// Practice test for constructor with const member
TEST(ConstructorsPractice, ConstMemberInitialization) {
    PracticeClass obj("practice", 50, 999);
    EXPECT_EQ("practice", obj.getName());
    EXPECT_EQ(50, obj.getValue());
    EXPECT_EQ(999, obj.getId());
}

// Practice test for copy constructor with const member
TEST(ConstructorsPractice, CopyConstructorWithConst) {
    PracticeClass original("original", 75, 888);
    PracticeClass copy = original;
    
    EXPECT_EQ(original.getName(), copy.getName());
    EXPECT_EQ(original.getValue(), copy.getValue());
    EXPECT_EQ(original.getId(), copy.getId());
}

// Practice test for constructor overloading
TEST(ConstructorsPractice, ConstructorOverloading) {
    class OverloadTest {
    private:
        std::string data;
        int number;
        
    public:
        // Default constructor
        OverloadTest() : data("default"), number(0) {}
        
        // Parameterized constructor
        OverloadTest(const std::string& d) : data(d), number(0) {}
        
        // Another parameterized constructor
        OverloadTest(int n) : data("number"), number(n) {}
        
        // Constructor with multiple parameters
        OverloadTest(const std::string& d, int n) : data(d), number(n) {}
        
        std::string getData() const { return data; }
        int getNumber() const { return number; }
    };
    
    OverloadTest obj1;
    EXPECT_EQ("default", obj1.getData());
    EXPECT_EQ(0, obj1.getNumber());
    
    OverloadTest obj2("test");
    EXPECT_EQ("test", obj2.getData());
    EXPECT_EQ(0, obj2.getNumber());
    
    OverloadTest obj3(42);
    EXPECT_EQ("number", obj3.getData());
    EXPECT_EQ(42, obj3.getNumber());
    
    OverloadTest obj4("combined", 99);
    EXPECT_EQ("combined", obj4.getData());
    EXPECT_EQ(99, obj4.getNumber());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}