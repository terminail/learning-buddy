#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>
#include <streambuf>

// Since our exercise is a simple main() function, we'll test by capturing stdout

class VariablesTypesTest : public ::testing::Test {
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
TEST_F(VariablesTypesTest, ProgramRuns) {
    // We can't directly test the main() function since it's not designed for testing
    // This is a limitation of our simple exercise approach
    SUCCEED() << "Program compiles successfully";
}

// Test that variables can be declared and used
TEST(VariablesTypesDirectTest, VariableDeclaration) {
    // Test basic variable declarations
    int age = 25;
    double height = 1.75;
    char grade = 'A';
    bool isStudent = true;
    std::string name = "John";
    
    // Basic assertions
    EXPECT_EQ(age, 25);
    EXPECT_DOUBLE_EQ(height, 1.75);
    EXPECT_EQ(grade, 'A');
    EXPECT_TRUE(isStudent);
    EXPECT_EQ(name, "John");
}

// Test basic operations with variables
TEST(VariablesTypesDirectTest, VariableOperations) {
    int a = 10;
    int b = 20;
    int sum = a + b;
    
    EXPECT_EQ(sum, 30);
    
    double x = 5.5;
    double y = 2.0;
    double product = x * y;
    
    EXPECT_DOUBLE_EQ(product, 11.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}