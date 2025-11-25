#include <gtest/gtest.h>
#include <string>

// Practice test for initialization comparison
TEST(VariableInitializationPractice, InitializationComparison) {
    // All of these are equivalent in result
    int a = 10;
    int b(10);
    int c{10};
    int d = {10};
    
    EXPECT_EQ(a, b);
    EXPECT_EQ(b, c);
    EXPECT_EQ(c, d);
    EXPECT_EQ(10, a);
}

// Practice test for narrowing conversions
TEST(VariableInitializationPractice, NarrowingConversions) {
    // List initialization prevents narrowing conversions
    int normalInit = 3.14;  // Allowed, but loses precision
    // int listInit{3.14};  // Compilation error - would prevent loss of precision
    
    EXPECT_EQ(3, normalInit);  // Truncated to 3
    
    // But we can test with compatible types
    double doubleValue = 5.0;
    int intFromDouble{static_cast<int>(doubleValue)};  // Explicit conversion
    EXPECT_EQ(5, intFromDouble);
}

// Practice test for default initialization
TEST(VariableInitializationPractice, DefaultInitialization) {
    std::string defaultString;  // Default initialized to empty
    std::vector<int> defaultVector;  // Default initialized to empty
    
    EXPECT_TRUE(defaultString.empty());
    EXPECT_TRUE(defaultVector.empty());
    EXPECT_EQ(0, defaultVector.size());
    
    // Test with class types that have default constructors
    class TestClass {
    public:
        int value;
        TestClass() : value(42) {}  // Default constructor
    };
    
    TestClass defaultObj;  // Default initialized
    EXPECT_EQ(42, defaultObj.value);
}

// Practice test for aggregate initialization
TEST(VariableInitializationPractice, AggregateInitialization) {
    // Arrays
    int array[]{1, 2, 3, 4, 5};
    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(5, array[4]);
    
    // Structs
    struct Point {
        double x;
        double y;
    };
    
    Point p{1.5, 2.5};
    EXPECT_DOUBLE_EQ(1.5, p.x);
    EXPECT_DOUBLE_EQ(2.5, p.y);
    
    // Nested structures
    struct Rectangle {
        Point topLeft;
        Point bottomRight;
    };
    
    Rectangle r{{0.0, 10.0}, {5.0, 0.0}};
    EXPECT_DOUBLE_EQ(0.0, r.topLeft.x);
    EXPECT_DOUBLE_EQ(10.0, r.topLeft.y);
    EXPECT_DOUBLE_EQ(5.0, r.bottomRight.x);
    EXPECT_DOUBLE_EQ(0.0, r.bottomRight.y);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}