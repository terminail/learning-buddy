#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>

// Test for file writing
TEST(FileStreamsTest, FileWriting) {
    const std::string filename = "test_output.txt";
    const std::string content = "Test content for file writing";
    
    // Write to file
    std::ofstream file(filename);
    EXPECT_TRUE(file.is_open());
    file << content;
    file.close();
    
    // Verify file was created and has correct content
    std::ifstream read_file(filename);
    EXPECT_TRUE(read_file.is_open());
    std::string read_content;
    std::getline(read_file, read_content);
    read_file.close();
    
    EXPECT_EQ(read_content, content);
    
    // Clean up
    std::filesystem::remove(filename);
}

// Test for file reading
TEST(FileStreamsTest, FileReading) {
    const std::string filename = "test_input.txt";
    const std::string content = "Line 1\nLine 2\nLine 3";
    
    // Create test file
    std::ofstream write_file(filename);
    EXPECT_TRUE(write_file.is_open());
    write_file << content;
    write_file.close();
    
    // Read from file
    std::ifstream file(filename);
    EXPECT_TRUE(file.is_open());
    
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    
    EXPECT_EQ(lines.size(), 3);
    EXPECT_EQ(lines[0], "Line 1");
    EXPECT_EQ(lines[1], "Line 2");
    EXPECT_EQ(lines[2], "Line 3");
    
    // Clean up
    std::filesystem::remove(filename);
}

// Test for file opening errors
TEST(FileStreamsTest, FileOpeningErrors) {
    const std::string filename = "nonexistent_directory/nonexistent_file.txt";
    
    // Try to open non-existent file for reading
    std::ifstream input_file(filename);
    EXPECT_FALSE(input_file.is_open());
    
    // Try to open file in non-existent directory for writing
    std::ofstream output_file(filename);
    EXPECT_FALSE(output_file.is_open());
}