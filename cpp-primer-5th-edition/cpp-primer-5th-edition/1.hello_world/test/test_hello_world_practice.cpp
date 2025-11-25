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
    
    EXPECT_EQ(number, 42);
    EXPECT_DOUBLE_EQ(pi, 3.14159);
    EXPECT_EQ(letter, 'A');
    EXPECT_TRUE(flag);
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

// Practice Test 3: Basic control flow
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

// Practice Test 4: Simple string concepts
TEST(HelloWorldPracticeTest, BasicStringConcepts) {
    // Test C-style string
    const char* cstring = "Hello";
    EXPECT_STREQ(cstring, "Hello");
    
    // Test that we can use string literals
    EXPECT_STREQ("Hello", "Hello");
    EXPECT_STRNE("Hello", "World");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}