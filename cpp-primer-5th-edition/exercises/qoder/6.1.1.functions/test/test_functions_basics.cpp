#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>
#include <streambuf>

// Test function operations

// Include the functions we want to test
int multiply(int a, int b) {
    return a * b;
}

void greet_user(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

bool is_even(int number) {
    return (number % 2 == 0);
}

class FunctionsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Redirect cout to our stringstream buffer
        old_cout_buffer = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
    }
    
    void TearDown() override {
        // Reset cout to original buffer
        std::cout.rdbuf(old_cout_buffer);
    }
    
    std::stringstream buffer;
    std::streambuf* old_cout_buffer;
};

// Test multiply function
TEST_F(FunctionsTest, MultiplyFunction) {
    EXPECT_EQ(multiply(3, 4), 12);
    EXPECT_EQ(multiply(-2, 5), -10);
    EXPECT_EQ(multiply(0, 100), 0);
}

// Test is_even function
TEST(FunctionsDirectTest, IsEvenFunction) {
    EXPECT_TRUE(is_even(2));
    EXPECT_FALSE(is_even(3));
    EXPECT_TRUE(is_even(0));
    EXPECT_FALSE(is_even(-1));
    EXPECT_TRUE(is_even(-4));
}

// Test greet_user function
TEST_F(FunctionsTest, GreetUserFunction) {
    greet_user("Alice");
    EXPECT_EQ(buffer.str(), "Hello, Alice!\n");
}

// Test function with multiple parameters
TEST(FunctionsDirectTest, FunctionWithMultipleParameters) {
    // Test a function that takes multiple parameters
    auto add_three = [](int a, int b, int c) -> int {
        return a + b + c;
    };
    
    EXPECT_EQ(add_three(1, 2, 3), 6);
    EXPECT_EQ(add_three(-1, 0, 1), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}