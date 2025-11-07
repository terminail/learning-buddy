#include <gtest/gtest.h>
#include "constants_exercises.h"

using namespace cpp_primer;

class ConstantsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(ConstantsTest, DefaultConstructor) {
    Constants exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== CONSTANT DECLARATION TESTS ==========

TEST_F(ConstantsTest, DeclareConstInteger) {
    Constants exercise;
    int result = exercise.declare_const_integer();
    
    // Verify that the function returns a const integer value
    EXPECT_NE(result, 0) << "Expected a non-zero integer value";
    EXPECT_TRUE((result == 42)) << "Expected 42 as example const integer value";
}

TEST_F(ConstantsTest, DeclareConstexprInteger) {
    Constants exercise;
    constexpr int result = exercise.declare_constexpr_integer();
    
    // Verify that the function returns a constexpr integer value
    EXPECT_NE(result, 0) << "Expected a non-zero integer value";
    EXPECT_TRUE((result == 100)) << "Expected 100 as example constexpr integer value";
}

TEST_F(ConstantsTest, DeclareConstDouble) {
    Constants exercise;
    double result = exercise.declare_const_double();
    
    // Verify that the function returns a const double value
    EXPECT_NE(result, 0.0) << "Expected a non-zero double value";
    EXPECT_NEAR(result, 3.14159, 0.0001) << "Expected 3.14159 as example const double value";
}

// ========== CALCULATION TESTS ==========

TEST_F(ConstantsTest, CalculateCircleArea) {
    Constants exercise;
    double result = exercise.calculate_circle_area(1.0);
    
    // Verify that the function calculates area of circle correctly
    EXPECT_NEAR(result, 3.14159, 0.001) << "Expected PI for radius 1";
    
    double result2 = exercise.calculate_circle_area(2.0);
    EXPECT_NEAR(result2, 12.56636, 0.001) << "Expected 4*PI for radius 2";
}

// ========== CONST REFERENCE TESTS ==========

TEST_F(ConstantsTest, UseConstReference) {
    Constants exercise;
    int input = 42;
    int result = exercise.use_const_reference(input);
    
    // Verify that the function properly accepts and returns const reference
    EXPECT_EQ(result, input) << "Expected the same value as input";
}

// ========== CONST MEMBER FUNCTION TESTS ==========

TEST_F(ConstantsTest, GetConstantValue) {
    Constants exercise;
    int result = exercise.get_constant_value();
    
    // Verify that the const member function returns the correct value
    EXPECT_EQ(result, 100) << "Expected the constant member value (100)";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}