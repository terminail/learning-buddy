#include <gtest/gtest.h>
#include "overloaded_operations_exercises.h"
#include "overloaded_operations_solutions.h"

namespace cpp_primer {

// Test fixture for OverloadedOperations exercises
class OverloadedOperationsBasicsTest : public ::testing::Test {
protected:
    ComplexNumber exercises_complex;
    ComplexNumberSolutions solutions_complex;
};

// Test ComplexNumber default constructor
TEST_F(OverloadedOperationsBasicsTest, TestComplexNumberDefaultConstructor) {
    ComplexNumber ex;
    ComplexNumberSolutions sol;
    
    EXPECT_EQ(ex.get_real(), 0);
    EXPECT_EQ(ex.get_imaginary(), 0);
    
    EXPECT_EQ(sol.get_real(), 0);
    EXPECT_EQ(sol.get_imaginary(), 0);
}

// Test ComplexNumber constructor with real part
TEST_F(OverloadedOperationsBasicsTest, TestComplexNumberRealConstructor) {
    ComplexNumber ex(5.0);
    ComplexNumberSolutions sol(5.0);
    
    EXPECT_EQ(ex.get_real(), 5.0);
    EXPECT_EQ(ex.get_imaginary(), 0);
    
    EXPECT_EQ(sol.get_real(), 5.0);
    EXPECT_EQ(sol.get_imaginary(), 0);
}

// Test ComplexNumber constructor with real and imaginary parts
TEST_F(OverloadedOperationsBasicsTest, TestComplexNumberFullConstructor) {
    ComplexNumber ex(3.0, 4.0);
    ComplexNumberSolutions sol(3.0, 4.0);
    
    EXPECT_EQ(ex.get_real(), 3.0);
    EXPECT_EQ(ex.get_imaginary(), 4.0);
    
    EXPECT_EQ(sol.get_real(), 3.0);
    EXPECT_EQ(sol.get_imaginary(), 4.0);
}

// Test ComplexNumber arithmetic operators
TEST_F(OverloadedOperationsBasicsTest, TestComplexNumberArithmetic) {
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(3.0, 4.0);
    ComplexNumberSolutions sol_a(1.0, 2.0);
    ComplexNumberSolutions sol_b(3.0, 4.0);
    
    // Test addition
    ComplexNumber sum = a + b;
    ComplexNumberSolutions sol_sum = sol_a + sol_b;
    
    EXPECT_EQ(sum.get_real(), 4.0);
    EXPECT_EQ(sum.get_imaginary(), 6.0);
    
    EXPECT_EQ(sol_sum.get_real(), 4.0);
    EXPECT_EQ(sol_sum.get_imaginary(), 6.0);
    
    // Test subtraction
    ComplexNumber diff = a - b;
    ComplexNumberSolutions sol_diff = sol_a - sol_b;
    
    EXPECT_EQ(diff.get_real(), -2.0);
    EXPECT_EQ(diff.get_imaginary(), -2.0);
    
    EXPECT_EQ(sol_diff.get_real(), -2.0);
    EXPECT_EQ(sol_diff.get_imaginary(), -2.0);
}

// Test ComplexNumber compound assignment operators
TEST_F(OverloadedOperationsBasicsTest, TestComplexNumberCompoundAssignment) {
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(3.0, 4.0);
    ComplexNumberSolutions sol_a(1.0, 2.0);
    ComplexNumberSolutions sol_b(3.0, 4.0);
    
    // Test +=
    a += b;
    sol_a += sol_b;
    
    EXPECT_EQ(a.get_real(), 4.0);
    EXPECT_EQ(a.get_imaginary(), 6.0);
    
    EXPECT_EQ(sol_a.get_real(), 4.0);
    EXPECT_EQ(sol_a.get_imaginary(), 6.0);
    
    // Test -=
    a -= b;
    sol_a -= sol_b;
    
    EXPECT_EQ(a.get_real(), 1.0);
    EXPECT_EQ(a.get_imaginary(), 2.0);
    
    EXPECT_EQ(sol_a.get_real(), 1.0);
    EXPECT_EQ(sol_a.get_imaginary(), 2.0);
}

// Test ComplexNumber unary operators
TEST_F(OverloadedOperationsBasicsTest, TestComplexNumberUnaryOperators) {
    ComplexNumber a(5.0, -3.0);
    ComplexNumberSolutions sol_a(5.0, -3.0);
    
    // Test unary +
    ComplexNumber pos = +a;
    ComplexNumberSolutions sol_pos = +sol_a;
    
    EXPECT_EQ(pos.get_real(), 5.0);
    EXPECT_EQ(pos.get_imaginary(), -3.0);
    
    EXPECT_EQ(sol_pos.get_real(), 5.0);
    EXPECT_EQ(sol_pos.get_imaginary(), -3.0);
    
    // Test unary -
    ComplexNumber neg = -a;
    ComplexNumberSolutions sol_neg = -sol_a;
    
    EXPECT_EQ(neg.get_real(), -5.0);
    EXPECT_EQ(neg.get_imaginary(), 3.0);
    
    EXPECT_EQ(sol_neg.get_real(), -5.0);
    EXPECT_EQ(sol_neg.get_imaginary(), 3.0);
}

// Test ComplexNumber comparison operators
TEST_F(OverloadedOperationsBasicsTest, TestComplexNumberComparisons) {
    ComplexNumber a(3.0, 4.0);  // magnitude = 5
    ComplexNumber b(5.0, 0.0);  // magnitude = 5
    ComplexNumber c(1.0, 1.0);  // magnitude = sqrt(2)
    ComplexNumberSolutions sol_a(3.0, 4.0);
    ComplexNumberSolutions sol_b(5.0, 0.0);
    ComplexNumberSolutions sol_c(1.0, 1.0);
    
    // Test ==
    EXPECT_TRUE(a == b);  // Same magnitude
    EXPECT_TRUE(sol_a == sol_b);  // Same magnitude
    
    // Test !=
    EXPECT_TRUE(a != c);  // Different magnitude
    EXPECT_TRUE(sol_a != sol_c);  // Different magnitude
    
    // Test <
    EXPECT_TRUE(c < a);  // Smaller magnitude
    EXPECT_TRUE(sol_c < sol_a);  // Smaller magnitude
    
    // Test >
    EXPECT_TRUE(a > c);  // Larger magnitude
    EXPECT_TRUE(sol_a > sol_c);  // Larger magnitude
}

// Test ComplexNumber utility functions
TEST_F(OverloadedOperationsBasicsTest, TestComplexNumberUtilities) {
    ComplexNumber a(3.0, 4.0);
    ComplexNumberSolutions sol_a(3.0, 4.0);
    
    // Test magnitude
    EXPECT_DOUBLE_EQ(a.magnitude(), 5.0);
    EXPECT_DOUBLE_EQ(sol_a.magnitude(), 5.0);
    
    // Test conjugate
    ComplexNumber conj = a.conjugate();
    ComplexNumberSolutions sol_conj = sol_a.conjugate();
    
    EXPECT_EQ(conj.get_real(), 3.0);
    EXPECT_EQ(conj.get_imaginary(), -4.0);
    
    EXPECT_EQ(sol_conj.get_real(), 3.0);
    EXPECT_EQ(sol_conj.get_imaginary(), -4.0);
}

// Test SafeArray basic functionality
TEST_F(OverloadedOperationsBasicsTest, TestSafeArrayBasics) {
    SafeArray arr(5, 10);  // Array of 5 elements, all 10
    SafeArraySolutions sol_arr(5, 10);
    
    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(sol_arr.size(), 5);
    
    // Test subscript operator
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(sol_arr[0], 10);
    
    // Test function call operator
    EXPECT_EQ(arr(2), 10);
    EXPECT_EQ(sol_arr(2), 10);
    
    // Test modification through function call operator
    arr(2, 20);
    sol_arr(2, 20);
    
    EXPECT_EQ(arr[2], 20);
    EXPECT_EQ(sol_arr[2], 20);
}

// Test SimplePtr basic functionality
TEST_F(OverloadedOperationsBasicsTest, TestSimplePtrBasics) {
    SimplePtr<int> ptr(new int(42));
    SimplePtrSolutions<int> sol_ptr(new int(42));
    
    // Test dereference operator
    EXPECT_EQ(*ptr, 42);
    EXPECT_EQ(*sol_ptr, 42);
    
    // Test member access operator (for int, not applicable, but testing conversion)
    EXPECT_NE(ptr.get(), nullptr);
    EXPECT_NE(sol_ptr.get(), nullptr);
    
    // Test boolean conversion
    EXPECT_TRUE(ptr);
    EXPECT_TRUE(sol_ptr);
    
    // Test release
    int* raw_ptr = ptr.release();
    int* sol_raw_ptr = sol_ptr.release();
    
    EXPECT_EQ(*raw_ptr, 42);
    EXPECT_EQ(*sol_raw_ptr, 42);
    
    EXPECT_FALSE(ptr);
    EXPECT_FALSE(sol_ptr);
    
    delete raw_ptr;
    delete sol_raw_ptr;
}

} // namespace cpp_primer