#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

// Test for stream state checking
TEST(StreamStatesTest, StateChecking) {
    std::istringstream iss("123");
    int number;
    
    // Test successful read
    iss >> number;
    EXPECT_TRUE(iss.good());
    EXPECT_FALSE(iss.fail());
    EXPECT_EQ(number, 123);
    
    // Test end of stream
    iss >> number;
    EXPECT_FALSE(iss.good());
    EXPECT_TRUE(iss.fail());
    EXPECT_TRUE(iss.eof());
}

// Test for clearing stream errors
TEST(StreamStatesTest, ErrorClearing) {
    std::istringstream iss("123 abc");
    int number;
    
    // Read successfully
    iss >> number;
    EXPECT_EQ(number, 123);
    
    // Force error by trying to read string into int
    iss >> number;
    EXPECT_TRUE(iss.fail());
    
    // Clear error and continue
    iss.clear();
    EXPECT_FALSE(iss.fail());
    
    std::string str;
    iss >> str;
    EXPECT_EQ(str, "abc");
}

// Test for stream state functions
TEST(StreamStatesTest, StateFunctions) {
    std::istringstream empty_stream("");
    
    // Test initial state
    EXPECT_TRUE(empty_stream.good());
    EXPECT_FALSE(empty_stream.fail());
    EXPECT_FALSE(empty_stream.bad());
    
    // Try to read from empty stream
    int number;
    empty_stream >> number;
    
    // Should be in fail state
    EXPECT_FALSE(empty_stream.good());
    EXPECT_TRUE(empty_stream.fail());
    EXPECT_FALSE(empty_stream.bad()); // Not necessarily bad, just failed
}