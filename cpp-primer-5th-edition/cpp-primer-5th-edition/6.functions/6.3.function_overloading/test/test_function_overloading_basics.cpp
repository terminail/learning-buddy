#include <gtest/gtest.h>
#include <string>

// Test overloaded functions with different parameter counts
TEST(FunctionOverloadingTest, DifferentParameterCounts) {
    // We'll use lambda functions to simulate overloaded functions for testing
    auto printValue0 = []() { return "No parameters"; };
    auto printValue1 = [](int) { return "One int parameter"; };
    auto printValue2 = [](int, int) { return "Two int parameters"; };
    
    EXPECT_EQ("No parameters", printValue0());
    EXPECT_EQ("One int parameter", printValue1(42));
    EXPECT_EQ("Two int parameters", printValue2(1, 2));
}

// Test overloaded functions with different parameter types
TEST(FunctionOverloadingTest, DifferentParameterTypes) {
    auto printInt = [](int) { return "int"; };
    auto printDouble = [](double) { return "double"; };
    auto printString = [](const std::string&) { return "string"; };
    auto printBool = [](bool) { return "bool"; };
    
    EXPECT_EQ("int", printInt(42));
    EXPECT_EQ("double", printDouble(3.14));
    EXPECT_EQ("string", printString("test"));
    EXPECT_EQ("bool", printBool(true));
}

// Test overloaded functions with different parameter orders
TEST(FunctionOverloadingTest, DifferentParameterOrders) {
    auto intDouble = [](int, double) { return "int-double"; };
    auto doubleInt = [](double, int) { return "double-int"; };
    
    EXPECT_EQ("int-double", intDouble(1, 2.0));
    EXPECT_EQ("double-int", doubleInt(1.0, 2));
}

// Test overload resolution
TEST(FunctionOverloadingTest, OverloadResolution) {
    // Test that the correct overload is selected based on argument types
    auto funcInt = [](int) { return "int"; };
    auto funcDouble = [](double) { return "double"; };
    auto funcFloat = [](float) { return "float"; };
    
    EXPECT_EQ("int", funcInt(42));
    EXPECT_EQ("double", funcDouble(3.14));
    EXPECT_EQ("float", funcFloat(3.14f));
    
    // Test promotion
    short shortValue = 100;
    EXPECT_EQ("int", funcInt(shortValue));  // short promotes to int
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}