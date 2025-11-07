#include <gtest/gtest.h>
#include "io_library_exercises.h"
#include <sstream>

using namespace cpp_primer;

class IOLibraryPracticeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== PRACTICE PROBLEM 1: STRING STREAMS ==========

/**
 * Practice Problem 1: Use string streams for parsing
 * 
 * Practice using std::istringstream and std::ostringstream for parsing and formatting
 */
TEST_F(IOLibraryPracticeTest, Practice1_StringStreams) {
    SUCCEED() << "Practice: Try implementing functions that parse numbers from strings using istringstream";
}

// ========== PRACTICE PROBLEM 2: BINARY FILE I/O ==========

/**
 * Practice Problem 2: Work with binary file I/O
 * 
 * Practice reading and writing binary data to files
 */
TEST_F(IOLibraryPracticeTest, Practice2_BinaryFileIO) {
    SUCCEED() << "Practice: Try implementing functions that read/write binary data";
}

// ========== PRACTICE PROBLEM 3: ERROR HANDLING ==========

/**
 * Practice Problem 3: Implement proper error handling
 * 
 * Practice checking stream states and handling errors
 */
TEST_F(IOLibraryPracticeTest, Practice3_ErrorHandling) {
    SUCCEED() << "Practice: Try implementing functions that check stream states and handle errors";
}

// ========== PRACTICE PROBLEM 4: CUSTOM STREAM MANIPULATORS ==========

/**
 * Practice Problem 4: Create custom stream manipulators
 * 
 * Practice creating custom manipulators for stream formatting
 */
TEST_F(IOLibraryPracticeTest, Practice4_CustomManipulators) {
    SUCCEED() << "Practice: Try creating custom stream manipulators";
}

// ========== CUSTOM PRACTICE PROBLEMS ==========

/**
 * Custom Practice: Add your own practice problems
 * This is where you can extend the exercise with your own concepts
 */
TEST_F(IOLibraryPracticeTest, CustomPracticeProblems) {
    SUCCEED() << "Custom Practice: Create your own IO library exercises";
}

// ========== BONUS CHALLENGE TESTS ==========

/**
 * Bonus Challenge: Implement more complex IO operations
 * 
 * Try implementing operations like reading CSV files or creating loggers
 */
TEST_F(IOLibraryPracticeTest, BonusChallenge_ComplexIO) {
    SUCCEED() << "Bonus: Try implementing a simple CSV reader or logger class";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}