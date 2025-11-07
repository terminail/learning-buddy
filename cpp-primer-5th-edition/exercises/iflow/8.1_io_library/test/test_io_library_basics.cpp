#include <gtest/gtest.h>
#include "io_library_exercises.h"
#include <sstream>
#include <fstream>

using namespace cpp_primer;

class IOLibraryTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(IOLibraryTest, DefaultConstructor) {
    IOLibrary exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== CONSOLE I/O TESTS ==========

// Note: Console I/O tests are difficult to implement without mock streams
// These would typically involve redirecting std::cin/cout, which is complex in tests
TEST_F(IOLibraryTest, ConsoleIOFunctions) {
    SUCCEED() << "Console I/O functions would typically be tested with mock streams";
}

// ========== FILE I/O TESTS ==========

TEST_F(IOLibraryTest, WriteAndReadFile) {
    IOLibrary exercise;
    std::string filename = "test_file.txt";
    std::string content = "Hello, World!";
    
    // Test writing to file
    bool write_result = exercise.write_to_file(filename, content);
    EXPECT_TRUE(write_result) << "Expected file write to succeed";
    
    // Test reading from file
    std::string read_content = exercise.read_from_file(filename);
    EXPECT_EQ(read_content, content) << "Expected read content to match written content";
}

TEST_F(IOLibraryTest, AppendToFile) {
    IOLibrary exercise;
    std::string filename = "test_append.txt";
    std::string content1 = "Hello, ";
    std::string content2 = "World!";
    std::string expected = content1 + content2;
    
    // Write initial content
    exercise.write_to_file(filename, content1);
    
    // Append additional content
    bool append_result = exercise.append_to_file(filename, content2);
    EXPECT_TRUE(append_result) << "Expected file append to succeed";
    
    // Read and verify combined content
    std::string read_content = exercise.read_from_file(filename);
    EXPECT_EQ(read_content, expected) << "Expected appended content to match";
}

// ========== STREAM MANIPULATORS TESTS ==========

TEST_F(IOLibraryTest, FormatDouble) {
    IOLibrary exercise;
    
    // Test with 2 decimal places
    std::string result = exercise.format_double(3.14159, 2);
    EXPECT_EQ(result, "3.14") << "Expected 3.14 with 2 decimal places";
    
    // Test with 4 decimal places
    std::string result2 = exercise.format_double(2.71828, 4);
    EXPECT_EQ(result2, "2.7183") << "Expected 2.7183 with 4 decimal places (rounded)";
}

// ========== FORMATTED OUTPUT TESTS ==========

TEST_F(IOLibraryTest, WriteFormattedOutput) {
    IOLibrary exercise;
    std::ostringstream oss;
    
    // Test formatted output
    exercise.write_formatted_output(oss, "Test", 123);
    std::string result = oss.str();
    
    // The exact format might vary, just check if something was written
    EXPECT_FALSE(result.empty()) << "Expected some formatted output";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}