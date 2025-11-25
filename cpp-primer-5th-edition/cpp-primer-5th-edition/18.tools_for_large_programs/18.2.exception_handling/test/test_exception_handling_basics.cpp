#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

// Function that throws an exception
int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

// Custom exception class
class CustomException : public std::exception {
private:
    std::string message;
    
public:
    CustomException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Test for basic exception handling
TEST(ExceptionHandlingTest, BasicExceptionHandling) {
    // Test that exception is thrown
    EXPECT_THROW(divide(10, 0), std::runtime_error);
    
    // Test that exception is caught correctly
    try {
        divide(10, 0);
        FAIL() << "Expected std::runtime_error";
    } catch (const std::runtime_error& e) {
        EXPECT_EQ(std::string(e.what()), "Division by zero");
    }
    
    // Test normal operation
    EXPECT_EQ(divide(10, 2), 5);
}

// Test for custom exceptions
TEST(ExceptionHandlingTest, CustomExceptions) {
    // Test that custom exception is thrown and caught
    try {
        throw CustomException("Custom error message");
        FAIL() << "Expected CustomException";
    } catch (const CustomException& e) {
        EXPECT_EQ(std::string(e.what()), "Custom error message");
    }
}

// Test for multiple catch blocks
TEST(ExceptionHandlingTest, MultipleCatchBlocks) {
    // Test catching different exception types
    try {
        throw std::invalid_argument("Invalid argument");
    } catch (const std::invalid_argument& e) {
        EXPECT_EQ(std::string(e.what()), "Invalid argument");
    } catch (const std::exception& e) {
        FAIL() << "Should have caught invalid_argument, not generic exception";
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}