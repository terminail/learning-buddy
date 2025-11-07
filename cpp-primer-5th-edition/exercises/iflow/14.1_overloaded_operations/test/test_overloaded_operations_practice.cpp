#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <sstream>
#include "overloaded_operations_exercises.h"
#include "overloaded_operations_solutions.h"

namespace cpp_primer {

// Test fixture for OverloadedOperations practice exercises
class OverloadedOperationsPracticeTest : public ::testing::Test {
protected:
    ComplexNumber exercises_complex;
    ComplexNumberSolutions solutions_complex;
};

// Test ComplexNumber comprehensive arithmetic operations
TEST_F(OverloadedOperationsPracticeTest, TestComplexNumberComprehensiveArithmetic) {
    ComplexNumber a(2.0, 3.0);
    ComplexNumber b(4.0, -1.0);
    ComplexNumberSolutions sol_a(2.0, 3.0);
    ComplexNumberSolutions sol_b(4.0, -1.0);
    
    // Test multiplication
    ComplexNumber product = a * b;
    ComplexNumberSolutions sol_product = sol_a * sol_b;
    
    // (2 + 3i) * (4 - i) = (2*4 - 3*(-1)) + (2*(-1) + 3*4)i = (8 + 3) + (-2 + 12)i = 11 + 10i
    EXPECT_DOUBLE_EQ(product.get_real(), 11.0);
    EXPECT_DOUBLE_EQ(product.get_imaginary(), 10.0);
    
    EXPECT_DOUBLE_EQ(sol_product.get_real(), 11.0);
    EXPECT_DOUBLE_EQ(sol_product.get_imaginary(), 10.0);
    
    // Test division
    ComplexNumber quotient = a / b;
    ComplexNumberSolutions sol_quotient = sol_a / sol_b;
    
    // (2 + 3i) / (4 - i) = ((2*4 + 3*(-1)) + (3*4 - 2*(-1))i) / (4^2 + (-1)^2)
    // = (8 - 3) + (12 + 2)i) / 17 = (5 + 14i) / 17 = 5/17 + (14/17)i
    EXPECT_NEAR(quotient.get_real(), 5.0/17.0, 1e-9);
    EXPECT_NEAR(quotient.get_imaginary(), 14.0/17.0, 1e-9);
    
    EXPECT_NEAR(sol_quotient.get_real(), 5.0/17.0, 1e-9);
    EXPECT_NEAR(sol_quotient.get_imaginary(), 14.0/17.0, 1e-9);
    
    // Test compound assignment operators with multiplication and division
    a *= b;
    sol_a *= sol_b;
    
    EXPECT_DOUBLE_EQ(a.get_real(), 11.0);
    EXPECT_DOUBLE_EQ(a.get_imaginary(), 10.0);
    
    EXPECT_DOUBLE_EQ(sol_a.get_real(), 11.0);
    EXPECT_DOUBLE_EQ(sol_a.get_imaginary(), 10.0);
    
    a /= b;
    sol_a /= sol_b;
    
    EXPECT_NEAR(a.get_real(), 2.0, 1e-9);
    EXPECT_NEAR(a.get_imaginary(), 3.0, 1e-9);
    
    EXPECT_NEAR(sol_a.get_real(), 2.0, 1e-9);
    EXPECT_NEAR(sol_a.get_imaginary(), 3.0, 1e-9);
}

// Test ComplexNumber increment and decrement operators
TEST_F(OverloadedOperationsPracticeTest, TestComplexNumberIncrementDecrement) {
    ComplexNumber a(5.0, 3.0);
    ComplexNumberSolutions sol_a(5.0, 3.0);
    
    // Test prefix increment
    ComplexNumber& prefix_inc_ref = ++a;
    ComplexNumberSolutions& sol_prefix_inc_ref = ++sol_a;
    
    EXPECT_EQ(a.get_real(), 6.0);
    EXPECT_EQ(a.get_imaginary(), 3.0);
    EXPECT_EQ(&prefix_inc_ref, &a);  // Should return reference to self
    
    EXPECT_EQ(sol_a.get_real(), 6.0);
    EXPECT_EQ(sol_a.get_imaginary(), 3.0);
    EXPECT_EQ(&sol_prefix_inc_ref, &sol_a);  // Should return reference to self
    
    // Test postfix increment
    ComplexNumber postfix_inc_val = a++;
    ComplexNumberSolutions sol_postfix_inc_val = sol_a++;
    
    EXPECT_EQ(postfix_inc_val.get_real(), 6.0);  // Should return old value
    EXPECT_EQ(postfix_inc_val.get_imaginary(), 3.0);
    EXPECT_EQ(a.get_real(), 7.0);  // a should be incremented
    EXPECT_EQ(a.get_imaginary(), 3.0);
    
    EXPECT_EQ(sol_postfix_inc_val.get_real(), 6.0);  // Should return old value
    EXPECT_EQ(sol_postfix_inc_val.get_imaginary(), 3.0);
    EXPECT_EQ(sol_a.get_real(), 7.0);  // sol_a should be incremented
    EXPECT_EQ(sol_a.get_imaginary(), 3.0);
    
    // Test prefix decrement
    ComplexNumber& prefix_dec_ref = --a;
    ComplexNumberSolutions& sol_prefix_dec_ref = --sol_a;
    
    EXPECT_EQ(a.get_real(), 6.0);
    EXPECT_EQ(a.get_imaginary(), 3.0);
    EXPECT_EQ(&prefix_dec_ref, &a);  // Should return reference to self
    
    EXPECT_EQ(sol_a.get_real(), 6.0);
    EXPECT_EQ(sol_a.get_imaginary(), 3.0);
    EXPECT_EQ(&sol_prefix_dec_ref, &sol_a);  // Should return reference to self
    
    // Test postfix decrement
    ComplexNumber postfix_dec_val = a--;
    ComplexNumberSolutions sol_postfix_dec_val = sol_a--;
    
    EXPECT_EQ(postfix_dec_val.get_real(), 6.0);  // Should return old value
    EXPECT_EQ(postfix_dec_val.get_imaginary(), 3.0);
    EXPECT_EQ(a.get_real(), 5.0);  // a should be decremented
    EXPECT_EQ(a.get_imaginary(), 3.0);
    
    EXPECT_EQ(sol_postfix_dec_val.get_real(), 6.0);  // Should return old value
    EXPECT_EQ(sol_postfix_dec_val.get_imaginary(), 3.0);
    EXPECT_EQ(sol_a.get_real(), 5.0);  // sol_a should be decremented
    EXPECT_EQ(sol_a.get_imaginary(), 3.0);
}

// Test stream operators for ComplexNumber
TEST_F(OverloadedOperationsPracticeTest, TestComplexNumberStreamOperators) {
    ComplexNumberSolutions a(3.0, 4.0);
    
    // Test output stream operator
    std::ostringstream oss;
    oss << a;
    std::string output = oss.str();
    
    // The output should be "3 + 4i"
    EXPECT_EQ(output, "3 + 4i");
    
    // Test input stream operator
    ComplexNumberSolutions b;
    std::istringstream iss("5 -2");
    iss >> b;
    
    EXPECT_EQ(b.get_real(), 5.0);
    EXPECT_EQ(b.get_imaginary(), -2.0);
}

// Test SafeArray comprehensive functionality
TEST_F(OverloadedOperationsPracticeTest, TestSafeArrayComprehensive) {
    SafeArray arr(5);
    SafeArraySolutions sol_arr(5);
    
    // Fill the arrays
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = static_cast<int>(i * 2);
        sol_arr[i] = static_cast<int>(i * 2);
    }
    
    // Test copy constructor
    SafeArray copy(arr);
    SafeArraySolutions sol_copy(sol_arr);
    
    EXPECT_EQ(copy.size(), arr.size());
    EXPECT_EQ(sol_copy.size(), sol_arr.size());
    
    for (size_t i = 0; i < copy.size(); ++i) {
        EXPECT_EQ(copy[i], arr[i]);
        EXPECT_EQ(sol_copy[i], sol_arr[i]);
    }
    
    // Test move constructor
    SafeArray moved(std::move(arr));
    SafeArraySolutions sol_moved(std::move(sol_arr));
    
    EXPECT_EQ(moved.size(), 5);
    EXPECT_EQ(sol_moved.size(), 5);
    
    for (size_t i = 0; i < moved.size(); ++i) {
        EXPECT_EQ(moved[i], static_cast<int>(i * 2));
        EXPECT_EQ(sol_moved[i], static_cast<int>(i * 2));
    }
    
    // Test resize
    copy.resize(3);
    sol_copy.resize(3);
    
    EXPECT_EQ(copy.size(), 3);
    EXPECT_EQ(sol_copy.size(), 3);
    
    // Test fill
    copy.fill(99);
    sol_copy.fill(99);
    
    for (size_t i = 0; i < copy.size(); ++i) {
        EXPECT_EQ(copy[i], 99);
        EXPECT_EQ(sol_copy[i], 99);
    }
    
    // Test utility functions
    copy.fill(2);  // Fill with 2s
    sol_copy.fill(2);  // Fill with 2s
    
    EXPECT_EQ(copy.sum(), 6);  // 2 + 2 + 2 = 6
    EXPECT_EQ(sol_copy.sum(), 6);  // 2 + 2 + 2 = 6
    
    EXPECT_DOUBLE_EQ(copy.average(), 2.0);
    EXPECT_DOUBLE_EQ(sol_copy.average(), 2.0);
}

// Test SafeArray copy and move assignment operators
TEST_F(OverloadedOperationsPracticeTest, TestSafeArrayAssignmentOperators) {
    SafeArray source(3, 5);  // Array of 3 elements, all 5
    SafeArraySolutions sol_source(3, 5);
    
    // Test copy assignment
    SafeArray dest(2, 0);  // Array of 2 elements, all 0
    SafeArraySolutions sol_dest(2, 0);
    
    dest = source;
    sol_dest = sol_source;
    
    EXPECT_EQ(dest.size(), 3);
    EXPECT_EQ(sol_dest.size(), 3);
    
    for (size_t i = 0; i < dest.size(); ++i) {
        EXPECT_EQ(dest[i], 5);
        EXPECT_EQ(sol_dest[i], 5);
    }
    
    // Test move assignment
    SafeArray dest2(1, 0);  // Array of 1 element, 0
    SafeArraySolutions sol_dest2(1, 0);
    
    dest2 = std::move(source);
    sol_dest2 = std::move(sol_source);
    
    EXPECT_EQ(dest2.size(), 3);
    EXPECT_EQ(sol_dest2.size(), 3);
    
    for (size_t i = 0; i < dest2.size(); ++i) {
        EXPECT_EQ(dest2[i], 5);
        EXPECT_EQ(sol_dest2[i], 5);
    }
}

// Test SimplePtr comprehensive functionality
TEST_F(OverloadedOperationsPracticeTest, TestSimplePtrComprehensive) {
    // Test copy constructor
    SimplePtrSolutions<int> ptr1(new int(100));
    SimplePtrSolutions<int> ptr2(ptr1);  // Copy constructor
    
    EXPECT_EQ(*ptr1, 100);
    EXPECT_EQ(*ptr2, 100);
    EXPECT_NE(ptr1.get(), ptr2.get());  // Should be different pointers to same value
    
    // Test move constructor
    SimplePtrSolutions<int> ptr3(new int(200));
    int* raw_ptr = ptr3.get();
    SimplePtrSolutions<int> ptr4(std::move(ptr3));  // Move constructor
    
    EXPECT_EQ(*ptr4, 200);
    EXPECT_EQ(ptr4.get(), raw_ptr);  // Should have same pointer
    EXPECT_EQ(ptr3.get(), nullptr);  // Original should be null after move
    
    // Test copy assignment
    SimplePtrSolutions<int> ptr5(new int(300));
    SimplePtrSolutions<int> ptr6(new int(400));
    ptr6 = ptr5;  // Copy assignment
    
    EXPECT_EQ(*ptr5, 300);
    EXPECT_EQ(*ptr6, 300);
    EXPECT_NE(ptr5.get(), ptr6.get());  // Should be different pointers to same value
    
    // Test move assignment
    SimplePtrSolutions<int> ptr7(new int(500));
    SimplePtrSolutions<int> ptr8(new int(600));
    int* raw_ptr7 = ptr7.get();
    ptr8 = std::move(ptr7);  // Move assignment
    
    EXPECT_EQ(*ptr8, 500);
    EXPECT_EQ(ptr8.get(), raw_ptr7);  // Should have same pointer
    EXPECT_EQ(ptr7.get(), nullptr);  // Original should be null after move
    
    // Test comparison operators
    SimplePtrSolutions<int> ptr9(new int(10));
    SimplePtrSolutions<int> ptr10(new int(20));
    SimplePtrSolutions<int> ptr11(ptr9);  // Copy of ptr9
    
    EXPECT_FALSE(ptr9 == ptr10);  // Different values
    EXPECT_TRUE(ptr9 != ptr10);   // Different values
    EXPECT_TRUE(ptr9 == ptr11);   // Same values (copies)
    EXPECT_FALSE(ptr9 != ptr11);  // Same values (copies)
}

// Test SimplePtr with different types
TEST_F(OverloadedOperationsPracticeTest, TestSimplePtrWithDifferentTypes) {
    // Test with double
    SimplePtrSolutions<double> double_ptr(new double(3.14159));
    EXPECT_DOUBLE_EQ(*double_ptr, 3.14159);
    EXPECT_TRUE(double_ptr);
    
    // Test with string
    SimplePtrSolutions<std::string> string_ptr(new std::string("Hello"));
    EXPECT_EQ(*string_ptr, "Hello");
    EXPECT_TRUE(string_ptr);
    
    // Test with nullptr
    SimplePtrSolutions<int> null_ptr;
    EXPECT_FALSE(null_ptr);
    EXPECT_EQ(null_ptr.get(), nullptr);
}

// Test complex scenario combining multiple overloaded operators
TEST_F(OverloadedOperationsPracticeTest, TestComplexScenario) {
    // Create complex numbers
    ComplexNumberSolutions a(1.0, 2.0);
    ComplexNumberSolutions b(3.0, 4.0);
    
    // Perform a series of operations
    ComplexNumberSolutions result = ((a + b) * a - b) / a;
    
    // Calculate expected result manually:
    // a + b = (1+3) + (2+4)i = 4 + 6i
    // (a + b) * a = (4 + 6i) * (1 + 2i) = (4*1 - 6*2) + (4*2 + 6*1)i = (4 - 12) + (8 + 6)i = -8 + 14i
    // ((a + b) * a) - b = (-8 + 14i) - (3 + 4i) = (-8 - 3) + (14 - 4)i = -11 + 10i
    // result = ((a + b) * a - b) / a = (-11 + 10i) / (1 + 2i)
    // = ((-11*1 + 10*2) + (10*1 - (-11)*2)i) / (1^2 + 2^2)
    // = ((-11 + 20) + (10 + 22)i) / 5
    // = (9 + 32i) / 5
    // = 1.8 + 6.4i
    
    EXPECT_NEAR(result.get_real(), 1.8, 1e-9);
    EXPECT_NEAR(result.get_imaginary(), 6.4, 1e-9);
    
    // Test with SafeArray
    SafeArraySolutions arr(5);
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = static_cast<int>(i + 1);
    }
    
    // Use function call operator to modify elements
    for (size_t i = 0; i < arr.size(); ++i) {
        arr(i, arr(i) * 2);  // Double each element
    }
    
    // Verify results
    for (size_t i = 0; i < arr.size(); ++i) {
        EXPECT_EQ(arr[i], static_cast<int>((i + 1) * 2));
    }
    
    // Test utility functions
    EXPECT_EQ(arr.sum(), 30);  // 2 + 4 + 6 + 8 + 10 = 30
    EXPECT_DOUBLE_EQ(arr.average(), 6.0);  // 30 / 5 = 6
    
    // Test with SimplePtr
    SimplePtrSolutions<ComplexNumberSolutions> complex_ptr(new ComplexNumberSolutions(2.0, 3.0));
    EXPECT_DOUBLE_EQ(complex_ptr->get_real(), 2.0);
    EXPECT_DOUBLE_EQ(complex_ptr->get_imaginary(), 3.0);
    EXPECT_DOUBLE_EQ((*complex_ptr).get_real(), 2.0);
    EXPECT_DOUBLE_EQ((*complex_ptr).get_imaginary(), 3.0);
}

} // namespace cpp_primer