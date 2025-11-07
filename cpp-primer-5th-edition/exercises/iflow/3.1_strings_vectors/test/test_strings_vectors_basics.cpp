#include <gtest/gtest.h>
#include "strings_vectors_exercises.h"

using namespace cpp_primer;

class StringsVectorsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(StringsVectorsTest, DefaultConstructor) {
    StringsVectors exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== STRING OPERATION TESTS ==========

TEST_F(StringsVectorsTest, CreateString) {
    StringsVectors exercise;
    std::string result = exercise.create_string("Hello");
    
    // Verify that the function creates a string correctly
    EXPECT_EQ(result, "Hello") << "Expected the created string to match the input";
}

TEST_F(StringsVectorsTest, ConcatenateStrings) {
    StringsVectors exercise;
    std::string result = exercise.concatenate_strings("Hello", "World");
    
    // Verify that the function concatenates strings correctly
    EXPECT_EQ(result, "HelloWorld") << "Expected the concatenated string to match";
}

TEST_F(StringsVectorsTest, GetStringLength) {
    StringsVectors exercise;
    std::string test_string = "Hello";
    size_t result = exercise.get_string_length(test_string);
    
    // Verify that the function returns the correct string length
    EXPECT_EQ(result, 5) << "Expected the string length to be 5";
}

// ========== VECTOR OPERATION TESTS ==========

TEST_F(StringsVectorsTest, CreateVector) {
    StringsVectors exercise;
    std::vector<int> result = exercise.create_vector(3, 10);
    
    // Verify that the function creates a vector with correct size and values
    EXPECT_EQ(result.size(), 3) << "Expected the vector to have size 3";
    EXPECT_EQ(result[0], 10) << "Expected the first element to be 10";
    EXPECT_EQ(result[1], 10) << "Expected the second element to be 10";
    EXPECT_EQ(result[2], 10) << "Expected the third element to be 10";
}

TEST_F(StringsVectorsTest, AddToVector) {
    StringsVectors exercise;
    std::vector<int> vec = {1, 2, 3};
    size_t new_size = exercise.add_to_vector(vec, 4);
    
    // Verify that the function adds to vector and returns correct size
    EXPECT_EQ(new_size, 4) << "Expected the new vector size to be 4";
    EXPECT_EQ(vec.size(), 4) << "Expected the vector size to be 4";
    EXPECT_EQ(vec[3], 4) << "Expected the new element to be 4";
}

TEST_F(StringsVectorsTest, GetVectorSize) {
    StringsVectors exercise;
    std::vector<int> vec = {1, 2, 3, 4};
    size_t result = exercise.get_vector_size(vec);
    
    // Verify that the function returns the correct vector size
    EXPECT_EQ(result, 4) << "Expected the vector size to be 4";
}

TEST_F(StringsVectorsTest, SumVectorElements) {
    StringsVectors exercise;
    std::vector<int> vec = {1, 2, 3, 4};
    int result = exercise.sum_vector_elements(vec);
    
    // Verify that the function returns the correct sum of elements
    EXPECT_EQ(result, 10) << "Expected the sum of elements to be 10";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}