#include <gtest/gtest.h>
#include <string>

// Simple class for testing constructors
class TestClass {
private:
    std::string name;
    int value;
    
public:
    // Default constructor
    TestClass() : name("default"), value(0) {}
    
    // Parameterized constructor
    TestClass(const std::string& n, int v) : name(n), value(v) {}
    
    // Copy constructor
    TestClass(const TestClass& other) : name(other.name), value(other.value) {}
    
    // Getters
    std::string getName() const { return name; }
    int getValue() const { return value; }
};

// Test default constructor
TEST(ConstructorsTest, DefaultConstructor) {
    TestClass obj;
    EXPECT_EQ("default", obj.getName());
    EXPECT_EQ(0, obj.getValue());
}

// Test parameterized constructor
TEST(ConstructorsTest, ParameterizedConstructor) {
    TestClass obj("test", 42);
    EXPECT_EQ("test", obj.getName());
    EXPECT_EQ(42, obj.getValue());
}

// Test copy constructor
TEST(ConstructorsTest, CopyConstructor) {
    TestClass original("original", 100);
    TestClass copy = original;
    
    EXPECT_EQ(original.getName(), copy.getName());
    EXPECT_EQ(original.getValue(), copy.getValue());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}