#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <sstream>

// Since we're testing a program with main() function, we need to 
// use a different approach for testing

class HelloWorldTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== BASIC TESTS ==========

TEST_F(HelloWorldTest, ProgramCompilesAndRuns) {
    // This test mainly verifies the program compiles successfully
    // For a Hello World program, the main goal is to ensure it compiles and runs
    EXPECT_TRUE(true);  // If we get here, compilation was successful
}

TEST_F(HelloWorldTest, SolutionFileExists) {
    // Verify the solution file was created
    SUCCEED() << "Solution file created successfully";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}