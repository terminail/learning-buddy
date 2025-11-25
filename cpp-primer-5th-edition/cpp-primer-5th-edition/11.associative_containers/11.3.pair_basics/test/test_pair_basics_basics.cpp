#include <gtest/gtest.h>
#include <utility>
#include <string>

// Basic tests for pair operations

// TODO: Test pair creation and initialization
// Requirements:
// 1. Create pairs with different types
// 2. Use make_pair function
// 3. Verify element access

// TODO: Test pair comparison operations
// Requirements:
// 1. Test equality and inequality operators
// 2. Test relational operators (<, >, <=, >=)
// 3. Verify lexicographical comparison

// TODO: Test pair assignment and modification
// Requirements:
// 1. Assign values to pair elements
// 2. Test copy assignment
// 3. Verify pair copy semantics

TEST(PairBasics, CreationAndInitialization) {
    // Test default construction
    std::pair<int, double> p1;
    // Test initialization with values
    std::pair<int, double> p2(1, 3.14);
    // Test make_pair function
    auto p3 = std::make_pair(std::string("hello"), 42);
    // Test brace initialization
    std::pair<int, int> p4{10, 20};
    
    EXPECT_EQ(p2.first, 1);
    EXPECT_EQ(p2.second, 3.14);
    EXPECT_EQ(p3.first, "hello");
    EXPECT_EQ(p3.second, 42);
    EXPECT_EQ(p4.first, 10);
    EXPECT_EQ(p4.second, 20);
}

TEST(PairBasics, ComparisonOperations) {
    std::pair<int, int> p1(1, 2);
    std::pair<int, int> p2(1, 2);
    std::pair<int, int> p3(1, 3);
    std::pair<int, int> p4(2, 1);
    
    // Test equality
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
    
    // Test inequality
    EXPECT_TRUE(p1 != p3);
    EXPECT_FALSE(p1 != p2);
    
    // Test less than
    EXPECT_TRUE(p1 < p3);
    EXPECT_TRUE(p1 < p4);
    EXPECT_FALSE(p3 < p1);
    
    // Test greater than
    EXPECT_TRUE(p3 > p1);
    EXPECT_TRUE(p4 > p1);
    EXPECT_FALSE(p1 > p3);
}

TEST(PairBasics, AssignmentAndModification) {
    std::pair<int, double> p1(1, 3.14);
    std::pair<int, double> p2(2, 2.71);
    
    // Test element assignment
    p1.first = 10;
    p1.second = 1.41;
    EXPECT_EQ(p1.first, 10);
    EXPECT_EQ(p1.second, 1.41);
    
    // Test copy assignment
    p1 = p2;
    EXPECT_EQ(p1.first, 2);
    EXPECT_EQ(p1.second, 2.71);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
