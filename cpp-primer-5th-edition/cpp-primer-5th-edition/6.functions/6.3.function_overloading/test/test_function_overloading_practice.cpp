#include <gtest/gtest.h>
#include <string>

// Practice test for complex overload resolution
TEST(FunctionOverloadingPractice, ComplexOverloadResolution) {
    // Test with multiple overloads that could match
    auto funcInt = [](int) { return "int"; };
    auto funcLong = [](long) { return "long"; };
    auto funcDouble = [](double) { return "double"; };
    auto funcFloat = [](float) { return "float"; };
    
    // Exact matches
    EXPECT_EQ("int", funcInt(42));
    EXPECT_EQ("long", funcLong(42L));
    EXPECT_EQ("float", funcFloat(3.14f));
    EXPECT_EQ("double", funcDouble(3.14));
    
    // Promotion scenarios
    short shortValue = 100;
    signed char charValue = 50;
    
    // short promotes to int
    EXPECT_EQ("int", funcInt(shortValue));
    
    // signed char promotes to int
    EXPECT_EQ("int", funcInt(charValue));
    
    // float promotes to double
    EXPECT_EQ("double", funcDouble(3.14f));
}

// Practice test for user-defined types and overloading
TEST(FunctionOverloadingPractice, UserDefinedTypes) {
    struct Point {
        int x, y;
        Point(int x = 0, int y = 0) : x(x), y(y) {}
    };
    
    // Overloaded functions for Point
    auto printPoint = [](const Point& p) { 
        return "Point(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")"; 
    };
    
    auto printPointWithLabel = [](const Point& p, const std::string& label) {
        return label + ": Point(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
    };
    
    Point p(10, 20);
    EXPECT_EQ("Point(10, 20)", printPoint(p));
    EXPECT_EQ("Test: Point(10, 20)", printPointWithLabel(p, "Test"));
}

// Practice test for const overloading
TEST(FunctionOverloadingPractice, ConstOverloading) {
    class Container {
    private:
        int value;
        
    public:
        Container(int v) : value(v) {}
        
        // Non-const version
        int& access() { 
            std::cout << "Non-const access" << std::endl;
            return value; 
        }
        
        // Const version
        const int& access() const { 
            std::cout << "Const access" << std::endl;
            return value; 
        }
    };
    
    Container c(42);
    const Container& constC = c;
    
    // Calls non-const version
    int& val1 = c.access();
    EXPECT_EQ(42, val1);
    
    // Calls const version
    const int& val2 = constC.access();
    EXPECT_EQ(42, val2);
}

// Practice test for ambiguity resolution
TEST(FunctionOverloadingPractice, AmbiguityResolution) {
    // Functions that could cause ambiguity
    auto funcInt = [](int) { return "int"; };
    auto funcDouble = [](double) { return "double"; };
    auto funcFloat = [](float) { return "float"; };
    
    // Cases that would be ambiguous without careful design:
    
    // char promotes to int, not double or float
    EXPECT_EQ("int", funcInt(static_cast<char>('A')));
    
    // unsigned int could promote to long or float, but typically promotes to long
    EXPECT_EQ("int", funcInt(static_cast<unsigned short>(100)));
    
    // Explicit casting to resolve potential ambiguities
    float floatValue = 3.14f;
    EXPECT_EQ("float", funcFloat(floatValue));
    EXPECT_EQ("double", funcDouble(static_cast<double>(floatValue)));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}