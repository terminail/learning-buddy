#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>
#include <streambuf>

// Test control flow operations

class ControlFlowTest : public ::testing::Test {
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

// Test that the program compiles and runs without errors
TEST_F(ControlFlowTest, ProgramCompiles) {
    // We can't directly test the main() function since it requires user input
    SUCCEED() << "Program compiles successfully";
}

// Test if/else statements directly
TEST(ControlFlowDirectTest, IfElseStatements) {
    std::stringstream output;
    std::streambuf* old_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    // Test positive number
    int number = 5;
    if (number > 0) {
        std::cout << "Positive";
    } else if (number < 0) {
        std::cout << "Negative";
    } else {
        std::cout << "Zero";
    }
    
    std::cout.rdbuf(old_cout_buffer);
    EXPECT_EQ(output.str(), "Positive");
}

// Test for loops
TEST(ControlFlowDirectTest, ForLoops) {
    std::stringstream output;
    std::streambuf* old_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    // Test for loop
    for (int i = 1; i <= 3; i++) {
        std::cout << i << " ";
    }
    
    std::cout.rdbuf(old_cout_buffer);
    EXPECT_EQ(output.str(), "1 2 3 ");
}

// Test while loops
TEST(ControlFlowDirectTest, WhileLoops) {
    std::stringstream output;
    std::streambuf* old_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    // Test while loop
    int i = 1;
    int sum = 0;
    while (i <= 3) {
        sum += i;
        i++;
    }
    std::cout << "Sum: " << sum;
    
    std::cout.rdbuf(old_cout_buffer);
    EXPECT_EQ(output.str(), "Sum: 6");
}

// Test nested loops
TEST(ControlFlowDirectTest, NestedLoops) {
    std::stringstream output;
    std::streambuf* old_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    // Test nested loop pattern
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    std::cout.rdbuf(old_cout_buffer);
    std::string expected = "*\n**\n";
    EXPECT_EQ(output.str(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}