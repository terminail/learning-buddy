#include <gtest/gtest.h>
#include <iostream>
#include <string>

// Simple practice tests for basic C++ concepts in hello world exercise
// No classes or complex structures since students haven't learned them yet

// Practice Test 1: Basic variable declarations and assignments
TEST(HelloWorldPracticeTest, BasicVariables) {
    // Test that students can declare and initialize variables
    int number = 42;
    double pi = 3.14159;
    char letter = 'A';
    bool flag = true;
    std::string message = "Hello, World!";
    
    EXPECT_EQ(number, 42);
    EXPECT_DOUBLE_EQ(pi, 3.14159);
    EXPECT_EQ(letter, 'A');
    EXPECT_TRUE(flag);
    EXPECT_EQ(message, "Hello, World!");
}

// Practice Test 2: Basic arithmetic operations
TEST(HelloWorldPracticeTest, BasicArithmetic) {
    int a = 10;
    int b = 5;
    
    EXPECT_EQ(a + b, 15);
    EXPECT_EQ(a - b, 5);
    EXPECT_EQ(a * b, 50);
    EXPECT_EQ(a / b, 2);
    
    // Test increment/decrement
    int counter = 0;
    counter++;
    EXPECT_EQ(counter, 1);
    
    counter--;
    EXPECT_EQ(counter, 0);
}

// Practice Test 3: String operations
TEST(HelloWorldPracticeTest, BasicStringOperations) {
    std::string greeting = "Hello";
    std::string target = "World";
    
    // Test string concatenation
    std::string result = greeting + ", " + target + "!";
    EXPECT_EQ(result, "Hello, World!");
    
    // Test string length
    EXPECT_EQ(greeting.length(), 5);
    EXPECT_FALSE(greeting.empty());
    
    // Test string comparison
    EXPECT_EQ(greeting, "Hello");
    EXPECT_NE(greeting, "Goodbye");
}

// Practice Test 4: Basic control flow
TEST(HelloWorldPracticeTest, BasicControlFlow) {
    int value = 10;
    
    // Test if statement
    if (value > 5) {
        EXPECT_TRUE(true);
    } else {
        FAIL() << "Condition should be true";
    }
    
    // Test simple loop
    int sum = 0;
    for (int i = 1; i <= 3; i++) {
        sum += i;
    }
    EXPECT_EQ(sum, 6);
    
    // Test while loop
    int count = 0;
    while (count < 3) {
        count++;
    }
    EXPECT_EQ(count, 3);
}

// Practice Test 5: Basic function concepts (without actually defining functions)
TEST(HelloWorldPracticeTest, BasicFunctionConcepts) {
    // This test verifies understanding of function calls and return values
    // Students should understand that main() is a function
    
    // Test basic standard library function usage
    std::string text = "hello";
    EXPECT_EQ(text.length(), 5);
    
    // Test that we can use basic standard library functions
    std::string upper_text = text + " world";
    EXPECT_EQ(upper_text.length(), 11);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}