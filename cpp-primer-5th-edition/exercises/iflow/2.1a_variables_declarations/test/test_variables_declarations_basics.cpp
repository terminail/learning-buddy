#include <gtest/gtest.h>
#include "variables_declarations_exercises.h"

using namespace cpp_primer;

class VariablesDeclarationsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(VariablesDeclarationsTest, DefaultConstructor) {
    VariablesDeclarations exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== BASIC VARIABLE DECLARATION TESTS ==========

TEST_F(VariablesDeclarationsTest, DeclareInteger) {
    VariablesDeclarations exercise;
    int result = exercise.declare_integer();
    
    // Verify that the function returns an integer value
    EXPECT_NE(result, 0) << "Expected a non-zero integer value";
    EXPECT_TRUE((result == 42)) << "Expected 42 as example integer value";
}

TEST_F(VariablesDeclarationsTest, DeclareDouble) {
    VariablesDeclarations exercise;
    double result = exercise.declare_double();
    
    // Verify that the function returns a double value
    EXPECT_NE(result, 0.0) << "Expected a non-zero double value";
    EXPECT_NEAR(result, 3.14159, 0.0001) << "Expected 3.14159 as example double value";
}

TEST_F(VariablesDeclarationsTest, DeclareCharacter) {
    VariablesDeclarations exercise;
    char result = exercise.declare_character();
    
    // Verify that the function returns a character value
    EXPECT_NE(result, ' ') << "Expected a non-space character value";
    EXPECT_TRUE(isalpha(result)) << "Expected an alphabetic character";
}

TEST_F(VariablesDeclarationsTest, DeclareBoolean) {
    VariablesDeclarations exercise;
    bool result = exercise.declare_boolean();
    
    // Verify that the function returns a boolean value
    EXPECT_TRUE(result) << "Expected true as example boolean value";
}

// ========== AUTO KEYWORD TESTS ==========

TEST_F(VariablesDeclarationsTest, UseAutoKeyword) {
    VariablesDeclarations exercise;
    int input = 100;
    int result = exercise.use_auto_keyword(input);
    
    // Verify that the function properly uses auto keyword and returns the same value
    EXPECT_EQ(result, input) << "Expected the same value as input";
}

// ========== MULTIPLE VARIABLES TESTS ==========

TEST_F(VariablesDeclarationsTest, DeclareMultipleVariables) {
    VariablesDeclarations exercise;
    int result = exercise.declare_multiple_variables();
    
    // Verify that the function returns the sum of multiple variables
    EXPECT_NE(result, 0) << "Expected a non-zero sum";
    EXPECT_EQ(result, 60) << "Expected sum of 10 + 20 + 30";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}