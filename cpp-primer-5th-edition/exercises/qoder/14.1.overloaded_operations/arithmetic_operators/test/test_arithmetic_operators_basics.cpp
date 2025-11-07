#include <gtest/gtest.h>
#include <cmath>

// Simple implementation for testing
class TestComplex {
private:
    double real;
    double imag;

public:
    TestComplex() : real(0.0), imag(0.0) {}
    TestComplex(double r, double i) : real(r), imag(i) {}
    
    TestComplex& operator+=(const TestComplex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }
    
    TestComplex& operator-=(const TestComplex& other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }
    
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

TestComplex operator+(const TestComplex& lhs, const TestComplex& rhs) {
    TestComplex result = lhs;
    result += rhs;
    return result;
}

TestComplex operator-(const TestComplex& lhs, const TestComplex& rhs) {
    TestComplex result = lhs;
    result -= rhs;
    return result;
}

// Basic test for addition operator
TEST(ArithmeticOperatorsTest, Addition) {
    TestComplex c1(1.0, 2.0);
    TestComplex c2(3.0, 4.0);
    TestComplex result = c1 + c2;
    
    EXPECT_DOUBLE_EQ(result.getReal(), 4.0);
    EXPECT_DOUBLE_EQ(result.getImag(), 6.0);
}

// Basic test for subtraction operator
TEST(ArithmeticOperatorsTest, Subtraction) {
    TestComplex c1(5.0, 7.0);
    TestComplex c2(2.0, 3.0);
    TestComplex result = c1 - c2;
    
    EXPECT_DOUBLE_EQ(result.getReal(), 3.0);
    EXPECT_DOUBLE_EQ(result.getImag(), 4.0);
}

// Test compound assignment operators
TEST(ArithmeticOperatorsTest, CompoundAssignment) {
    TestComplex c1(1.0, 2.0);
    TestComplex c2(3.0, 4.0);
    
    c1 += c2;
    EXPECT_DOUBLE_EQ(c1.getReal(), 4.0);
    EXPECT_DOUBLE_EQ(c1.getImag(), 6.0);
    
    c1 -= c2;
    EXPECT_DOUBLE_EQ(c1.getReal(), 1.0);
    EXPECT_DOUBLE_EQ(c1.getImag(), 2.0);
}