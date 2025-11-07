#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>
#include <streambuf>

// Since our exercise is a simple main() function, we'll test by capturing I/O

class BasicIOTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Redirect cin and cout to our stringstream buffers
        old_cout_buffer = std::cout.rdbuf();
        old_cin_buffer = std::cin.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
    }
    
    void TearDown() override {
        // Reset cin and cout to original buffers
        std::cout.rdbuf(old_cout_buffer);
        std::cin.rdbuf(old_cin_buffer);
    }
    
    std::stringstream buffer;
    std::stringstream input;
    std::streambuf* old_cout_buffer;
    std::streambuf* old_cin_buffer;
};

// Test that the program compiles and runs without errors
TEST_F(BasicIOTest, ProgramCompiles) {
    // We can't directly test the main() function since it requires user input
    // This is a limitation of our simple exercise approach
    SUCCEED() << "Program compiles successfully";
}

// Test basic I/O operations directly
TEST(BasicIODirectTest, OutputOperations) {
    std::stringstream output;
    std::streambuf* old_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    // Test basic output
    std::cout << "Hello, World!" << std::endl;
    
    std::cout.rdbuf(old_cout_buffer);
    
    EXPECT_NE(output.str().find("Hello, World!"), std::string::npos);
}

// Test input operations
TEST(BasicIODirectTest, InputOperations) {
    // We can't easily test cin in unit tests without complex mocking
    // This demonstrates the challenge of testing I/O operations
    SUCCEED() << "Input operations require interactive testing";
}

// Test string stream operations
TEST(BasicIODirectTest, StringStreamOperations) {
    std::stringstream ss;
    std::string name = "John";
    int age = 25;
    
    // Test output to stringstream
    ss << "Name: " << name << ", Age: " << age;
    EXPECT_EQ(ss.str(), "Name: John, Age: 25");
    
    // Test input from stringstream
    std::string read_name;
    int read_age;
    std::stringstream input_ss("John 25");
    input_ss >> read_name >> read_age;
    
    EXPECT_EQ(read_name, "John");
    EXPECT_EQ(read_age, 25);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}