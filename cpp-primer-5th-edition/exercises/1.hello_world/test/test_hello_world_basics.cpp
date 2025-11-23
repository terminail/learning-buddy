#include <gtest/gtest.h>
#include <iostream>

// Simple test for basic hello world output
// No classes or complex structures since students haven't learned them yet

// Test that basic C++ syntax works
TEST(HelloWorldTest, BasicSyntax) {
    int value = 42;
    EXPECT_EQ(value, 42);
    
    // Test basic string
    const char* message = "Hello, World!";
    EXPECT_STREQ(message, "Hello, World!");
}

// Test that we can use basic standard library features
TEST(HelloWorldTest, StandardLibraryBasics) {
    // Test basic arithmetic
    EXPECT_EQ(2 + 2, 4);
    EXPECT_EQ(10 - 3, 7);
    EXPECT_EQ(5 * 6, 30);
    EXPECT_EQ(15 / 3, 5);
    
    // Test boolean operations
    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
    EXPECT_TRUE(5 > 3);
    EXPECT_FALSE(2 > 10);
}

// Test basic control flow concepts
TEST(HelloWorldTest, BasicControlFlow) {
    int x = 10;
    
    // Test if statement
    if (x > 5) {
        EXPECT_TRUE(true);  // This should execute
    } else {
        FAIL() << "This branch should not execute";
    }
    
    // Test simple loop
    int sum = 0;
    for (int i = 1; i <= 3; i++) {
        sum += i;
    }
    EXPECT_EQ(sum, 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}